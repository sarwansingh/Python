#include<LiquidCrystal.h>
const int button1 = 7, button2 = 8,button3 = 12, button4 = 13;  
const int led1 =  10, led2 =  6, led3 =  9, led4 =  11; 
const int buzzer =  04; 

const int rs=5 , e=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, e, d4,d5,d6,d7); 
int r1=13, r2=12, r3=11, r4=10 ;
int c1=9, c2=8, c3=7 ,c4=6 ;
/*
 * 0 1 2 3  
 * 4 5 6 7 
 * 8 9 A B
 * C D E F
 */

void setup()
{ lcd.begin(16,2); lcd.print("LCD Keypad ex" ) ;
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);    pinMode(c4,INPUT);  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);  digitalWrite(c4,HIGH);   
  lcd.setCursor(0,1);
}
 
void loop(){
  //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("0"); delay(300);   }
  if(digitalRead(c2)==LOW){ lcd.print("1"); delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("2"); delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("3"); delay(300);  }
  
//make ROW2 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("4");  delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("5");  delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("6");  delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("7");  delay(300);  }

//make ROW3 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("8"); delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("9"); delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("A"); delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("B"); delay(300);  }
  
  //make ROW4 as LOW, rest all rows HIGH and check all the corresponding columns
 digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ lcd.print("C"); delay(300);  }
  if(digitalRead(c2)==LOW){ lcd.print("D"); delay(300);  }
  if(digitalRead(c3)==LOW){ lcd.print("E"); delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("F"); delay(300);  }
}
