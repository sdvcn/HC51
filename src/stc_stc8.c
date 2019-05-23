/**
 * STC8 专有增强部分
  *  
*/
#include <stcmcu.h>
/// 不再开启调试
#define NDEBUG
#include <ext_debug.h>

/**
 * stc8a8k 8k/ram
*/
near static xdata unsigned char membuff[512] _at_ 0xFE00;

const size_t memPtr = (size_t)&membuff;
const size_t memSize = sizeof(membuff);

// 分配不大于 127 
typedef struct _mNode
{
    //struct mNode * mNext;
    //unsigned char mFlag;
    //unsigned char mFlag:1;
    unsigned char mSize:7;

}mNode,*pNode;



void * malloc(size_t nw)
{
    //pNode s1 = 0x33;
    //s1->mSize=80;
    unsigned char * pMem;

    if(nw == 0) return NULL;
    pMem = &membuff[0];
    


    return NULL;
}

void free(void * p)
{

}
#define IRCMST      0x01
#define ENIRC       0x80
#define SelectIrc24M    0x00;
#define SelectIrc32K    0x03;




void _SelectIrc24m()
{
    IRCRC = ExtSfrGet8(&IRC24M);
    ExtSfrSet8(&IRC24MCR,ENIRC);
    while(!(ExtSfrGet8(&IRC24MCR) & IRCMST));
}

void _SelectIrc32k()
{
    ExtSfrSet8(&IRC32KCR,ENIRC);
    while(!(ExtSfrGet8(&IRC32KCR) & IRCMST));
}

/**
 * 不对外部时钟进行验证
 * 且转时会等待稳定
*/
void SetSystemClock(unsigned char op,unsigned char cdiv)
{
    unsigned char cksel = 0x00;

    if((op& 0x03) == 0x00){
        _SelectIrc24m();
    }else if((op& 0x03) == 0x03) {
        _SelectIrc32k();
    }else{
        // todo:外部晶振未实现
    }
    ExtSfrSet8(&CLKDIV,cdiv);
    ExtSfrSet8(&CKSEL,op);

    cksel = ExtSfrGet8(&CKSEL);
    /**
     * 关闭无用时钟源
    */
    if((cksel& 0x03) == 0x00){
        //_SelectIrc24m();
        ExtSfrSet8(&IRC32KCR,0x00);
    }else if((cksel& 0x03) == 0x03) {
        //_SelectIrc32k();
        ExtSfrSet8(&IRC24MCR,0x00);
    }else{
        // todo:外部晶振未实现
    }
}


unsigned long GetSystemClock()
{
    unsigned char cksel = ExtSfrGet8(&CKSEL);
    unsigned char clkdiv = ExtSfrGet8(&CLKDIV);
    unsigned long r;
    if((cksel & 0x03) == 0x00 ) r = DEFCLK;
    if((cksel & 0x03) == 0x01 ) return 0ul;
    if((cksel & 0x03) == 0x02 ) return 0ul;
    if((cksel & 0x03) == 0x03 ) r = 32000ul;

    if (clkdiv) r /= clkdiv;                            // 系统分频

    return r;
}





#ifdef STC8
/**
 * 地址直读
*/

/// 8位
//#define GetVal8(_addr) (*(xdata volatile unsigned char *)_addr)
/// 16位
//#define GetVal16(_addr) (*(xdata volatile unsigned short *)_addr)

/**
 * STC8 扩展寄存器调用
 * 禁止从中断处调用
*/
unsigned char _ExtSfrGet8(far volatile unsigned char* reg){
	unsigned char r = 0x00;
    DLOGINT(ExtSfrGet8,reg);
    assert((size_t)reg > 0xfdff);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    r = (*(volatile unsigned char xdata *)reg);
    asm("pop _P_SW2");
    DLOGINT(ExtSfrSet8,r);
    return r;
}

void _ExtSfrSet8(far volatile unsigned char* addr,unsigned char v)
{
    DLOGINT(ExtSfrSet8,addr);
    DLOGINT(ExtSfrSet8,v);
    assert((size_t)addr > 0xfdff);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    (*(volatile unsigned char xdata *)addr) = v;
    asm("pop _P_SW2");
    #ifndef NDEBUG
        ExtSfrGet8(addr);
    #endif
}

unsigned short _ExtSfrGet16(far volatile unsigned short * addr){
	unsigned short r = 0x00;
    DLOGINT(ExtSfrGet8,addr);
    assert((size_t)addr > 0xfdff);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    r = (*(volatile unsigned short xdata *)addr);
    asm("pop _P_SW2");
    DLOGINT(ExtSfrSet8,r);
    return r;
}

void _ExtSfrSet16(far volatile unsigned short * addr,unsigned short v){
    DLOGINT(ExtSfrSet16,addr);
    DLOGINT(ExtSfrSet16,v);
    assert((size_t)addr > 0xfdff);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    //s1 = (*(volatile unsigned char xdata *)0xFE81);
    (*(volatile unsigned short xdata *)addr) = v;
    asm("pop _P_SW2");
    #ifndef NDEBUG
        ExtSfrGet16(addr);
    #endif
}


/**
 * 对DSP进行写操作
 * todo:暂时未实现
*/
void SetDPS(unsigned char v)
{
    if(!(v & 0x10) == (v & 0x08)){
        asm("push ie");		// 保留现场
        di();				// 关闭中断
        TA = 0xAA;          // 触发指令 1
        TA = 0x55;          // 触发指令 2
        DPS = v;            // 写入DPS值
        NOP();
        asm("pop ie");
        NOP();	
    }else{
        DPS = v;
    }

}

void sw123(const char *src,char *dst,unsigned len )
{
    

}
#endif
