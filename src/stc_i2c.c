/**
 * STC8 测试后部分扩展指令支持存在问题
*/
#include <stcmcu.h>

#include <string.h>

#include <i2c.h>

#define NDEBUG
#include <ext_debug.h>

//#include "../config.h"
#ifdef COMPILE_STC_IIC


/**
 * 时许严谨,禁止占用
*/

#ifdef DEBUG
    #define CheckI2C() _CheckI2C()
#else
    #define CheckI2C()
#endif

#undef DEBUG

//------------------------------------------
/**
 * 模拟方式实现IIC
*/
#define PSDA P01
#define PSCL P02
#define PHigh   1
#define PLow    0

/// 400Khz
#define LOOP1   5
#define LOOP2   6

void Emu_delay()
{
    unsigned char i,j;
    i = LOOP1;
    j = LOOP2;
    do{
        while(--i);
    }while(--j);
}

void Emu_Init()
{
    PSCL = PHigh;
    PSDA = PHigh;
}

void Emu_Start()
{
    PSDA = PHigh;
    PSCL = PHigh;
    Emu_delay();
    PSDA = PLow;
    Emu_delay();
    PSCL = PLow;
}

void Emu_Stop()
{
    PSDA = PLow;
    Emu_delay();
    PSCL = PHigh;
    Emu_delay();
    PSDA = PHigh;
}

unsigned char Emu_Read()
{
    unsigned char c = 0x00;
    for (unsigned char i = 0; i < 8; i++)
    {
        PSCL = PHigh;
        Emu_delay();
        Emu_delay();
        c << = 1;
        c |= PSDA;
        PSCL = PLow;
        Emu_delay();
        Emu_delay();
    }
    return c;
}
void Emu_Write(unsigned char c)
{
    for (unsigned char i = 0; i < 8; i++){
        PSDA = (c & (1 << i))?PHigh:PLow;
        PSCL = PHigh;
        Emu_delay();
        PSCL = PLow;
        Emu_delay();
    }
}

//-----------------------------------------------------------------------------
/**
 * IIC中断向量 0xc3
*/


/**
 * 等待指令执行
 * 私有
*/
void IIC_sfr_Wait()
{
    //if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return;
    while(!(ExtSfrGet8(&I2CMSST) & MSIF));
    ExtSfrClear8(&I2CMSST,MSIF);
}

/**
 * 配置寄存器初始化
 * todo 未实现从机模式
*/
void IIC_sfr_Config(unsigned char op,unsigned char saddr)
{
    DLOGINT(IIC_sfr_Config,op);

    ExtSfrSet8(&I2CCFG,op);
    ExtSfrSet8(&I2CMSST,0x00);
    ExtSfrSet8(&I2CMSAUX,0x00);
    //ExtSfrSet8(&I2CSLADR,saddr);
    //if(!(ExtSfrGet8(&I2CCFG) & IIC_MSSL)){
        //ExtSfrSet8(&I2CSLST,0x00);
        //ExtSfrSet8(&I2CSLCR,0x78);
    //}
}

/**
 * 指令
*/
void IIC_sfr_Command(unsigned char cmd)
{
    cmd &= 0x0F;                                                        //  保留底4位
    ExtSfrSet8(&I2CMSCR,(ExtSfrGet8(&I2CMSCR) & 0xF0)|cmd);             //  执行新指令
    IIC_sfr_Wait();                                                    //  等待执行部完毕
}

/**
 * 字节读
*/
unsigned char IIC_sfr_Read()
{
    IIC_sfr_Command(MSCMD_READ);
    return ExtSfrGet8(&I2CRxD);
}

/**
 * 读字符串
*/
unsigned IIC_sfr_Reads(char * dst,unsigned len)
{
    unsigned r = len;
    if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return 0;

    while(!IIC_sfr_AckI()&&len){
        len--;
        *dst++ = IIC_sfr_Read();
        if(len == 0x00) {
            unsigned char to = (ExtSfrGet8(&I2CMSST) & 0xfe) | 0x01 ; 
            ExtSfrSet8(&I2CMSST,to);
        }
        IIC_sfr_SendAck();
    }
    return (r - len);
}

