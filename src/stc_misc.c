
/*
    实现杂项功能部分
*/
#include <stcmcu.h>

#include <ext_debug.h>

/// HTC 对应开始地址 针对编译器

near void HC51_Init() @ PROSTARTADDR
{
    asm("NOP");
}


