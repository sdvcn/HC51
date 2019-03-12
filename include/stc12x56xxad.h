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

code  unsigned char STCID_ROM[7] @ ID_ADDR_ROM;

/* Watchdog Timer Register */
static volatile unsigned char	WDT_CONTR	@	0xe1;

/* ISP_IAP_EEPROM Register */
static volatile unsigned char	ISP_DATA	@	0xe2;
static volatile unsigned char	ISP_ADDRH	@	0xe3;
static volatile unsigned char	ISP_ADDRL	@	0xe4;
static volatile unsigned short	ISP_ADDR	@	0xe3;
static volatile unsigned char	ISP_CMD		@	0xe5;
static volatile unsigned char	ISP_TRIG	@	0xe6;
static volatile unsigned char	ISP_CONTR	@	0xe7;


/* System Clock Divider */
static volatile unsigned char	CLK_DIV	@	0xc7;

/* I_O Port Mode Set Register */
static volatile unsigned char	P0M0	@	0x93;
static volatile unsigned char	P0M1	@	0x94;
static volatile unsigned char	P1M0	@	0x91;
static volatile unsigned char	P1M1	@	0x92;
static volatile unsigned char	P2M0	@	0x95;
static volatile unsigned char	P2M1	@	0x96;
static volatile unsigned char	P3M0	@	0xb1;
static volatile unsigned char	P3M1	@	0xb2;
/* SPI Register */
static volatile unsigned char	SPSTAT	@	0x84;
static volatile unsigned char	SPCTL	@	0x85;
static volatile unsigned char	SPDAT	@	0x86;

static volatile unsigned char	P0	@	0x86;

#endif