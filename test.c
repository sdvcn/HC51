#include <8051.h>
#include <stcmcu.h>

#define	FOSC	24000000UL
#define	BRT	(65536 - FOSC / 115200 / 4)

void uSEND(unsigned char s)
{
	SBUF = s;
	while(!TI);
	TI = 0;
}

void uSENDs(const char* str,unsigned len)
{
	while(len--){
		uSEND(*str++);
	}
}

void UartInit()
{
	SCON = 0x50;
	TMOD = 0x00;
	TL1 = BRT;
	TH1 = BRT >> 8;
	TR1 = 1;
	AUXR = 0x40;
	//busy = 0;
}

void main()
{
	UartInit();
	//uSENDs("ID:",3);
	//en_EAXFR();
	//uSEND(PWM0T1H);
	//uSEND(ExtSfrGet(&PWM0T1L));

	while(1);
}
