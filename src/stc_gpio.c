#include <stcmcu.h>
#include "../config.h"

#ifdef COMPILE_STC_GPIO

#define GPIO_STATUS_BLOCK   (1ul << 7)              // 阻塞方式





/**
 * 返回激活的tick周期
 */
unsigned GPIO_GetStatus(pGPIO_Status st,unsigned char io)
{
    if(st->mHigh){

    }
    if(st->mLastIO <> io){
        st->mTick = GetSystemTick();
        return ~0x00;
    }
    return DiffTick(st->mTick);
}

//#define GetIOStatus_Block(_st,_io) while(GPIO_GetStatus(_st,_io))

void GPIO_RestartStatus(pGPIO_Status st)
{
    st->mHit = 0;
    st->mTick = 0x00;
}
#endif //COMPILE_STC_GPIO