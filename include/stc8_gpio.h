#ifndef __STC8_GPIO_H__
#define __STC8_GPIO_H__

/*
typedef union _IOMODE
{
    struct 
    {
        unsigned char M0;
        unsigned char M1;
    };
    unsigned short Ms;    
} IOMODE;

*/


/**
 * _p=IO位
 * _m=0 准双向口
 * _m=1 推挽输出
 * _m=2 高阻输入
 * _m=3 开漏输出
*/
#define GPIO_MakeMode(_p,_m)    (unsigned short)(((CheckBIT(_m,1) << (_p)) << 8) | (CheckBIT(_m,0) << (_p)))

unsigned short GPIO_Mode(size_t io,unsigned short);             // 设置IO工作模式
unsigned char GPIO_PU(size_t io,unsigned char mask);            // 内置上拉电阻
unsigned char GPIO_NCS(size_t io,unsigned char mask);           // 斯密特触发器
//#define GPIO_Mode(_v,_m) 

#endif