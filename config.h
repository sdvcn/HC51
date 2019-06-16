#ifndef __CONFIG_H__
#define __CONFIG_H__

/**
 * APA102器件扩展库支持
 */
#define NCOMPILE_EXT_APA102
#define APA102IOCI    P32
#define APA102IODI    P33

/**
 * W281x 器件扩展库
 */
#define NCOMPILE_EXT_W281X

/**
 * APDS9960 扩展库
 */
#define NCOMPILE_EXT_APDS9960
/**
 * STC器件
 */
#define ADCCH	8
#define NCOMPILE_STC_ADC

#define NCOMPILE_STC_IIC

#define NCOMPILE_STC_EXT_DEBUG

#define NCOMPILE_STC_EPROM

#define NCOMPILE_STC_PWM


#define NCOMPILE_STC8_GPIO

//#define NCOMPILE_STC_TIMER

/**
 * 定时器栈数量
 * 栈内函数顺序执行
 */
#define TIMER_STACK 3
/**
 * 系统Tick应使用最高优先级的timer0
 * 定义为系统Tick的isr不执行callback;
 */
#define SYSTEM_TIMER    0               // 使用定时器
/**
 * 系统时钟定义
 * STC8 系列默认24M
 */
#define CONFIG_FOSC    24000000ul


//#define NCOMPILE_STC_RTC
//
#undef STCY
#define STCY    6


#endif