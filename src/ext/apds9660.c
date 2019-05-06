
/**
 * Apds-9960 操作封装
 * 采用I2c方案
*/

#include "apds9660.h"
#include <i2c.h>
#include <ext_debug.h>
/**
 * Apds-9960总线地址
*/
#ifndef APDS9960_ADDRES
#define APDS9960_ADDRES 0x39
#endif
/**
 * Apds-9960 总线速度
*/
#ifndef I2C_SPEED
#define I2C_SPEED 0x30
#endif
/**
 * 9960基础定义
*/
/* APDS-9960 register addresses */
#define APDS9960_ENABLE         0x80
/// 环境光 adc 中断时间
#define APDS9960_ATIME          0x81
/// 延时
#define APDS9960_WTIME          0x83
/// 环境光阀值
#define APDS9960_AILTL          0x84
#define APDS9960_AILTH          0x85

#define APDS9960_AIHTL          0x86
#define APDS9960_AIHTH          0x87
/// 接近中断阀值
#define APDS9960_PILT           0x89
#define APDS9960_PIHT           0x8B

#define APDS9960_PERS           0x8C
#define APDS9960_CONFIG1        0x8D
/// 接近脉冲寄存器
#define APDS9960_PPULSE         0x8E

#define APDS9960_CONTROL        0x8F
#define APDS9960_CONFIG2        0x90
/// 驱动器编号
#define APDS9960_ID             0x92
/// 驱动器状态
#define APDS9960_STATUS         0x93
///
#define APDS9960_CDATAL         0x94
#define APDS9960_CDATAH         0x95
/// 红通道数据
#define APDS9960_RDATAL         0x96
#define APDS9960_RDATAH         0x97
/// 绿通道数据
#define APDS9960_GDATAL         0x98
#define APDS9960_GDATAH         0x99
/// 蓝通道数据
#define APDS9960_BDATAL         0x9A
#define APDS9960_BDATAH         0x9B
/// 接近通道数据
#define APDS9960_PDATA          0x9C


#define APDS9960_POFFSET_UR     0x9D
#define APDS9960_POFFSET_DL     0x9E
#define APDS9960_CONFIG3        0x9F
#define APDS9960_GPENTH         0xA0
#define APDS9960_GEXTH          0xA1
#define APDS9960_GCONF1         0xA2
#define APDS9960_GCONF2         0xA3
#define APDS9960_GOFFSET_U      0xA4
#define APDS9960_GOFFSET_D      0xA5
#define APDS9960_GOFFSET_L      0xA7
#define APDS9960_GOFFSET_R      0xA9
#define APDS9960_GPULSE         0xA6
#define APDS9960_GCONF3         0xAA
/// 手势设定 
#define APDS9960_GCONF4         0xAB
/// 手势寄存器缓冲数量
#define APDS9960_GFLVL          0xAE
/// 手势状态
#define APDS9960_GSTATUS        0xAF
/// 强制中断
#define APDS9960_IFORCE         0xE4
/// 接近中断清除
#define APDS9960_PICLEAR        0xE5
/// ALS 通道中断清除
#define APDS9960_CICLEAR        0xE6
/// 全部非手势中断清除
#define APDS9960_AICLEAR        0xE7
/// 手势 上
#define APDS9960_GFIFO_U        0xFC
/// 手势 下
#define APDS9960_GFIFO_D        0xFD
/// 手势 左
#define APDS9960_GFIFO_L        0xFE
/// 手势 右
#define APDS9960_GFIFO_R        0xFF

