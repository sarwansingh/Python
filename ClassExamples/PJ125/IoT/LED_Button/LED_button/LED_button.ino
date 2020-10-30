/* TOGGLE 
 * LED should be on once button is pressed and released
 * till next time button is pressed and released
 * button - 7,8,12,13 LED - 10,6,9,11  buzzer -4
 */
int but1=7;
int led1=10;
void setup() {
   pinMode(led1,OUTPUT) ;  
   pinMode(but1,INPUT) ;
}
int buttonPressed=0;
void loop() {
  if (digitalRead (but1) == HIGH){ 
    if (buttonPressed==1) buttonPressed=0;
    else buttonPressed=1;
    while (digitalRead (but1) == HIGH) {}
  }
  if (buttonPressed==1){
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  } 
  
}
/*
 * if button pressed then  led is on else off  
 * int but1=7;
int led1=10;
void setup() {
   pinMode(led1,OUTPUT) ;  
   pinMode(but1,INPUT) ;
}

void loop() {
  if (digitalRead (but1) == HIGH){ 
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  
}

 */
