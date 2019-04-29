//#include <8051.h>
#include <stcmcu.h>

#include "src/ext/apds9660.h"


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
	/// 初始化串口
	ExtSfrSet(&P3PU,BIT(0)|BIT(1));
	UartInit();
	
	/// 设置端口寄存器 高阻态
	P1M0 = 0x00;
	P1M1 = (BIT(4)|BIT(5));
	/// 开启 P14 P15 内置上拉电阻
	ExtSfrSet(&P1PU,0xff);

	P_SW2 |= 0x80;
	///设置IO端口

	uSENDs("Init:",5);
	unsigned char sv1;
		
	do{
		sv1 = APDS9960_ReadReg8(APDS9960_ID);
		if(P10 == 0)uSEND(sv1);
	}
	while(1);
}
