const int LEDpin = 2;
const int doorSensor = 4;

void setup() {
  pinMode(LEDpin , OUTPUT);
  pinMode(doorSensor , INPUT_PULLUP);
//  testing
  for (int i=5; i--;){
    digitalWrite(LEDpin, HIGH);delay(500);
    digitalWrite(LEDpin, LOW); delay(500);
  }
}
void loop() {
   if (digitalRead(doorSensor) == HIGH){
      digitalWrite(LEDpin, HIGH);
   }else{
      digitalWrite(LEDpin, LOW);
   }
}
