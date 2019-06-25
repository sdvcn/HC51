#ifndef __STC8_GPIO_H__
#define __STC8_GPIO_H__

#ifdef COMPILE_STC8_GPIO

#define _mkfun(x)   x
/**
 * IO设置准双向
 */
#define IO_ClrMod(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)M0 &= ~(1ul << _pin);\
_mkfun(_io)M1 &= ~(1ul << _pin);\
asm("POP _P_SW2");\
}while(0)

/**
 * IO设置推挽模式
 */
#define IO_SetPP(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)M0 |= (1ul << _pin);\
_mkfun(_io)M1 &= ~(1ul << _pin);\
asm("POP _P_SW2");\
}while(0)

/**
 * IO设置高阻
 */
#define IO_SetHR(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)M0 &= (1ul << _pin);\
_mkfun(_io)M1 |= ~(1ul << _pin);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO设置开漏
 */
#define IO_SetOP(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)M0 |= (1ul << _pin);\
_mkfun(_io)M1 |= (1ul << _pin);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO模式同时设置
 */
#define IO_Mode_Set(_io,_m0,_m1) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)M0 = (_m0);\
_mkfun(_io)M1 = (_m1);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO上拉电阻设置
 */
#define IO_SetPU(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)PU |= (1ul << _pin);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO上拉电阻清除
 */
#define IO_ClrPU(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)PU &= ~(1ul << _pin);\
asm("POP _P_SW2");\
}while(0)
/**
 * 上拉电阻同时设置
 */
#define IO_PU_Set(_io,_mask) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)PU |= (_mask);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO施密特触发器设置
 */
#define IO_SetNCS(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)NCS |= (1ul << _pin);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO施密特触发器清除
 */
#define IO_ClrNCS(_io,_pin) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)NCS &= ~(1ul << _pin);\
asm("POP _P_SW2");\
}while(0)
/**
 * IO施密特触发器同时设置
 */
#define IO_NCS_Set(_io,_mask) do{\
asm("PUSH   _P_SW2;ORL  _P_SW2,#80h;NOP");\
_mkfun(_io)NCS |= (_mask);\
asm("POP _P_SW2");\
}while(0)
#endif
#ifdef COMPILE_STC8_GPIO_old

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



#define GPIO_MakeMode(_p,_m)    (unsigned short)(((CheckBIT(_m,1) << (_p)) << 8) | (CheckBIT(_m,0) << (_p)))
#define GPIO_ModeMask(_b)       (~((BIT((_b)+8)) |BIT(_b)))


/**
 * 设置端口工作模式
 * _p:=端口     [P0~P7]
 * _b:=IO位     [0~7]
 * _v:=设定值   [0|1|2|3]
 * 0:准双向口   1:推挽输出  2:高阻输入  3:开漏输出
*/
#define GPIO_SetMode(_p,_b,_m)  GPIO_Mode(PtrAddr(_p),((GPIO_GetMode(PtrAddr(_p)) & GPIO_ModeMask(_b)) |GPIO_MakeMode(_b,_m)))
/**
 * 获取工作模式设置
 * IO:=端口     [P0~P7]
*/
unsigned short GPIO_GetMode(size_t io);                         // 获取历史
unsigned short GPIO_Mode(size_t io,unsigned short);             // 设置IO工作模式
/**
 * 获取上拉电阻设置
 * IO:=端口     [P0~P7]
*/
unsigned char GPIO_GetPU(size_t io);
unsigned char GPIO_PU(size_t io,unsigned char mask);            // 内置上拉电阻
/**
 * 设定内置上拉
 * _p:=端口     [P0~P7]
 * _b:=IO位     [0~7]
 * _v:=设定值   [0|1]
*/
#define GPIO_SetPU(_p,_b,_v) GPIO_PU(PtrAddr(_p),((GPIO_GetPU(PtrAddr(_p)) & ~BIT(_b)) | (CheckBIT(_v,0) << (_b)))) 
/**
 * 获取斯密特触发器设定
 * IO:=端口     [P0~P7]
*/
unsigned char GPIO_GetNCS(size_t io);
unsigned char GPIO_NCS(size_t io,unsigned char mask);           // 斯密特触发器
/**
 * 设定施密特触发器
 * _p:=端口     [P0~P7]
 * _b:=IO位     [0~7]
 * _v:=设定值   [0|1]
*/
#define GPIO_SetNCS(_p,_b,_v)       GPIO_NCS(PtrAddr(_p),((GPIO_GetNCS(PtrAddr(_p)) & ~BIT(_b)) | (CheckBIT(_v,0) << (_b)))) 


#endif // COMPILE_STC8_GPIO
#endif