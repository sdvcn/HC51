#include <8051.h>
#include <stcmcu.h>

void main()
{
	union{
		unsigned short s;
		unsigned char c[2];
	} un;
	un.s = 0x0102;
	if(un.c[0] == 1 && un.c[1] == 2){
		P0 = 0x0f;
	}else{
		P0 = 0xf0;
	}
	

	while(1);
}
