#include <stcmcu.h>
#include <i2c.h>
#include <ext_debug.h>
/**
 * 本地变量
*/
static void (*pIICSLFUNCTION)(unsigned char r);



/**
 * IIC中断向量 0xc3
*/


/**
 * 等待指令执行
*/
void _IIC_sfr_Wait(){
    while(!(ExtSfrGet8(&I2CMSST) & MSIF));
    ExtSfrClear8(&I2CMSST,MSIF);
}

/**
 * 配置寄存器初始化
 * todo 未实现从机模式
*/
void _IIC_sfr_Config(unsigned char op,unsigned char saddr)
{
    ExtSfrSet8(&I2CCFG,op);
    ExtSfrSet8(&I2CMSST,0x00);
    ExtSfrSet8(&I2CMSAUX,0x00);
    ExtSfrSet8(&I2CSLADR,saddr);
    //if(!(ExtSfrGet8(&I2CCFG) & IIC_MSSL)){
        ExtSfrSet8(&I2CSLST,0x00);
        ExtSfrSet8(&I2CSLCR,0x78);
    //}
}

/**
 * 指令
*/
void _IIC_sfr_Command(unsigned char cmd)
{
    cmd &= 0x0F;                                                        //  保留底4位
    ExtSfrSet8(&I2CMSCR,(ExtSfrGet8(&I2CMSCR) & 0xF0)|cmd);             //  执行新指令
    _IIC_sfr_Wait();                                                    //  等待执行部完毕
}

/**
 * 字节读
*/
unsigned char _IIC_sfr_Read()
{
    _IIC_sfr_Command(MSCMD_READ);
    return ExtSfrGet8(&I2CRxD);
}

/**
 * 读字符串
*/
unsigned char _IIC_sfr_Reads(char * dst,unsigned char len)
{
    unsigned char r = len;
    while(!IIC_sfr_AckI()&&len--){
        *dst++ = _IIC_sfr_Read();
        if(len) IIC_sfr_SendAck();
    }
    return (r - len);
}

/**
 * 字节写
*/
void _IIC_sfr_Write(unsigned char c)
{
    ExtSfrSet8(&I2CTxD,c);
    _IIC_sfr_Command(MSCMD_WRITE);
}

/**
 * 写字符串
*/
unsigned char _IIC_sfr_Writes(const char* src,unsigned char len)
{
    unsigned char r = len;

    while(!IIC_sfr_AckI()&&len--){
        _IIC_sfr_Write(*src++);
        IIC_sfr_RecvAck();
    }
    return (r - len);
}

unsigned char _IIC_sfr_ExWrites(const char* src,unsigned char len)
{
    unsigned char r = len;
    if(len == 0x00) return 0;
    
    ExtSfrSet8(&I2CMSAUX,0x01);                     // 扩展使能

    while(!IIC_sfr_AckI()&&len--){
        ExtSfrSet8(&I2CTxD,*src++);
        _IIC_sfr_Wait();
    }
    ExtSfrSet8(&I2CMSAUX,0x00);                     // 关闭扩展
    return (r - len);
}


#pragma warning disable 359

void CreateIICM4Sfr(sI2c *mio)
{
    //assert((sizeof(sI2c)==sizeof(BaseIO)));
    /// 申请内存
    //memset(mio,0x00,sizeof(sI2c));                     //重置
    /// 函数赋值
    //pI2c(mio)->pCommand = _Sfr_Cmd;
    //pI2c(mio)->pReadReg8 = _sfr_ReadReg8;
    //pI2c(mio)->mIOs.pRead = _Sfr_Read;
    //pI2c(mio)->mIOs.pWrite = _Sfr_Write;
    //pI2c(mio)->mIOs.pClose = _Sfr_Close;

}
#pragma warning enable 359