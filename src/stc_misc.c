
/*
    实现杂项功能部分
*/
#include <stcmcu.h>

///地址直读
#define GetVal(_addr) (*(volatile unsigned char xdata *)_addr)



unsigned char ExtSfrGet8(size_t addr){
	unsigned char r;
    if(EaxFRST()){
        r = GetVal(addr);
        return r;
    };

    En_EAXFR();
    //r = (*(volatile unsigned char  xdata *)addr);
    r = GetVal(addr);
    Di_EAXFR();
    return r;
}

unsigned short ExtSfrGet16(size_t addr){
	unsigned short r;
    En_EAXFR();
    //r = (*(volatile unsigned char  xdata *)addr);
    r = GetVal(addr);
    Di_EAXFR();
    return r;
}

void ExtSfrSet16(size_t addr,unsigned short nv){
    En_EAXFR();
    //(*(unsigned char volatile xdata *)addr) = nv;
    GetVal(addr) = nv;
    Di_EAXFR();
}

//STC8 扩展
#ifdef STC8

#endif