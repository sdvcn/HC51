#ifndef __CONFIG_H__
#define __CONFIG_H__

/**
 * APA102器件扩展库支持
 */
//#define COMPILE_EXT_APA102
#define APA102IOCI    P32
#define APA102IODI    P33

/**
 * W281x 器件扩展库
 */
//#define COMPILE_EXT_W281X

/**
 * APDS9960 扩展库
 */
//#define COMPILE_EXT_APDS9960
/**
 * STC器件
 */
#define ADCCH	8

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


/**
 * Console 
 */

#define CONSOLE_USE_UART    4                       // Consol 使用端口
#define CONSOLE_BAUD_RATE   115200                  // 通讯波特率
#define CONSOLE_TIMER       4
#define CONSOLE_RXBUFFER_SIZE   0xff
#define CONSOLE_TXBUFFER_SIZE   0xff


#ifndef HI_TECH_C

#define STCY    6
#define COMPILE_STC_IIC
#define COMPILE_STC_ADC

#define COMPILE_STC_EXT_DEBUG
#ifdef  COMPILE_STC_EXT_DEBUG
    #include <ext_debug.h>
#endif

#define COMPILE_STC_EPROM

#define COMPILE_STC_PWM
#ifdef  COMPILE_STC_PWM
    
#endif

#define COMPILE_STC8_GPIO
#ifdef  COMPILE_STC8_GPIO
    #include <stc8_gpio.h>
#endif

#define COMPILE_STC_GPIO
#ifdef  COMPILE_STC_GPIO
    #include <stc_gpio.h>
#endif

#define COMPILE_STC_TIMER
#ifdef  COMPILE_STC_TIMER
    #include <stc_timer.h>
#endif

#define COMPILE_STC_CONSOLE
#ifdef  COMPILE_STC_CONSOLE
    #include <stc_console.h>
#endif
#define COMPILE_STC_ISR
#ifdef  COMPILE_STC_ISR

#endif

#endif

#endif