/**
 * 扩展方式读字符串
*/
unsigned IIC_sfr_ExReads(char * dst,unsigned len)
{
    unsigned r = len;
    if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return 0;

    while(!IIC_sfr_AckI()&&len){
        len--;
        (len)?IIC_sfr_Command(Ext_MSCMD_READACK):IIC_sfr_Command(Ext_MSCMD_READNACK);
        *dst++ = ExtSfrGet8(&I2CRxD);
    }
    return (r - len);
}

/**
 * 字节写
*/
void IIC_sfr_Write(unsigned char c)
{
    DLOGINT(IIC_sfr_Write,c);
    ExtSfrSet8(&I2CTxD,c);
    IIC_sfr_Command(MSCMD_WRITE);
    IIC_sfr_RecvAck();
}

/**
 * 写字符串
*/
unsigned IIC_sfr_Writes(const char* src,unsigned len)
{
    unsigned r = len;
    //if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return 0;
    DLOGINT(IIC_sfr_Writes,len);

    while(!IIC_sfr_AckI()&&len){
        len--;
        IIC_sfr_Write(*src++);
    }
    return (r - len);
}

/**
 * 扩展指令完成写
*/
unsigned IIC_sfr_ExWrites(const char* src,unsigned len)
{
    unsigned r = len;
    //if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return 0;
    DLOGINT(IIC_sfr_ExWrites,len);

    while(!IIC_sfr_AckI()&&len){
        len--;
        ExtSfrSet8(&I2CTxD,*src++);
        IIC_sfr_Command(Ext_MSCMD_WRITE);
    }
    return (r - len);
}

/**
 * 扩展:自动完成写入
*/
unsigned IIC_sfr_ExAuxWrites(const char* src,unsigned len)
{
    unsigned r = len;
    if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return 0;
    
    ExtSfrSet8(&I2CMSAUX,0x01);                     // 扩展使能

    while(!IIC_sfr_AckI()&&len){
        len--;
        ExtSfrSet8(&I2CTxD,*src++);
        IIC_sfr_Wait();                            // 无指令形式,需手动等待
    }
    ExtSfrSet8(&I2CMSAUX,0x00);                     // 关闭扩展
    return (r - len);
}

void IIC_sfr_Start(unsigned char addr)
{
    //DLOGINT(IIC_sfr_Start,addr);
    IIC_sfr_Command(MSCMD_START);
    IIC_sfr_Write(addr);
}

void IIC_sfr_ExStart(unsigned char addr)
{
    //DLOGINT(IIC_sfr_ExStart,addr);
    ExtSfrSet8(&I2CTxD,addr);
    IIC_sfr_Command(Ext_MSCMD_START);
}
//-----------------------------------------------------------------------------
/**
 * 寄存器方式实现
*/
unsigned _IIC_sfr_Writes(sI2c* h,const char* src,unsigned len)
{
    if(h->mFlag & SI2c_Flag_Ext){
        return IIC_sfr_ExWrites(src,len);
    }else{
        return IIC_sfr_Writes(src,len);
    }
    //IIC_sfr_Write(c);
    
}

unsigned _IIC_sfr_Reads(sI2c* h,char* dst,unsigned len)
{
    if(h->mFlag & SI2c_Flag_Ext){
        return IIC_sfr_ExReads(dst,len);
    }else{
        return IIC_sfr_Reads(dst,len);
    }
    //return IIC_sfr_Reads(dst,len);
}

void _IIC_sfr_Disable(sI2c* h)
{
    //DLOGINT(IIC_sfr_Writes,ExtSfrGet8(&I2CCFG));
    if(!(ExtSfrGet8(&I2CCFG) & IIC_ENI2C)) return;

    //DLOGINT(IIC_sfr_Writes,ExtSfrGet8(&I2CMSST));
    if(ExtSfrGet8(&I2CMSST) & MSBUSY){
        //IIC_sfr_Command(MSCMD_STOP);
        IIC_sfr_Command(MSCMD_STOP);
    } 

    IIC_sfr_Config(0x00,0x00);
    
}

