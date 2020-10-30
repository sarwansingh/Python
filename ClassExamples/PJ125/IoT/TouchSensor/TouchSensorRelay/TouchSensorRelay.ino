//Digital Capacitive Touch Sensor Switch Arduino Interfacing
 
#define sensorPin 12 // capactitive touch sensor - Arduino Digital pin D1
 
int relayPin = 13; // Output RelayPin - Arduino Digital pin D13
 
boolean currentState = LOW;
boolean lastState = LOW;
boolean RelayState = LOW;
 
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
}
 
void loop() {
  currentState = digitalRead(sensorPin);
    if (currentState == HIGH && lastState == LOW){
    delay(1);
    
    if (RelayState == HIGH){
      digitalWrite(relayPin, LOW);
      RelayState = LOW;
    } else {
      digitalWrite(relayPin, HIGH);
      RelayState = HIGH;
    }
  }
  lastState = currentState;
}
