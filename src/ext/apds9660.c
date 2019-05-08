
/**
 * Apds-9960 操作封装
 * 采用I2c方案
*/

#include <i2c.h>
#include <ext_debug.h>
#include "apds9660.h"
/**
 * 内置宏
*/

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
/* Acceptable device IDs */
#define APDS9960_ID_1           0xAB        //ADPS-9960
#define APDS9960_ID_2           0x9C 





/**
 * 获取器件ID
 * 0xAB APDS-9960
*/
//#define APDS9960_GetID()            APDS9960_ReadReg8(APDS9960_ID)

/**
 * 检查器件ID
 * _v=APDS9960_ID_1 (APDS-9960 ID)
 * _v=APDS9960_ID_2
*/
//#define APDS9960_Check(_v)            (APDS9960_GetID()==(_v))

// 关闭主电源
//#define D_Power(_v)          APDS9960_WriteReg8(APDS9960_ENABLE,_v)
//#define D_PowerOFF()         D_Power(0x00)
//#define D_GetPower()

/**
 * 清理ALS中断
 * APDS9960_CICLEAR 寄存器写入任意值
*/
#define D_ClearCI()          APDS9960_WriteReg8(APDS9960_CICLEAR,0xff)
/**
 * 清理ALS中断
 * APDS9960_PICLEAR 寄存器写入任意值
*/
#define D_ClearPI()          APDS9960_WriteReg8(APDS9960_PICLEAR,0xff)
/**
 * 清理所有非手势中断
*/
#define D_ClearInt()         APDS9960_WriteReg8(APDS9960_AICLEAR,0xff)
//-----------------------------------------------------------------------------
#define DBitModify(_o,_f,_v) 

typedef struct{
    unsigned char mU;
    unsigned char mD;
    unsigned char mL;
    unsigned char mR;
} GFifos;

xdata static GFifos fifoBuf[32];


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
    DLOGINT(_WriteReg,reg);
    DLOGINT(_WriteReg,len);

    ADPS9960_I2c_En();
    ///选择寄存器
    pWriteReg(reg);
    ///发数据 同时判定NAck
    ret = I2c_Writes(len,src);

    I2c_Stop();
    ADPS9960_I2c_Di();
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
unsigned char APDS9960_ReadReg(unsigned char reg,unsigned len,char* dst)
{
    unsigned ret = 0x00;
    DLOGINT(_ReadReg,reg);
    DLOGINT(_ReadReg,len);

    ADPS9960_I2c_En();
    ///选择寄存器
    pWriteReg(reg);
    ret = APDS9960_Reads(len,dst); 
    ADPS9960_I2c_Di();   
    return ret;
}

//---------------------------------------------
// 寄存器读取 unsigned char
unsigned char APDS9960_ReadReg8(unsigned char reg)
{
 
    unsigned char val = 0x00;
    APDS9960_ReadReg(reg,1,&val);

    DLOGINT(_ReadReg8,val);
    return val;
}
/// 寄存器读取 unsigned short

unsigned short APDS9960_ReadReg16(unsigned char reg)
{
    unsigned short ret = 0x00;
    unsigned char val[2] = {0x00};
    APDS9960_ReadReg(reg,2,&val);
    ret = ((val[1] << 8)|val[0]);

    DLOGINT(_ReadReg16,ret);
    DLOGINT(_ReadReg16,val[0]);
    DLOGINT(_ReadReg16,val[1]);
    return ret;
}

/// 寄存器写 unsigned char
void APDS9960_WriteReg8(unsigned char reg,unsigned char val)
{
    DLOGINT(_WriteReg8,val);
    APDS9960_WriteReg(reg,1,&val);
}
/// 寄存器写 unsigned short

void APDS9960_WriteReg16(unsigned char reg,unsigned short val)
{
    DLOGINT(_WriteReg16,val);
    unsigned char v[2];
    //v[0] = (val >> 8);
    //v[1] = val;
    v[0] = (val & 0x00ff);
    v[1] = (val & 0xff00) >> 8;
    DLOGINT(_WriteReg16,v[0]);
    DLOGINT(_WriteReg16,v[1]);
    APDS9960_WriteReg(reg,2,&v);

}

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------

/// 获取开启模式

