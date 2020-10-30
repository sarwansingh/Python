const int button1 = 7, button2 = 8, button3 = 12, button4 = 13;  
const int led1 =  10, led2 =  6,led3 =  9,led4 =  11;
void setup() {
  pinMode(led1, OUTPUT);
}
int but1Press=0;
void loop() {
  // check whether button1 is pressed 
  //if yes make but1Press variable togle 
  if(digitalRead(button1)== HIGH){
    if (but1Press==1) {
      but1Press=0;
    }else {
      but1Press=1;
    }
    while (digitalRead(button1)== HIGH ) {}
  }
  // do the required task if but1Press variable is high do the task 
  //else dont do anything
  if (but1Press==1) {
    digitalWrite(led1 , HIGH); 
  }else {
    digitalWrite(led1 , LOW); 
  }
}
