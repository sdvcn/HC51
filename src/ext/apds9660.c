/*
apds 9660
*/

#include <stcmcu.h>

#include "apds9660.h"


#ifndef APDS9960_ADDRES
#define APDS9960_ADDRES 0x39
#endif
#ifndef I2C_SPEED
#define I2C_SPEED 0x3f
#endif

#define RAddr(_addr) ((_addr << 1) | 1ul)
#define WAddr(_addr) ((_addr << 1) | 0ul)

///写
void APDS9960_Write(unsigned char reg,unsigned len,char* src)
{
    if(I2c_InitM(I2C_SPEED)==0) return;

    I2c_Start();
    I2c_Write(WAddr(APDS9960_ADDRES));
    I2c_RxAck();
    I2c_Write(reg);
    I2c_RxAck();
    while(len--){
        I2c_Write(*src++);
        I2c_RxAck();
    }
    I2c_Stop();

    I2c_Di();
}


void APDS9960_Read(unsigned len,char* dst)
{
    if(I2c_InitM(I2C_SPEED)==0) return;

    I2c_Start();
    I2c_Write(RAddr(APDS9960_ADDRES));
    I2c_RxAck();
    while(len--){
        *dst++ = I2c_Read();
        I2c_TxAck();
    }
    I2c_Stop();

    I2c_Di();
}

void APDS9960_ReadReg(unsigned char reg,unsigned len,char* dst)
{
    if(I2c_InitM(I2C_SPEED)==0) return;

    I2c_Start();
    I2c_Write(WAddr(APDS9960_ADDRES));
    I2c_RxAck();
    I2c_Write(reg);
    I2c_RxAck();

    I2c_Start();        //ReStart
    I2c_Write(RAddr(APDS9960_ADDRES));
    I2c_RxAck();

    while(len--){
        *dst++ = I2c_Read();
        I2c_TxAck();
    }
    I2c_Stop();

    I2c_Di();
}

//-----------------

//-----------------
/// 寄存器读取 unsigned char
unsigned char APDS9960_ReadReg8(unsigned char reg)
{
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
    APDS9960_Write(reg,1,&val);
}
/// 寄存器写 unsigned short
void APDS9960_WriteReg16(unsigned char reg,unsigned short val)
{
    unsigned char v[2];
    v[0] = (val >> 7);
    v[1] = val;
    APDS9960_Write(reg,2,&v);

}

/// 检测器件
bool APDS9960_Check()
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
unsigned char APDS9960_GetMode()
{
    unsigned char enop = 0x00;
    APDS9960_ReadReg(APDS9960_ENABLE,1,&enop);
    return enop;    
}

void APDS9960_SetMode(unsigned char op)
{

}

void APDS9960_Init()
{
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


typedef struct{
    unsigned char mU;
    unsigned char mD;
    unsigned char mL;
    unsigned char mR;
} GFifos;

void APDS9960_ReadGesture()
{
    GFifos buffer[32];
    GFifos* pbuff;
    pbuff = &buffer;

    while(APDS9960_ReadReg8(APDS9960_GFLVL))
    {

    }
}