/**
 * 初始化 9960
 * >关闭所有
 * >设定环境光源默认值
*/
void APDS9960_Init()
{
    unsigned r=0x00;
    DLOG("APDS9960_Init");

    // 检查器件ID
    r = APDS9960_ReadReg8(APDS9960_ID);
    if(!(r == APDS9960_ID_1)||(r == APDS9960_ID_2)){
        DLOG("No found Apds-9960 for I2c");
    }

    // Reset APDS9960
    APDS9960_WriteReg8(APDS9960_ENABLE,0x00);
    r = APDS9960_ReadReg8(APDS9960_ENABLE);
    if(!(r == 0x00)){
        DLOG("No Reset Apds9960");
    }
    
    // 环境延时
    APDS9960_WriteReg8(APDS9960_ATIME,DEFAULT_ATIME);

    APDS9960_WriteReg8(APDS9960_WTIME,DEFAULT_WTIME);
    
    APDS9960_WriteReg8(APDS9960_PPULSE,DEFAULT_PROX_PPULSE);

    APDS9960_WriteReg8(APDS9960_POFFSET_UR,DEFAULT_POFFSET_UR);

    APDS9960_WriteReg8(APDS9960_POFFSET_DL,DEFAULT_POFFSET_DL);

    APDS9960_WriteReg8(APDS9960_CONFIG1,DEFAULT_CONFIG1);

    // LED 工作电流
    APDS9960_LedDrive(DEFAULT_LDRIVE);

    //接近传感器增益
    APDS9960_SetProximityGain(DEFAULT_PGAIN);

    APDS9960_SetAmbientLightGain(DEFAULT_AGAIN);

    /// 距离传感器
    DLOG("Thresh");
    APDS9960_SetProxIntLowThresh(DEFAULT_PILT);

    APDS9960_SetProxIntHighThresh(DEFAULT_PIHT);

    /// 光线传感器
    DLOG("Threshold");
    APDS9960_SetLightIntLowThreshold(DEFAULT_AILT);

    APDS9960_SetLightIntHighThreshold(DEFAULT_AIHT);

    /// 循环测试数量
    //APDS9960_WriteReg8(APDS9960_PERS,DEFAULT_PERS);
    DLOG("PERS");
    APDS9960_SetPPERS(0x01);
    APDS9960_SetAPRES(0x01);



    
    APDS9960_WriteReg8(APDS9960_CONFIG2,DEFAULT_CONFIG2);

    //----

    r = APDS9960_GetLightIntLowThreshold();
    
    DLOGINT(_GetLightIntLowThreshold,r);

    r = APDS9960_ReadReg8(APDS9960_AILTL);
    DLOGINT(AAPDS9960_PILT,r);
    r = APDS9960_ReadReg8(APDS9960_AILTH);
    DLOGINT(AAPDS9960_PIHT,r);

}

void APDS9960_GestureSensor()
{
    DLOG("APDS9960_GestureSensor()");

    //D_PowerOFF();
    APDS9960_WriteReg8(APDS9960_ENABLE,0x00);
    //延时值
    APDS9960_WriteReg8(APDS9960_WTIME,0xff);
    //设置
    APDS9960_WriteReg8(APDS9960_PPULSE,DEFAULT_GESTURE_PPULSE);
    // 设置LED
    //APDS9960_WriteReg8(APDS9960_CONFIG2,0xf0);
    APDS9960_LedBoost(3u);
    // 开启手势中断 设定手势模式
    APDS9960_WriteReg8(APDS9960_GCONF4,0x03);
    // 开启供电
    APDS9960_WriteReg8(APDS9960_ENABLE,0x7f);
    
}



unsigned char APDS9960_ReadGesture()
{
    unsigned char ret = 0x00;
    //unsigned char bup[32*4];
    unsigned char flevel = APDS9960_ReadReg8(APDS9960_GFLVL);
    DLOGINT(_ReadGesture,flevel);

    //while(I2c_NAckStatus())
    if(flevel) ret = APDS9960_ReadReg(APDS9960_GFIFO_U,32*4,(char*)&fifoBuf);
    DLOGINT(_ReadGesture,ret);
    return ret;
}

//#define LEDA(_v) ((_v & 0x03) << 4)

