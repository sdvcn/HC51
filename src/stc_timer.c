#include <stcmcu.h>
#include <ext_debug.h>
#include "../config.h"

#ifndef NCOMPILE_STC_TIMER

static volatile unsigned _SystemTick;

typedef void (*pCallBackISR)();


static pCallBackISR _t0isr[TIMER_STACK]={0x00};
void _Timer0_isr() _at_ STC_ISR_TIMER0
{
	#if SYSTEM_TIMER == 0
		++_SystemTick;
	#else
		for(unsigned char i=0;i<TIMER_STACK;i++)
		{
			if(_t0isr[i]) _t0isr[i]();
		}
	#endif
}

static pCallBackISR _t1isr[TIMER_STACK]={0x00};
void _Timer1_isr() _at_ STC_ISR_TIMER1
{
	#if SYSTEM_TIMER == 1
		++_SystemTick;
	#else
		for(unsigned char i=0;i<TIMER_STACK;i++)
		{
			if(_t1isr[i]) _t1isr[i]();
		}
	#endif
}


static pCallBackISR _t2isr[TIMER_STACK]={0x00};
void _Timer2_isr() _at_ STC_ISR_TIMER2
{
	#if SYSTEM_TIMER == 2
		++_SystemTick;
	#else
		for(unsigned char i=0;i<TIMER_STACK;i++)
		{
			if(_t2isr[i]) _t2isr[i]();
		}
	#endif
}

#if STCY > 5

static pCallBackISR _t3isr[TIMER_STACK]={0x00};
void _Timer3_isr() _at_ STC_ISR_TIMER3
{
	#if SYSTEM_TIMER == 3
		++_SystemTick;
	#else
		for(unsigned char i=0;i<TIMER_STACK;i++)
		{
			if(_t3isr[i]) _t3isr[i]();
		}
	#endif
}



static pCallBackISR _t4isr[TIMER_STACK]={0x00};
void _Timer4_isr() _at_ STC_ISR_TIMER4
{
	#if SYSTEM_TIMER == 4
		++_SystemTick;
	#else
		for(unsigned char i=0;i<TIMER_STACK;i++)
		{
			if(_t4isr[i]) _t4isr[i]();
		}
	#endif
}
#endif

unsigned GetSystemTick()
{
	return _SystemTick;
}

static unsigned long GetFrequency()
{
#if STCY == 6
    unsigned char cksel = ExtSfrGet8(&CKSEL);
    unsigned char clkdiv = ExtSfrGet8(&CLKDIV);
    unsigned long r;
    if((cksel & 0x03) == 0x00 ) r = CONFIG_FOSC;
    if((cksel & 0x03) == 0x01 ) return 0ul;
    if((cksel & 0x03) == 0x02 ) return 0ul;
    if((cksel & 0x03) == 0x03 ) r = 32000ul;
    if (clkdiv) r /= clkdiv;                            // 系统分频
    return r;
#else
	return CONFIG_FOSC;
#endif
}

#define DefT12	BIT(7)

#define TIMER_EN	(7)
#define TIMER_ENISR	(6)
#define TIMER_ENOUT	(5)
#define TIMER_ENIN	(4)
#define TIMER_CLEAR	(3)


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
	bit T12 = 0;

	if(!CheckBIT(flag,TIMER_ENIN)){
		if((GetFrequency()-us) > 0xffff){
			T12 = 1;
			//opflag |= DefT12;
			bu = 0xffff - ((GetFrequency()-us)/12);
		}else{
			T12 = 0;
			//opflag &= ~DefT12;
			bu = 0xffff - (GetFrequency()-us);
		}
	}

	switch (flag & 0x07)
	{
	case 0x00:{
		//T0x12 = ~T12;
		(T12)?AUXR&=~T0x12:AUXR|=T0x12;

		TL0 = (bu & 0xff);		//设置定时初值
		TH0 = (bu >> 8);		//设置定时初值
		ET0 = CheckBIT(flag,TIMER_ENISR);
		TR0 = CheckBIT(flag,TIMER_EN);
	}
	break;
	case 0x01:{
		//T1x12 = ~T12;
		(T12)?AUXR&=~T1x12:AUXR|=T1x12;

		TL1 = (bu & 0xff);		//设置定时初值
		TH1 = (bu >> 8);		//设置定时初值
		ET1 = CheckBIT(flag,TIMER_ENISR);
		TR1 = CheckBIT(flag,TIMER_EN);
	}
	break;
	case 0x02:{
		(T12)?AUXR&=~T2x12:AUXR|=T2x12;

		TL2 = (bu & 0xff);		//设置定时初值
		TH2 = (bu >> 8);		//设置定时初值
		#if STCY == 1
		assert(!T12);
		RCAP2L = (bu & 0xff);	//设置定时重载值
		RCAP2H = (bu >> 8);		//设置定时重载值
		ET2 = CheckBIT(flag,TIMER_ENISR);
		#else
		//IE2
		CheckBIT(flag,TIMER_ENISR)?IE2|=ET2:IE2 &= ~ET2;
		#endif
		TR2 = CheckBIT(flag,TIMER_EN);
	}
	break;
	#if STCY > 1
		case 0x03:{
			(T12)?AUXR&=~T3x12:AUXR|=T3x12;
			TL3 = (bu & 0xff);		//设置定时初值
			TH3 = (bu >> 8);		//设置定时初值
			//TR3 = CheckBIT(flag,TIMER_EN);
			CheckBIT(flag,TIMER_ENISR)?IE2|=ET3:IE2 &= ~ET3;
			CheckBIT(flag,TIMER_EN)?T4T3M|=T3R:T4T3M&=~T3R;
		}
		break;
		case 0x04:{
			(T12)?AUXR&=~T4x12:AUXR|=T4x12;
			TL4 = (bu & 0xff);		//设置定时初值
			TH4 = (bu >> 8);		//设置定时初值
			//TR4 = CheckBIT(flag,TIMER_EN);
			CheckBIT(flag,TIMER_ENISR)?IE2|=ET4:IE2 &= ~ET4;
			CheckBIT(flag,TIMER_EN)?T4T3M|=T4R:T4T3M&=~T4R;

		}
		break;
	#endif
	default:
		assert(0);
		break;
	}
}

unsigned DiffTick(unsigned t0)
{
    unsigned r = _SystemTick - t0;
    if(r & 0x8000) r = ~r;
    return r;
}

#endif //NCOMPILE_STC_TIMER