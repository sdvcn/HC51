#ifndef _STCMCU_H_
#define _STCMCU_H_

#ifndef	__HTC8051__
#error Header file no sup.
#endif

	#if defined(_STC12XX5604AD)	|| defined(_STC12XX5608AD)	|| defined(_STC12XX5616AD)	||\
	    defined(_STC12XX5620AD)	|| defined(_STC12XX5624AD)	|| defined(_STC12XX5628AD)	||\
		defined(_STC12XX5630AD)
		#include <stc12x56xxad.h>
	#endif


#endif