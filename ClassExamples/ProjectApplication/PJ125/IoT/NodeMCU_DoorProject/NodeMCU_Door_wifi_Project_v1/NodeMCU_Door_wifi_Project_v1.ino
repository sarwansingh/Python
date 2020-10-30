#include <ESP8266WiFi.h>
#include "JSON.h"

const int LEDpin = 2;
const int doorSensor = 4;
int doorStatus=0;
String wifiusername = "DIGISOL" , pwd ="";
String username = "demo";
String Device_No = "Door001" ;
int sensorVal1 = -1, sensorVal2 = -1;

String getJSON();

void setup_wifi(){
  Serial.println();
  Serial.print("Connecting to WiFi ");
  
  WiFi.begin(wifiusername , pwd);

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
        sensorVal1 = doorStatus;
        String content =  getJSON() ;
        Serial.println( content );
        jsonPOST( content);
      }
   }else{
      if (doorStatus !=0) {
        doorStatus = 0;
        digitalWrite(LEDpin, LOW);
        Serial.println("Door Close");
        
        sensorVal1 = doorStatus;
        String content =  getJSON() ;
        Serial.println( content );
        jsonPOST( content);
      }
   }
    
}
//form the JSON string with the available sensor data
String getJSON() {
  String data ;
  data += "{\"username\":\"" + String(username)  + "\",\"name\":\"";
  data += String(Device_No);
  data += "\",\"sample1\":\"";
  data += String( sensorVal1);    //(unsigned char)
  data += "\",\"sample2\":\"";
  data += String(sensorVal2);
  data += "\",\"sample5\":\"";
  int nosample = -1;
  data += String(nosample);
  data += "\"}";
  return data;
}
