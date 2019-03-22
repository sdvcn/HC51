#include <stcmcu.h>


static void InitSPI(void)
{
    P0= 0xf1;
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