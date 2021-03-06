
/**
 * Apds-9960 操作封装
 * 采用I2c方案
*/
#include <stcmcu.h>
#include <i2c.h>
#include <ext_debug.h>
#include "apds9660.h"
//#include "../../config.h"

#ifdef COMPILE_EXT_APDS9960

/**
 * 内置宏
*/
#ifndef NDEBUG
#define DumpReg(_f,_v) (printf("[%s:%d]\tTracert:%s[%s:0x%2.2X|%u]\n",__FILE__,__LINE__,_f,#_v,_v,_v))
#else
#define DumpReg(_f,_r,_v)
#endif

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

/* LED Drive values */
#define LED_DRIVE_100MA         0
#define LED_DRIVE_50MA          1
#define LED_DRIVE_25MA          2
#define LED_DRIVE_12_5MA        3
/* Proximity Gain (PGAIN) values */
#define PGAIN_1X                0
#define PGAIN_2X                1
#define PGAIN_4X                2
#define PGAIN_8X 3
/* ALS Gain (AGAIN) values */
#define AGAIN_1X                0
#define AGAIN_4X                1
#define AGAIN_16X               2
#define AGAIN_64X               3
/* Gesture Gain (GGAIN) values */
#define GGAIN_1X                0
#define GGAIN_2X                1
#define GGAIN_4X                2
#define GGAIN_8X                3
/* LED Boost values */
#define LED_BOOST_100           0
#define LED_BOOST_150           1
#define LED_BOOST_200           2
#define LED_BOOST_300           3    

/* Gesture wait time values */
#define GWTIME_0MS              0
#define GWTIME_2_8MS            1
#define GWTIME_5_6MS            2
#define GWTIME_8_4MS            3
#define GWTIME_14_0MS           4
#define GWTIME_22_4MS           5
#define GWTIME_30_8MS           6
#define GWTIME_39_2MS           7

//-----------------------------------------------------------------------------
// 通用

/**
 * 数据结构
*/
typedef struct _R9960Data
{
    unsigned char mDeviceID;
    unsigned char mStatus;
    union 
    {
        struct 
        {
            unsigned char mClearL;
            unsigned char mClearH;
        };
        unsigned short mClear;
    };
    union 
    {
        struct 
        {
            unsigned char mRedL;
            unsigned char mRedH;
        };
        unsigned short mRed;
    };
    union 
    {
        struct 
        {
            unsigned char mGreenL;
            unsigned char mGreenH;
        };
        unsigned short mGreen;
    };
    union 
    {
        struct 
        {
            unsigned char mBlueL;
            unsigned char mBlueH;
        };
        unsigned short mBlue;
    };
    unsigned char mProximity;
    //unsigned short 
}R9960Data;

typedef struct _R9960FIFO
{
    unsigned char   mUp;
    unsigned char   mDown;
    unsigned char   mLeft;
    unsigned char   mRight;
}R9960FIFO;

void Apds_Dump(sI2c* h)
{
    R9960Data rd;
    IIC_ReadMem(h,0x92,(void*)&rd,sizeof(R9960Data));
    //DumpReg("DUMP",rd.mDeviceID);
    DumpReg("DUMP",rd.mStatus);

    //DumpReg("DUMP",rd.mClearL);
    //DumpReg("DUMP",rd.mClearH);
    DumpReg("DUMP",rd.mClear);

    //DumpReg("DUMP",rd.mRedL);
    //DumpReg("DUMP",rd.mRedH);
    DumpReg("DUMP",rd.mRed);

    //DumpReg("DUMP",rd.mGreenL);
    //DumpReg("DUMP",rd.mGreenH);
    DumpReg("DUMP",rd.mGreen);

    //DumpReg("DUMP",rd.mBlueL);
    //DumpReg("DUMP",rd.mBlueH);
    DumpReg("DUMP",rd.mBlue);

    DumpReg("DUMP",rd.mProximity);
    //DLOGINT()
}

void ApdsGetFifo(sI2c* h)
{
    unsigned fifolen = APDS9960_GetGFLVL(h);

}

