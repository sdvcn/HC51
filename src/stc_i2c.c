/**
 * STC8 测试后部分扩展指令支持存在问题
*/
#include <stcmcu.h>
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
    if(ExtSfrGet8((size_t)&I2CCFG)&ENI2C){
        DLOG("_CheckI2C");  
    }
}
// 内置延时等待
void I2c_Wait()
{
    while(!(ExtSfrGet8((size_t)&I2CMSST) & MSIF));
    ExtSfrClear((size_t)&I2CMSST,MSIF);
}

unsigned char I2c_GetBuf()
{
    return (ExtSfrGet8((size_t)&I2CRxD));
}

void I2c_SetBuf(unsigned char c)
{
    //I2CTxD = c;
    ExtSfrSet8((size_t)&I2CTxD,c);
}

bit I2c_Busy()
{
    return ((ExtSfrGet8((size_t)&I2CMSST) & MSBUSY) ? 1ul:0ul;
}


/// 检测收到NAck
unsigned char I2c_NAckStatus()
{
    unsigned char ret = 0x00;
    ret = ExtSfrGet8((size_t)&I2CMSST);
    return (ret & MSACKI);
}

bit I2c_CFG(unsigned char op)
{
    //DLOGINT(I2c_CFG,op);
    if(ExtSfrGet8((size_t)&I2CMSST) & MSBUSY) return 0ul;
    ExtSfrSet8((size_t)&I2CCFG,op);
    ExtSfrSet8((size_t)&I2CMSST,0x00);
    ExtSfrSet8((size_t)&I2CMSAUX,0x00);
    return 1ul;
}
/// I2C 控制命令
void I2c_Cmd(unsigned char cmd)
{
    /// 清除高4位
    cmd &= ~0xF0;
    //todo 处理硬件版本兼容问题
    //I2CMSCR = ((I2CMSCR & ~0x0f)| cmd);
    ExtSfrSet8((size_t)&I2CMSCR,(ExtSfrGet8((size_t)&I2CMSCR) & ~0x0f)|cmd);
    I2c_Wait();
}
/**
 * 基础方式实现
*/
/// 写入字符
void I2c_Write(unsigned char c)
{
    ExtSfrSet8((size_t)&I2CTxD,c);
    I2c_Cmd(MSCMD_WRITE);
}
/// 读字符
unsigned char I2c_Read()
{
    I2c_Cmd(MSCMD_READ);
    return ExtSfrGet8((size_t)&I2CRxD);
}
/// 发送应答
void I2c_Ack(unsigned char nAck)
{
    ExtSfrSet8((size_t)&I2CMSST,(nAck?0x01:0x00));
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
