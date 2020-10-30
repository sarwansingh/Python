#include <ESP8266WiFi.h>
#include <PubSubClient.h>
void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();

const char* ssid = "simer";
const char* password = "012345678";
const char* mqtt_server = "mqtt.eclipse.org";
const int ledPin = 2;
const int buttonPin = 0;     // onboard  flash button
int buttonState=0;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    reconnect();
}

void setup_wifi(){

  delay(10);
  // We start by connecting to a WiFi network
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]  ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  
  if((char)payload[0] == '1') { //on
     digitalWrite(ledPin, HIGH);
     Serial.print("pin high");
  }   
  else if((char)payload[0] == '0' ) //off
  {  digitalWrite(ledPin, LOW);
     Serial.print("pin low");
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("NIELITPJ125")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("Class/light1", "1");
      // ... and resubscribe
      client.subscribe("Class/light1");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {

  ///// button interfacing 
    if ( digitalRead(buttonPin) ==LOW) {
      if (buttonState ==1) buttonState =0;
      else buttonState =1;
      while(digitalRead(buttonPin) ==LOW) ;
  } 

  if (buttonState == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  /////end button interfacing
 
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