/**
 * 验证器件
*/
unsigned char ApdsCheckID(sI2c* h)
{
    switch (IIC_ReadMem8(h,APDS9960_ID))
    {
        case APDS9960_ID_1: return 1ul;
        case APDS9960_ID_2: return 1ul;
    }
    return 0ul;
}

void Apds9960_Init(sI2c* h)
{

    //APDS9960_SetATIME(h,DEFAULT_ATIME);
    

}

/**
 * 获取状态
*/

/**
 * 器件休眠
*/

//-----------------------------------------------------------------------------
/**
 * 中断向量
*/
void Apds_irsSW(sI2c* h)
{
    unsigned char status = APDS9960_GetSTATUS(h);
    DLOGINT(GetSTATUS,status);
    if(CheckBIT(status,7))
    {
        assert(0);
        APDS9960_ClearCI(h);
        while(!APDS9960_GetAVALID(h));
        Apds_Dump(h);
    }


    if(APDS9960_GetPINT(h)){
        assert(0);
        APDS9960_ClearPI(h);
        DLOGINT(GetSTATUS,APDS9960_GetCONFIG2(h));
        DLOGINT(GetSTATUS,APDS9960_GetSTATUS(h));
    }
    if(APDS9960_GetAINT(h))
    {
        assert(0);
        APDS9960_ClearAI(h);
        
        while(!APDS9960_GetAVALID(h));
        Apds_Dump(h);

        DLOGINT(GetSTATUS,APDS9960_GetSTATUS(h));
    }
    APDS9960_ClearGFIFO(h);
}

//-----------------------------------------------------------------------------
/**
 * 手势识别
*/

/**
 * 颜色传感器
*/

/**
 * 环境光传感器
*/
void Apds_InitALS(sI2c *h)
{
    APDS9960_ClearENABLE(h);

    APDS9960_SetATIME(h,182);

    DumpReg("DUMP",APDS9960_GetAILT(h));
    DumpReg("DUMP",APDS9960_GetAIHT(h));

    APDS9960_SetAILT(h,1000);
    APDS9960_SetAIHT(h,20000);

    APDS9960_SetAPRES(h,0x0f);
    
    //APDS9960_SetAGAIN(h,0x01);
    APDS9960_SetCPSIEN(h,0x01);

    APDS9960_SetENABLE(h,BIT_AIEN|BIT_WEN|BIT_AEN|BIT_PON);
}

//-----------------------------------------------------------------------------
/**
 * 距离传感器
*/


















#ifdef AAC

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

//sI2c ApdsI2c;

static sI2c* pmio;

void Apds9960_Init(sApds9960* pApds)
{
    //pApds->mIOs.pRead

}

void Apds9960_SetIIC(sApds9960* pApds,sI2c* pmio)
{
    //(sI2c*)(pApds->mApdsIO) = pmio;
}


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
    //DLOGINT(_WriteReg,reg);
    //DLOGINT(_WriteReg,len);
    DLOGINT(S_WriteReg,reg);
    Console_DumpHex(len,src);
    

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
    //DLOGINT(_ReadReg,reg);
    //DLOGINT(_ReadReg,len);

    ADPS9960_I2c_En();
    ///选择寄存器
    pWriteReg(reg);
    ret = APDS9960_Reads(len,dst); 
    ADPS9960_I2c_Di();
    
    DLOGINT(E_ReadReg,reg);
    Console_DumpHex(ret,dst);
    return ret;
}

//---------------------------------------------
// 寄存器读取 unsigned char
unsigned char APDS9960_ReadReg8(unsigned char reg)
{
 
    unsigned char val = 0x00;
    APDS9960_ReadReg(reg,1,&val);
    //DLOGINT(_ReadReg8,val);
    DumpReg("E_ReadReg8",reg,val);
    return val;
}
/// 寄存器读取 unsigned short

unsigned short APDS9960_ReadReg16(unsigned char reg)
{
    unsigned short ret = 0x00;
    unsigned char val[2] = {0x00};
    APDS9960_ReadReg(reg,2,&val);
    ret = ((val[1] << 8)|val[0]);

    //DLOGINT(_ReadReg16,ret);
    //DLOGINT(_ReadReg16,val[0]);
    //DLOGINT(_ReadReg16,val[1]);
    DumpReg("E_ReadReg16",reg,val);
    return ret;
}

