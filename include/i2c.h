#ifndef __I2C_H__
#define __I2C_H__

#ifdef EMUI2C

#else

#endif // <EMUI2C

/// 初始化配置
extern bool I2c_CFG(unsigned char op);
/// 读取忙
extern bool I2c_Busy();
/// 启动
extern void I2c_Start();
/// 读应答
extern void I2c_RxAck();
/// 发送应答
extern void I2c_TxAck();
/// 发送无回应应答
extern void I2c_TxNAck();
/// 传输停止
extern void I2c_Stop();
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