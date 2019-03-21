#include <stcmcu.h>

//#define FOSC        11059200L
//#define FOSC        STCCLKR
//#define BAUD        (256 - FOSC / 32 / 115200)


///波特率
unsigned char SetRate(unsigned short v)
{
    return (256 - STCCLKR / 32 / v);
}

static void InitUart()
{

}

///模拟方式实现串口