
#ifndef __STC_GPIO_H__
#define __STC_GPIO_H__


#define GPIO_STATUS_LEVELHIGH   (7ul << 0)              // 电平变化

typedef struct _GPIO_Status{
    unsigned char mMask;        //
    unsigned char mHit;         // 激活次数统计
    unsigned short long mTick;        // tick统计
}GPIO_Status,*pGPIO_Status;

// 获取电平变化
extern unsigned GPIO_GetStatus(pGPIO_Status st,unsigned char io);
// 获取电平变化累计
// 重置统计
//#define GPIO_RestartStatus(_v)

// 电平无变化连续统计

#endif //__STC_GPIO_H__