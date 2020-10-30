int led1 =13;
void setup() {
  pinMode(led1 , OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading value from serial " ) ;
}
int val = 0;
void loop() {
  val = Serial.read();
  // if nothing is received val will have -1
  if (val != -1)  {
    Serial.println(val);
    
    delay(500);
  }
  if (val==49)  { //when 1 is received
    digitalWrite(led1, HIGH);
  }
  if (val==50) { // when 2 is received
    digitalWrite(led1, LOW);
  }
  

}
