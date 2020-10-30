 #include<reg51.h>
sbit but1 = P2^0;
int but1press = 0;
void my_delay()
{	int i,j;
 
	for (j=0;j<3 ;j++){
		for (i=0 ; i<30000 ;i++){
		//no operation 
		}
	}
}	
void main()
{	P1=0x00;
  	while(1){
	 if (but1==0){
	 	// if button is pressed toogle the value in	but1press variable
	 	 if (	but1press == 0)	but1press=1;
		 else 	but1press = 0 ; 
		 while  (but1==0); //wait here
	  }
	  if(	but1press==1 ) { // if 	but1press value is 1 then display pattern1
	   	P1=0xf0; my_delay();
		P1=0x0f; my_delay();
	  }else { P1=0x00; } 
	}
}
/*
   if (but2==0){
	  // if button on P2.1 pin is pressed display pattern2
		P1=0x00; my_delay();
		P1=0xff; my_delay();
	  }
	  if (but3==0){
	  // pattern3
		P1=0xaa; my_delay();
		P1=0x55; my_delay();
	  }
	  else { P1=0x00; } // make all LEDs off 
	 
*/