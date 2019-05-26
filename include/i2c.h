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
/// I2c 主机辅助控制寄存器
//far volatile unsigned char I2CMSAUX	@ 0xFE88;
//#define EXTSFR_I2CMSST  0xFE82
//#define EXTSFR_I2CMSAUX 0xFE88

#define WDTA    0

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


/**
 * 扩展方式
*/
//extern void I2c_Ext_Start(unsigned char c);
//extern unsigned char I2c_Ext_Write(unsigned char c);
//extern unsigned char I2c_Ext_Writes(unsigned char len,char* src);
//extern unsigned char I2c_Ext_StartReg(unsigned char addr,unsigned char reg);
//extern unsigned char I2c_Ext_Reads(unsigned char len,char* dst);
/// 导出内置
extern unsigned char I2c_GetBuf();
extern void I2c_SetBuf(unsigned char c);
/**
 * 基本方式
 * todo:故障
*/



/// 初始化配置
extern bit I2c_CFG(unsigned char op);
/// 总线上ACK状态
extern unsigned char I2c_NAckStatus();
/// 读取忙
extern bit I2c_Busy();
/// I2C 控制命令
extern void I2c_Cmd(unsigned char cmd);
/// 启动
#define I2c_Start() I2c_Cmd(MSCMD_START);
/// 读应答
#define I2c_RxAck() I2c_Cmd(MSCMD_RACK);
/// 传输停止
#define I2c_Stop()  I2c_Cmd(MSCMD_STOP);


//extern void I2c_Start();
//extern void I2c_RxAck();

/// 发送应答
extern void I2c_Ack(unsigned char nAck);
#define I2c_TxAck() I2c_Ack(0x00)
#define I2c_TxNAck() I2c_Ack(0x01)

/// 发送无回应应答
//extern void I2c_TxNAck();

/// 传输停止
//extern void I2c_Stop();

/// 写字节
extern void I2c_Write(unsigned char c);
/// 写字串
extern unsigned I2c_Writes(unsigned len,char* src);
/// 读字符
extern unsigned char I2c_Read();
/// 读字串
extern unsigned I2c_Reads(unsigned len,char* dst);



#define I2c_InitM(_v) I2c_CFG(0xc0 | _v)
#define I2c_InitS(_v) I2c_CFG(0x80 | _v)
#define I2c_Di() I2c_CFG(0x00)


//-----------------------------------------------------------------------------
#define IIC_ENI2C   (1ul << 7)
#define IIC_MSSL    (1ul << 6)

#define IIC_sfr_Command _IIC_sfr_Command

#define IIC_sfr_RecvAck() IIC_sfr_Command(MSCMD_RACK)                   //  接收ACK指令
#define IIC_sfr_SendAck() IIC_sfr_Command(MSCMD_TACK)                   //  发送ACK指令
#define IIC_sfr_AckI() (ExtSfrGet8(&I2CMSST) & MSACKI)                  //  收到的ACK状态

#include <obj.h>
/**
 * 读写完成开始时建立IIC通道
 * 结束读写后立即释放
*/
typedef struct _sI2c
{
    BaseIO  mIOs;                                       // 基础IO操作
	//---
    void (*pCommand)(void *,unsigned char);              // 指令
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

    unsigned char (*pIOs)(void*,unsigned char);  
    unsigned char (*pReadReg8)(struct _sI2c *,unsigned char);
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
#define m2_I2c_Start(_h)    pI2c(_h)->pCommand(_h,MSCMD_START)
#define m2_I2c_Stop(_h)     pI2c(_h)->pCommand(_h,MSCMD_STOP)



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

#endif