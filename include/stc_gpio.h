
#ifndef __STC_GPIO_H__
#define __STC_GPIO_H__


#define GPIO_STATUS_LEVELHIGH   (7ul << 0)              // 电平变化

typedef struct _GPIO_Status{
    union 
    {
        unsigned char mFlag;
        struct 
        {
            unsigned char mHigh:1;                      // H->L
            unsigned char mHit:7;                     //
        };
    };
    unsigned char mLastIO;
    unsigned mTick;        // 
}GPIO_Status,*pGPIO_Status;

// 获取电平变化
extern unsigned GPIO_GetStatus(pGPIO_Status st,unsigned char io);
// 获取电平变化累计
// 重置统计
//#define GPIO_RestartStatus(_v)

#endif //__STC_GPIO_H__