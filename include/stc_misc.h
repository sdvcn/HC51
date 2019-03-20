#ifndef _STC_MISC_H_
#define _STC_MISC_H_

extern reentrant void _delay(unsigned long);
#pragma inline(_delay)
#define NOP()   _delay(1)

typedef unsigned short size_t;
typedef unsigned int	uint;
typedef unsigned char	ubyte;
typedef signed char		byte;
typedef unsigned short	ushort;



#endif