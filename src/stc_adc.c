/*
    实现ADC功能部分
    支持型号
    Stc12x56xxAD系列
    STC8A8KxxSA12系列
    
*/

#include <stcmcu.h>
#include "../config.h"

#ifdef COMPILE_STC_ADC


#define ADC_POWER       (0x80)
#define ADC_SPEED9      (0x60)
#define ADC_SPEED54     (0x40)
#define ADC_SPEED810    (0x20)
#define ADC_SPEED108    (0x00)
#define ADC_START       (0x08)
#define ADC_FLAG        (0x10)

unsigned short GetResult(unsigned char ch)
{
    asm("push ie");
    di();                                                       //关闭全局中断
    ch &= ~0xf8;
    ADC_CONTR = ADC_POWER|ADC_SPEED9 | ADC_START | ch;
    NOP();
    NOP();
    NOP();
    NOP();
    while (!(ADC_CONTR & ADC_FLAG));
    asm("pop ie");                                              // 恢复中断
    ADC_CONTR &= ~ADC_FLAG;
    //return (ADC_DATA << 2) | ADC_LOW2;
    return Adc_Result;                                          // 宏定义返回值
}

void Adc_Init(unsigned char mask)
{
	static unsigned char ADCMask;
    unsigned char ch;
    //卸载之前状态
    ADC_CONTR = 0x00;
    if(ADCMask){
        P1M0 &= ~ ADCMask;
        P1M1 &= ~ ADCMask;
    }

    ADCMask = mask;
    ///关闭adc
    if(ADCMask == 0x00) return;
    //设置通道IO开漏
    P1 = P1M0 = P1M1 = ADCMask;
    //复位值
    ADC_RESH = 0x00;
    ADC_RESL = 0x00;
    ADC_CONTR =ADC_POWER|ADC_SPEED9;
    //DelayMs(1);
    _delay(1000);
}

/*
    //ISR
#define NCh(_v) do{}while(!(ADCMask & (1u << (++_v &= ~0xf8))))
unsigned short ADCres[ADCCH];

void adc_isr() interrupt 5
{
    ///清除中断
    ADC_CONTR &= ~ADC_FLAG ;

    unsigned char ch = ADC_CONTR & (~0xf8);
    ADCres[ch] = (ADC_DATA << 2) | ADC_LOW2;

    NCh(ch);

    ADC_CONTR = (ADC_CONTR & (~0x07) ) | ADC_START | ch;
}

void Adc_InitIsr(unsigned char mask)
{
    unsigned char ch;
    //卸载之前状态
    ADC_CONTR = 0x00;
    if(ADCMask){
        P1M0 &= ~ ADCMask;
        P1M1 &= ~ ADCMask;
    }

    ADCMask = mask;
    ///关闭adc
    if(ADCMask == 0x00) return;
    //设置通道IO开漏
    P1 = P1M0 = P1M1 = ADCMask;
    ADC_DATA = 0x00;

    NCh(ch);
    ADC_CONTR =ADC_POWER|ADC_SPEED9 | ADC_START | ch;
    DelayMs(1);
}

unsigned short GetResultIsr(unsigned char ch)
{
    ch &= ~0xf8;
    return ADCres[ch];
}

*/
#endif //COMPILE_STC_ADC