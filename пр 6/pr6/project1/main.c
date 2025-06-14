#include <8051.h>
void tput(unsigned char c1)
{
	SBUF=c1;
	while(!TI); 
	TI=0; 
}
void init_serial()
{
	PCON_BITS.B7 = 0; 
  	TMOD_BITS.B6 = 0; 
  	TMOD_BITS.B4 = 0; 
  	TMOD_BITS.B5 = 1;
  	TH1 = 0x0FA;  
  	TR1 = 1; 
	SCON = 0;
	SCON_BITS.B3 = 1;
  	SCON_BITS.B4 = 0;  
  	SCON_BITS.B5 = 0; 
  	SCON_BITS.B6 = 1; 
  	SCON_BITS.B7 = 0; 
}
void main()
{
	int i;
	char xdata *ptr;
	ptr = (char xdata *) 0x60;
    ptr[0] = 'C';
    ptr[1] = 'h';
    ptr[2] = 'e';
    ptr[3] = 'b';
    ptr[4] = 'y';
    ptr[5] = 'k';
    ptr[6] = 'i';
    ptr[7] = 'n';
    ptr[8] = 'T';
    ptr[9] = 'S';
	init_serial();
	while(1){
		for(i=0; i<10; i++)
		{
			tput(ptr[i]);
		}
	}
}
