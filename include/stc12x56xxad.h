#ifndef _STC12X56XXAD_H_
#define _STC12X56XXAD_H_

#ifndef	_STCMCU_H_
#error Header file no sup.
#endif

#define ID_ADDR_RAM 0xf1

#ifdef _STC12XX5604AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x0ff9
#endif

#ifdef _STC12XX5608AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x1ff9
#endif

#ifdef _STC12XX5612AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x2ff9
#endif

#ifdef _STC12XX5616AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x3ff9
#endif

#ifdef _STC12XX5620AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x4ff9
#endif

#ifdef _STC12XX5624AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x5ff9
#endif

#ifdef _STC12XX5628AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x6ff9
#endif

#ifdef _STC12XX5630AD
	#ifdef ID_ADDR_ROM
		#error Double MCU
	#endif
	#define ID_ADDR_ROM 0x77f9
#endif

#ifndef ID_ADDR_ROM
#error Header file no sup.
#endif



#endif