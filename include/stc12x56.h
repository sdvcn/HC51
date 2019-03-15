#ifndef _STC12X56XXAD_H_
#define _STC12X56XXAD_H_

#ifndef	_STCMCU_H_
#warning Header file no sup.
#endif

#define LVDF_Bit	(1u << 5)


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

/* ADC Register */
static volatile unsigned char ADC_CONTR  @ 0xc5;
static volatile unsigned char ADC_DATA   @ 0xc6;
static volatile unsigned char ADC_LOW2   @ 0xbe;

/* PCA static volatile unsigned char */
static volatile unsigned char CCON   @ 0xD8;
static volatile unsigned char CMOD   @ 0xD9;
static volatile unsigned char CCAPM0 @ 0xDA;
static volatile unsigned char CCAPM1 @ 0xDB;
static volatile unsigned char CCAPM2 @ 0xDC;
static volatile unsigned char CCAPM3 @ 0xDD;
static volatile unsigned char CCAPM4 @ 0xDE;
static volatile unsigned char CCAPM5 @ 0xDF;

static volatile unsigned char CL     @ 0xE9;
static volatile unsigned char CCAP0L @ 0xEA;
static volatile unsigned char CCAP1L @ 0xEB;
static volatile unsigned char CCAP2L @ 0xEC;
static volatile unsigned char CCAP3L @ 0xED;
static volatile unsigned char CCAP4L @ 0xEE;
static volatile unsigned char CCAP5L @ 0xEF;

static volatile unsigned char CH     @ 0xF9;
static volatile unsigned char CCAP0H @ 0xFA;
static volatile unsigned char CCAP1H @ 0xFB;
static volatile unsigned char CCAP2H @ 0xFC;
static volatile unsigned char CCAP3H @ 0xFD;
static volatile unsigned char CCAP4H @ 0xFE;
static volatile unsigned char CCAP5H @ 0xFF;

static volatile unsigned char PCA_PWM0 @ 0xF2;
static volatile unsigned char PCA_PWM1 @ 0xF3;
static volatile unsigned char PCA_PWM2 @ 0xF4;
static volatile unsigned char PCA_PWM3 @ 0xF5;
static volatile unsigned char PCA_PWM4 @ 0xF6;
static volatile unsigned char PCA_PWM5 @ 0xF7;

/*  CCON  */
static volatile bit CF    @ 0xD8^7;
static volatile bit CR    @ 0xD8^6;
static volatile bit CCF5  @ 0xD8^5;
static volatile bit CCF4  @ 0xD8^4;
static volatile bit CCF3  @ 0xD8^3;
static volatile bit CCF2  @ 0xD8^2;
static volatile bit CCF1  @ 0xD8^1;
static volatile bit CCF0  @ 0xD8^0;

//interrupt 中断优先
static volatile unsigned char IPH @ 0xB7;

///
far unsigned char STCID1[7] @ 0xF1;
far unsigned long STCCLK	@ 0xF8;			//最近
far unsigned long STCCLKR	@ 0xFC;			//内置




///初始化等待电压
#define InitLvdf()	do{PCON &= ~LVDF_Bit;NOP();NOP();}while(PCON & LVDF_Bit)

#endif