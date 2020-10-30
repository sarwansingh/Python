#include <LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int button1=7, button2=8;
int cnt1=0;
void setup() { 
  lcd.begin(16, 2);
  lcd.print("PJ125 champ!");
  pinMode(button1, INPUT);pinMode(button2, INPUT);
}

void loop() {
  if (digitalRead(button1) == HIGH){
    cnt1++;
    lcd.setCursor(0, 1);//col,row
    lcd.print("button1 :" ) ;
    lcd.print(cnt1);
    while (digitalRead(button1) == HIGH) ;
  }
  if (digitalRead(button2) == HIGH){
    lcd.setCursor(0, 1);//col,row
    lcd.print("button2 pressed" ) ;
    while (digitalRead(button2) == HIGH) ;
  }

//  lcd.setCursor(0, 1); //lcd.print("sahil desh!");
//  lcd.print(millis() /1000 );
  //delay(1000);
}
