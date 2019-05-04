
/*
    实现杂项功能部分
*/
#include <stcmcu.h>

///
#define EN_EXTSFR() SetBIT(P_SW2,EAXFR)
#define Di_EXTSFR() ClearBIT(P_SW2,EAXFR)
///地址直读
#define GetVal(_addr) (*(volatile unsigned char xdata *)_addr)

/**
 * STC8 扩展寄存器调用
 * 禁止从中断处调用
*/

unsigned char ExtSfrGet8(size_t addr){
	unsigned char r;
    if(EaxFRST()){
        r = GetVal(addr);
        return r;
    };

    EN_EXTSFR();
    r = GetVal(addr);
    Di_EXTSFR();
    return r;
}

extern void ExtSfrSet8(size_t addr,unsigned char v)
{
    if(EaxFRST()){
        GetVal(addr) = v;
        return;
    };
    EN_EXTSFR();
    GetVal(addr) = v;
    Di_EXTSFR();

}

unsigned short ExtSfrGet16(size_t addr){
	unsigned short r;
    if(EaxFRST()){
        r = GetVal(addr);
        return r;
    };

    EN_EXTSFR();
    r = GetVal(addr);
    Di_EXTSFR();
    return r;
}

void ExtSfrSet16(size_t addr,unsigned short v){
    if(EaxFRST()){
        GetVal(addr) = v;
        return;
    };
    EN_EXTSFR();
    GetVal(addr) = v;
    Di_EXTSFR();
}

//STC8 扩展
#ifdef STC8

#endif