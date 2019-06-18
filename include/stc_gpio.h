
#ifndef __STC_GPIO_H__
#define __STC_GPIO_H__


typedef struct _GPIO_Status{
    unsigned mTick;        // 
    unsigned char mLastIO;
}GPIO_Status,*pGPIO_Status;


extern unsigned GPIO_GetStatus(pGPIO_Status st,unsigned char io);

#endif //__STC_GPIO_H__