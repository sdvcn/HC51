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
/*
    ISP IAP EEPROM
*/
extern unsigned char IspRead(unsigned short addr);
extern void IspReads(char* buf,unsigned short len,unsigned short addr);
extern void IspWrite(unsigned char v,unsigned short addr);
extern void IspWrites(char* buf,unsigned short len,unsigned short addr);
extern void IspErase(unsigned short addr);
///GPIO
extern void SetGPIO(unsigned char mio,ModeOP* mode);



#endif
