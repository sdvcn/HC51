#ifndef _STCMCU_H_
#define _STCMCU_H_

#ifndef	__HTC8051__
#warning Header file no sup.
#endif
/**
 * 产生nop次数
*/
extern reentrant void _delay(unsigned long);
#pragma inline(_delay)
#define NOP()   _delay(1)
#define DelayUs(_v) _delay(_v)

typedef unsigned short size_t;
typedef unsigned int	uint;
typedef unsigned char	ubyte;
typedef signed char		byte;
typedef unsigned short	ushort;

/**
 * 位操作
*/
///位操作
#define BIT(_Sv)	(1ul << _Sv)
///检查位
#define CheckBIT(_addr,_bit) ((_addr & BIT(_bit))?1:0)
///清除位
#define ClearBIT(_addr,_bit) (_addr &=~ BIT(_bit))
///设置位
#define SetBIT(_addr,_bit) (_addr |= BIT(_bit))




///杂项
//#include <stc_misc.h>

//Include STD 8051
#define _HTC_H_
#include <8052.h>
#undef _HTC_H_

	#if defined(_STC12XX5604AD)	|| defined(_STC12XX5608AD)	|| defined(_STC12XX5616AD)	||\
	    defined(_STC12XX5620AD)	|| defined(_STC12XX5624AD)	|| defined(_STC12XX5628AD)	||\
		defined(_STC12XX5630AD) || defined(_STC12X56)
		#define STCY	3
		#define SUPPORT_AD	1
		#define SUPPORT_EEPROM	1
		#include <stc12x56.h>
		//#include <stc_suppor.h>
	#elif defined(_STC8A8K16S4A12) || defined(_STC8A8K32S4A12) || defined(_STC8A8K60S4A12) || defined(_STC8A8K64S4A12)
		#ifdef _STC8A8K64S4A12
			#define SUPPORT_IAP	1
		#endif
		#define SUPPORT_AD	1
		#define SUPPORT_EEPROM	1
		#define STC8 1
		#include <stc8.h>
		//#include <stc_suppor.h>
	#else
		#warning No StcMCU
	#endif

#include <stc_suppor.h>
	 

	



	

#endif