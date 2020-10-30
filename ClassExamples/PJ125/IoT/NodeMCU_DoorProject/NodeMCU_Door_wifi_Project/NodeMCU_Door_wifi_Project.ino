#include <ESP8266WiFi.h>
const int LEDpin = 2;
const int doorSensor = 4;
int doorStatus=0;
String username = "DIGISOL" , pwd ="";
void setup_wifi(){
  Serial.println();
  Serial.print("Connecting to WiFi ");
  
  WiFi.begin(username , pwd);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void setup() {
  Serial.begin(115200);
  pinMode(LEDpin , OUTPUT);
  pinMode(doorSensor , INPUT_PULLUP);
  setup_wifi() ; 
//  testing LED
//  for (int i=5; i--;){
//    digitalWrite(LEDpin, HIGH);delay(500);
//    digitalWrite(LEDpin, LOW); delay(500);
//  }
}
void loop() {
   if (digitalRead(doorSensor) == HIGH){
      if (doorStatus!=1) { doorStatus=1; 
        digitalWrite(LEDpin, HIGH);
        Serial.println("Door Open");
      }
   }else{
      if (doorStatus !=0) {
        doorStatus = 0;
        digitalWrite(LEDpin, LOW);
        Serial.println("Door Close");
      }
   }
    
}
