
/*
    实现杂项功能部分
*/
#include <stcmcu.h>

//实现延时功能
void DelayUs_Y1(ushort v)
{
	_delay(v);
}

void DelayUs_Y3(ushort v)
{
	_delay(v);
}

void DelayUs_Y5(ushort v)
{
	_delay(v);
}

void DelayUs_Y6(ushort v)
{
	_delay(v);
}

//STC8 扩展
#ifdef STC8

unsigned char ExtSfrGet(unsigned short addr){
    En_EAXFR();
    unsigned char r = (*(unsigned char volatile xdata *)addr);
    Di_EAXFR();
    return r;
}

void ExtSfrSet(unsigned short addr,unsigned char nv){
    En_EAXFR();
    (*(unsigned char volatile xdata *)addr) = nv;
    Di_EAXFR();
    
}
#endif