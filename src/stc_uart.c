/**
 * HTC 编译器支持 支持到串口2输出信息
 * 串口操作需要手工初始化,初始化时确认波特率等参数
 * 默认使用串口2进行工作
 * 编译时宏定制
*/
#include <stcmcu.h>
//#include "../config.h"

#ifdef COMPILE_STC_UART
#include "stc_uart.h"

/**
 * 串口初始化
 * flag:0	RI
 * flag:1	TI
 * flag:2	RB8
 * flag:3	TB8
 * flag:4	Ren
 * flag:5	SM2
 * flag:6	ST4
 * flag:7	SM0
 * 
 * mask:0-1	Port
 * 只初始化对应定时器
 * 
 */
void InitUart(unsigned char mask,unsigned char flag,unsigned baud)
{
	switch (mask & 0x03)
	{
	case 0x01:{
		
	}break;
	
	default:
		break;
	}
}
#endif //COMPILE_STC_UART

#ifdef AAA

//#define FOSC        11059200L
//#define FOSC        STCCLKR
//#define BAUD        (256 - FOSC / 32 / 115200)

/**
 * 基本设置
*/
/*
#ifndef CONSOLE_RX()
#define CONSOLE_RX()    S2Pop()
#endif

#ifndef CONSOLE_TX(_v)
#define CONSOLE_TX(_v)    S2Put(_v)
#endif
*/
//#ifndef CONSOLE_EN 
#define CONSOLE_EN()    (S2CON & S2REN)
//#endif

//#ifndef CONSOLE_RI()
#define CONSOLE_RI()    (S2CON & S2RI)
//#endif

//#ifndef CONSOLE_CON
#define CONSOLE_CON    S2CON
//#endif

//#ifndef CONSOLE_BUF
#define CONSOLE_BUF    S2BUF
//#endif

#define CONSOLE_ES_EN() (IE2 |= 0x01)
#define CONSOLE_ES_DI() (IE2 &= ~0x01)

///波特率计算 
/// todo:未完成

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
#define CONSOLE_BUFFER	0xFF
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

// 设置mask
//#define IMask(_v)  (_v & 0x3f)
//#define SizeMask 0x3f
//#define IMask(_v) ((##_v) = (_v++) & SizeMask)

//发送缓冲
static unsigned char TxBuf[CONSOLE_BUFFER+1];

//接收缓冲
static unsigned char RxBuf[CONSOLE_BUFFER+1];

// 读位置
unsigned char RxSeek = 0x00;

// 读标记
unsigned char RxCursor = 0x00;

// 写位置
unsigned char TxSeek = 0x00;

// 写标记
unsigned char TxCursor = 0x00;

//xdata static volatile bit _RxIsEmpty = 1ul;
//xdata static volatile bit _TxIsEmpty = 0b0001;

volatile unsigned char _Status = 0xff;
#define RxStatBit	(0)
#define TxStatBit	(1)
#define RxIsEmpty()	(CheckBIT(_Status,RxStatBit))
#define TxIsEmpty()	(CheckBIT(_Status,TxStatBit))

/**
 * 默认值初始化
*/
 void _Init()
{
	RxSeek = 0x00;
	TxSeek = 0x00;
	RxCursor = 0x00;
	TxCursor = 0x00;
	_Status = 0xff;
}

/**
 * 需要开启全局中断使能
*/
//void UART2_Isr() interrupt 8
//void serial_intr(void) interrupt CONSOLE_UARTIR

/// 自动中断
interrupt void Console_intr(void) using 1 _at_ CONSOLE_UARTIR 
{
	CONSOLE_ES_DI();
	NOP();
	//RI
	if(CONSOLE_CON & 0x01){
		CONSOLE_CON &= ~0x01;
		RxBuf[RxSeek++] = CONSOLE_BUF;
		//_RxIsEmpty = 0;
		ClearBIT(_Status,RxStatBit);
	}
	//TI
	if(CONSOLE_CON & 0x02){
		CONSOLE_CON &= ~0x02;
		if(TxCursor == TxSeek){
			//_TxIsEmpty = 1;	
			SetBIT(_Status,TxStatBit);
		}else{
			CONSOLE_BUF = TxBuf[TxCursor++];
		}
	}
	CONSOLE_ES_EN();
}

/**
 * 发送
 * 超出缓冲部分阻塞等待
*/
void Console_Tx(unsigned char c)
{
	P1 = 0xf0;
	while(((TxSeek + 1)>TxCursor)&&!(TxSeek == TxCursor)){NOP();};
	//while(TxSeek != TxCursor){};
	TxBuf[TxSeek++] = c;
	CONSOLE_ES_DI();

	if(TxIsEmpty()){
		//_TxIsEmpty = 0;
		ClearBIT(_Status,TxStatBit);
		CONSOLE_CON |= 0x02;
	}

	CONSOLE_ES_EN();
}
/**
 * 接收,无数据阻塞操作
 * todo:未作溢出检查
 * todo:未完成
*/
unsigned char Console_Rx()
{
	unsigned char ret = 0x00;
	
	while(!(RxCursor == RxSeek)){};
	ret = RxBuf[RxCursor++];
	return ret;
	
}


/**
 * 接管句柄
*/
char _Consolehandler(unsigned char c, unsigned char func)
{
	//P1 = 0x0f;
	//if(!CONSOLE_EN) Uart2Init();
	
	switch (func){
		
		case 0:{
			//Uart2Init();
			_Init();
			return 0x00;
		}
		case 1:{
			//if(c== '\n') CONSOLE_TX('\r');
			//CONSOLE_TX(c);
			//if(c== '\n') Console_Tx('\r');
			Console_Tx(c);
			return 0;
		}
		case 2:{
			c = (Console_Rx() & 0x7F);
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

#endif