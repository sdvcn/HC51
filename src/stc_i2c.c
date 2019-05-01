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
    I2CMSCR = ((I2CMSCR & ~0x0f)| (cmd & ~0xf0));
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

///写字符串 ???
unsigned I2c_Writes(unsigned len,char* src)
{
    unsigned ret = 0x00;
    while(len--){
        I2c_Write(*src++);
        ///发送ACK
        //I2c_Ack(!len);
        
        ret++;
        I2c_RxAck();
        if(I2c_NAckStatus()) break;
    }
    return ret;
}
///读字符串
unsigned I2c_Reads(unsigned len,char* dst)
{
    unsigned ret = 0x00;
    while(len--){
        *dst++=I2c_Read();
        ret++;
        if(I2c_NAckStatus) break;
        //if(CheckBIT(I2CMSST,1)) break;
    }
    return ret;
}
