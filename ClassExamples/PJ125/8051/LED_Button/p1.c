 #include<reg51.h>
sbit but1 = P2^0;
void my_delay()
{	int i,j;
 
	for (j=0;j<3 ;j++){
		for (i=0 ; i<30000 ;i++){
		}
	}
}	
void main()
{
  	while(1){
	 // if(P2 == 0xfe ){ //1111 1110  // not the correct way
	 if (but1==0){
	  // if button on P2.0 pin is pressed display pattern
		P1=0xf0; my_delay();
		P1=0x0f; my_delay();
	  }
	  else { P1=0x00; } // make all LEDs off 
	}
}