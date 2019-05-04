
//#include <stcmcu.h>

#include "apds9660.h"
#include <i2c.h>
#include <ext_debug.h>


#ifndef APDS9960_ADDRES
#define APDS9960_ADDRES 0x39
#endif
#ifndef I2C_SPEED
#define I2C_SPEED 0x30
#endif

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

struct TStatus
{
    ///
    unsigned mI2c:1;
    unsigned mBusy:1;
} Status={0x00};
///复位状态
#define ClearStatus() do{*((char*)&Status)=0x00;}while(0)


/// 开启APDS-9960 I2c访问
unsigned char ADPS9960_I2c_En()
{
    DLOG("ADPS9960_I2c_En");
    if(I2c_InitM(I2C_SPEED)==0){
        ELOG("ADPS9960_I2c_En");
        return (-1);
    } 
    Status.mI2c = 1;
    return 0x00;
}
/// 停止APDS-9960 I2c访问
unsigned char ADPS9960_I2c_Di()
{
    if(Status.mBusy) return (-1);
    //释放I2c总线
    I2c_Di();
    return (-1);
}
///私有 设置寄存器
void pSelectReg(unsigned char addr,unsigned char reg)
{
    DLOG("pSelectReg");
    Status.mBusy = 1;
    /// 发送地址
    I2c_Start();
    I2c_Write(addr);
    I2c_RxAck();
    I2c_Write(reg);
    I2c_RxAck();
    
}

/// 写字符串到指定寄存器
unsigned APDS9960_WriteReg(unsigned char reg,unsigned len,char* src)
{
    DLOG("APDS9960_WriteReg");
    
    unsigned ret = 0x00;
    ///选择寄存器
    pSelectReg(I2C_WRITE_ADDR(APDS9960_ADDRES),reg);
    //I2c_Ext_Start(I2C_WRITE_ADDR(APDS9960_ADDRES));
    //I2c_StartAddr(I2C_WRITE_ADDR(APDS9960_ADDRES));
    //I2c_Ext_StartReg(I2C_WRITE_ADDR(APDS9960_ADDRES),0x66);
    ///发数据 同时判定NAck
    //ret = I2c_Ext_Writes(len,src);
    ret = I2c_Writes(len,src);
    /*
    while((!I2c_NAckStatus())&&(len--)){
        I2c_SetBuf(*src++);
        I2c_Cmd(Ext_MSCMD_WRITE);
    }
    */
    I2c_Stop();
    /// 返回发送量
    return ret;
}

unsigned char APDS9960_Reads(unsigned char len,char* dst)
{
    DLOG("APDS9960_Reads");
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
    DLOG("APDS9960_ReadReg");
    unsigned ret = 0x00;
    
    ///选择寄存器
    pSelectReg(reg);
    ///重发Start
    I2c_Start();
    I2c_Write(I2C_WRITE_ADDR(APDS9960_ADDRES));
    I2c_RxAck();
    ret = I2c_Reads(len,dst);
    ///停止
    I2c_Stop();
    
    return ret;
}

//---------------------------------------------
// 寄存器读取 unsigned char
unsigned char APDS9960_ReadReg8(unsigned char reg)
{
    DLOG("APDS9960_ReadReg8");
    unsigned char val = 0x00;
    
    APDS9960_ReadReg(reg,1,&val);

    return val;
}
/// 寄存器读取 unsigned short
unsigned short APDS9960_ReadReg16(unsigned char reg)
{
    unsigned char val[2] = {0x00};

    APDS9960_ReadReg(reg,2,&val);
 
    return ((val[1] << 7)|val[0]);
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
char APDS9960_Check()
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

void APDS9960_Init()
{
    unsigned char mid=0x00;
    DLOG("APDS9960_Init:");
    //
    mid = APDS9960_ReadReg8(APDS9960_ID);
    //DLOGINT(APDS9960_Init,mid);
    //关闭所有
    //APDS9960_WriteReg8(APDS9960_ENABLE,0x00);
#ifdef DEBUG
    //printf("%s\t%d:APDS9960_ENABLE(%d):%d",__FILE__,__LINE__,APDS9960_ENABLE,APDS9960_ReadReg8(APDS9960_ENABLE));
#endif
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