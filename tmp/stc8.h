#ifndef __STC8_H
#define __STC8_H

#include "stc.h"

//extern reentrant void _delay(unsigned long);
//#pragma inline(_delay)

//






static volatile unsigned char	P0	@	0x80;
/* bit addressable locations */

static volatile unsigned char	SP	@	0x81;
static volatile unsigned char	DPL	@	0x82;
static volatile unsigned char	DPH	@	0x83;
static volatile unsigned char	S4CON	@	0x84;
static volatile unsigned char	S4BUF	@	0x85;
//static volatile unsigned char	_DEF_	@	0x86;
//static volatile unsigned char	PCON	@	0x87;
static volatile unsigned char	TCON	@	0x88;
//static volatile unsigned char	TMOD	@	0x89;
static volatile unsigned char	TL0		@	0x8A;
static volatile unsigned char	TL1		@	0x8B;
static volatile unsigned char	TH0		@	0x8C;
static volatile unsigned char	TH1		@	0x8D;
static volatile unsigned char	AUXR	@	0x8E;
static volatile unsigned char	INTCLKO	@	0x8F;
static volatile unsigned char	P1		@	0x90;
static volatile unsigned char	P1M1	@	0x91;
static volatile unsigned char	P1M0	@	0x92;
static volatile unsigned char	P0M1	@	0x93;
static volatile unsigned char	P0M0	@	0x94;
static volatile unsigned char	P2M1	@	0x95;
static volatile unsigned char	P2M0	@	0x96;
static volatile unsigned char	AUXR2	@	0x97;
//static volatile unsigned char	SCON	@	0x98;
//static volatile unsigned char	SBUF	@	0x99;
static volatile unsigned char	S2CON	@	0x9A;
static volatile unsigned char	S2BUF	@	0x9B;
//static volatile unsigned char	_DEF_	@	0x9C;
//static volatile unsigned char	_DEF_	@	0x9D;
//static volatile unsigned char	_DEF_	@	0x9E;
//static volatile unsigned char	_DEF_	@	0x9F;
static volatile unsigned char	P2		@	0xA0;
static volatile unsigned char	BUS_SPEED	@	0xA1;
static volatile unsigned char	P_SW1	@	0xA2;
//static volatile unsigned char	_DEF_	@	0xA3;
//static volatile unsigned char	_DEF_	@	0xA4;
//static volatile unsigned char	_DEF_	@	0xA5;
//static volatile unsigned char	_DEF_	@	0xA6;
//static volatile unsigned char	_DEF_	@	0xA7;
//static volatile unsigned char	IE		@	0xA8;
static volatile unsigned char	SADDR	@	0xA9;
static volatile unsigned char	WKTCL	@	0xAA;
static volatile unsigned char	WKTCH	@	0xAB;
static volatile unsigned char	S3CON	@	0xAC;
static volatile unsigned char	S3BUF	@	0xAD;
static volatile unsigned char	TA		@	0xAE;
static volatile unsigned char	IE2		@	0xAF;

static volatile unsigned char	P3		@	0xB0;
static volatile unsigned char	P3M1	@	0xB1;
static volatile unsigned char	P3M0	@	0xB2;
static volatile unsigned char	P4M1	@	0xB3;
static volatile unsigned char	P4M0	@	0xB4;
static volatile unsigned char	IP2		@	0xB5;
static volatile unsigned char	IP2H	@	0xB6;
static volatile unsigned char	IPH		@	0xB7;

//static volatile unsigned char	IP		@	0xB8;
static volatile unsigned char	SADEN	@	0xB9;
static volatile unsigned char	P_SW2	@	0xBA;
static volatile unsigned char	VOCTRL	@	0xBB;
static volatile unsigned char	ADC_CONTR	@	0xBC;
///FIX 16Bit
static volatile unsigned short	ADC_RES	@	0xBD;
static volatile unsigned char	ADC_RESL	@	0xBE;
static volatile unsigned char	ADC_RESH	@	0xBF;

