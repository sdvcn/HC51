#ifndef _STC_MISC_H_
#define _STC_MISC_H_

///位操作
#define BIT(_Sv)	(1ul << _Sv)

#define CheckBIT(_addr,_bit) ((_addr & BIT(_bit))?1:0)
#define ClearBIT(_addr,_bit) (_addr &=~ BIT(_bit))
#define SetBIT(_addr,_bit) (_addr |= BIT(_bit))



#endif