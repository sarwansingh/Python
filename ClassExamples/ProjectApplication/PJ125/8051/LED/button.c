#include <reg51.h>
sbit button1 = P2^0;

void mydelay(int t){
   int x=0,y=0;
   for (x=0 ; x<t; x++)
   {  for (y=0 ; y<20000; y++)
   		{ }		
   }
}
void main(){
	  while(1){
	   if (button1 ==0) {
		   	P1 = 0xaa;	 //1010 1010
			mydelay(10);
			P1= 0x55;	 //0101 0101
			mydelay(10);
		} else {
		 	P1 = 0x00;
		}
	  }
}