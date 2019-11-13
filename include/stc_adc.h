#ifndef __STC_ADC_H__
#define __STC_ADC_H__

#define PADC0   0b0000
#define PADC1   0b0001
#define PADC2   0b0010
#define PADC3   0b0011
#define PADC4   0b0100
#define PADC5   0b0101
#define PADC6   0b0110
#define PADC7   0b0111
#define PADC8   0b1000
#define PADC9   0b1001
#define PADC10   0b1010
#define PADC11   0b1011
#define PADC12   0b1100
#define PADC13   0b1101
#define PADC14   0b1110
#define PADC15   0b1111

void Adc_Init(unsigned short mask);
unsigned short Adc_GetResult(unsigned char ch);

#endif