void setup() {
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

}
