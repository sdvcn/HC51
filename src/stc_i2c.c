/**
 * STC8 测试后部分扩展指令支持存在问题
*/
#include <stcmcu.h>

#include <string.h>

#include <i2c.h>
#include <ext_debug.h>


/**
 * 时许严谨,禁止占用
*/

#ifdef DEBUG
    #define CheckI2C() _CheckI2C()
#else
    #define CheckI2C()
#endif

#undef DEBUG



//检查确认I2c总线开启
void _CheckI2C()
{
    if(ExtSfrGet8(&I2CCFG)&ENI2C){
        DLOG("_CheckI2C");  
    }
}

// 内置延时等待
void I2c_Wait()
{
    while(!(ExtSfrGet8(&I2CMSST) & MSIF));
    ExtSfrClear8(&I2CMSST,MSIF);
}

unsigned char I2c_GetBuf()
{
    return (ExtSfrGet8(&I2CRxD));
}

void I2c_SetBuf(unsigned char c)
{
    //I2CTxD = c;
    ExtSfrSet8(&I2CTxD,c);
}

bit I2c_Busy()
{
    return ((ExtSfrGet8(&I2CMSST) & MSBUSY) ? 1ul:0ul;
}


/// 检测收到NAck
unsigned char I2c_NAckStatus()
{
    unsigned char ret = 0x00;
    ret = ExtSfrGet8(&I2CMSST);
    return (ret & MSACKI);
}

bit I2c_CFG(unsigned char op)
{
    //DLOGINT(I2c_CFG,op);
    if(ExtSfrGet8(&I2CMSST) & MSBUSY) return 0ul;
    ExtSfrSet8(&I2CCFG,op);
    ExtSfrSet8(&I2CMSST,0x00);
    ExtSfrSet8(&I2CMSAUX,0x00);
    return 1ul;
}
/// I2C 控制命令
void I2c_Cmd(unsigned char cmd)
{
    /// 清除高4位
    cmd &= ~0xF0;
    //todo 处理硬件版本兼容问题
    //I2CMSCR = ((I2CMSCR & ~0x0f)| cmd);
    ExtSfrSet8(&I2CMSCR,(ExtSfrGet8(&I2CMSCR) & ~0x0f)|cmd);
    I2c_Wait();
}
/**
 * 基础方式实现
*/
/// 写入字符
void I2c_Write(unsigned char c)
{
    ExtSfrSet8(&I2CTxD,c);
    I2c_Cmd(MSCMD_WRITE);
}
/// 读字符
unsigned char I2c_Read()
{
    I2c_Cmd(MSCMD_READ);
    return ExtSfrGet8(&I2CRxD);
}
/// 发送应答
void I2c_Ack(unsigned char nAck)
{
    ExtSfrSet8(&I2CMSST,(nAck?0x01:0x00));
    I2c_Cmd(MSCMD_TACK);
}
//-----------
///写字符串 ???
unsigned I2c_Writes(unsigned len,char* src)
{
    unsigned ret = 0x00;

    while((!I2c_NAckStatus())&&(len--)){
        I2c_Write(*src++);
        ret++;
        ///收ACK
        I2c_RxAck();
    }
    return ret;
}
///读字符串
unsigned I2c_Reads(unsigned len,char* dst)
{
    unsigned ret = 0x00;
    while((!I2c_NAckStatus())&&(len--)){
        *dst++=I2c_Read();
        ret++;
        I2CMSST = ((len)?0x00:0x01);
        I2c_Cmd(MSCMD_TACK);
    }
    return ret;
}
//------------------------------------------
/**
 * 模拟方式实现IIC
*/
#define PSDA P01
#define PSCL P02
#define PHigh   1
#define PLow    0

/// 400Khz
#define LOOP1   5
#define LOOP2   6

void Emu_delay()
{
    unsigned char i,j;
    i = LOOP1;
    j = LOOP2;
    do{
        while(--i);
    }while(--j);
}

void Emu_Init()
{
    PSCL = PHigh;
    PSDA = PHigh;
}

void Emu_Start()
{
    PSDA = PHigh;
    PSCL = PHigh;
    Emu_delay();
    PSDA = PLow;
    Emu_delay();
    PSCL = PLow;
}

void Emu_Stop()
{
    PSDA = PLow;
    Emu_delay();
    PSCL = PHigh;
    Emu_delay();
    PSDA = PHigh;
}

unsigned char Emu_Read()
{
    unsigned char c = 0x00;
    for (unsigned char i = 0; i < 8; i++)
    {
        PSCL = PHigh;
        Emu_delay();
        Emu_delay();
        c << = 1;
        c |= PSDA;
        PSCL = PLow;
        Emu_delay();
        Emu_delay();
    }
    return c;
}
void Emu_Write(unsigned char c)
{
    for (unsigned char i = 0; i < 8; i++){
        PSDA = (c & (1 << i))?PHigh:PLow;
        PSCL = PHigh;
        Emu_delay();
        PSCL = PLow;
        Emu_delay();
    }
}

void Emu_RxACK()
{

}
void Emu_Cmd(unsigned char cmd)
{

}


//-----------------------------------------------------------------------------

/**
 * 寄存器方式实现
*/
void _Sfr_CFG(unsigned char op)
{
    DLOGINT(_Sfr_CFG,op);
    //DLOGINT(I2c_CFG,op);
    //if(ExtSfrGet8(&I2CMSST) & MSBUSY) return 0ul;
    ExtSfrSet8(&I2CCFG,op);
    ExtSfrSet8(&I2CMSST,0x00);
    ExtSfrSet8(&I2CMSAUX,0x00);
    //return 1ul;
}

void _Sfr_Wait()
{
    DLOGINT(_Sfr_Wait,0);
    while(!(ExtSfrGet8(&I2CMSST) & MSIF));
    ExtSfrClear8(&I2CMSST,MSIF);
}

void _Sfr_Cmd(sI2c* h,unsigned char cmd)
{
    DLOGINT(_Sfr_Cmd,cmd);
    /// 清除高4位
    cmd &= ~0xF0;
    /// 新连接 开启IIC
    if(!(ExtSfrGet8(&I2CMSST) & MSBUSY)){
        if(h->mSpeed > 127) h->mSpeed = 127;
        _Sfr_CFG(IIC_ENI2C|IIC_MSSL|(h->mSpeed-1)/2);
    } 

    //todo 处理硬件版本兼容问题
    //I2CMSCR = ((I2CMSCR & ~0x0f)| cmd);
    ExtSfrSet8(&I2CMSCR,(ExtSfrGet8(&I2CMSCR) & ~0x0f)|cmd);
    _Sfr_Wait();
}

void _Sfr_Write(sI2c* h,unsigned char c)
{
    ExtSfrSet8(&I2CTxD,c);
    _Sfr_Cmd(h,MSCMD_WRITE);
}

/// 读字符
unsigned char _Sfr_Read(sI2c* h)
{
    _Sfr_Cmd(h,MSCMD_READ);
    return ExtSfrGet8(&I2CRxD);
}

void _Sfr_Close(sI2c* h)
{
    _Sfr_CFG(0x00);
}

///
#pragma warning disable 359

void CreateIICM4Sfr(sI2c *mio)
{
    //assert((sizeof(sI2c)==sizeof(BaseIO)));
    /// 申请内存
    //memset(mio,0x00,sizeof(sI2c));                     //重置
    /// 函数赋值
    pI2c(mio)->pCommand = _Sfr_Cmd;

    pI2c(mio)->mIOs.pRead = _Sfr_Read;
    pI2c(mio)->mIOs.pWrite = _Sfr_Write;
    pI2c(mio)->mIOs.pClose = _Sfr_Close;

}
#pragma warning enable 359
//-----------------------------------------------------------------------------
/**
 * 通用方法
*/
void I2c_Speed(sI2c *mio,unsigned sp)
{
    mio->mSpeed = GetSystemClock()/sp;    
}

