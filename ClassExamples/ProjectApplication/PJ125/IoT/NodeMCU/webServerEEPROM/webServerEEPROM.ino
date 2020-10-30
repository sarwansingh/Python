#include <ESP8266WiFi.h>
#include<EEPROM.h>
 
const char* ssid = "simer";//type your ssid
const char* password = "012345678";//type your password
int value = LOW;
int ledPin = 2; // GPIO2 of ESP8266
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  delay(10);
  
  pinMode(ledPin, OUTPUT);
  //// read the EEPROM 
  value = EEPROM.read(0);
  digitalWrite(ledPin, value);
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
    
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) { //client ==NULL
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 
  
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, LOW);
    EEPROM.write(0, 0);
    EEPROM.commit();
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, HIGH);
    EEPROM.write(0, 1);
    EEPROM.commit();
    value = LOW;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><h1> Welcome ST402 </h1><hr><br>");
  if (value == LOW){ 
      client.println("Click <a href=\"/LED=ON\">here</a> turn the LED ON<br>");
  }else {
      client.println("Click <a href=\"/LED=OFF\"><img src=\"http://getdrawings.com/img/light-bulb-silhouette-vector-11.png\" height=100 width=100 alt=\"OFF\"> </a> turn the LED OFF <br>");
  }
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
