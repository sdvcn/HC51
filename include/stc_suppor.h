#ifndef _STC_ADC_H_
#define _STC_ADC_H_


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
//extern void SetGPIO(unsigned char mio,ModeOP* mode);


#ifdef STC8
///PWM
extern void PWM_CR(unsigned char ch,unsigned char OP);
extern void PWM_SetHld(unsigned char mh,unsigned char ml);
extern void PWN_ClrN(unsigned char mio);



#endif

#endif
