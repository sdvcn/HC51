#include <stcmcu.h>
#include <i2c.h>
//MSCMDEXT
unsigned char I2c_GetBuf()
{
    return I2CRxD;
}

void I2c_SetBuf(unsigned char c)
{
    I2CTxD = c;
}

bit I2c_Busy()
{
    return (I2CMSST & MSBUSY) ? 1ul:0ul;
}

/// 检测收到NAck
bit I2c_NAckStatus()
{
    return CheckBIT(I2CMSST,1);
}

bit I2c_CFG(unsigned char op)
{
    if(I2CMSST & MSBUSY) return 0ul;
    I2CCFG      = op;
    I2CMSST     = 0x00;
    I2CMSAUX    = 0x00;
    return 1ul;
}
/// I2C 控制命令
void I2c_Cmd(unsigned char cmd)
{
    /// 清除高4位
    cmd &= ~0xF0;
    //todo 处理硬件版本兼容问题
    I2CMSCR = ((I2CMSCR & ~0x0f)| cmd);
    while(!(I2CMSST & MSIF));
    I2CMSST &= ~MSIF;
}
/// 写入字符
void I2c_Write(unsigned char c)
{
    I2CTxD = c;
    I2c_Cmd(MSCMD_WRITE);
}
/// 读字符
unsigned char I2c_Read()
{
    I2c_Cmd(MSCMD_READ);
    return I2CRxD;
}
/// 发送应答
void I2c_Ack(unsigned char nAck)
{
    I2CMSST = (nAck?0x01:0x00);
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
