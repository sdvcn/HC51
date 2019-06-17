#ifndef __STC_TIMER_H__
#define __STC_TIMER_H__

#ifdef COMPILE_STC_TIMER
typedef void (*pCallBackISR)();

/**
 * 输出当前时间戳
 * 时间戳无单独存在意义
 */
extern unsigned GetSystemTick();

extern unsigned long GetFrequency();

/**
 * 清除指定寄存器的CallBack
 */
extern void Timer_ClearCallBack(unsigned char sel);
/**
 * 压入指定寄存器的CallBack
 */
extern void Timer_PushCallBack(unsigned char sel,pCallBackISR cb);

/**
 * 时间戳比较
 * 输出当前时间与输入时间差值
 */
extern unsigned DiffTick(unsigned t0);


#define TIMER_EN	(7)
#define TIMER_ENISR	(6)
#define TIMER_ENOUT	(5)
#define TIMER_T12 	(4)
#define TIMER_CLEAR	(3)

#define CalcFreq(_us)    (1000000/(_us))
#define CalcTimer(_v)   (GetFrequency()/CalcFreq(_v))
#define CalcBaud(_v)    (GetFrequency()/(_v)/4)
#define CheckT12(_v)     (((_v)>0xffff)?1ul:0ul)

/**
 * 定时器初始化
 * 自动重载设置值
 * flag:2-0 指定定时器
 * flag:3	手动重载
 * flag:4	T12
 * flag:5	输出使能
 * flag:6	使能中断
 * flag:7	启动使能
 * us > 0	以us为量级的溢出值
  */
extern void InitTimer(unsigned char flag,unsigned us);
/**
 * 初始化系统Tick
 */
#define InitSystemTick(_u) ((CheckT12(_u))?InitTimer(TIMER_EN|(SYSTEM_TIMER&0x07),(unsigned)(_u/12)):InitTimer(TIMER_EN|TIMER_T12|(SYSTEM_TIMER&0x07),(unsigned)(_u)))




#endif  // COMPILE_STC_TIMER
#endif