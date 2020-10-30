#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "JSON.h"

boolean motionstatus = false;
const char* ssid     = "nielit1";
const char* password = "N1el1t@123";
boolean isWifiConnnected = false;
//////////////// Function Prototype ///////////
String getJSON( ) ;
boolean connectWifi ()  ;
void  jsonPOST(String);

String username = "demo";
String Device_No = "F1Stair01" ;
String content  ;
int sensorVal1 = -1, sensorVal2 = -1;
unsigned long lastUploadTime = 0;
unsigned long lastTime = 0;
boolean readyToUpload = true;
////////////////////
int Relay1 = 4;//13;         // 13 for uno , 4 for node
int sensor = 5;              // the pin that the sensor is atteched to
int state =  LOW;            // by default, no motion detected
int val =    0;              // variable to store the sensor status (value)
int uploadTimer = 0;

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(Relay1, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);
  digitalWrite(Relay1, HIGH);
  isWifiConnnected = connectWifi() ;
  delay(4000);
  lastUploadTime = millis();

}
void loop() {

  content =  getJSON() ;
  jsonPOST( content);
  sensorVal1++; sensorVal2++;
  if (isWifiConnnected == false )
  {
    isWifiConnnected = connectWifi() ;
  }
  delay(3000);
}// loop() ends
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
boolean connectWifi () {
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  delay(4000);

  if  (WiFi.status() != WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi Not connected");
    isWifiConnnected = false;
    return false ;
  } else {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    isWifiConnnected = true;
    return true;
  }
  return false ;
}
