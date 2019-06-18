#include <stcmcu.h>
#include "../config.h"

#ifdef COMPILE_STC_GPIO

#define GPIO_STATUS_BLOCK   (1ul << 7)              // 阻塞方式

#define GPIO_STATUS_LEVEL   (1ul << 0)              // 电平变化



/**
 * 返回激活的tick周期
 */
unsigned GPIO_GetStatus(pGPIO_Status st,unsigned char io)
{
    if(st->mLastIO <> io){
        st->mTick = GetSystemTick();
        return ~0x00;
    }
    return DiffTick(st->mTick);
}

//#define GetIOStatus_Block(_st,_io) while(GPIO_GetStatus(_st,_io))
#endif //COMPILE_STC_GPIO