/* 启动使能 */
/// 主电源
#define APDS9960_PON            (1ul << 0)
/// 环境光线
#define APDS9960_AEN            (1ul << 1)
/// 接近判定
#define APDS9960_PEN            (1ul << 2)
/// 等待延时
#define APDS9960_WEN            (1ul << 3)
/// 环境光线
#define APSD9960_AIEN           (1ul << 4)
/// 接近中断
#define APDS9960_PIEN           (1ul << 5)
/// 手势
#define APDS9960_GEN            (1ul << 6)
///
//#define APDS9960_GVALID         0b00000001
/* Default values */
#define DEFAULT_ATIME           219     // 103ms
#define DEFAULT_WTIME           246     // 27ms
#define DEFAULT_PROX_PPULSE     0x87    // 16us, 8 pulses
#define DEFAULT_GESTURE_PPULSE  0x89    // 16us, 10 pulses
#define DEFAULT_POFFSET_UR      0       // 0 offset
#define DEFAULT_POFFSET_DL      0       // 0 offset      
#define DEFAULT_CONFIG1         0x60    // No 12x wait (WTIME) factor
#define DEFAULT_LDRIVE          LED_DRIVE_100MA
#define DEFAULT_PGAIN           PGAIN_4X
#define DEFAULT_AGAIN           AGAIN_4X
#define DEFAULT_PILT            0       // Low proximity threshold
#define DEFAULT_PIHT            50      // High proximity threshold
#define DEFAULT_AILT            0xFFFF  // Force interrupt for calibration
#define DEFAULT_AIHT            0
#define DEFAULT_PERS            0x11    // 2 consecutive prox or ALS for int.
#define DEFAULT_CONFIG2         0x01    // No saturation interrupts or LED boost  
#define DEFAULT_CONFIG3         0       // Enable all photodiodes, no SAI
#define DEFAULT_GPENTH          40      // Threshold for entering gesture mode
#define DEFAULT_GEXTH           30      // Threshold for exiting gesture mode    
#define DEFAULT_GCONF1          0x40    // 4 gesture events for int., 1 for exit
#define DEFAULT_GGAIN           GGAIN_4X
#define DEFAULT_GLDRIVE         LED_DRIVE_100MA
#define DEFAULT_GWTIME          GWTIME_2_8MS
#define DEFAULT_GOFFSET         0       // No offset scaling for gesture mode
#define DEFAULT_GPULSE          0xC9    // 32us, 10 pulses
#define DEFAULT_GCONF3          0       // All photodiodes active during gesture
#define DEFAULT_GIEN            0       // Disable gesture interrupts



typedef struct{
    unsigned char mU;
    unsigned char mD;
    unsigned char mL;
    unsigned char mR;
} GFifos;

typedef struct{
    unsigned char   mAddr;
    unsigned char   mReg;
    GFifos          mFifo[32];
} TBuf,*pBuf;

/// 开启APDS-9960 I2c访问 
#define ADPS9960_I2c_En() (I2c_InitM(I2C_SPEED))
/// 停止APDS-9960 I2c访问
#define ADPS9960_I2c_Di() I2c_Di()


///私有 设置寄存器
void pWriteReg(unsigned char reg)
{
    I2c_Start();
    I2c_Write(I2C_WRITE_ADDR(APDS9960_ADDRES));
    I2c_RxAck();
    I2c_Write(reg);
    I2c_RxAck();
}

/// 写字符串到指定寄存器
unsigned APDS9960_WriteReg(unsigned char reg,unsigned len,char* src)
{
    unsigned ret = 0x00;
    DLOGINT(APDS9960_ReadReg,reg);

    ADPS9960_I2c_En();
    ///选择寄存器
    pWriteReg(reg);
    ///发数据 同时判定NAck
    ret = I2c_Writes(len,src);

    I2c_Stop();
    /// 返回发送量
    return ret;
}

unsigned char APDS9960_Reads(unsigned char len,char* dst)
{
    unsigned ret = 0x00;
    I2c_Start();
    I2c_Write(I2C_READ_ADDR(APDS9960_ADDRES));
    I2c_RxAck();
    ret = I2c_Reads(len,dst);
    I2c_Stop();
    return ret;
}

///从指定寄存器中读字符串
unsigned APDS9960_ReadReg(unsigned char reg,unsigned len,char* dst)
{
    unsigned ret = 0x00;
    DLOGINT(APDS9960_ReadReg,reg);

    ADPS9960_I2c_En();
    ///选择寄存器
    pWriteReg(reg);
    ret = APDS9960_Reads(len,dst); 

    I2c_Stop();

    ADPS9960_I2c_Di();   
    return ret;
}

