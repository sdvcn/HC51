#include <string.h>
#include <stcmcu.h>

#include <ext_debug.h>
#include <spi.h>

///模拟方式实现spi
void SPI_sfr_Config(unsigned char c)
{
    SPCTL = c;
    SPSTAT = 0xc0;
}




void CreateSPI4Sfr(void *mio,unsigned char op)
{
    //assert(sizeof(sSPI)==sizeof(BaseIO));
    //memset(mio,0x00,sizeof(BaseIO));                     //重置
}