static volatile unsigned char	P4		@	0xC0;
static volatile unsigned char	WDT_CONTR	@	0xC1;
static volatile unsigned char	IAP_DATA	@	0xC2;

static volatile unsigned int	IAP_ADDR	@	0xC3;		//fix

static volatile unsigned char	IAP_ADDRH	@	0xC3;
static volatile unsigned char	IAP_ADDRL	@	0xC4;
static volatile unsigned char	IAP_CMD	@	0xC5;
static volatile unsigned char	IAP_TRIG	@	0xC6;
static volatile unsigned char	IAP_CONTR	@	0xC7;

static volatile unsigned char	P5		@	0xC8;
static volatile unsigned char	P5M1	@	0xC9;
static volatile unsigned char	P5M0	@	0xCA;
static volatile unsigned char	P6M1	@	0xCB;
static volatile unsigned char	P6M0	@	0xCC;
static volatile unsigned char	SPSTAT	@	0xCD;
static volatile unsigned char	SPCTL	@	0xCE;
static volatile unsigned char	SPDAT	@	0xCF;

static volatile unsigned char	PSW		@	0xD0;
static volatile unsigned char	T4T3M	@	0xD1;

static volatile unsigned int	T4		@	0xD2;	//fix
static volatile unsigned char	T4H		@	0xD2;
static volatile unsigned char	T4L		@	0xD3;

static volatile unsigned int	T3		@	0xD4;	//fix
static volatile unsigned char	T3H		@	0xD4;
static volatile unsigned char	T3L		@	0xD5;

//static volatile unsigned int	T2		@	0xD6;	//fix
static volatile unsigned char	T2H		@	0xD6;
static volatile unsigned char	T2L		@	0xD7;

static volatile unsigned char	CCON	@	0xD8;
static volatile unsigned char	COMD	@	0xD9;
static volatile unsigned char	CCAPM0	@	0xDA;
static volatile unsigned char	CCAPM1	@	0xDB;
static volatile unsigned char	CCAPM2	@	0xDC;
static volatile unsigned char	CCAPM3	@	0xDD;
static volatile unsigned char	ADCCFG	@	0xDE;
//static volatile unsigned char	IP3		@	0xDF;

static volatile unsigned char	ACC		@	0xE0;
static volatile unsigned char	P7M1	@	0xE1;
static volatile unsigned char	P7M0	@	0xE2;
static volatile unsigned char	DPS		@	0xE3;
static volatile unsigned char	DPL1	@	0xE4;
static volatile unsigned char	DPH1	@	0xE5;
static volatile unsigned char	CMPCR1	@	0xE6;
static volatile unsigned char	CMPCR2	@	0xE7;

static volatile unsigned char	P6		@	0xE8;
static volatile unsigned char	CL		@	0xE9;
static volatile unsigned char	CCAP0L	@	0xEA;
static volatile unsigned char	CCAP1L	@	0xEB;
static volatile unsigned char	CCAP2L	@	0xEC;
static volatile unsigned char	CCAP3L	@	0xED;
//static volatile unsigned char	IP3H	@	0xEE;
static volatile unsigned char	AUXINTIF	@	0xEF;


static volatile unsigned char	B		@	0xF0;
static volatile unsigned char	PWMCFG	@	0xF1;
static volatile unsigned char	PCA_PWM0	@	0xF2;
static volatile unsigned char	PCA_PWM1	@	0xF3;
static volatile unsigned char	PCA_PWM2	@	0xF4;
static volatile unsigned char	PCA_PWM3	@	0xF5;
static volatile unsigned char	PWMIF	@	0xF6;
static volatile unsigned char	PWMFDCR	@	0xF7;

