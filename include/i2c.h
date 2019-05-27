#ifndef __I2C_H__
#define __I2C_H__


/**
 * 通用
*/

/// 读地址移位
#define I2C_READ_ADDR(_addr) ((_addr << 1) | 1ul)
/// 写地址移位
#define I2C_WRITE_ADDR(_addr) ((_addr << 1) | 0ul)


#ifdef EMUI2C

#else

#endif // <EMUI2C
/**
 * 寄存器及基础定义
*/


/*
扩展指令部分在D/E版本之后被支持
*/
/// 寄存器基本指令
enum{
    MSCMD_NONE    = 0b0000,                                             //  无动作
    MSCMD_START   = 0b0001,                                             //  起始
    MSCMD_WRITE   = 0b0010,                                             //  写入
    MSCMD_RACK    = 0b0011,                                             //  收ACK
    MSCMD_READ    = 0b0100,                                             //  读取
    MSCMD_TACK    = 0b0101,                                             //  发ACK
    MSCMD_STOP    = 0b0110,                                             //  停止
    //todo:未确认硬件兼容
    Ext_MSCMD_START = 0b1001,
    Ext_MSCMD_WRITE = 0b1010,
    Ext_MSCMD_READACK = 0b1011,
    Ext_MSCMD_READNACK = 0b1100,

};
//-----------------------------------------------------------------------------
/**
 * 扩展方式
*/
//-----------------------------------------------------------------------------
#define IIC_ENI2C   (1ul << 7)
#define IIC_MSSL    (1ul << 6)

#define IIC_sfr_RecvAck()       IIC_sfr_Command(MSCMD_RACK)                   //  接收ACK指令
#define IIC_sfr_SendAck()       IIC_sfr_Command(MSCMD_TACK)                   //  发送ACK指令



#define IIC_sfr_AckI()          (ExtSfrGet8(&I2CMSST) & MSACKI)                  //  收到的ACK状态
#define IIC_sfr_Stop()          IIC_sfr_Command(MSCMD_STOP)
#define IIC_sfr_InitM(_v)       IIC_sfr_Config(IIC_ENI2C|IIC_MSSL|(_v & 0x0F),0x00)
#define IIC_sfr_InitS(_v,_s)    IIC_sfr_Config(IIC_ENI2C|(_v & 0x0F),_s)
#define IIC_sfr_Disable()       IIC_sfr_Config(0x00,0x00)

#include <obj.h>
/**
 * 读写完成开始时建立IIC通道
 * 结束读写后立即释放
*/
typedef struct _sI2c
{
    BaseIO  mIOs;                                       // 基础IO操作
	//---
    /*
        unsigned char CallIOs(void*,unsigned char op)
        {
            #define SDA P33
            #define SCL P34
            unsigned char r = 0x00;

            if (op & IOs_Read) {
                r |= IOs_Read;
            }else{
                P33 = (op & 1ul << 0) ?1ul:0ul;
                P34 = (op & 1ul << 1) ?1ul:0ul;
            }

            r |= (SDA) ? IOs_SDA:IOs_None;
            r |= (SCL) ? IOs_SCL:IOs_None;
            return r;

            #undef SDA
            #undef SCL
        }
    */

    void (*pEnable)(struct _sI2c *h );
    void (*pDisable)(struct _sI2c *h );
    void (*pStart)(struct _sI2c *h ,unsigned char read);
    void (*pCommand)(struct _sI2c *h ,unsigned char cmd);       // 指令
    unsigned char (*pIOs)(void*,unsigned char);  
    //unsigned char (*pReadReg8)(struct _sI2c *,unsigned char);
    //void (*pWriteReg8)(struct _sI2c *,unsigned char,unsigned char);
    unsigned mSpeed;                                            // 仅主机模式生效
    unsigned char mFlag:6;                                      //
    unsigned char mSelectPort:2;                                // 端口选择 仅寄存器方式
    unsigned char mAddr;   
} sI2c;

enum {
    IOs_None = 0ul,
    IOs_SDA  = (1ul << 0),                              // 控制SDA
    IOs_SCL  = (1ul << 1),                              // 控制SCL
    IOs_Read = 0x80,                                    // 只读控制
};

#define SI2c_Flag_Ext            BIT(1)
#define SI2c_Flag_ExtAuto        BIT(2)
/**
 * I2c扩展指令部分
*/
#define pI2c(_v)      ((sI2c*)_v)
//#define m2_I2c_Start(_h)    pI2c(_h)->pCommand(_h,MSCMD_START)
//#define m2_I2c_Stop(_h)     pI2c(_h)->pCommand(_h,MSCMD_STOP)

/**
 * 使用寄存器
*/

void CreateIICM4Sfr(sI2c *mio);
/**
 * 模拟方式
*/
//void Create4Emu(BaseIO* mio,unsigned char mhz,unsigned char mSda,unsigned char mScl);

/**
 * IIC总线速度设置
*/
#define SI2c_Speed(_h,_v)               do{pI2c(_h)->mSpeed = GetSystemClock()/(_v);}while(0)
/**
 * 总线端口选择
 * 0:SCL=P15 SDA=P14
 * 1:SCL=P25 SDA=P24
 * 2:SCL=P77 SDA=P76
 * 3:SCL=P32 SDA=P33
*/
#define SI2c_SelectPort(_h,_v)          do{pI2c(_h)->mSelectPort = (_v & 0x03);}while(0)

#define I2c_SetAddr(_h,_v)              do{pI2c(_h)->mAddr = (_v);}while(0)


//-----------------------------------------------------------------------------
/**
 * 寄存器方法
*/
void IIC_sfr_Config(unsigned char op,unsigned char saddr);
void IIC_sfr_Command(unsigned char cmd);
unsigned char IIC_sfr_Read();
unsigned char IIC_sfr_Reads(char * dst,unsigned char len);
unsigned char IIC_sfr_ExReads(char * dst,unsigned char len);
void IIC_sfr_Write(unsigned char c);
unsigned char IIC_sfr_Writes(const char* src,unsigned char len);
unsigned char IIC_sfr_ExWrites(const char* src,unsigned char len);
unsigned char IIC_sfr_ExAuxWrites(const char* src,unsigned char len);
void IIC_sfr_Start(unsigned char addr);
void IIC_sfr_ExStart(unsigned char addr);
//-----------------------------------------------------------------------------
/**
 * 模拟方式实现
*/
//-----------------------------------------------------------------------------
/**
 * 通用方法
*/
unsigned char IIC_ReadMem8(sI2c* h,unsigned char reg);
void IIC_WriteMem8(sI2c* h,unsigned char reg,unsigned char v);


#endif