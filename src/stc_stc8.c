/**
 * STC8 专有增强部分
  *  
*/
#include <stcmcu.h>
/// 不再开启调试
#define NDEBUG
#include <ext_debug.h>

#ifdef STC8
/**
 * 地址直读
*/

/// 8位
#define GetVal8(_addr) (*(xdata volatile unsigned char *)_addr)
/// 16位
#define GetVal16(_addr) (*(xdata volatile unsigned short *)_addr)

/**
 * STC8 扩展寄存器调用
 * 禁止从中断处调用
*/
unsigned char ExtSfrGet8(size_t addr){
	unsigned char r = 0x00;
    DLOGINT(ExtSfrGet8,addr);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    r = (*(volatile unsigned char xdata *)addr);
    asm("pop _P_SW2");
    DLOGINT(ExtSfrSet8,r);
    return r;
}

void ExtSfrSet8(size_t addr,unsigned char v)
{
    DLOGINT(ExtSfrSet8,addr);
    DLOGINT(ExtSfrSet8,v);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    (*(volatile unsigned char xdata *)addr) = v;
    asm("pop _P_SW2");
    #ifndef NDEBUG
        ExtSfrGet8(addr);
    #endif
}

unsigned short ExtSfrGet16(size_t addr){
	unsigned short r = 0x00;
    DLOGINT(ExtSfrGet8,addr);
    asm("push _P_SW2");
    asm("orl _P_SW2,#80h");
    asm("nop");
    r = (*(volatile unsigned short xdata *)addr);
    asm("pop _P_SW2");
    DLOGINT(ExtSfrSet8,r);
    return r;
}

void ExtSfrSet16(size_t addr,unsigned short v){
    DLOGINT(ExtSfrSet16,addr);
    DLOGINT(ExtSfrSet16,v);
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
