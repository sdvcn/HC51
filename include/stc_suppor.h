#ifndef _STC_ADC_H_
#define _STC_ADC_H_

#ifndef SUPPORT_AD
#warning No Support ad
#endif

extern void Adc_Init(unsigned char mask);
extern unsigned short GetResult(unsigned char ch);

#ifndef SUPPORT_EEPROM
#warning No Support EEprom
#endif



#endif