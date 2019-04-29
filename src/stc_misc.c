
/*
    实现杂项功能部分
*/
#include <stcmcu.h>

//实现延时功能

//STC8 扩展
#ifdef STC8

unsigned char ExtSfrGet(unsigned short addr){
	unsigned char r;
    En_EAXFR();
    r = (*(unsigned char volatile xdata *)addr);
    Di_EAXFR();
    return r;
}

void ExtSfrSet(unsigned short addr,unsigned char nv){
    En_EAXFR();
    (*(unsigned char volatile xdata *)addr) = nv;
    Di_EAXFR();
    
}
#endif