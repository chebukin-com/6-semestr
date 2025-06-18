#include <8051.h> 

void main() 
{
	unsigned char i,j,t,k;
	unsigned char massiv[12]= 
	{ 
 	0xFF,
 	0x90,
	0xF8,
	0x92,
	0xB0,  
	0xF9, 
 	0xFF 
	}; 
P1=massiv[10];
P3=0;
i=0;
while(1)
{
while(P30==1)
{
P2=massiv[i];
i++;
if(i>9)
{
i=0;
}
}
}
}