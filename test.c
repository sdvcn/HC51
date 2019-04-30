//#include <8051.h>
#include <stcmcu.h>

#include "src/ext/apds9660.h"


#define	FOSC	24000000UL
#define	BRT	(65536 - FOSC / 115200 / 4)


void uSEND(unsigned char s)
{
	S2BUF = s;
	while(!(S2CON & BIT(1)));
	ClearBIT(S2CON,1);
	//while(!S2TI);
	//S2TI = 0;
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

void UartInit2(void)		//115200bps@23.996MHz
{
	S2CON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = 0xCC;		//设定定时初值
	T2H = 0xFF;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
	//IE2 = 0x01;
}

void main()
{
	/// 初始化串口
	//ExtSfrSet(&P3PU,BIT(0)|BIT(1));
	UartInit2();
	//EA = 1;
	
	/// 设置端口寄存器 高阻态
	//P1M0 = 0x00;
	//P1M1 = (BIT(4)|BIT(5));
	/// 开启 P14 P15 内置上拉电阻
	//ExtSfrSet(&P1PU,0xff);

	P_SW2 = 0x80;
	//P1PU = 0xff;
	
	///设置IO端口

	uSENDs("Init:",5);
	unsigned char sv1;
	APDS9960_GestureSensor();
		
	do{
		//uSENDs("Init:",5);
		
		if(P77 == 0){
			//I2c_InitM(0x3f);
			
			//uSENDs("Init:",5);
			//sv1 = APDS9960_ReadReg8(APDS9960_ID);
			//uSEND(sv1);
			//sv1 = APDS9960_ReadReg8(APDS9960_GFLVL);
			//uSEND(sv1);
			APDS9960_ReadGesture();
		};
	}while(1);
}
