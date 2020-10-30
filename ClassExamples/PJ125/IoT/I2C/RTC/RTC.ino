// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// SDA - A4 , SCL - A5
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(9600);
  lcd.begin(16,2);  lcd.print("Welcome I2C RTC" ) ;
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  } 
  // run the below line of code once , in order to adjust the Date and time 
 // rtc.adjust(DateTime(2020,02, 26, 11, 22,05));
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!"); 
  }
}

void loop () {
    DateTime now = rtc.now();
    lcd.setCursor(0,1);

    lcd.print(now.day());   lcd.print("/");
    lcd.print(now.month()); lcd.print("  ");
    //lcd.print(now.year());  lcd.print(" ");
    
    lcd.print(now.hour());lcd.print(":");
    lcd.print(now.minute());lcd.print(":");
    lcd.print(now.second());
    // for displaying data on serial monitor
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(")   ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(1000);
}
