#include <stcmcu.h>

enum{
    MSCMD_NONE    = 0b0000,
    MSCMD_START   = 0b0001,
    MSCMD_WRITE   = 0b0010,
    MSCMD_RACK    = 0b0011,
    MSCMD_READ    = 0b0100,
    MSCMD_TACK    = 0b0101,
    MSCMD_STOP    = 0b0110,
};
//MSCMDEXT

bool I2c_Busy()
{
    return (I2CMSST & MSBUSY) ? 1ul:0ul;
}

bool I2c_CFG(unsigned char op)
{
    if(I2CMSST & MSBUSY) return 0ul;
    I2CCFG = op;
    //I2CCFG = 0x00;
    //_delay(10);
    //I2CCFG = 0xe0;
    I2CMSST = 0x00;
    return 1ul;
}

void I2c_Wait()
{
    //_delay(10);
    while(!(I2CMSST & MSIF));
    I2CMSST &= ~MSIF;
    //_delay(10);
}

void I2c_Start()
{
    I2CMSCR = MSCMD_START;
    I2c_Wait();
}

void I2c_Write(unsigned char c)
{
    I2CTxD = c;
    I2CMSCR = MSCMD_WRITE;
    I2c_Wait();
}

void I2c_RxAck()
{
    I2CMSCR = MSCMD_RACK;
    I2c_Wait();
}

unsigned char I2c_Read()
{
    I2CMSCR = MSCMD_READ;
    I2c_Wait();
    return I2CRxD;
}

void I2c_TxAck()
{
    I2CMSST = 0x00;
    I2CMSCR = MSCMD_TACK;
    I2c_Wait();
}

void I2c_TxNAck()
{
    I2CMSST = 0x01;
    I2CMSCR = MSCMD_TACK;
    I2c_Wait();
}

void I2c_Stop()
{
    I2CMSCR = MSCMD_STOP;

    I2c_Wait();
    
}




/*
bool I2c_Reads(unsigned char addr,unsigned char len,char* dst)
{
    if(I2CMSST & MSBUSY) return false;
    I2c_Start();
    I2c_Write(RAddr(addr));
    I2c_RxAck();

    while(len--){
        *dst++ = I2c_Read();
        I2c_TxAck();
    }
    I2c_Stop();
    return true;
}

bool I2c_Writes(unsigned char addr,unsigned char len,char* src)
{
    if(I2CMSST & MSBUSY) return false;
    I2c_Start();
    I2c_Write(WAddr(addr));
    I2c_RxAck();
    while(len--){
        
    }
    


    return true;
}
*/