//---------------------------------------------
// 寄存器读取 unsigned char
unsigned char APDS9960_ReadReg8(unsigned char reg)
{
 
    unsigned char val = 0x00;
    APDS9960_ReadReg(reg,1,&val);

    DLOGINT(APDS9960_ReadReg8,val);
    return val;
}
/// 寄存器读取 unsigned short
unsigned short APDS9960_ReadReg16(unsigned char reg)
{
    unsigned short ret = 0x00;
    unsigned char val[2] = {0x00};
    APDS9960_ReadReg(reg,2,&val);
    ret = ((val[1] << 7)|val[0]);

    DLOGINT(APDS9960_ReadReg16,ret);
    return ret;
}
/// 寄存器写 unsigned char
void APDS9960_WriteReg8(unsigned char reg,unsigned char val)
{
    APDS9960_WriteReg(reg,1,&val);
}
/// 寄存器写 unsigned short
void APDS9960_WriteReg16(unsigned char reg,unsigned short val)
{
    unsigned char v[2];
    v[0] = (val >> 7);
    v[1] = val;
    APDS9960_WriteReg(reg,2,&v);

}
//-------------------------------------------------------------
//环境光 及其 中断

/// 环境光线
/**
 * 获取环境光线值
*/
#define APDS9960_Light_Ambient()    APDS9960_ReadReg16(APDS9960_CDATAL)
/**
 * 获取红色环境光线值
*/
#define APDS9960_Light_Red()        APDS9960_ReadReg16(APDS9960_RDATAL)
/**
 * 获取绿色环境光线值
*/
#define APDS9960_Light_Green()      APDS9960_ReadReg16(APDS9960_GDATAL)
/**
 * 获取蓝色环境光线值
*/
#define APDS9960_Light_blue()       APDS9960_ReadReg16(APDS9960_BDATAL)
/**
 * 清理ALS中断
*/
#define APDS9960_ClearCI()          APDS9960_WriteReg8(APDS9960_CICLEAR,0xff)
/**
 * 清理ALS中断
*/
#define APDS9960_ClearPI()          APDS9960_WriteReg8(APDS9960_PICLEAR,0xff)
/**
 * 清理所有非手势中断
*/
#define APDS9960_ClearInt()         APDS9960_WriteReg8(APDS9960_AICLEAR,0xff)

//-------------------------------------------------------------
/// 检测器件
unsigned char APDS9960_Check()
{
    unsigned char mID = APDS9960_ReadReg8(APDS9960_ID);

    switch (mID)
    {
        case APDS9960_ID_1: return 1ul;
        case APDS9960_ID_2: return 1ul;
    }
    return 0ul;
}
/// 获取开启模式

//初始化
void APDS9960_Init()
{
    unsigned char mid=0x00;
    DLOG("APDS9960_Init");
    //
    mid = APDS9960_ReadReg8(APDS9960_ID);
    //DLOGINT(APDS9960_Init,mid);
    mid = APDS9960_ReadReg8(APDS9960_ENABLE);
    //关闭所有
    APDS9960_WriteReg8(APDS9960_ENABLE,0x00);
}

void APDS9960_GestureSensor()
{
    //延时值
    APDS9960_WriteReg8(APDS9960_WTIME,0xff);
    //设置
    APDS9960_WriteReg8(APDS9960_PPULSE,DEFAULT_GESTURE_PPULSE);
    // 设置LED
    APDS9960_WriteReg8(APDS9960_CONFIG2,0xf0);
    // 开启手势中断 设定手势模式
    APDS9960_WriteReg8(APDS9960_GCONF4,0x03);
    // 开启供电
    APDS9960_WriteReg8(APDS9960_ENABLE,0x7f);
}




void APDS9960_ReadGesture()
{
    GFifos buffer[32];
    char* pbuff;
    pbuff = (char*)&buffer;

    unsigned char flevel;
    flevel = APDS9960_ReadReg8(APDS9960_GFLVL);
    APDS9960_ReadReg(APDS9960_GFIFO_U,flevel*4,pbuff);


}