/**
 * HTC 编译器支持 支持到串口2输出信息
 * 串口操作需要手工初始化,初始化时确认波特率等参数
 * 默认使用串口2进行工作
 * 编译时宏定制
*/
#include <stcmcu.h>

//#define FOSC        11059200L
//#define FOSC        STCCLKR
//#define BAUD        (256 - FOSC / 32 / 115200)

/**
 * 基本设置
*/

#ifndef CONSOLE_RX()
#define CONSOLE_RX()    S2Pop()
#endif

#ifndef CONSOLE_TX(_v)
#define CONSOLE_TX(_v)    S2Put(_v)
#endif

#ifndef CONSOLE_EN 
#define CONSOLE_EN()    (S2CON & S2REN)
#endif

#ifndef CONSOLE_RI()
#define CONSOLE_RI()    (S2CON & S2RI)
#endif

#ifndef CONSOLE_CON
#define CONSOLE_CON    S2CON
#endif

#ifndef CONSOLE_BUF
#define CONSOLE_BUF    S2BUF
#endif

///波特率计算 
/// todo:未完成
unsigned char SetRate(unsigned short v)
{
    return (256 - STCCLKR / 32 / v);
}

/**
 * 串口1
*/


/**
 * 串口2
*/
void S2Put(unsigned char s)
{
	S2BUF = s;
	while(!(S2CON & BIT(1)));
	ClearBIT(S2CON,1);
}

unsigned char S2Pop()
{
    while(!(S2CON & BIT(0)));
    ClearBIT(S2CON,0);
    return S2BUF;
}

///模拟方式实现串口

/**
 * Console I/O
 * 开辟内存实现写缓冲
*/
#ifndef CONSOLE_BUFFER
#define CONSOLE_BUFFER	64
#endif
/**
 * STC8
 * UART1 0x23
 * UART2 0x43
 * UART3 0x8b
 * UART4 0x93
*/
#ifndef CONSOLE_UARTIR
#define CONSOLE_UARTIR 0x43
#endif
//63
//#define IMask(_v)  (_v & 0x3f)
xdata unsigned char TxBuf[CONSOLE_BUFFER];
xdata unsigned char RxBuf[CONSOLE_BUFFER];
/// 写指针
xdata volatile unsigned char WSeek = 0x00;
/// 写缓冲指针
xdata volatile unsigned char WbSeek = 0x00;
/// 读指针
xdata volatile unsigned char RSeek = 0x00;
/// 读缓冲指针
xdata volatile unsigned char RbSeek = 0x00;
/**
 * 需要开启全局中断使能
*/
//void UART2_Isr() interrupt 8
//void serial_intr(void) interrupt CONSOLE_UARTIR
unsigned char IMask(unsigned char v)
{
	v&=0x3f;
	return v;
}
interrupt void Console_intr(void) _at_ CONSOLE_UARTIR
{
	//RI
	if(CONSOLE_CON & 0x01){
		CONSOLE_CON &= 0x01;
		if(IMask(RbSeek) != IMask(RSeek)){
			RxBuf[IMask(RbSeek++)] = CONSOLE_BUF;
		}else{
			///原路退回
			//TxBuf = RxBuf;
		}
				
	}
	//TI
	if(CONSOLE_CON & 0x02){
		CONSOLE_CON &= 0x02;
		if(IMask(WbSeek) != IMask(WSeek))
		{
			CONSOLE_BUF = TxBuf[IMask(WbSeek++)];
		}
		
	}
}
void Console_Tx(unsigned char c)
{
	TxBuf[IMask(WSeek++)]=c;
}

unsigned Console_Rx()
{
	//while(IMask(RSeek)!=IMask(RbSeek));
	return RxBuf[IMask(RSeek++)];

}



char _Consolehandler(unsigned char c, unsigned char func)
{
	//P1 = 0x0f;
	//if(!CONSOLE_EN) Uart2Init();
	
	switch (func){
		
		case 0:{
			//Uart2Init();
			return 0x00;
		}
		case 1:{
			//if(c== '\n') CONSOLE_TX('\r');
			//CONSOLE_TX(c);
			if(c== '\n') Console_Tx('\r');
			Console_Tx(c);
			return 0;
		}
		case 2:{
			c = (CONSOLE_RX() & 0x7F);
			if(c == '\r') return '\n';
			return c;
		} 
		case 3:{
			return (CONSOLE_RI())?1:0;
		}
		
		default:{
			return 0xff;
		}
	}
	
}

near unsigned char _conio_(unsigned char c, unsigned char f) @ 0x10
{
	asm("global	__Consolehandler");
	asm("ljmp	__Consolehandler");
}