static volatile unsigned char	P7		@	0xF8;
static volatile unsigned char	CH	@	0xF9;
static volatile unsigned char	CCAP0H	@	0xFA;
static volatile unsigned char	CCAP1H	@	0xFB;
static volatile unsigned char	CCAP2H	@	0xFC;
static volatile unsigned char	CCAP3H	@	0xFD;
static volatile unsigned char	PWMCR	@	0xFE;
static volatile unsigned char	RSTCFG	@	0xFF;



//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
far volatile unsigned char CKSEL @ 0xFE00; 
far volatile unsigned char CLKDIV @ 0xFE01; 
far volatile unsigned char IRC24MCR @ 0xFE02; 
far volatile unsigned char XOSCCR @ 0xFE03; 
far volatile unsigned char IRC32KCR @ 0xFE04; 

far volatile unsigned char P0PU @ 0xFE10; 
far volatile unsigned char P1PU @ 0xFE11; 
far volatile unsigned char P2PU @ 0xFE12; 
far volatile unsigned char P3PU @ 0xFE13; 
far volatile unsigned char P4PU @ 0xFE14; 
far volatile unsigned char P5PU @ 0xFE15; 
far volatile unsigned char P6PU @ 0xFE16; 
far volatile unsigned char P7PU @ 0xFE17; 

far volatile unsigned char P0NCS @ 0xFE18; 
far volatile unsigned char P1NCS @ 0xFE19; 
far volatile unsigned char P2NCS @ 0xFE1A; 
far volatile unsigned char P3NCS @ 0xFE1B; 
far volatile unsigned char P4NCS @ 0xFE1C; 
far volatile unsigned char P5NCS @ 0xFE1D; 
far volatile unsigned char P6NCS @ 0xFE1E; 
far volatile unsigned char P7NCS @ 0xFE1F; 

far volatile unsigned char I2CCFG	@ 0xFE80; 
far volatile unsigned char I2CMSCR	@ 0xFE81; 
far volatile unsigned char I2CMSST	@ 0xFE82; 
far volatile unsigned char I2CSLCR	@ 0xFE83; 
far volatile unsigned char I2CSLST	@ 0xFE84; 
far volatile unsigned char I2CSLADR	@ 0xFE85; 
far volatile unsigned char I2CTxD	@ 0xFE86; 
far volatile unsigned char I2CRxD	@ 0xFE87; 
far volatile unsigned char I2CMSAUX	@ 0xFE88;

far volatile unsigned int PWM0T1	@ 0xFF00; 
far volatile unsigned char PWM0T1H	@ 0xFF00; 
far volatile unsigned char PWM0T1L	@ 0xFF01; 

far volatile unsigned int PWM0T2	@ 0xFF02; 
far volatile unsigned char PWM0T2H	@ 0xFF02; 
far volatile unsigned char PWM0T2L	@ 0xFF03; 
far volatile unsigned char PWM0CR	@ 0xFF04; 
far volatile unsigned char PWM0HLD	@ 0xFF05; 

//--
far volatile unsigned int PWM1T1	@ 0xFF10; 
far volatile unsigned char PWM1T1H	@ 0xFF10; 
far volatile unsigned char PWM1T1L	@ 0xFF11; 

far volatile unsigned int PWM1T2	@ 0xFF12; 
far volatile unsigned char PWM1T2H	@ 0xFF12; 
far volatile unsigned char PWM1T2L	@ 0xFF13; 
far volatile unsigned char PWM1CR	@ 0xFF14; 
far volatile unsigned char PWM1HLD	@ 0xFF15; 

//--
far volatile unsigned int PWM2T1	@ 0xFF20; 
far volatile unsigned char PWM2T1H	@ 0xFF20; 
far volatile unsigned char PWM2T1L	@ 0xFF21; 

far volatile unsigned int PWM2T2	@ 0xFF22; 
far volatile unsigned char PWM2T2H	@ 0xFF22; 
far volatile unsigned char PWM2T2L	@ 0xFF23; 
far volatile unsigned char PWM2CR	@ 0xFF24; 
far volatile unsigned char PWM2HLD	@ 0xFF25; 