void _IIC_sfr_Enable(sI2c* h)
{
    if(ExtSfrGet8(&I2CCFG) & IIC_ENI2C) return;

    P_SW2 |= (h->mSelectPort << 4);

    if(h->mSpeed > 127) h->mSpeed = 127;
    IIC_sfr_InitM(h->mSpeed);
}

void _IIC_sfr_Start(sI2c* h,unsigned char read)
{
    if(h->mFlag & SI2c_Flag_Ext){
        IIC_sfr_ExStart(h->mAddr << 1 | (read & 0x01));
    }else{
        IIC_sfr_Start(h->mAddr << 1 | (read & 0x01));
    }
}
/**
 * 初始化创建
*/
void CreateIICM4Sfr(sI2c *h)
{
    #pragma warning disable 359
    h->mIOs.pWrites = _IIC_sfr_Writes;
    h->mIOs.pReads = _IIC_sfr_Reads;

    h->pStart = _IIC_sfr_Start;
    //h->pCommand = _IIC_sfr_Command;

    h->pEnable = _IIC_sfr_Enable;
    h->pDisable = _IIC_sfr_Disable;


    //h->pReadReg8 = _IIC_ReadMem8;
    //h->pWriteReg8 = _IIC_WriteMem8;
    //todo 端口电阻初始化
    #pragma warning enable 359
}


//----------------------------------------------

///

//-----------------------------------------------------------------------------
// 通用方法
/**
 * 读取8位寄存器
*/
unsigned char IIC_ReadMem8(sI2c* h,unsigned char reg)
{
    unsigned char r = 0x00;
    h->pEnable(h);
    h->pStart(h,0x00);
    h->mIOs.pWrites(h,&reg,1);
    h->pStart(h,0x01);
    h->mIOs.pReads(h,&r,1);
    h->pDisable(h);
    return r;
}


/**
 * 写入8位
*/
void IIC_WriteMem8(sI2c* h,unsigned char reg,unsigned char v)
{
    unsigned char wbuf[2]={0x00};
    
    wbuf[0]=reg;
    wbuf[1]=v;
    h->pEnable(h);
    h->pStart(h,0x00);
    h->mIOs.pWrites(h,&wbuf,2);
    h->pDisable(h);
}

/**
 * 连续写寄存器
*/
unsigned IIC_WriteMem(sI2c* h,unsigned char reg,const char *src,unsigned len)
{
    unsigned r = 0x00;
    //wbuf[0] = reg;
    //wbuf[1] = 
    h->pEnable(h);
    h->pStart(h,0x00);
    h->mIOs.pWrites(h,&reg,1);
    r = h->mIOs.pWrites(h,src,len);
    h->pDisable(h);
    return r;
}

/**
 * 连续读取寄存器
*/
unsigned IIC_ReadMem(sI2c* h,unsigned char reg,char *dst,unsigned len)
{
    unsigned r = 0x00;
    h->pEnable(h);
    h->pStart(h,0x00);
    h->mIOs.pWrites(h,&reg,1);
    h->pStart(h,0x01);
    r = h->mIOs.pReads(h,dst,len);
    h->pDisable(h);
    return r;
}

/**
 * 
*/
unsigned short IIC_ReadShort(sI2c* h,unsigned char reg)
{
    unsigned char buf[2] = {0x00};
    if(IIC_ReadMem(h,reg,&buf,2) == 2){
        return (unsigned short)((buf[1] << 8)|(buf[0]));
    };
    return 0;
}

void IIC_WriteShort(sI2c* h,unsigned char reg,unsigned short v)
{
    unsigned char buf[2] = {0x00};

    buf[0] = v & 0xff;
    buf[1] = (v >> 8);

    IIC_WriteMem(h,reg,&buf,2);

}

#endif //COMPILE_STC_IIC