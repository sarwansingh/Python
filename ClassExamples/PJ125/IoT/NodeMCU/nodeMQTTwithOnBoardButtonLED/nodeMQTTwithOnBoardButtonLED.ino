#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const int buttonPin = 0;     // onboard  flash button
const int ledPin = 2;      // onboard LED pin
char ssid[]="Redmi" ,*pwd = "123456789" ;
int buttonState = 0;         // variable for reading the pushbutton status
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
void connect_wifi(){
  Serial.print("Connecting to ");
 
  WiFi.begin(ssid, pwd);
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  } 
  WiFiServer server(80);

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

void setup() {
  Serial.begin(115200);
  Serial.println("welcome MQTT Node Ex");
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  connect_wifi();     // connect to wifi hotspot
  client.setServer("mqtt.eclipse.org", 1883);  // connect to MQTT Server/broker
  client.setCallback(callback);
  reconnect();
}
void reconnect() {
  // Loop until we're reconnected
  while  (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("PJ125NODE")) { 
      Serial.println("connected");
       client.subscribe("Class/Light1");   
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(1000);
    }
  }
}
void callback(char* topic, byte* payload, unsigned int length){
  Serial.println();
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.print ( "  " );

  if ((char)payload[0] == '0') {
    digitalWrite(ledPin, LOW);
   // client.publish("Class/Light1", "0");
    Serial.print("LED 1 LOW");
  }
  if ((char)payload[0] == '1') {
    digitalWrite(ledPin, HIGH);
    //client.publish("Class/Light1", "1");
    Serial.print("LED 1 HIGH");
  }
}
void loop() {

  if ( digitalRead(buttonPin) ==LOW) {
      if (buttonState ==1){
         buttonState =0;
         client.publish("Class/Light1", "0");
         digitalWrite(ledPin, LOW);
      }
      else{
        buttonState =1;
         client.publish("Class/Light1", "1");
         digitalWrite(ledPin, HIGH);
      }
      while(digitalRead(buttonPin) ==LOW ) ;
  }

   if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(100);
}
