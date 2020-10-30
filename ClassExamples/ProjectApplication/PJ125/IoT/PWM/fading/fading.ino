int led1 =10,led2=6,led3=9,led4=11; 
void setup() {
  pinMode(led1, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  for (int i=0; i<255 ; i+=10){
    analogWrite(led1, i);
     analogWrite(led4, 255-i);
     Serial.println(i);
    delay(500);
  }
  delay(3000);
//   analogWrite(led1, 5);
//  analogWrite(led2, 127);
//  analogWrite(led3, 191);
//  analogWrite(led4, 255);
//  

//  digitalWrite(led1, HIGH); delay(1000);
//  digitalWrite(led1, LOW); delay(1000);


}
