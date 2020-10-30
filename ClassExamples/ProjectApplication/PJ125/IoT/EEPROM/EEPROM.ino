#include <EEPROM.h>
const int button1 = 7,button2 = 8,button3 = 12, button4 = 13;  
const int led1 =  10, led2 =  6,led3 =  9, led4 =  11;
int button1Pressed=0;
void setup() {
    pinMode(led1 , OUTPUT);
    pinMode(button1, INPUT);
    button1Pressed = EEPROM.read(10);
}

void loop() {
    if (digitalRead(button1) == HIGH){
      if (button1Pressed ==1) button1Pressed=0;
      else button1Pressed = 1; 
      while(digitalRead(button1) == HIGH) ;
    }
    if (button1Pressed ==1) {
      EEPROM.write(10, 1); // write 1 on address 10 
      digitalWrite(led1, HIGH);
    }else {
      EEPROM.write(10, 0);// write 0 on address 10 
      digitalWrite(led1, LOW);
    }
}
