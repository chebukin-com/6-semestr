#include <8051.h>
void main() {
	int i;
	char xdata *ptr;
	char test, nabor;
	nabor = 0xAA;
	P1 = 0x0;
	ptr = (char xdata *) 0x400;
	for (i=0; i<1024; i++) {
		*ptr = nabor;
		test = *ptr;
		if (test != nabor) {
			P1 = 0x1;
			break;
		}
		ptr++;
	}
}