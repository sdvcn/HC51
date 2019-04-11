
#ifndef _STC_MISC_H_
#define _STC_MISC_H_

///位操作
#define BIT(_Sv)	(1ul << _Sv)
///检查位
#define CheckBIT(_addr,_bit) ((_addr & BIT(_bit))?1:0)
///清除位
#define ClearBIT(_addr,_bit) (_addr &=~ BIT(_bit))
///设置位
#define SetBIT(_addr,_bit) (_addr |= BIT(_bit))


///GPIO状态设置
typedef struct {
    unsigned char M0;
    unsigned char M1;
    unsigned char PU;
    unsigned char CS;
} ModeOP;





#endif