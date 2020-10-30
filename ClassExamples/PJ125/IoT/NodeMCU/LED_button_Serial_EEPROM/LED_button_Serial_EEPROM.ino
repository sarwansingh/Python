#include<EEPROM.h>
const int buttonPin = 0;     // onboard  flash button
const int ledPin =  2;      // onboard LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  buttonState = EEPROM.read(10);
  Serial.print("Data from EEPROM : ");
  Serial.println(buttonState);
}

void loop() {
  if ( digitalRead(buttonPin) == HIGH) {
    if (buttonState == 1) {
      buttonState = 0;
      Serial.println("LED ON");
      EEPROM.write(10,0);  EEPROM.commit();
    }else {
      buttonState = 1;
      Serial.println("LED OFF");
      EEPROM.write(10,1);  EEPROM.commit();
    }
    while (digitalRead(buttonPin) == HIGH ) ;
  }

  if (buttonState == 1) {
    digitalWrite(ledPin, HIGH);
    //    Serial.println("LED ON");
  } else {
    digitalWrite(ledPin, LOW);
    //    Serial.println("LED OFF");
  }
}
