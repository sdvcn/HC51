
#ifndef __STC_GPIO_H__
#define __STC_GPIO_H__


typedef struct _GPIO_Status{
    unsigned mTick;        // 
    //unsigned mTickOut;     // 延时
    unsigned char mLastIO;
    //unsigned mCount;            // 除颤
    
    //void (*pExec)(struct _ScanIO*);
}GPIO_Status,*pGPIO_Status;


extern unsigned GPIO_GetStatus(pGPIO_Status st,unsigned char io);

#endif //__STC_GPIO_H__