//--
far volatile unsigned int PWM3T1	@ 0xFF30; 
far volatile unsigned char PWM3T1H	@ 0xFF30; 
far volatile unsigned char PWM3T1L	@ 0xFF31; 

far volatile unsigned int PWM3T2	@ 0xFF32; 
far volatile unsigned char PWM3T2H	@ 0xFF32; 
far volatile unsigned char PWM3T2L	@ 0xFF33; 
far volatile unsigned char PWM3CR	@ 0xFF34; 
far volatile unsigned char PWM3HLD	@ 0xFF35; 

//--
far volatile unsigned int PWM4T1	@ 0xFF40; 
far volatile unsigned char PWM4T1H	@ 0xFF40; 
far volatile unsigned char PWM4T1L	@ 0xFF41; 

far volatile unsigned int PWM4T2	@ 0xFF42; 
far volatile unsigned char PWM4T2H	@ 0xFF42; 
far volatile unsigned char PWM4T2L	@ 0xFF43; 
far volatile unsigned char PWM4CR	@ 0xFF44; 
far volatile unsigned char PWM4HLD	@ 0xFF45; 

//--
far volatile unsigned int PWM5T1	@ 0xFF50; 
far volatile unsigned char PWM5T1H	@ 0xFF50; 
far volatile unsigned char PWM5T1L	@ 0xFF51; 

far volatile unsigned int PWM5T2	@ 0xFF52; 
far volatile unsigned char PWM5T2H	@ 0xFF52; 
far volatile unsigned char PWM5T2L	@ 0xFF53; 
far volatile unsigned char PWM5CR	@ 0xFF54; 
far volatile unsigned char PWM5HLD	@ 0xFF55; 

//--
far volatile unsigned int PWM6T1	@ 0xFF60; 
far volatile unsigned char PWM6T1H	@ 0xFF60; 
far volatile unsigned char PWM6T1L	@ 0xFF61; 

far volatile unsigned int PWM6T2	@ 0xFF62; 
far volatile unsigned char PWM6T2H	@ 0xFF62; 
far volatile unsigned char PWM6T2L	@ 0xFF63; 
far volatile unsigned char PWM6CR	@ 0xFF64; 
far volatile unsigned char PWM6HLD	@ 0xFF65; 

//--
far volatile unsigned int PWM7T1	@ 0xFF70; 
far volatile unsigned char PWM7T1H	@ 0xFF70; 
far volatile unsigned char PWM7T1L	@ 0xFF71; 

far volatile unsigned int PWM7T2	@ 0xFF72; 
far volatile unsigned char PWM7T2H	@ 0xFF72; 
far volatile unsigned char PWM7T2L	@ 0xFF73; 
far volatile unsigned char PWM7CR	@ 0xFF74; 
far volatile unsigned char PWM7HLD	@ 0xFF75; 


far volatile unsigned char PWMCH	@ 0xFFF0; 
far volatile unsigned char PWMCKS	@ 0xFFF0; 
far volatile unsigned char TADCPH	@ 0xFFF0; 
far volatile unsigned char TADCPL	@ 0xFFF0; 


//#define Set_EA

