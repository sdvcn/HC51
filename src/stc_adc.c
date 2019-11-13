/*
    实现ADC功能部分
    支持型号
    Stc12x56xxAD系列
    STC8A8KxxSA12系列
    
*/

#include <stcmcu.h>


#define COMPILE_STC_ADC
// ISR 暂时不可用
#define STC_ADC_ISR

#ifdef COMPILE_STC_ADC

volatile xdata unsigned short  ADC_ChMask = 0x00;


void Adc_Init(unsigned short mask){
    //static unsigned short OldMask = 0x00;
    // ADC 关闭
    ADC_CONTR = 0x00;
    // 恢复IO状态为双向
    if(ADC_ChMask){
        #ifdef STC_ADC_ISR
            // 不处理 内部 VREF 通道
            ADC_ChMask &= 0b01111111;
        #endif

        P0M0 &= ~ ((char*) &ADC_ChMask)[1];
        P0M1 &= ~ ((char*) &ADC_ChMask)[1];
        P1M0 &= ~ ((char*) &ADC_ChMask)[0];
        P1M1 &= ~ ((char*) &ADC_ChMask)[0];
    }
    ADC_ChMask = mask;
    if(ADC_ChMask == 0x00) return ;

    // 配置IO高阻输入
    P0M1 |= ((char*) &ADC_ChMask)[1];
    P0M0 &= ~((char*) &ADC_ChMask)[1];

    P1M1 |= ((char*) &ADC_ChMask)[0];
    P1M0 &= ~((char*) &ADC_ChMask)[0];
    // 初始值清空
    ADC_RESH = 0x00;
    ADC_RESL = 0x00;

    #ifdef STC_ADC_ISR
        // 内部基准
        ADC_ChMask |= (1ul << 0x0f);
    #endif
    // adc配置
    ADC_CFG = ADC_RESFMT | ADC_SPEED7;

    #ifdef STC_ADC_ISR
        EADC = 1;
        // 启动ADC电源
        ADC_CONTR = ADC_POWER | ADC_START | 0b1111;
    #elif
        // 启动ADC电源
        ADC_CONTR = ADC_POWER;
        _delay(500);
    #endif
}



#ifdef STC_ADC_ISR
///自增长
//#define AdcNextCh(_v) while(ADC_ChMask & (1ul << _v)){++_v;_v &= 0x0f; }
//unsigned idata char ia = 0x03;

volatile xdata unsigned short ADC_Res[0x0F+1] = {0x00};
//unsigned short CCount ;
//interrupt void Adc_ISR(void) _at_ ADC_ISRADDR
void Adc_ISR() interrupt 5
{
    unsigned char ch;
    ch = (ADC_CONTR & 0x0f);
    //unsigned short mask = 1ul << ch;
    //unsigned idata char ia = 0x03;

    ADC_CONTR &= ~(ADC_FLAG | 0x0f);
    ADC_Res[ch]=Adc_Result();
    
    do{
        ++ch;
        ch &= 0x0f;
    }while(!(ADC_ChMask & (1ul << ch)));
    
    //++ch & 0x0f
    
    //ADC_CONTR &= 0xF0;
    ADC_CONTR |=  ADC_START | ch;
}
// 中断方式获取adc
unsigned short Adc_GetResult(unsigned char ch)
{
    return ADC_Res[ch];
}
#else
// 查询方式获取ADC,会关闭全局中断
unsigned short Adc_GetResult(unsigned char ch)
{
    // 判定是否为已初始化
    if(!(ADC_ChMask & (1ul << ch))) return 0;
    //ADC_CONTR = ADC_POWER | ADC_START;
    asm("push ie");
    di();                                                       //关闭全局中断
    ch &= 0x0f;
    ADC_CONTR = ADC_POWER | ADC_START | ch;
    NOP();
    NOP();
    NOP();
    NOP();
    while (!(ADC_CONTR & ADC_FLAG));
    asm("pop ie");                                              // 恢复中断
    ADC_CONTR &= ~(ADC_FLAG);
    return Adc_Result();                                          // 宏定义返回值
}

#endif

#endif //COMPILE_STC_ADC