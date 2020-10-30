#include <reg51.h>
void my_delay()
{	int i,j; 
	// increment value of i in a loop
	
	for (j=0; j<30000 ; j++) 
	{   }

}
void main()
{
	while(1){
		P1= 0x55; //0101 0101->	   0x55
		my_delay(); // call function
		P1= 0xaa;  //1010 1010->    0xaa
		my_delay(); 
	}
}

/* multi line comment
  	P1= 0x00; //0000 0000->	   0x00
	P1= 0xff;  //1111 1111->    0xff
*/