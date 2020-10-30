#include<reg51.h>
sbit buzz = P0^4;
void my_delay(int t) //parameter passing in function
{	int i,j;
 
	for (j=0;j<t ;j++){
		for (i=0 ; i<30000 ;i++){
		}
	}
}	
void main()
{
  	while(1){
	buzz=0;  my_delay(10); //call my_delay method with argument 4
	buzz=1;  my_delay(2);
	} 
}