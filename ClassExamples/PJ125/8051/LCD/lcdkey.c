#include <reg51.h>
#define LCDDATA P2
sbit RS	=	P3^6;
sbit E	=	P3^7;

sbit C1=P1^0;
sbit C2=P1^1;
sbit C3=P1^2;
sbit C4=P1^3;
sbit R1=P1^4;
sbit R2=P1^5;
sbit R3=P1^6;
sbit R4=P1^7;

void mydelay(int t){
   int x=0,y=0;
   for (x=0 ; x<t; x++)
   {  for (y=0 ; y<20000; y++){ 		}		
   }
}
void lcd_cmd(char d)
{
	RS=0;
	E=1;	LCDDATA= d;	mydelay(1); E=0;
}

void lcd_data(char d)
{
	RS=1;
	E=1;	LCDDATA= d; mydelay(1); E=0;
}

void main(){
		lcd_cmd(0x38);
		lcd_cmd(0x0E);
		lcd_cmd(0x01);	    
		lcd_data('N');
		lcd_data('I');
		lcd_data('E');
		lcd_data('L');
		lcd_data('I');
		lcd_data('T');
		lcd_cmd(0xC0);	 // bring cursor to second line   
	  while(1){
///////////
		C1 = C2= C3=C4= R1= R2=R3=R4 =1;   
         C1= 0 ; 
		 if (R1 == 0 ) 	 { lcd_data('1');  }
		 if (R2 == 0 ) 	 { lcd_data('2'); }
		 if (R3 == 0 ) 	 { lcd_data('3'); }
		 if (R4 == 0 ) 	 { lcd_data('4'); }

         C1= 1 ; C2= 0 ;  
		 if (R1 == 0 ) 	 { lcd_data('5'); }
		 if (R2 == 0 ) 	 { lcd_data('6'); }
		 if (R3 == 0 ) 	 { lcd_data('7'); }
		 if (R4 == 0 ) 	 { lcd_data('8'); }

         C2= 1 ; C3= 0 ;  
		 if (R1 == 0 ) 	 { lcd_data('9'); }
		 if (R2 == 0 )   { lcd_data('A'); }
		 if (R3 == 0 ) 	 { lcd_data('B'); }
		 if (R4 == 0 ) 	 { lcd_data('C'); }
		 C3= 1 ; C4= 0 ;  
		 if (R1 == 0 ) 	 { lcd_data('D'); }
		 if (R2 == 0 )   { lcd_data('E'); }
		 if (R3 == 0 ) 	 { lcd_data('F'); 	}
		 if (R4 == 0 ) 	 { lcd_cmd(0x01); }
////////////
	   	mydelay(1);
	  }
}