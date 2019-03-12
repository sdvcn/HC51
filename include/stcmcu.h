#ifndef _STCMCU_H_
#define _STCMCU_H_

#ifndef	__HTC8051__
#error Header file no sup.
#endif

//Include STD 8051
#define _HTC_H_
#include <8052.h>
#undef _HTC_H_

typedef unsigned int	uint;
typedef unsigned char	ubyte;
typedef signed char		byte;
typedef unsigned short	ushort;


	#if defined(_STC12XX5604AD)	|| defined(_STC12XX5608AD)	|| defined(_STC12XX5616AD)	||\
	    defined(_STC12XX5620AD)	|| defined(_STC12XX5624AD)	|| defined(_STC12XX5628AD)	||\
		defined(_STC12XX5630AD)
		#define STCY	3
		#include <stc12x56xxad.h>
	#elif defined(_STC8A8K)
		#define STCY	6
	#else
		#error No StcMCU
	#endif


#ifndef STCY
#error No StcMCU
#endif

#if STCY == 1
#elif STCY == 3
#elif STCY == 5
#elif STCY == 6
#else
	
#endif

#endif