#include <8051.h>
void main() {
	unsigned int i,j,k,jj;
	unsigned int pos = 0;
	unsigned char str1[] = {0xB8, 0xA5, 0xA1, 0xBC, 0xAB, 0xA9, 0xAE, 0x00};
	unsigned char str2[] = {0xB3, 0xA9, 0xAD, 0xAF, 0xB5, 0xA4, 0xAA, 0x00};
	unsigned char len1 = 0, len2 = 0;
	while (str1[len1] != '\0') len1++;
	while (str2[len2] != '\0') len2++;
	P0 = 0xC;
	P2 = 0x1;
	P2 = 0x0;
	P0 = 0x38;
	P2 = 0x1;
	P2 = 0x0;
	pos = 0x80 + 10-len1/2;
	P0 = pos;
	P2 = 0x1;
	P2 = 0x0;
	for (i = 0; i<len1; i++) {
		P0 = str1[i];
		P2 = 0x3;
		P2 = 0x2;
	}
	while(1) {
		j = 0;
		while (j + len2 < 21) {
			P0 = 0xC0;
			P2 = 0x1;
			P2 = 0x0;
			for (jj = 0; jj<j; jj++) {
				P0 = " ";
				P2 = 0x3;
				P2 = 0x2;
			}
			for (i = 0; i < len2; i++) {
				if (i == 5) {
					P0 = str1[1];
					P2 = 0x3;
					P2 = 0x2;
				}
				else {
					P0 = str2[i];
					P2 = 0x3;
					P2 = 0x2;
				}
			}
			j += 2;
		}
		while (j <= 20) {
			P0 = 0xC0;
			P2 = 0x1;
			P2 = 0x0;
			for (jj = 0; jj<j; jj++) {
				P0 = " ";
				P2 = 0x3;
				P2 = 0x2;
			}
			for (i = 0; i < 20 - j; i++) {
				if (i == 5) {
					P0 = str1[1];
					P2 = 0x3;
					P2 = 0x2;
				}
				else {
					P0 = str2[i];
					P2 = 0x3;
					P2 = 0x2;
				}
			}
			j += 2;
		}
	}
}
