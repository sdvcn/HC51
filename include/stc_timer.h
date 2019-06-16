#ifndef __STC_TIMER_H__
#define __STC_TIMER_H__

#ifndef NCOMPILE_STC_TIMER
/**
 * 输出当前时间戳
 * 时间戳无单独存在意义
 */
extern unsigned GetSystemTick();

/**
 * 时间戳比较
 * 输出当前时间与输入时间差值
 */
extern unsigned DiffTick(unsigned t0);
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
extern void InitTimer(unsigned char flag,unsigned us);
/**
 * 初始化系统Tick
 */
#define InitSystemTick(_u)	InitTimer(TIMER_EN|(SYSTEM_TIMER&0x07),_u)

#endif  // NCOMPILE_STC_TIMER
#endif