#include <stcmcu.h>

#define CMD_Idle    0b0000
#define CMD_Read    0b0001
#define CMD_Write   0b0010
#define CMD_Erase   0b0011

#define ISPEN       (1u << 7)
#define SWBS        (1u << 6)
#define SWRST       (1u << 5)
#define CMD_FAIL    (1u << 4)
#define WT2         (1u << 2)
#define WT1         (1u << 1)
#define WT0         (1u << 0)

#define WT1M        1000000u
#define WT2M        2000000u
#define WT3M        3000000u
#define WT6M        6000000u
#define WT12M       12000000u
#define WT20M       20000000u
#define WT24M       24000000u
#define WT30M       30000000u


#define Trig()      do{ISP_TRIG = 0x46;NOP();ISP_TRIG=0xb9;NOP();}while(0)

static unsigned char IspWT()
{

    if (STCCLKR < WT1M) return 0b0111;
    if (STCCLKR < WT2M) return 0b0110;
    if (STCCLKR < WT3M) return 0b0101;
    if (STCCLKR < WT6M) return 0b0100;
    if (STCCLKR < WT12M) return 0b0011;
    if (STCCLKR < WT20M) return 0b0010;
    if (STCCLKR < WT24M) return 0b0001;

    return 0b000; 
}

void IspIdle()
{
    ISP_CONTR   = 0x00;
    ISP_CMD     = CMD_Idle;
    ISP_TRIG    = 0x00;
    ISP_ADDR    = ~0x00;
}

unsigned char IspReadByte(unsigned short addr)
{
    unsigned char dat;
    ISP_CONTR   = ISPEN | IspWT();
    ISP_CMD     = CMD_Read;
    ISP_ADDR    = addr;
    Trig();
    dat = ISP_DATA;
    return dat;
}

void IspRead(char* buf,unsigned short len,unsigned short addr)
{
    
}


void IspErase(unsigned short addr)
{

}