// Port 0 P0
//static volatile SFR_BITS	P0_BITS @ 0x80;
//static volatile bit	P00	@ 0x80;
//static volatile bit	P01	@ 0x81;
//static volatile bit	P02	@ 0x82;
//static volatile bit	P03	@ 0x83;
//static volatile bit	P04	@ 0x84;
//static volatile bit	P05	@ 0x85;
//static volatile bit	P06	@ 0x86;
//static volatile bit	P07	@ 0x87;
// Port 1 P1
//static volatile SFR_BITS	P1_BITS @ 0x90;
//static volatile bit	P10	@ 0x90;
//static volatile bit	P11	@ 0x91;
//static volatile bit	P12	@ 0x92;
//static volatile bit	P13	@ 0x93;
//static volatile bit	P14	@ 0x94;
//static volatile bit	P15	@ 0x95;
//static volatile bit	P16	@ 0x96;
//static volatile bit	P17	@ 0x97;
// Port 2 P2
//static volatile SFR_BITS	P2_BITS @ 0xA0;
//static volatile bit	P20	@ 0xA0 ^ 0;
//static volatile bit	P21	@ 0xA0 ^ 1;
//static volatile bit	P22	@ 0xA0 ^ 2;
//static volatile bit	P23	@ 0xA0 ^ 3;
//static volatile bit	P24	@ 0xA0 ^ 4;
//static volatile bit	P25	@ 0xA0 ^ 5;
//static volatile bit	P26	@ 0xA0 ^ 6;
//static volatile bit	P27	@ 0xA0 ^ 7;
// Port 3 P3
//static volatile SFR_BITS	P3_BITS @ 0xB0;
//static volatile bit	P30	@ 0xB0 ^ 0;
//static volatile bit	P31	@ 0xB0 ^ 1;
//static volatile bit	P32	@ 0xB0 ^ 2;
//static volatile bit	P33	@ 0xB0 ^ 3;
//static volatile bit	P34	@ 0xB0 ^ 4;
//static volatile bit	P35	@ 0xB0 ^ 5;
//static volatile bit	P36	@ 0xB0 ^ 6;
//static volatile bit	P37	@ 0xB0 ^ 7;
// Port 4 P4
static volatile SFR_BITS	P4_BITS @ 0xC0;
static volatile bit	P40	@ 0xC0 ^ 0;
static volatile bit	P41	@ 0xC0 ^ 1;
static volatile bit	P42	@ 0xC0 ^ 2;
static volatile bit	P43	@ 0xC0 ^ 3;
static volatile bit	P44	@ 0xC0 ^ 4;
static volatile bit	P45	@ 0xC0 ^ 5;
static volatile bit	P46	@ 0xC0 ^ 6;
static volatile bit	P47	@ 0xC0 ^ 7;
// Port 5 P5
static volatile SFR_BITS	P5_BITS @ 0xC8;
static volatile bit	P50	@ 0xC8 ^ 0;
static volatile bit	P51	@ 0xC8 ^ 1;
static volatile bit	P52	@ 0xC8 ^ 2;
static volatile bit	P53	@ 0xC8 ^ 3;
static volatile bit	P54	@ 0xC8 ^ 4;
static volatile bit	P55	@ 0xC8 ^ 5;
static volatile bit	P56	@ 0xC8 ^ 6;
static volatile bit	P57	@ 0xC8 ^ 7;
// Port 6 P6
static volatile SFR_BITS	P6_BITS @ 0xE8;
static volatile bit	P60	@ 0xE8 ^ 0;
static volatile bit	P61	@ 0xE8 ^ 1;
static volatile bit	P62	@ 0xE8 ^ 2;
static volatile bit	P63	@ 0xE8 ^ 3;
static volatile bit	P64	@ 0xE8 ^ 4;
static volatile bit	P65	@ 0xE8 ^ 5;
static volatile bit	P66	@ 0xE8 ^ 6;
static volatile bit	P67	@ 0xE8 ^ 7;
// Port 7 P7
static volatile SFR_BITS	P7_BITS @ 0xF8;
static volatile bit	P70	@ 0xF8 ^ 0;
static volatile bit	P71	@ 0xF8 ^ 1;
static volatile bit	P72	@ 0xF8 ^ 2;
static volatile bit	P73	@ 0xF8 ^ 3;
static volatile bit	P74	@ 0xF8 ^ 4;
static volatile bit	P75	@ 0xF8 ^ 5;
static volatile bit	P76	@ 0xF8 ^ 6;
static volatile bit	P77	@ 0xF8 ^ 7;

///FIX Addon

