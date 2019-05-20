/**
 * STC8增强型双数据指针
 * 相关寄存器
 *  
*/
#include <stcmcu.h>
/**
 * 对DSP进行写操作
 * 
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