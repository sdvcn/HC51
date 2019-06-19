#include <stcmcu.h>
//#include <ext_debug.h>
#include "../config.h"
#ifdef COMPILE_STC_TIMER
#include "stc_timer.h"

static unsigned short long _SystemTick = 0x00;
static unsigned long _SystemFrequency = 0x00;

#if SYSTEM_TIMER == 0
#define ISRADDR STC_ISR_TIMER0
#elif SYSTEM_TIMER == 1
#define ISRADDR STC_ISR_TIMER1
#elif SYSTEM_TIMER == 2
#define ISRADDR STC_ISR_TIMER2
#elif SYSTEM_TIMER == 3
#define ISRADDR STC_ISR_TIMER3
#elif SYSTEM_TIMER == 4
#define ISRADDR STC_ISR_TIMER4
#else
#error NO System_Timer_isr SYSTEM_TIMER
#endif
interrupt void _Timer0_isr(void) using 1 _at_ ISRADDR
{
	++_SystemTick;
}

unsigned short long GetSystemTick()
{
	return _SystemTick;
}

unsigned long * GetFrequency()
{
#if STCY == 6
	//static unsigned long r=0x00;
	//unsigned long r = 0;
	if(_SystemFrequency) return &_SystemFrequency;
	//if(_SystemFreq) return &_SystemFreq;
    unsigned char cksel = ExtSfrGet8(&CKSEL);
    unsigned char clkdiv = ExtSfrGet8(&CLKDIV);
    
    if((cksel & 0x03) == 0x00 ) _SystemFrequency = CONFIG_FOSC;
    if((cksel & 0x03) == 0x01 ) return 0ul;
    if((cksel & 0x03) == 0x02 ) return 0ul;
    if((cksel & 0x03) == 0x03 ) _SystemFrequency = 32000ul;
    if (clkdiv) _SystemFrequency /= clkdiv;                            // 系统分频
    return &_SystemFrequency;
#else
	return CONFIG_FOSC;
#endif
}

#define DefT12	BIT(7)

#define TL3	T3L
#define TH3	T3H
#define TH4	T4H
#define TL4	T4L

/**
 * 定时器初始化
 * 自动重载设置值
 * flag:2-0 指定定时器
 * flag:3	手动重载
 * flag:4	输入使能
 * flag:5	输出使能
 * flag:6	使能中断
 * flag:7	启动使能
 * us > 0	以us为量级的溢出值
  */
void InitTimer(unsigned char flag,unsigned us)
{
	unsigned char opflag = 0x00;
	unsigned bu = 0x00;

	bu = 65536 - us;

	DLOGINT(InitTimer,flag);
	DLOGINT(InitTimer,bu);

	switch (flag & 0x07)
	{
	case 0x00:{
		//T0x12 = ~T12;
		(flag & TIMER_T12)?AUXR&=~T0x12:AUXR|=T0x12;
		TMOD &= 0xF0;		//设置定时器模式	16位自动重载

		//TL0 = (bu & 0xff);		//设置定时初值
		//TH0 = (bu >> 8);		//设置定时初值
		
		TL0 = bu%256;		//设置定时初值
		TH0 = bu/256;		//设置定时初值

		TF0 = 0;		//清除TF0标志
		ET0 = (flag & TIMER_ENISR)?1ul:0ul;
		TR0 = (flag & TIMER_EN)?1ul:0ul;
	}
	break;
	case 0x01:{
		//T1x12 = ~T12;
		(flag & TIMER_T12)?AUXR&=~T1x12:AUXR|=T1x12;

		//TL1 = (bu & 0xff);		//设置定时初值
		//TH1 = (bu >> 8);		//设置定时初值
		TL1 = bu%256;		//设置定时初值
		TH1 = bu/256;		//设置定时初值

		TF1 = 0;		//清除TF0标志
		ET1 = (flag & TIMER_ENISR)?1ul:0ul;
		TR1 = (flag & TIMER_EN)?1ul:0ul;
	}
	break;
	case 0x02:{
		(flag & TIMER_T12)?AUXR&=~T2x12:AUXR|=T2x12;

		//TL2 = (bu & 0xff);		//设置定时初值
		//TH2 = (bu >> 8);		//设置定时初值
		TL2 = bu%256;		//设置定时初值
		TH2 = bu/256;		//设置定时初值

		#if STCY == 1
		assert(!T12);
		RCAP2L = (bu & 0xff);	//设置定时重载值
		RCAP2H = (bu >> 8);		//设置定时重载值
		ET2 = (flag & TIMER_ENISR)?1ul:0ul;
		#else
		//IE2
		(flag & TIMER_ENISR)?IE2|=ET2:IE2 &= ~ET2;
		#endif
		TR2 = (flag & TIMER_EN)?1ul:0ul;
	}
	break;
	#if STCY > 1
		case 0x03:{
			(flag & TIMER_T12)?AUXR&=~T3x12:AUXR|=T3x12;
			//TL3 = (bu & 0xff);		//设置定时初值
			//TH3 = (bu >> 8);		//设置定时初值
			TL3 = bu%256;		//设置定时初值
			TH3 = bu/256;		//设置定时初值
			//TR3 = CheckBIT(flag,TIMER_EN);
			(flag & TIMER_ENISR)?IE2|=ET3:IE2 &= ~ET3;
			(flag & TIMER_EN)?T4T3M|=T3R:T4T3M&=~T3R;
		}
		break;
		case 0x04:{
			(flag & TIMER_T12)?AUXR&=~T4x12:AUXR|=T4x12;
			//TL4 = (bu & 0xff);		//设置定时初值
			//TH4 = (bu >> 8);		//设置定时初值
			TL4 = bu%256;		//设置定时初值
			TH4 = bu/256;		//设置定时初值
			//TR4 = CheckBIT(flag,TIMER_EN);
			(flag & TIMER_ENISR)?IE2|=ET4:IE2 &= ~ET4;
			(flag & TIMER_EN)?T4T3M|=T4R:T4T3M&=~T4R;

		}
		break;
	#endif
	default:
		assert(0);
		break;
	}
}

unsigned short long DiffTick(unsigned short long t0)
{
    unsigned short long r = _SystemTick - t0;
    if(r & 0x800000) r = ~r;
    return r;
}


#endif //COMPILE_STC_TIMER