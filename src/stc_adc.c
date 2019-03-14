#include <stdio.h>
#include <stcmcu.h>
#include <stc_adc.h>

#define ADCCH	8


#define ADC_POWER       (0x80)
#define ADC_SPEED9      (0x60)
#define ADC_SPEED54     (0x40)
#define ADC_SPEED810    (0x20)
#define ADC_SPEED108    (0x00)
#define ADC_START       (0x08)
#define ADC_FLAG        (0x10)

#define DelayUs(_x)
#define DelayMs(_x)
#define NOP()   asm("nop")


unsigned char ADCMask;
#ifdef INTER_ADC 
#define NCh(_v) do{}while(!(ADCMask & (1u << (++_v &= ~0xf8))))
//#define GetResult(_v) ADCres[(_v & (~0xf8))]
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
unsigned short GetResult(unsigned char ch)
{
    ch &= ~0xf8;
    return ADCres[ch];
}

#else

unsigned short GetResult(unsigned char ch)
{
    ch &= ~0xf8;
    ADC_CONTR = ADC_POWER|ADC_SPEED9 | ADC_START | ch;
    NOP();
    NOP();
    NOP();
    NOP();
    while (!(ADC_CONTR & ADC_FLAG));
    ADC_CONTR &= ~ADC_FLAG;
    return (ADC_DATA << 2) | ADC_LOW2;
}

	
#endif

void Adc_Init(unsigned char mask)
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
#ifdef INTER_ADC 
    NCh(ch);
    ADC_CONTR =ADC_POWER|ADC_SPEED9 | ADC_START | ch;
#else
    ADC_CONTR =ADC_POWER|ADC_SPEED9;
#endif
    DelayMs(1);
}