/// 寄存器写 unsigned char
void APDS9960_WriteReg8(unsigned char reg,unsigned char val)
{
    //DLOGINT(_WriteReg8,val);
    DumpReg("S_ReadReg8",reg,val);
    APDS9960_WriteReg(reg,1,&val);
}
/// 寄存器写 unsigned short

void APDS9960_WriteReg16(unsigned char reg,unsigned short val)
{
    //DLOGINT(_WriteReg16,val);
    DumpReg("S_ReadReg16",reg,val);
    unsigned char v[2];
    //v[0] = (val >> 8);
    //v[1] = val;
    v[0] = (val & 0x00ff);
    v[1] = (val & 0xff00) >> 8;
    //DLOGINT(_WriteReg16,v[0]);
    //DLOGINT(_WriteReg16,v[1]);
    APDS9960_WriteReg(reg,2,&v);

}

//-----------------------------------------------------------------------------
/**
 * 开启手势识别
*/
void APDS9960_EnableGestureSensor(unsigned char itr)
{
    DLOG("APDS9960_EnableGestureSensor()");

    APDS9960_WriteReg8(APDS9960_WTIME,0xff);

    APDS9960_WriteReg8(APDS9960_PPULSE,DEFAULT_GESTURE_PPULSE);

    /// 增强
    APDS9960_LedBoost(LED_BOOST_100);
    /// 红外线电流
    APDS9960_SetGLDRIVE(1);

    if(itr){
        APDS9960_SetGIEN(1);
    }else{
        APDS9960_SetGIEN(0);
    }

    APDS9960_SetGMODE(1);

    APDS9960_SetPON(1);

    APDS9960_SetWEN(1);

    APDS9960_SetPEN(1);

    APDS9960_SetGEN(1);
}

void APDS9960_DisableGestureSensor()
{
    DLOG("APDS9960_DisableGestureSensor()");
    APDS9960_SetGIEN(0)
    APDS9960_SetGMODE(0);
    APDS9960_SetGEN(0);
}
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

    APDS9960_WriteReg8(APDS9960_CONFIG3,DEFAULT_CONFIG3);

    APDS9960_SetGestureEnterThresh(DEFAULT_GPENTH);

    APDS9960_SetGestureExitThresh(DEFAULT_GEXTH);

    APDS9960_WriteReg8(APDS9960_GCONF1,DEFAULT_GCONF1);

    APDS9960_SetGGAIN(DEFAULT_GGAIN);

    APDS9960_SetGLDRIVE(DEFAULT_GLDRIVE);

    APDS9960_SetGWTIME(DEFAULT_GWTIME);

    // 手势偏移
    APDS9960_WriteReg8(APDS9960_GOFFSET_U,DEFAULT_GOFFSET);
    APDS9960_WriteReg8(APDS9960_GOFFSET_D,DEFAULT_GOFFSET);
    APDS9960_WriteReg8(APDS9960_GOFFSET_L,DEFAULT_GOFFSET);
    APDS9960_WriteReg8(APDS9960_GOFFSET_R,DEFAULT_GOFFSET);

    APDS9960_WriteReg8(APDS9960_GPULSE,DEFAULT_GPULSE);

    APDS9960_WriteReg8(APDS9960_GCONF3,DEFAULT_GCONF3);

    APDS9960_SetGIEN(DEFAULT_GIEN);

    //APDS9960_GCONF4

    //----
}



unsigned char APDS9960_ReadGesture()
{
    DLOG("ReadGesture()");

    if(!APDS9960_GetGVALID()){
        return 0x00;
    }

    unsigned char ret = 0x00;
    //unsigned char bup[32*4];
    unsigned char flevel = APDS9960_ReadReg8(APDS9960_GFLVL);
    //DLOGINT(_ReadGesture,flevel);
    DumpReg("ReadGesture:GFLVL",APDS9960_GFLVL,flevel);

    //while(I2c_NAckStatus())
    if(flevel) ret = APDS9960_ReadReg(APDS9960_GFIFO_U,32*4,(char*)fifoBuf);
    Console_DumpHex(ret,(char*)fifoBuf);
    return ret;
}



#endif 
#endif //COMPILE_EXT_APDS9960