#include <reg51.h>
#define LCDDATA P2
sbit RS	=	P3^6;
sbit E	=	P3^7;

void mydelay(int t){
   int x=0,y=0;
   for (x=0 ; x<t; x++)
   {  for (y=0 ; y<20000; y++){ 		}		
   }
}

void lcd_cmd(char d)
{
	RS=0; // command is being sent on LCDDATA
	E=1;	LCDDATA= d;	mydelay(1); E=0;
}
void lcd_data(char d)
{
	RS=1; // data/information is being sent on LCDDATA
	E=1;	LCDDATA= d; mydelay(1); E=0;
}

void main(){
int i;
	  while(1){
		lcd_cmd(0x38);	//initalize lcd 16x2
		//lcd_cmd(0x0E);	// display cursor on
		lcd_cmd(0x01);	 // clear lcd    
		lcd_data('I');
		lcd_data('N');
		lcd_data('D');
		lcd_data('I');
		lcd_data('A');

		for(i=0;i<4;i++){	lcd_data('!');}
	   	
		mydelay(100);
	  }
}