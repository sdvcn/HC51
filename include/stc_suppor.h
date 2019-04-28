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


#ifdef STC8
///PWM
extern void PWM_CR(unsigned char ch,unsigned char OP);
extern void PWM_SetHld(unsigned char mh,unsigned char ml);
extern void PWN_ClrN(unsigned char mio);
//I2c
extern bool I2c_Busy();
extern void I2c_Start();
extern void I2c_Write(unsigned char c);
extern void I2c_RxAck();
extern unsigned char I2c_Read();
extern void I2c_TxAck();
extern void I2c_TxNAck();
extern void I2c_Stop();

#endif

#endif
