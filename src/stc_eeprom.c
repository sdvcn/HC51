/*
    实现Eeprom功能部分
    支持型号
    Stc12x56xxAD系列
    
*/
#include <stcmcu.h>
//#include "../config.h"
#include <stc_timer.h>
#ifdef COMPILE_STC_EPROM

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

#define WT1M        1000000ul
#define WT2M        2000000ul
#define WT3M        3000000ul
#define WT6M        6000000ul
#define WT12M       12000000ul
#define WT20M       20000000ul
#define WT24M       24000000ul
#define WT30M       30000000ul


#define Trig()      do{ISP_TRIG = 0x46;NOP();ISP_TRIG=0xb9;NOP();}while(0)
/*
    ISP or IAP 等待时间
*/
static unsigned char IspWT()
{
    unsigned char r;

    if (GetFrequency() < WT1M) return 0b0111;
    if (GetFrequency() < WT2M) return 0b0110;
    if (GetFrequency() < WT3M) return 0b0101;
    if (GetFrequency() < WT6M) return 0b0100;
    if (GetFrequency() < WT12M) return 0b0011;
    if (GetFrequency() < WT20M) return 0b0010;
    if (GetFrequency() < WT24M) return 0b0001;

    return 0b000; 
}

void _Idle()
{
    ISP_CONTR   = 0x00;
    ISP_CMD     = CMD_Idle;
    ISP_TRIG    = 0x00;
    ISP_ADDR    = ~0x00;
}

unsigned char _Read(unsigned short addr)
{
    ISP_CMD     = CMD_Read;
    ISP_ADDRL   = addr;
    ISP_ADDRL   = addr >> 8;
    Trig();
    return ISP_DATA;
}

unsigned char IspRead(unsigned short addr)
{
    unsigned char dat;
    ISP_CONTR   = ISPEN | IspWT();
    /*
    ISP_CMD     = CMD_Read;
    ISP_ADDR    = addr;
    Trig();
    dat = ISP_DATA;
    */
    dat = _Read(addr);
    _Idle();
    return dat;
}

void IspReads(char* buf,unsigned short len,unsigned short addr)
{
    while(len--){
        *buf++ = _Read(addr++);
    }
    /*
    for(size_t i = 0; i < len; i++)
    {
        buf[i] = _Read(addr++);
    }
    */
    _Idle();
}

void _Write(unsigned char v,unsigned short addr)
{
    ISP_CMD     = CMD_Write;
    ISP_ADDRL   = addr;
    ISP_ADDRL   = addr >> 8;
    ISP_DATA    = v;
    Trig();
}

void IspWrite(unsigned char v,unsigned short addr)
{
    ISP_CONTR   = ISPEN | IspWT();
    _Write(v,addr);
    _Idle();
}

void IspWrites(char *buf,unsigned short len,unsigned short addr)
{
    ISP_CONTR   = ISPEN | IspWT();
    while(len--){
        _Write(*buf++,addr++);
    }
    _Idle();
}


void IspErase(unsigned short addr)
{
    ISP_CONTR   = ISPEN | IspWT();
    ISP_CMD     = CMD_Erase;
    ISP_ADDRL   = addr;
    ISP_ADDRL   = addr >> 8;
    Trig();
    _Idle();
}


#endif //COMPILE_STC_EPROM