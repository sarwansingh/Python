#include <LiquidCrystal.h>
int rs=5 , en=3, d4=2,d5=16, d6=15,d7=14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int r1=13, r2=12, r3=11, r4=10 ;
int c1=9, c2=8, c3=7 ,c4=6 ;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter Pass");
  // all rows as OUTPUT, columns as INPUT, make all Columns HIGH
  pinMode(r1,OUTPUT);  pinMode(r2,OUTPUT);  pinMode(r3,OUTPUT);   pinMode(r4,OUTPUT);   
  pinMode(c1,INPUT);   pinMode(c2,INPUT);   pinMode(c3,INPUT);    pinMode(c4,INPUT);  
  digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);  digitalWrite(c3,HIGH);  digitalWrite(c4,HIGH);   
  lcd.setCursor(0,1);
  
}
int i=0, pass=0; 
void loop() {
   //make ROW1 as LOW, rest all rows HIGH and check all the corresponding columns
  digitalWrite(r1,LOW);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("0"); pass = pass*10+0; delay(300);   }
  if(digitalRead(c2)==LOW){ lcd.print("1"); pass = pass*10+1;delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("2"); pass = pass*10+2;delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("3"); pass = pass*10+3;delay(300);  }

  digitalWrite(r1,HIGH);   digitalWrite(r2,LOW);  digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("4"); pass = pass*10+4;  delay(300);   }
  if(digitalRead(c2)==LOW){ lcd.print("5"); pass = pass*10+5;delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("6"); pass = pass*10+6;delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("7"); pass = pass*10+7; delay(300);  }

  digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,LOW); digitalWrite(r4,HIGH); 
  if(digitalRead(c1)==LOW){ lcd.print("8"); delay(300);   }
  if(digitalRead(c2)==LOW){ lcd.print("*"); delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("A"); delay(300);  }
  if(digitalRead(c4)==LOW){ lcd.print("B"); delay(300);  }

  digitalWrite(r1,HIGH);   digitalWrite(r2,HIGH);  digitalWrite(r3,HIGH); digitalWrite(r4,LOW); 
  if(digitalRead(c1)==LOW){ //lcd.print("C"); delay(300);  
    lcd.clear();    pass=0;
    lcd.print("Enter Pass");
    lcd.setCursor(0,1); 
  }
  if(digitalRead(c2)==LOW){ lcd.print("D"); delay(300);   }
  if(digitalRead(c3)==LOW){ lcd.print("E"); delay(300);  }
  if(digitalRead(c4)==LOW){ 
    if ( pass==37){
      lcd.print(" right"); pass=0;
    }else  {
      lcd.print(" wrong"); pass=0;
    }
    delay(300); 
    }
    
}
