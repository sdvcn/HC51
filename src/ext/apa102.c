#include <stcmcu.h>
#include <i2c.h>
#include "apa102.h"
#include "../../config.h"


#ifdef COMPILE_EXT_APA102

void _iicWrite(unsigned char c)
{
    ExtSfrSet8(&I2CTxD,c);
    IIC_sfr_Command(MSCMD_WRITE);
}

void apa102Gen(papa102 src,unsigned len)
{

    while(len--)
    {
        src->mGlobal = 0xe0;
        src->mBlue = 0x00;
        src->mGreen = 0x00;
        src->mRed   = 0x00;
        src++;
    }
}



void _EmuWrite(volatile char c)
{
    unsigned char i = 0x08;
    do{
        APA102IOCI = 0;
        c <<= 1;
        //_delay(1);
        APA102IODI = CY;
        //_delay(3);
        APA102IOCI = 1;
        //_delay(3);
    }while(--i);
}

void apa102WriteEmu(const papa102 src,unsigned len)
{
    len *= sizeof(apa102);
    char * psrc = (char*)src;
    //volatile unsigned char c;
    APA102IOCI = 1;
    _EmuWrite(0x00);
    _EmuWrite(0x00);
    _EmuWrite(0x00);
    _EmuWrite(0x00);


    do{
        unsigned char i = 0x08;
        //c = *psrc++;
        _EmuWrite(*psrc++);
    }while(--len);  
    _EmuWrite(0xff); 
    _EmuWrite(0xff); 
    _EmuWrite(0xff); 
    _EmuWrite(0xff); 

}

void apa102Write4iic(const papa102 src,unsigned len)
{
    len = len * sizeof(apa102);
    char * psrc = (char*)src;

    // heard
    IIC_sfr_InitM(0x00);
    IIC_sfr_Command(MSCMD_START);
    _iicWrite(0x00);
    _iicWrite(0x00);
    _iicWrite(0x00);
    _iicWrite(0x00);
    // body
    while(len--)
    {
        _iicWrite(*psrc++);
    }
    // end
    _iicWrite(0xff);
    _iicWrite(0xff);
    _iicWrite(0xff);
    _iicWrite(0xff);
    IIC_sfr_Command(MSCMD_STOP);
    IIC_sfr_Disable();
}

#endif //COMPILE_EXT_APA102