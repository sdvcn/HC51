#ifndef __I2C_H__
#define __I2C_H__

#ifdef EMUI2C

#else

#endif // <EMUI2C
/*
扩展指令部分在D/E版本之后被支持
*/
/// 寄存器基本指令
enum{
    MSCMD_NONE    = 0b0000,
    MSCMD_START   = 0b0001,
    MSCMD_WRITE   = 0b0010,
    MSCMD_RACK    = 0b0011,
    MSCMD_READ    = 0b0100,
    MSCMD_TACK    = 0b0101,
    MSCMD_STOP    = 0b0110,
    //todo:未确认硬件兼容
    //Ext_MSCMD_START = 0b1001,
    //Ext_MSCMD_WRITE = 0b1010,
    //Ext_MSCMD_READACK = 0b1011,
    //Ext_MSCMD_READNACK = 0b1100,

};
/// 导出内置
extern unsigned char I2c_GetBuf();
extern void I2c_SetBuf(unsigned char c);

/// 初始化配置
extern bit I2c_CFG(unsigned char op);
/// 总线上ACK状态
extern bit I2c_NAckStatus();
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

#endif