//static SFR_BITS	P_SW2_BITS	@	0xBA;
///-------------- 扩展部分
static volatile  struct {
	unsigned S2_S : 1;
	unsigned S3_S : 1;
	unsigned S4_S : 1;
	unsigned CMPO_S : 1;
	unsigned I2C_S : 2;
	unsigned : 1;
	unsigned Eaxfr:1;
}P_SW2Ex @ 0xBA;

#define EAXFR P_SW2Ex.Eaxfr

//#define EnableEX() do{asm("push _P_SW2");P_SW2 |= 0x80;}while(0)
//#define DisableEX() do{asm("pop _P_SW2");}while(0)

//#define EnableEX() do{_push_(P_SW2);P_SW2 |= 0x80;}while(0);

//#define DisableEX() do{_pop_(P_SW2);}while(0);


//#define ExecEx(_v) do{EnableEX;##_v;DisableEX;}while(0);
#define ENI2C() CheckBIT(I2CCFG,7)
#define ENI2C_Set() SetBIT(I2CCFG,7)
#define ENI2C_Clr() ClearBIT(I2CCFG,7)
//I2CCFG

//static volatile unsigned char	P_SW2	@	0xBA;

//
#define MSBUSY() CheckBIT(I2CMSST,7)

#define MSIF()  CheckBIT(I2CMSST,6)
#define MSIF_Clr()  ClearBIT(I2CMSST,6)

#define MSACKI() CheckBIT(I2CMSST,1)
#define MSACKI_Clr() ClearBIT(I2CMSST, 1)

#define MSACKO() CheckBIT(I2CMSST,0)
#define MSACKO_Clr() ClearBIT(I2CMSST, 0)


//far FixSFR_BITS	I2CSLST_BITS	@	0xFE84;
#define SLBUSY() CheckBIT(I2CSLST,7)

#define STAIF()  CheckBIT(I2CSLST,6)
#define STAIF_Clr()  ClearBIT(I2CSLST,6)

#define RXIF() CheckBIT(I2CSLST,5)
#define RXIF_Clr() ClearBIT(I2CSLST, 5)

#define TXIF() CheckBIT(I2CSLST,4)
#define TXIF_Clr() ClearBIT(I2CSLST, 4)

#define STOIF() CheckBIT(I2CSLST,3)
#define STOIF_Clr() ClearBIT(I2CSLST, 3)

#define TXING() CheckBIT(I2CSLST,2)
#define TXING_Clr() ClearBIT(I2CSLST, 2)

#define SLACKI() CheckBIT(I2CSLST,1)
#define SLACKI_Clr() ClearBIT(I2CSLST, 1)

#define SLACKO() CheckBIT(I2CSLST,0)
#define SLACKO_Clr() ClearBIT(I2CSLST, 0)



//#define ENEx()
//#define SelectI2c(_v) do{P_SW2_BITS.B5 = 0;P_SW2_BITS.B4 = 0; P_SW2|=((_v)<< 4);}while(0);

#define SelectSPI(_v) do{P_SW1_BITS.B3 = 0;P_SW1_BITS.B2 = 0;P_SW1 |= ((_v)<<2);}while(0);
idata  unsigned short BGV @ 0xEF;
idata  unsigned char STCID[7] @ 0xF1;
idata  unsigned short F32K  @ 0xF8;
idata  unsigned char IRC22M @ 0xFA;
idata  unsigned char IRC24M @ 0xFB;

#if defined(STC8A8K64SA12) || defined(STC8A4K64SA12) || defined(STC8F2K64S4) || defined(STC8F2K64S2)

code  unsigned short BGV_ROM @ 0xFDF9;
code  unsigned char STCID_ROM[7] @ 0xFDF7;
code  unsigned short F32K_ROM  @ 0xFDF5;
code  unsigned char IRC22M_ROM @ 0xFDF4;
code  unsigned char IRC24M_ROM @ 0xFDF3;

#endif //  STC8A8K64SA12



#endif