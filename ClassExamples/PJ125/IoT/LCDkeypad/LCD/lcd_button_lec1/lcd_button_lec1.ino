#include <LiquidCrystal.h>
const int button1 = 7, button2 = 8,button3 = 12, button4 = 13;  
const int led1 =  10, led2 =  6, led3 =  9, led4 =  11; 
const int buzzer =  4; 

int rs=5 , en=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(button1, INPUT); 
  pinMode(led1, OUTPUT);
  pinMode(button2, INPUT);  pinMode(button3, INPUT); pinMode(button4, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Timer Button");
}
int button1Press=0,button2Press=0; int timerVal=0;
void loop() {
  
  if (digitalRead(button1) == HIGH){
    digitalWrite(led1, HIGH);  
    timerGo();
    while(digitalRead(button1) == HIGH ) ;
       digitalWrite(led1, LOW);  
  }
  if (digitalRead(button2) == HIGH){
     timerVal=5;
    while(digitalRead(button2) == HIGH ) ;
  }
  if (digitalRead(button3) == HIGH){
     timerVal=10;
    while(digitalRead(button3) == HIGH ) ;
  }
  if (digitalRead(button4) == HIGH){
     timerVal=15;
    while(digitalRead(button4) == HIGH ) ;
  }
   
}
void timerGo(){
   ////////////// timer logic 
  if (timerVal>0){
//    for (int k=0; k<timerVal ; k++){
//      digitalWrite(led2, HIGH);  delay(500);
//      digitalWrite(led2, LOW); delay(500);
//    }
//    timerVal=0;
      for ( ; timerVal>0 ; timerVal--){
        digitalWrite(led2, HIGH); digitalWrite(buzzer, HIGH);  delay(500);
        digitalWrite(led2, LOW); digitalWrite(buzzer, LOW);  delay(500);
        lcd.setCursor(0,1); lcd.print (timerVal);  lcd.print (" sec remaining"); 
      }
  }

  ////////////// timer logic end 
}
//void BuzzOn(int x)
//{
//  digitalWrite(buzzer, HIGH);  delay(x);
//}
//void BuzzOff(int x)
//{
//  digitalWrite(buzzer, LOW);  delay(x);
//}
