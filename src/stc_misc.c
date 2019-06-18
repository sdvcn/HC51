
/*
    实现杂项功能部分
*/
#include <stcmcu.h>

/// HTC 对应开始地址 针对编译器
//interrupt void Console_intr(void) using 1 _at_ CONSOLE_UARTIR 
interrupt void HC51_Init(void) using 1 @ PROSTARTADDR
{
    asm("NOP");
}


