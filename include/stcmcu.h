#ifndef _STCMCU_H_
#define _STCMCU_H_

#ifndef	__HTC8051__
#warning Header file no sup.
#endif
///
extern reentrant void _delay(unsigned long);
#pragma inline(_delay)
#define NOP()   _delay(1)

typedef unsigned short size_t;
typedef unsigned int	uint;
typedef unsigned char	ubyte;
typedef signed char		byte;
typedef unsigned short	ushort;

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
		#include <stc_suppor.h>
	#elif defined(_STC8A8K)
		#define STCY	6
	#else
		#warning No StcMCU
	#endif

#include <stc_misc.h>

	

#endif