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

// 设置mask
#define IMask(_v)  (_v & 0x3f)

char _Consolehandler(unsigned char c, unsigned char func)
{
	switch (func){
		
		case 0:{
			//Uart2Init();
			return 0x00;
		}
		case 1:{
			if(c== '\n') CONSOLE_TX('\r');
			CONSOLE_TX(c);
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