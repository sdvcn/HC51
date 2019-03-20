#include <8051.h>
#include <stcmcu.h>

void main()
{
	unsigned short v1;
	unsigned short v2;
	unsigned char c1;
	unsigned char c2;

	v1 = 0x1020;
	c1 = v1;
	c2 = v1 >> 8;
	v2 = 0x1020;

	while(1);
}
