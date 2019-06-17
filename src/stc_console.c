#include <stcmcu.h>
#include "../config.h"
#ifdef  COMPILE_STC_CONSOLE

static unsigned char _RxBuffer[CONSOLE_RXBUFFER_SIZE]={0x00};
static unsigned char _TxBuffer[CONSOLE_TXBUFFER_SIZE]={0x00};
static volatile unsigned char _RxSeek = 0x00;
static volatile unsigned char _TxSeek = 0x00;
static volatile unsigned char _RxCursor = 0x00;
static volatile unsigned char _TxCursor = 0x00;
static volatile unsigned char _Status = 0xff;
#define RxStatBit	(0)
#define TxStatBit	(1)
#define RxIsEmpty()	(CheckBIT(_Status,RxStatBit))
#define TxIsEmpty()	(CheckBIT(_Status,TxStatBit))

#if CONSOLE_USE_UART == 1
#define CONSOLE_ISRADDR     STC_ISR_UART1
#define CONSOLE_ES_EN() (ES = 1)
#define CONSOLE_ES_DI() (ES = 0)

#define CONSOLE_TI_EN() (TI = 1)
#define CONSOLE_RI_EN() (RI = 1)

#define CONSOLE_TI()    (TI)
#define CONSOLE_RI()    (RI)
#elif CONSOLE_USE_UART == 2
#define CONSOLE_ISRADDR     STC_ISR_UART2
#define CONSOLE_ES_EN() (IE2 |= ES2)
#define CONSOLE_ES_DI() (IE2 &= ~ES2)

#define CONSOLE_TI_EN() (S2CON |= S2TI)
#define CONSOLE_RI_EN() (S2CON |= S2RI)

#define CONSOLE_TI()    (S2CON & S2TI)
#define CONSOLE_RI()    (S2CON & S2RI)
#elif CONSOLE_USE_UART == 3
#define CONSOLE_ISRADDR     STC_ISR_UART3
#define CONSOLE_ES_EN() (IE2 |= ES3)
#define CONSOLE_ES_DI() (IE2 &= ~ES3)

#define CONSOLE_TI_EN() (S3CON |= S3TI)
#define CONSOLE_RI_EN() (S3CON |= S3RI)

#define CONSOLE_TI()    (S3CON & S3TI)
#define CONSOLE_RI()    (S3CON & S3RI)

#elif CONSOLE_USE_UART == 4
#define CONSOLE_ISRADDR     STC_ISR_UART4
#define CONSOLE_ES_EN() (IE2 |= ES4)
#define CONSOLE_ES_DI() (IE2 &= ~ES4)

#define CONSOLE_TI_EN() (S4CON |= S4TI)
#define CONSOLE_TI_DI() (S4CON &= ~S4TI)
#define CONSOLE_RI_EN() (S4CON |= S4RI)
#define CONSOLE_RI_DI() (S4CON &= ~S4RI)
#define CONSOLE_TI()    (S4CON & S4TI)
#define CONSOLE_RI()    (S4CON & S4RI)

#else
#error NO CONSOLE_USE_UART
#endif

static void InitConsole()
{
    unsigned long bu = CalcBaud(CONSOLE_BAUD_RATE);
    CheckT12(bu)?InitTimer(TIMER_EN|TIMER_T12|CONSOLE_TIMER,(unsigned)(bu/12)):InitTimer(TIMER_EN|CONSOLE_TIMER,(unsigned)bu);
}

interrupt void Console_isr(void) using 1 _at_ CONSOLE_ISRADDR
{

} 

void Console_Tx(unsigned char c)
{
	while(((_TxSeek + 1)>_TxCursor)&&!(_TxSeek == _TxCursor)){NOP();};
	//while(TxSeek != TxCursor){};
	_TxBuffer[_TxSeek++] = c;
	CONSOLE_ES_DI();

	if(TxIsEmpty()){
		ClearBIT(_Status,TxStatBit);
        CONSOLE_TI_EN();
	}

	CONSOLE_ES_EN();
}

unsigned char Console_Rx()
{
	unsigned char ret = 0x00;
	
	while(!(_RxCursor == _RxSeek)){};
	ret = _RxBuffer[_RxCursor++];
	return ret;
	
}


/**
 * 接管句柄
*/
char _Consolehandler(unsigned char c, unsigned char func)
{
	//P1 = 0x0f;
	//if(!CONSOLE_EN) Uart2Init();
    InitConsole();
	
	switch (func){
		
		case 0:{
			
			return 0x00;
		}
		case 1:{
			Console_Tx(c);
			return 0;
		}
		case 2:{
			c = (Console_Rx() & 0x7F);
			//if(c == '\r') return '\n';
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

#endif // COMPILE_STC_CONSOLE