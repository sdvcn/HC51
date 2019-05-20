#include <string.h>
#include <stcmcu.h>

#include <ext_debug.h>
#include <spi.h>


static void InitSPI(void)
{
    
}

//写字节
void SpiWrite(unsigned char v)
{
    InitSPI();
}

///写组
void SpiWrites(char* buf,unsigned short len)
{

}
///读字节
void SpiRead()
{

}
///读组
void SpiReads(char* buf,unsigned short len)
{

}

///模拟方式实现spi


void CreateSPI4Sfr(void *mio,unsigned char op)
{
    //assert(sizeof(sSPI)==sizeof(BaseIO));
    //memset(mio,0x00,sizeof(BaseIO));                     //重置
}