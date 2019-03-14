
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/



#ifndef	_STC8xxxx_H
#define	_STC8xxxx_H

#include <intrins.h>

/*  BYTE Registers  */
sfr P0    = 0x80;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr	S4CON = 0x84;
sfr	S4BUF = 0x85;
sfr PCON  = 0x87;

sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr	AUXR = 0x8E;
sfr WAKE_CLKO = 0x8F;
sfr INT_CLKO  = 0x8F;

sfr P1    = 0x90;
sfr P1M1  = 0x91;	//P1M1.n,P1M0.n 	=00--->Standard,	01--->push-pull		实际上1T的都一样
sfr P1M0  = 0x92;	//					=10--->pure input,	11--->open drain
sfr P0M1  = 0x93;	//P0M1.n,P0M0.n 	=00--->Standard,	01--->push-pull
sfr P0M0  = 0x94;	//					=10--->pure input,	11--->open drain
sfr P2M1  = 0x95;	//P2M1.n,P2M0.n 	=00--->Standard,	01--->push-pull
sfr P2M0  = 0x96;	//					=10--->pure input,	11--->open drain
sfr PCON2 = 0x97;
sfr	AUXR2 = 0x97;

sfr SCON  = 0x98;
sfr SBUF  = 0x99;
sfr S2CON = 0x9A;	//
sfr S2BUF = 0x9B;	//

sfr P2    = 0xA0;
sfr BUS_SPEED = 0xA1;
sfr AUXR1 = 0xA2;
sfr P_SW1 = 0xA2;

sfr IE    = 0xA8;
sfr SADDR = 0xA9;
sfr WKTCL = 0xAA;	//唤醒定时器低字节
sfr WKTCH = 0xAB;	//唤醒定时器高字节
sfr	S3CON = 0xAC;
sfr S3BUF = 0xAD;
sfr TA    = 0xAE;
sfr IE2   = 0xAF;	//STC12C5A60S2系列

sfr P3    = 0xB0;
sfr P3M1  = 0xB1;	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
sfr P3M0  = 0xB2;	//					=10--->pure input,	11--->open drain
sfr P4M1  = 0xB3;	//P4M1.n,P4M0.n 	=00--->Standard,	01--->push-pull
sfr P4M0  = 0xB4;	//					=10--->pure input,	11--->open drain
sfr IP2   = 0xB5;	//STC12C5A60S2系列
sfr IP2H  = 0xB6;	//STC12C5A60S2系列
sfr IPH   = 0xB7;

sfr IP        = 0xB8;
sfr SADEN     = 0xB9;
sfr	P_SW2     = 0xBA;
sfr	VOCTRL    = 0xBB;
sfr ADC_CONTR = 0xBC;	//ADC控制寄存器
sfr ADC_RES   = 0xBD;	//ADC结果高字节
sfr ADC_RESL  = 0xBE;	//ADC结果低字节

sfr P4        = 0xC0;
sfr WDT_CONTR = 0xC1;

sfr IAP_DATA  = 0xC2;
sfr IAP_ADDRH = 0xC3;
sfr IAP_ADDRL = 0xC4;
sfr IAP_CMD   = 0xC5;
sfr IAP_TRIG  = 0xC6;
sfr IAP_CONTR = 0xC7;

sfr ISP_DATA  = 0xC2;
sfr ISP_ADDRH = 0xC3;
sfr ISP_ADDRL = 0xC4;
sfr ISP_CMD   = 0xC5;
sfr ISP_TRIG  = 0xC6;
sfr ISP_CONTR = 0xC7;

sfr P5     = 0xC8;	//
sfr P5M1   = 0xC9;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
sfr P5M0   = 0xCA;	//					=10--->pure input,	11--->open drain
sfr P6M1   = 0xCB;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
sfr P6M0   = 0xCC;	//					=10--->pure input,	11--->open drain
sfr SPSTAT = 0xCD;	//
sfr SPCTL  = 0xCE;	//
sfr SPDAT  = 0xCF;	//

sfr PSW    = 0xD0;
sfr	T4T3M  = 0xD1;
sfr	T4H    = 0xD2;
sfr	T4L    = 0xD3;
sfr	T3H    = 0xD4;
sfr	T3L    = 0xD5;
sfr	T2H    = 0xD6;
sfr	T2L    = 0xD7;

sfr	TH4    = 0xD2;
sfr	TL4    = 0xD3;
sfr	TH3    = 0xD4;
sfr	TL3    = 0xD5;
sfr	TH2    = 0xD6;
sfr	TL2    = 0xD7;

sfr CCON   = 0xD8;	//
sfr CMOD   = 0xD9;	//
sfr CCAPM0 = 0xDA;	//PCA模块0的工作模式寄存器。
sfr CCAPM1 = 0xDB;	//PCA模块1的工作模式寄存器。
sfr CCAPM2 = 0xDC;	//PCA模块2的工作模式寄存器。
sfr CCAPM3 = 0xDD;	//PCA模块3的工作模式寄存器。
sfr	ADCCFG = 0xDE;	//

sfr ACC    = 0xE0;
sfr	P7M1   = 0xE1;
sfr	P7M0   = 0xE2;
sfr	DPS    = 0xE3;
sfr	DPL1   = 0xE4;
sfr	DPH1   = 0xE5;
sfr	CMPCR1 = 0xE6;
sfr	CMPCR2 = 0xE7;

sfr	P6     = 0xE8;
sfr CL     = 0xE9;	//
sfr CCAP0L = 0xEA;	//PCA模块0的捕捉/比较寄存器低8位。
sfr CCAP1L = 0xEB;	//PCA模块1的捕捉/比较寄存器低8位。
sfr CCAP2L = 0xEC;	//PCA模块2的捕捉/比较寄存器低8位。
sfr CCAP3L = 0xED;	//PCA模块3的捕捉/比较寄存器低8位。
sfr	AUXINTIF = 0xEF;	//辅助中断标志 B6-INT4IF, B5-INT3IF, B4-INT2IF, B2-T4IF, B1-T3IF, B0-T2IF

sfr B        = 0xF0;
sfr	PWMCFG   = 0xF1;	//PWM配置寄存器
sfr PCA_PWM0 = 0xF2;	//PCA模块0 PWM寄存器。
sfr PCA_PWM1 = 0xF3;	//PCA模块1 PWM寄存器。
sfr PCA_PWM2 = 0xF4;	//PCA模块2 PWM寄存器。
sfr PCA_PWM3 = 0xF5;	//PCA模块3 PWM寄存器。
sfr	PWMIF    = 0xF6;	//PWM中断标志寄存器
sfr	PWMFDCR  = 0xF7;	//PWM外部异常控制寄存器

sfr	P7     = 0xF8;
sfr CH     = 0xF9;
sfr CCAP0H = 0xFA;		//PCA模块0的捕捉/比较寄存器高8位。
sfr CCAP1H = 0xFB;		//PCA模块1的捕捉/比较寄存器高8位。
sfr CCAP2H = 0xFC;		//PCA模块2的捕捉/比较寄存器高8位。
sfr CCAP3H = 0xFD;		//PCA模块3的捕捉/比较寄存器高8位。
sfr	PWMCR  = 0xFE;		//PWM控制寄存器
sfr	RSTCFG = 0xFF;		//


//                                     7    6    5    4    3     2       1       0      Reset Value
//INT_CLKO:  中断与时钟输出控制寄存器  -   EX4  EX3  EX2   -   T2CLKO  T1CLKO  T0CLKO    0000,0000
#define	INT4_Enable()	INT_CLKO |= (1 << 6)
#define	INT3_Enable()	INT_CLKO |= (1 << 5)	
#define	INT2_Enable()	INT_CLKO |= (1 << 4)	
#define	INT1_Enable()	EX1 = 1
#define	INT0_Enable()	EX0 = 1

#define	INT4_Disable()	INT_CLKO &= ~(1 << 6)
#define	INT3_Disable()	INT_CLKO &= ~(1 << 5)	
#define	INT2_Disable()	INT_CLKO &= ~(1 << 4)	
#define	INT1_Disable()	EX1 = 0
#define	INT0_Disable()	EX0 = 0

//                               7    6       5       4      3    2     1     0      Reset Value
//AUXINTIF:  辅助中断标志寄存器  -  INT4IF  INT3IF  INT2IF   -   T4IF  T3IF  T2IF    0000,0000
#define	INT4IF	0x40
#define	INT3IF	0x20
#define	INT2IF	0x10
#define	T4IF	0x04
#define	T3IF	0x02
#define	T2IF	0x01

#define	INT4_Clear()	AUXINTIF &= ~INT4IF		/* 清除外中断4标志位 */
#define	INT3_Clear()	AUXINTIF &= ~INT3IF		/* 清除外中断3标志位 */
#define	INT2_Clear()	AUXINTIF &= ~INT2IF		/* 清除外中断2标志位 */
#define	INT1_Clear()	IE1 = 0					/* 清除外中断1标志位 */
#define	INT0_Clear()	IE0 = 0					/* 清除外中断0标志位 */

#define	INT0_Fall()		IT0 = 1		/* INT0 下降沿中断           */
#define	INT0_RiseFall()	IT0 = 0		/* INT0 下降沿上升沿均中断   */
#define	INT1_Fall()		IT1 = 1		/* INT1 下降沿中断           */
#define	INT1_RiseFall()	IT0 = 0		/* INT1 下降沿上升沿均中断   */


//===============================================================
#define	EAXSFR()		P_SW2 |=  0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */

#define CLKSEL      (*(unsigned char volatile xdata *)0xfe00)
#define	CKSEL		(*(unsigned char volatile xdata *)0xfe00)	/* 主时钟源选择    */
#define	CLKDIV		(*(unsigned char volatile xdata *)0xfe01)	/* 主时钟分频      */
#define	IRC24MCR	(*(unsigned char volatile xdata *)0xfe02)	/* IRC 24MHZ控制   */
#define	XOSCCR		(*(unsigned char volatile xdata *)0xfe03)	/* XOSC控制        */
#define	IRC32KCR	(*(unsigned char volatile xdata *)0xfe04)	/* IRC 32KHZ控制   */

#define	MainFosc_IRC24M()	CKSEL = (CKSEL & ~0x03)			/* 选择内部24MHZ时钟 */
#define	MainFosc_XTAL()		CKSEL = (CKSEL & ~0x03) | 0x01	/* 选择外部晶振或时钟 */
#define	EXT_CLOCK()			XOSCCR = 0x80					/* 选择外部时钟 */
#define	EXT_CRYSTAL()		XOSCCR = 0xC0					/* 选择外部晶振 */
#define	MainFosc_IRC32K()	CKSEL =  CKSEL | 0x03			/* 选择内部32K时钟 */
#define	MainFosc_OutP54()	CKSEL = (CKSEL & ~0x08)			/* 从P5.4输出主时钟分频 */
#define	MainFosc_OutP16()	CKSEL = (CKSEL |  0x08)			/* 从P1.6输出主时钟分频 */
#define	MCLKO_None()		CKSEL = (CKSEL &  0x0f)			/* 主时钟不输出 	*/
#define	MCLKO_DIV1()		CKSEL = (CKSEL &  0x0f) | 0x10	/* 主时钟1分频输出 */
#define	MCLKO_DIV2()		CKSEL = (CKSEL &  0x0f) | 0x20	/* 主时钟2分频输出  */
#define	MCLKO_DIV4()		CKSEL = (CKSEL &  0x0f) | 0x40	/* 主时钟4分频输出  */
#define	MCLKO_DIV8()		CKSEL = (CKSEL &  0x0f) | 0x60	/* 主时钟8分频输出  */
#define	MCLKO_DIV16()		CKSEL = (CKSEL &  0x0f) | 0x80	/* 主时钟16分频输出  */
#define	MCLKO_DIV32()		CKSEL = (CKSEL &  0x0f) | 0xa0	/* 主时钟32分频输出  */
#define	MCLKO_DIV64()		CKSEL = (CKSEL &  0x0f) | 0xc0	/* 主时钟64分频输出  */
#define	MCLKO_DIV128()		CKSEL = (CKSEL &  0x0f) | 0xe0	/* 主时钟128分频输出  */

#define	MCLKO_P54	0x00	/* 从P5.4输出主时钟分频 */
#define	MCLKO_P16	0x08	/* 从P1.6输出主时钟分频 */
#define	MCLKO_0		0x00	/* 主时钟不输出 	*/
#define	MCLKO_1		0x10	/* 主时钟1分频输出 */
#define	MCLKO_2		0x20	/* 主时钟2分频输出  */
#define	MCLKO_4		0x40	/* 主时钟4分频输出  */
#define	MCLKO_8		0x60	/* 主时钟8分频输出  */
#define	MCLKO_16	0x80	/* 主时钟16分频输出  */
#define	MCLKO_32	0xa0	/* 主时钟32分频输出  */
#define	MCLKO_64	0xc0	/* 主时钟64分频输出  */
#define	MCLKO_128	0xe0	/* 主时钟128分频输出  */


#define	P0PU		(*(unsigned char volatile xdata *)0xfe10)	/* P0 1.5K Pull Up Enable  */
#define	P1PU		(*(unsigned char volatile xdata *)0xfe11)	/* P1 1.5K Pull Up Enable  */
#define	P2PU		(*(unsigned char volatile xdata *)0xfe12)	/* P2 1.5K Pull Up Enable  */
#define	P3PU		(*(unsigned char volatile xdata *)0xfe13)	/* P3 1.5K Pull Up Enable  */
#define	P4PU		(*(unsigned char volatile xdata *)0xfe14)	/* P4 1.5K Pull Up Enable  */
#define	P5PU		(*(unsigned char volatile xdata *)0xfe15)	/* P5 1.5K Pull Up Enable  */
#define	P6PU		(*(unsigned char volatile xdata *)0xfe16)	/* P6 1.5K Pull Up Enable  */
#define	P7PU		(*(unsigned char volatile xdata *)0xfe17)	/* P7 1.5K Pull Up Enable  */

#define	P0NCS		(*(unsigned char volatile xdata *)0xfe18)	/* P0 Non Schmit Trigger  */
#define	P1NCS		(*(unsigned char volatile xdata *)0xfe19)	/* P1 Non Schmit Trigger  */
#define	P2NCS		(*(unsigned char volatile xdata *)0xfe1a)	/* P2 Non Schmit Trigger  */
#define	P3NCS		(*(unsigned char volatile xdata *)0xfe1b)	/* P3 Non Schmit Trigger  */
#define	P4NCS		(*(unsigned char volatile xdata *)0xfe1c)	/* P4 Non Schmit Trigger  */
#define	P5NCS		(*(unsigned char volatile xdata *)0xfe1d)	/* P5 Non Schmit Trigger  */
#define	P6NCS		(*(unsigned char volatile xdata *)0xfe1e)	/* P6 Non Schmit Trigger  */
#define	P7NCS		(*(unsigned char volatile xdata *)0xfe1f)	/* P7 Non Schmit Trigger  */

#define	I2CCFG		(*(unsigned char volatile xdata *)0xfe80)	/*   */
#define	I2CMSCR		(*(unsigned char volatile xdata *)0xfe81)	/*   */
#define	I2CMSST		(*(unsigned char volatile xdata *)0xfe82)	/*   */
#define	I2CSLCR		(*(unsigned char volatile xdata *)0xfe83)	/*   */
#define	I2CSLST		(*(unsigned char volatile xdata *)0xfe84)	/*   */
#define	I2CSLADR	(*(unsigned char volatile xdata *)0xfe85)	/*   */
#define	I2CTXD		(*(unsigned char volatile xdata *)0xfe86)	/*   */
#define	I2CRXD		(*(unsigned char volatile xdata *)0xfe87)	/*   */

#define PWM0T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM0T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM1T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM1T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff50)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff60)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff62)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff70)        
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff72)
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define TADCP      	(*(unsigned int  volatile xdata *)0xfff3)	/* 在 ETADC==1 的情况下,  每一个周期中, 当Counter计数到 TADCP[15:0] 时,自动启动 ADC */

#define PWM0T1H     (*(unsigned char volatile xdata *)0xff00)	/* PWM0T1计数高字节 */
#define PWM0T1L     (*(unsigned char volatile xdata *)0xff01)	/* PWM0T1计数低字节 */
#define PWM0T2H     (*(unsigned char volatile xdata *)0xff02)	/* PWM0T2计数高字节 */
#define PWM0T2L     (*(unsigned char volatile xdata *)0xff03)	/* PWM0T2计数低字节 */
#define PWM0CR      (*(unsigned char volatile xdata *)0xff04)	/* PWM0控制         */
#define PWM0HLD     (*(unsigned char volatile xdata *)0xff05)	/*          */

#define PWM1T1H     (*(unsigned char volatile xdata *)0xff10)	/* PWM1T1计数高字节 */
#define PWM1T1L     (*(unsigned char volatile xdata *)0xff11)	/* PWM1T1计数低字节 */
#define PWM1T2H     (*(unsigned char volatile xdata *)0xff12)	/* PWM1T2计数高字节 */
#define PWM1T2L     (*(unsigned char volatile xdata *)0xff13)	/* PWM1T2计数低字节 */
#define PWM1CR      (*(unsigned char volatile xdata *)0xff14)	/* PWM1控制         */
#define PWM1HLD     (*(unsigned char volatile xdata *)0xff15)	/*          */

#define PWM2T1H     (*(unsigned char volatile xdata *)0xff20)	/* PWM2T1计数高字节 */
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff21)	/* PWM2T1计数低字节 */
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff22)	/* PWM2T2计数高字节 */
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff23)	/* PWM2T2计数低字节 */
#define PWM2CR      (*(unsigned char volatile xdata *)0xff24)	/* PWM2控制         */
#define PWM2HLD     (*(unsigned char volatile xdata *)0xff25)	/*          */

#define PWM3T1H     (*(unsigned char volatile xdata *)0xff30)	/* PWM3T1计数高字节 */
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff31)	/* PWM3T1计数低字节 */
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff32)	/* PWM3T2计数高字节 */
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff33)	/* PWM3T2计数低字节 */
#define PWM3CR      (*(unsigned char volatile xdata *)0xff34)	/* PWM3控制         */
#define PWM3HLD     (*(unsigned char volatile xdata *)0xff35)	/*          */

#define PWM4T1H     (*(unsigned char volatile xdata *)0xff40)	/* PWM4T1计数高字节 */
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff41)	/* PWM4T1计数低字节 */
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff42)	/* PWM4T2计数高字节 */
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff43)	/* PWM4T2计数低字节 */
#define PWM4CR      (*(unsigned char volatile xdata *)0xff44)	/* PWM4控制         */
#define PWM4HLD     (*(unsigned char volatile xdata *)0xff45)	/*          */

#define PWM5T1H     (*(unsigned char volatile xdata *)0xff50)	/* PWM5T1计数高字节 */
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff51)	/* PWM5T1计数低字节 */
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff52)	/* PWM5T2计数高字节 */
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff53)	/* PWM5T2计数低字节 */
#define PWM5CR      (*(unsigned char volatile xdata *)0xff54)	/* PWM5控制         */
#define PWM5HLD     (*(unsigned char volatile xdata *)0xff15)	/*          */

#define PWM6T1H     (*(unsigned char volatile xdata *)0xff60)	/* PWM6T1计数高字节 */
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff61)	/* PWM6T1计数低字节 */
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff62)	/* PWM6T2计数高字节 */
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff63)	/* PWM6T2计数低字节 */
#define PWM6CR      (*(unsigned char volatile xdata *)0xff64)	/* PWM6控制         */
#define PWM6HLD     (*(unsigned char volatile xdata *)0xff65)	/*          */

#define PWM7T1H     (*(unsigned char volatile xdata *)0xff70)	/* PWM7T1计数高字节 */        
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff71)	/* PWM7T1计数低字节 */
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff72)	/* PWM7T2计数高字节 */
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff73)	/* PWM7T2计数低字节 */
#define PWM7CR      (*(unsigned char volatile xdata *)0xff74)	/* PWM7控制         */
#define PWM7HLD     (*(unsigned char volatile xdata *)0xff75)	/*          */

#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)	/* PWM计数器高字节  */
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)	/* PWM计数器低字节  */
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)	/* PWM时钟选择      */
#define TADCPH      (*(unsigned char volatile xdata *)0xfff3)	/* 在 ETADC==1 的情况下,  每一个周期中, 当Counter计数到 TADCP[15:0] 时,自动启动 ADC*/
#define TADCPL      (*(unsigned char volatile xdata *)0xfff4)	/* 触发ADC选择低字节*/


#define	PWM0_ID		0
#define	PWM1_ID		1
#define	PWM2_ID		2
#define	PWM3_ID		3
#define	PWM4_ID		4
#define	PWM5_ID		5
#define	PWM6_ID		6
#define	PWM7_ID		7

#define	PwmClk_T2	0

//                    7   6   5   4     3        2       1        0      Reset Value
//PWMnCR:  PWMn控制   ENCnO   -   -   -   PWMn_PS  EPWMnI  ECnT2SI  ECnT1SI   0000,0000
#define	PWM_ENCnO		0x80	/* PWM管脚选择位 */
#define	PWM_CnINI		0x40	/* PWM管脚选择位 */
#define	PWMn_PS_0		0x00	/* PWM管脚选择位 */
#define	PWMn_PS_1		0x08	/* PWM管脚选择位 */
#define	PWMn_PS_2		0x10	/* PWM管脚选择位 */
#define	PWM_ECnI		0x04	/* 允许PWM中断   */
#define	PWM_ECnT2SI		0x02	/* 允许T2翻转时中断 */
#define	PWM_ECnT1SI		0x01	/* 允许T1翻转时中断 */

#define	PWM0_P20	0x00
#define	PWM0_P10	0x08
#define	PWM0_P60	0x10
#define	PWM1_P21	0x00
#define	PWM1_P11	0x08
#define	PWM1_P61	0x10
#define	PWM2_P22	0x00
#define	PWM2_P12	0x08
#define	PWM2_P62	0x10
#define	PWM3_P23	0x00
#define	PWM3_P13	0x08
#define	PWM3_P63	0x10
#define	PWM4_P24	0x00
#define	PWM4_P14	0x08
#define	PWM4_P64	0x10
#define	PWM5_P25	0x00
#define	PWM5_P15	0x08
#define	PWM5_P65	0x10
#define	PWM6_P26	0x00
#define	PWM6_P16	0x08
#define	PWM6_P66	0x10
#define	PWM7_P27	0x00
#define	PWM7_P17	0x08
#define	PWM7_P67	0x10

//                      7      6    5   4   3  2  1  0   Reset Value
//PWMCFG:  配置寄存器  CBIF  ETADC  -   -   -  -  -  -    0000,0000
#define	CBIF	0x80	/* PWM计数器归零中断标志位 */
#define	ETADC	0x40	/* PWM与ADC关联, 由TADCP设置触发时刻. */

//                        7     6     5     4     3     2     1     0     Reset Value
//PWMIF: 中断标志寄存器  C7IF  C6IF  C5IF  C4IF  C3IF  C2IF  C1IF  C0IF    0000,0000
#define	C7IF	0x80
#define	C6IF	0x40	/* 第n通道的PWM中断标志位 */
#define	C5IF	0x20
#define	C4IF	0x10
#define	C3IF	0x08
#define	C2IF	0x04
#define	C1IF	0x02
#define	C0IF	0x01

//                        7     6     5     4     3     2     1     0     Reset Value
//PWMFDCR: 异常检测控制寄存器  C7IF  C6IF  C5IF  C4IF  C3IF  C2IF  C1IF  C0IF    0000,0000
#define	INVCMP		0x80	/* 0: 比较器结果由低变高为异常信号, 1: 比较器结果由高变低为异常信号 */
#define	INVIO		0x40	/* 0: P3.5由低变高为异常信号, 1: P3.5由高变低为异常信号*/
#define	INVP35		0x40	/* 0: P3.5由低变高为异常信号, 1: P3.5由高变低为异常信号*/
#define	ENFD		0x20	/* 0: 关闭PWM外部异常检测功, 1: 允许PWM外部异常检测功 */
#define	FLTFLIO		0x10	/* 0: 发生WM外部异常时，PWM的输出口不变,  1: 发生WM外部异常时，PWM的输出口立即被设置为高阻输入模式。（注：只有ENCnO==1所对应的端口才会被强制悬空） */
#define	EFDI		0x08	/* 1: 使能PWM异常检测中断, 0: 关闭PWM异常检测中断(FDIF依然会被硬件置位) */
#define	FDCMP		0x04	/* 1: 设定PWM异常检测源为比较器输出(异常类型由INVCMP设定), 0: 比较器与PWM无关 */
#define	FDIO		0x02	/* 1: P3.5设置为PWM异常检测, 异常类型由INVIO设定, 0: P3.5与PWM无关 */
#define	FDIF		0x01	/* 异常中断标志位, 当发生PWM异常（比较器的输出由低变高或者P3.5的电平由低变高）时，硬件自动将此位置1, 并置位中断标志.需要软件清零 */
#define	PWM_FaultDetect_Enable()	PWMFDCR |=  0x20		/* 使能PWM的外部异常检测功能 */
#define	PWM_FaultDetect_Disable()	PWMFDCR &= ~0x20		/* 禁止PWM的外部异常检测功能 */

//                        7     6    5  4  3  2  1  0   Reset Value
//PWMCR: PWM控制寄存器  ENPWM  ECBI  -  -  -  -  -  -   0000,0000
#define	ENPWM	0x80	/* 使能PWM波形发生器，PWM计数器开始计数 */
#define	ECBI	0x40	/* 使能PWM计数器归零中断 */
#define	PWM_Enable()	PWMCR |=  0x80	/* 使能PWM波形发生器，PWM计数器开始计数 */
#define	PWM_Disable()	PWMCR &= ~0x80	/* 关闭PWM波形发生器 */



/*  BIT Registers  */
/*  PSW   */
sbit CY   = PSW^7;
sbit AC   = PSW^6;
sbit F0   = PSW^5;
sbit RS1  = PSW^4;
sbit RS0  = PSW^3;
sbit OV   = PSW^2;
sbit F1   = PSW^1;
sbit P    = PSW^0;

/*  TCON  */
sbit TF1  = TCON^7;	//定时器1溢出中断标志位
sbit TR1  = TCON^6;	//定时器1运行控制位
sbit TF0  = TCON^5;	//定时器0溢出中断标志位
sbit TR0  = TCON^4;	//定时器0运行控制位
sbit IE1  = TCON^3;	//外中断1标志位
sbit IT1  = TCON^2;	//外中断1信号方式控制位，1：下降沿中断，0：上升下降均中断。
sbit IE0  = TCON^1;	//外中断0标志位
sbit IT0  = TCON^0;	//外中断0信号方式控制位，1：下降沿中断，0：上升下降均中断。

/*  P0  */
sbit  P00 = P0^0;
sbit  P01 = P0^1;
sbit  P02 = P0^2;
sbit  P03 = P0^3;
sbit  P04 = P0^4;
sbit  P05 = P0^5;
sbit  P06 = P0^6;
sbit  P07 = P0^7;

/*  P1  */
sbit  P10 = P1^0;
sbit  P11 = P1^1;
sbit  P12 = P1^2;
sbit  P13 = P1^3;
sbit  P14 = P1^4;
sbit  P15 = P1^5;
sbit  P16 = P1^6;
sbit  P17 = P1^7;

sbit  RXD2      = P1^0;
sbit  TXD2      = P1^1;
sbit  CCP1      = P1^0;
sbit  CCP0      = P1^1;
sbit  SPI_SS    = P1^2;
sbit  SPI_MOSI  = P1^3;
sbit  SPI_MISO  = P1^4;
sbit  SPI_SCLK  = P1^5;

sbit  SPI_SS_2    = P2^4;
sbit  SPI_MOSI_2  = P2^3;
sbit  SPI_MISO_2  = P2^2;
sbit  SPI_SCLK_2  = P2^1;

sbit  SPI_SS_3    = P5^4;
sbit  SPI_MOSI_3  = P4^0;
sbit  SPI_MISO_3  = P4^1;
sbit  SPI_SCLK_3  = P4^3;

/*  P2  */
sbit  P20 = P2^0;
sbit  P21 = P2^1;
sbit  P22 = P2^2;
sbit  P23 = P2^3;
sbit  P24 = P2^4;
sbit  P25 = P2^5;
sbit  P26 = P2^6;
sbit  P27 = P2^7;

/*  P3  */
sbit  P30 = P3^0;
sbit  P31 = P3^1;
sbit  P32 = P3^2;
sbit  P33 = P3^3;
sbit  P34 = P3^4;
sbit  P35 = P3^5;
sbit  P36 = P3^6;
sbit  P37 = P3^7;

sbit RXD  = P3^0;
sbit TXD  = P3^1;
sbit INT0 = P3^2;
sbit INT1 = P3^3;
sbit T0   = P3^4;
sbit T1   = P3^5;
sbit WR   = P3^6;
sbit RD   = P3^7;
sbit CCP2  = P3^7;

sbit CLKOUT0   = P3^5;
sbit CLKOUT1   = P3^4;

/*  P4  */
sbit  P40 = P4^0;
sbit  P41 = P4^1;
sbit  P42 = P4^2;
sbit  P43 = P4^3;
sbit  P44 = P4^4;
sbit  P45 = P4^5;
sbit  P46 = P4^6;
sbit  P47 = P4^7;

/*  P5  */
sbit  P50 = P5^0;
sbit  P51 = P5^1;
sbit  P52 = P5^2;
sbit  P53 = P5^3;
sbit  P54 = P5^4;
sbit  P55 = P5^5;
sbit  P56 = P5^6;
sbit  P57 = P5^7;

/*  P6  */
sbit  P60 = P6^0;
sbit  P61 = P6^1;
sbit  P62 = P6^2;
sbit  P63 = P6^3;
sbit  P64 = P6^4;
sbit  P65 = P6^5;
sbit  P66 = P6^6;
sbit  P67 = P6^7;

/*  P7  */
sbit  P70 = P7^0;
sbit  P71 = P7^1;
sbit  P72 = P7^2;
sbit  P73 = P7^3;
sbit  P74 = P7^4;
sbit  P75 = P7^5;
sbit  P76 = P7^6;
sbit  P77 = P7^7;


/*  SCON  */
sbit SM0  = SCON^7;	//SM0/FE		SM0 SM1 = 00 ~ 11: 方式0~3
sbit SM1  = SCON^6;	//
sbit SM2  = SCON^5;	//多机通讯
sbit REN  = SCON^4;	//接收允许
sbit TB8  = SCON^3;	//发送数据第8位
sbit RB8  = SCON^2;	//接收数据第8位
sbit TI   = SCON^1;	//发送中断标志位
sbit RI   = SCON^0;	//接收中断标志位

/*  IE   */
sbit EA   = IE^7;	//中断允许总控制位
sbit ELVD = IE^6;	//低压监测中断允许位
sbit EADC = IE^5;	//ADC 中断 允许位
sbit ES   = IE^4;	//串行中断 允许控制位
sbit ET1  = IE^3;	//定时中断1允许控制位
sbit EX1  = IE^2;	//外部中断1允许控制位
sbit ET0  = IE^1;	//定时中断0允许控制位
sbit EX0  = IE^0;	//外部中断0允许控制位

sbit ACC0 = ACC^0;
sbit ACC1 = ACC^1;
sbit ACC2 = ACC^2;
sbit ACC3 = ACC^3;
sbit ACC4 = ACC^4;
sbit ACC5 = ACC^5;
sbit ACC6 = ACC^6;
sbit ACC7 = ACC^7;

sbit B0 = B^0;
sbit B1 = B^1;
sbit B2 = B^2;
sbit B3 = B^3;
sbit B4 = B^4;
sbit B5 = B^5;
sbit B6 = B^6;
sbit B7 = B^7;


//							7     6     5    4    3    2    1     0    Reset Value
//sfr IE2       = 0xAF;		-     -     -    -    -    -   ESPI  ES2   0000,0000B	//Auxiliary Interrupt   
#define		SPI_INT_ENABLE()		IE2 |=  2	/* 允许SPI中断		*/
#define		SPI_INT_DISABLE()		IE2 &= ~2	/* 允许SPI中断		*/
#define		UART2_INT_ENABLE()		IE2 |=  1	/* 允许串口2中断	*/
#define		UART2_INT_DISABLE()		IE2 &= ~1	/* 允许串口2中断	*/

//                                          7     6     5    4    3    2    1    0    Reset Value
//sfr IP      = 0xB8; //中断优先级低位      PPCA  PLVD  PADC  PS   PT1  PX1  PT0  PX0   0000,0000
//--------
sbit PPCA	= IP^7;	//PCA 模块中断优先级
sbit PLVD	= IP^6;	//低压监测中断优先级
sbit PADC	= IP^5;	//ADC 中断优先级
sbit PS   	= IP^4;	//串行中断0优先级设定位
sbit PT1	= IP^3;	//定时中断1优先级设定位
sbit PX1	= IP^2;	//外部中断1优先级设定位
sbit PT0	= IP^1;	//定时中断0优先级设定位
sbit PX0	= IP^0;	//外部中断0优先级设定位

//                                           7      6      5     4     3     2    1     0        Reset Value
//sfr IPH   = 0xB7; //中断优先级高位       PPCAH  PLVDH  PADCH  PSH  PT1H  PX1H  PT0H  PX0H   0000,0000
//sfr IP2   = 0xB5; //                       -      -      -     -     -     -   PSPI   PS2   xxxx,xx00
//sfr IP2H  = 0xB6; //                       -      -      -     -     -     -   PSPIH  PS2H  xxxx,xx00
#define		PPCAH	0x80
#define		PLVDH	0x40
#define		PADCH	0x20
#define		PSH		0x10
#define		PT1H	0x08
#define		PX1H	0x04
#define		PT0H	0x02
#define		PX0H	0x01

#define		PCA_InterruptFirst()	PPCA = 1
#define		LVD_InterruptFirst()	PLVD = 1
#define		ADC_InterruptFirst()	PADC = 1
#define		UART1_InterruptFirst()	PS   = 1
#define		Timer1_InterruptFirst()	PT1  = 1
#define		INT1_InterruptFirst()	PX1  = 1
#define		Timer0_InterruptFirst()	PT0  = 1
#define		INT0_InterruptFirst()	PX0  = 1


/*************************************************************************************************/


//                       7      6     5    4    3    2     1      0        Reset Value
//sfr CMPCR1 = 0xE6;   CMPEN  CMPIF  PIE  NIE  PIS  NIS  CMPOE  CMPRES      00000000B
#define	CMPEN	0x80	//1: 允许比较器, 0: 禁止,关闭比较器电源
#define	CMPIF	0x40	//比较器中断标志, 包括上升沿或下降沿中断, 软件清0
#define	PIE		0x20	//1: 比较结果由0变1, 产生上升沿中断
#define	NIE		0x10	//1: 比较结果由1变0, 产生下降沿中断
#define	PIS		0x08	//输入正极性选择, 0: 选择内部P5.5做正输入,           1: 由ADCIS[2:0]所选择的ADC输入端做正输入.
#define	NIS		0x04	//输入负极性选择, 0: 选择内部BandGap电压BGv做负输入, 1: 选择外部P5.4做输入.
#define	CMPOE	0x02	//1: 允许比较结果输出到P1.2, 0: 禁止.
#define	CMPRES	0x01	//比较结果, 1: CMP+电平高于CMP-,  0: CMP+电平低于CMP-,  只读

//                       7        6       5  4  3  2  1  0    Reset Value
//sfr CMPCR2 = 0xE7;   INVCMPO  DISFLT       LCDTY[5:0]       00001001B
#define	INVCMPO	0x80	//1: 比较器输出取反,  0: 不取反
#define	DISFLT	0x40	//1: 关闭0.1uF滤波,   0: 允许
#define	LCDTY	0x00	//0~63, 比较结果变化延时周期数


/*************************************************************************************************/
//                     7     6     5    4    3    2   1   0       Reset Value
//sfr SCON  = 0x98;   SM0   SM1   SM2  REN  TB8  RB8  TI  RI      00000000B		 //S1 Control

#define		S1_DoubleRate()		PCON  |=  0x80
#define		S1_SHIFT()			SCON  &=  0x3f

#define		S1_8bit()			SCON   =  (SCON & 0x3f) | 0x40
#define		S1_9bit()			SCON   =  (SCON & 0x3f) | 0xc0
#define		S1_RX_Enable()		SCON  |=  0x10
#define		S1_RX_Disable()		SCON  &= ~0x10
#define		TI1					TI					/* 判断TI1是否发送完成								 */
#define		RI1					RI					/* 判断RI1是否接收完成								 */
#define		SET_TI1()			TI = 1				/* 设置TI1(引起中断)								 */
#define		CLR_TI1()			TI = 0				/* 清除TI1											 */
#define		CLR_RI1()			RI = 0				/* 清除RI1											 */
#define		S1TB8_SET()			TB8 = 1				/* 设置TB8											 */
#define		S1TB8_CLR()			TB8 = 0				/* 清除TB8											 */
#define		S1_Int_Enable()		ES     =  1			/* 串口1允许中断									 */
#define		S1_Int_Disable()	ES     =  0			/* 串口1禁止中断									 */
#define 	S1_BRT_UseTimer1()	AUXR  &= ~1
#define 	S1_BRT_UseTimer2()	AUXR  |=  1
#define		S1_USE_P30P31()		P_SW1 &= ~0xc0						//UART1 使用P30 P31口	默认
#define		S1_USE_P36P37()		P_SW1  =  (P_SW1 & ~0xc0) | 0x40	//UART1 使用P36 P37口
#define		S1_USE_P16P17()		P_SW1  =  (P_SW1 & ~0xc0) | 0x80	//UART1 使用P16 P17口
#define		S1_TXD_RXD_SHORT()	PCON2 |=  (1<<4)	//将TXD与RXD连接中继输出
#define		S1_TXD_RXD_OPEN()	PCON2 &= ~(1<<4)	//将TXD与RXD连接中继断开	默认

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S2CON = 0x9A;		S2SM0    -    S2SM2  S2REN  S2TB8  S2RB8  S2TI  S2RI      00000000B		 //S2 Control

#define		S2_MODE0()			S2CON &= ~(1<<7)	/* 串口2模式0，8位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_MODE1()			S2CON |=  (1<<7)	/* 串口2模式1，9位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_8bit()			S2CON &= ~(1<<7)	/* 串口2模式0，8位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_9bit()			S2CON |=  (1<<7)	/* 串口2模式1，9位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_RX_Enable()		S2CON |=  (1<<4)	/* 允许串2接收										 */
#define		S2_RX_Disable()		S2CON &= ~(1<<4)	/* 禁止串2接收										 */
#define		TI2					(S2CON & 2) != 0	/* 判断TI2是否发送完成								 */
#define		RI2					(S2CON & 1) != 0	/* 判断RI2是否接收完成								 */
#define		SET_TI2()			S2CON |=  (1<<1)	/* 设置TI2(引起中断)								 */
#define		CLR_TI2()			S2CON &= ~(1<<1)	/* 清除TI2											 */
#define		CLR_RI2()			S2CON &= ~1			/* 清除RI2											 */
#define		S2TB8_SET()			S2CON |=  (1<<3)	/* 设置TB8											 */
#define		S2TB8_CLR()			S2CON &= ~(1<<3)	/* 清除TB8											 */
#define		S2_Int_Enable()		IE2   |=  1			/* 串口2允许中断									 */
#define		S2_Int_Disable()	IE2   &= ~1			/* 串口2禁止中断									 */
#define		S2_USE_P10P11()		P_SW2 &= ~1			/* UART2 使用P1口	默认							 */
#define		S2_USE_P46P47()		P_SW2 |=  1			/* UART2 使用P4口									 */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S3CON = 0xAC;		S3SM0  S3ST3  S3SM2  S3REN  S3TB8  S3RB8  S3TI  S3RI      00000000B		 //S3 Control

#define		S3_MODE0()			S3CON &= ~(1<<7)	/* 串口3模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_MODE1()			S3CON |=  (1<<7)	/* 串口3模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_8bit()			S3CON &= ~(1<<7)	/* 串口3模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_9bit()			S3CON |=  (1<<7)	/* 串口3模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_RX_Enable()		S3CON |=  (1<<4)	/* 允许串3接收									     */
#define		S3_RX_Disable()		S3CON &= ~(1<<4)	/* 禁止串3接收									     */
#define		TI3					(S3CON & 2) != 0	/* 判断TI3是否发送完成								 */
#define		RI3					(S3CON & 1) != 0	/* 判断RI3是否接收完成								 */
#define		SET_TI3()			S3CON |=  (1<<1)	/* 设置TI3(引起中断)								 */
#define		CLR_TI3()			S3CON &= ~(1<<1)	/* 清除TI3											 */
#define		CLR_RI3()			S3CON &= ~1			/* 清除RI3											 */
#define		S3TB8_SET()			S3CON |=  (1<<3)	/* 设置TB8											 */
#define		S3TB8_CLR()			S3CON &= ~(1<<3)	/* 清除TB8											 */
#define		S3_Int_Enable()		IE2   |=  (1<<3)	/* 串口3允许中断								     */
#define		S3_Int_Disable()	IE2   &= ~(1<<3)	/* 串口3禁止中断								     */
#define 	S3_BRT_UseTimer3()	S3CON |=  (1<<6)	/* BRT select Timer3								 */
#define 	S3_BRT_UseTimer2()	S3CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S3_USE_P00P01()		P_SW2 &= ~2			/* UART3 使用P0口	默认						     */
#define		S3_USE_P50P51()		P_SW2 |=  2			/* UART3 使用P5口								     */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S4CON = 0x84;		S4SM0  S4ST4  S4SM2  S4REN  S4TB8  S4RB8  S4TI  S4RI      00000000B		 //S4 Control

#define		S4_MODE0()			S4CON &= ~(1<<7)	/* 串口4模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_MODE1()			S4CON |=  (1<<7)	/* 串口4模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_8bit()			S4CON &= ~(1<<7)	/* 串口4模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_9bit()			S4CON |=  (1<<7)	/* 串口4模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_RX_Enable()		S4CON |=  (1<<4)	/* 允许串4接收									     */
#define		S4_RX_Disable()		S4CON &= ~(1<<4)	/* 禁止串4接收									     */
#define		TI4					(S4CON & 2) != 0	/* 判断TI3是否发送完成							     */
#define		RI4					(S4CON & 1) != 0	/* 判断RI3是否接收完成							     */
#define		SET_TI4()			S4CON |=  2			/* 设置TI3(引起中断)							     */
#define		CLR_TI4()			S4CON &= ~2			/* 清除TI3										     */
#define		CLR_RI4()			S4CON &= ~1			/* 清除RI3										     */
#define		S4TB8_SET()			S4CON |=  8			/* 设置TB8										     */
#define		S4TB8_CLR()			S4CON &= ~8			/* 清除TB8										     */
#define		S4_Int_Enable()		IE2   |=  (1<<4)	/* 串口4允许中断								     */
#define		S4_Int_Disable()	IE2   &= ~(1<<4)	/* 串口4禁止中断								     */
#define 	S4_BRT_UseTimer4()	S4CON |=  (1<<6)	/* BRT select Timer4								 */
#define 	S4_BRT_UseTimer2()	S4CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S4_USE_P02P03()		P_SW2 &= ~4			/* UART4 使用P0口	默认						     */
#define		S4_USE_P52P53()		P_SW2 |=  4			/* UART4 使用P5口								     */




/**********************************************************/
//						   7     6       5      4     3      2      1      0    Reset Value
//sfr AUXR  = 0x8E;		T0x12 T1x12 UART_M0x6  T2R  T2_C/T T2x12 EXTRAM  S1ST2  0000,0000	//Auxiliary Register 

#define 	ExternalRAM_enable()		AUXR |=  2		/* 允许外部XRAM，禁止使用内部1024RAM     */
#define 	InternalRAM_enable()		AUXR &= ~2		/* 禁止外部XRAM，允许使用内部1024RAM     */
#define		S1_M0x6()					AUXR |=  (1<<5)	/* UART Mode0 Speed is 6x Standard       */
#define		S1_M0x1()					AUXR &= ~(1<<5)	/* default,	UART Mode0 Speed is Standard */

//====================================
#define		Timer0_16bitAutoReload()	TMOD &= ~0x03					/* 16位自动重装	*/
#define		Timer0_16bit()				TMOD  = (TMOD & ~0x03) | 0x01	/* 16位         */
#define		Timer0_8bitAutoReload()		TMOD  = (TMOD & ~0x03) | 0x02	/* 8位自动重装	*/
#define		Timer0_16bitAutoRL_NoMask()	TMOD |=  0x03		/* 16位自动重装不可屏蔽中断	*/
#define 	Timer0_Run()	 			TR0 = 1				/* 允许定时器0计数			*/
#define 	Timer0_Stop()	 			TR0 = 0				/* 禁止定时器0计数			*/
#define		Timer0_Gate_INT0_P32()		TMOD |=  (1<<3)		/* 时器0由外部INT0高电平允许定时计数 */
#define		Timer0_AsTimer()			TMOD &= ~(1<<2)		/* 时器0用做定时器	*/
#define		Timer0_AsCounter()			TMOD |=  (1<<2)		/* 时器0用做计数器	*/
#define		Timer0_AsCounterP34()		TMOD |=  (1<<2)		/* 时器0用做计数器	*/
#define 	Timer0_1T()					AUXR |=  (1<<7)		/* Timer0 clodk = fo	*/
#define 	Timer0_12T()				AUXR &= ~(1<<7)		/* Timer0 clodk = fo/12	12分频,	default	*/
#define		Timer0_CLKO_Enable()		INT_CLKO |=  1			/* 允许 T0 溢出脉冲在T0(P3.5)脚输出，Fck0 = 1/2 T0 溢出率，T0可以1T或12T。	*/
#define		Timer0_CLKO_Disable()		INT_CLKO &= ~1
#define		Timer0_CLKO_Enable_P34()	INT_CLKO |=  1			/* 允许 T0 溢出脉冲在T0(P3.5)脚输出，Fck0 = 1/2 T0 溢出率，T0可以1T或12T。	*/
#define		Timer0_CLKO_Disable_P34()	INT_CLKO &= ~1
#define 	Timer0_InterruptEnable()	ET0 = 1				/* 允许Timer1中断.*/
#define 	Timer0_InterruptDisable()	ET0 = 0				/* 禁止Timer1中断.*/

#define		T0_Load(n)					TH0 = (n) / 256,	TL0 = (n) % 256
#define		T0_Load_us_1T(n)			Timer0_AsTimer(),Timer0_1T(), Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL0=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T0_Load_us_12T(n)			Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL0=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T0_Frequency_1T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_1T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit0,TR0=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T0_Frequency_12T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit0,TR0=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define		Timer1_16bitAutoReload()	TMOD &= ~0x30					/* 16位自动重装	*/
#define		Timer1_16bit()				TMOD  = (TMOD & ~0x30) | 0x10	/* 16位			*/
#define		Timer1_8bitAutoReload()		TMOD  = (TMOD & ~0x30) | 0x20	/* 8位自动重装	*/
#define 	Timer1_Run()	 			TR1 = 1				/* 允许定时器1计数			*/
#define 	Timer1_Stop()	 			TR1 = 0				/* 禁止定时器1计数			*/
#define		Timer1_Gate_INT1_P33()		TMOD |=  (1<<7)		/* 时器1由外部INT1高电平允许定时计数	*/
#define		Timer1_AsTimer()			TMOD &= ~(1<<6)		/* 时器1用做定时器			*/
#define		Timer1_AsCounter()			TMOD |=  (1<<6)		/* 时器1用做计数器			*/
#define		Timer1_AsCounterP35()		TMOD |=  (1<<6)		/* 时器1用做计数器			*/
#define 	Timer1_1T()					AUXR |=  (1<<6)		/* Timer1 clodk = fo		*/
#define 	Timer1_12T()				AUXR &= ~(1<<6)		/* Timer1 clodk = fo/12	12分频,	default	*/
#define		Timer1_CLKO_Enable()		INT_CLKO |=  2			/* 允许 T1 溢出脉冲在T1(P3.4)脚输出，Fck1 = 1/2 T1 溢出率，T1可以1T或12T。	*/
#define		Timer1_CLKO_Disable()		INT_CLKO &= ~2
#define		Timer1_CLKO_Enable_P35()	INT_CLKO |=  2			/* 允许 T1 溢出脉冲在T1(P3.4)脚输出，Fck1 = 1/2 T1 溢出率，T1可以1T或12T。	*/
#define		Timer1_CLKO_Disable_P35()	INT_CLKO &= ~2
#define 	Timer1_InterruptEnable()	ET1 = 1				/* 允许Timer1中断.	*/
#define 	Timer1_InterruptDisable()	ET1 = 0				/* 禁止Timer1中断.	*/

#define		T1_Load(n)					TH1 = (n) / 256,	TL1 = (n) % 256
#define		T1_Load_us_1T(n)			Timer1_AsTimer(),Timer1_1T(), Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T1_Load_us_12T(n)			Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T1_Frequency_1T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_1T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit1,TR1=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T1_Frequency_12T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit1,TR1=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer2_Run()	 			AUXR |=  (1<<4)	/* 允许定时器2计数	*/
#define 	Timer2_Stop()	 			AUXR &= ~(1<<4)	/* 禁止定时器2计数	*/
#define		Timer2_AsTimer()			AUXR &= ~(1<<3)	/* 时器2用做定时器	*/
#define		Timer2_AsCounter()			AUXR |=  (1<<3)	/* 时器2用做计数器	*/
#define		Timer2_AsCounterP31()		AUXR |=  (1<<3)	/* 时器2用做计数器	*/
#define 	Timer2_1T()					AUXR |=  (1<<2)	/* Timer0 clock = fo	*/
#define 	Timer2_12T()				AUXR &= ~(1<<2)	/* Timer0 clock = fo/12	12分频,	default	*/
#define		Timer2_CLKO_Enable()		INT_CLKO |=  4		/* 允许 T2 溢出脉冲在T1(P3.0)脚输出，Fck2 = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer2_CLKO_Disable()		INT_CLKO &= ~4
#define		Timer2_CLKO_Enable_P30()	INT_CLKO |=  4		/* 允许 T2 溢出脉冲在T1(P3.0)脚输出，Fck2 = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer2_CLKO_Disable_P30()	INT_CLKO &= ~4
#define 	Timer2_InterruptEnable()	IE2  |=  (1<<2)	/* 允许Timer2中断.	*/
#define 	Timer2_InterruptDisable()	IE2  &= ~(1<<2)	/* 禁止Timer2中断.	*/

#define		T2_Load(n)					TH2 = (n) / 256,	TL2 = (n) % 256
#define		T2_Load_us_1T(n)			Timer2_AsTimer(),Timer2_1T(), TH2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T2_Load_us_12T(n)			Timer2_AsTimer(),Timer2_12T(),TH2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T2_Frequency_1T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_1T(), TH2=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL2=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T2_Frequency_12T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_12T(),TH2=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL2=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer3_Run()	 			T4T3M |=  (1<<3)	/* 允许定时器3计数	*/
#define 	Timer3_Stop()	 			T4T3M &= ~(1<<3)	/* 禁止定时器3计数	*/
#define		Timer3_AsTimer()			T4T3M &= ~(1<<2)	/* 时器3用做定时器	*/
#define		Timer3_AsCounter()			T4T3M |=  (1<<2)	/* 时器3用做计数器, P0.5为外部脉冲	*/
#define		Timer3_AsCounterP05()		T4T3M |=  (1<<2)	/* 时器3用做计数器, P0.5为外部脉冲	*/
#define 	Timer3_1T()					T4T3M |=  (1<<1)	/* 1T模式	*/
#define 	Timer3_12T()				T4T3M &= ~(1<<1)	/* 12T模式,	default	*/
#define		Timer3_CLKO_Enable()		T4T3M |=  1			/* 允许T3溢出脉冲在T3(P0.4)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer3_CLKO_Disable()		T4T3M &= ~1			/* 禁止T3溢出脉冲在T3(P0.4)脚输出	*/
#define		Timer3_CLKO_Enable_P04()	T4T3M |=  1			/* 允许T3溢出脉冲在T3(P0.4)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer3_CLKO_Disable_P04()	T4T3M &= ~1			/* 禁止T3溢出脉冲在T3(P0.4)脚输出	*/
#define 	Timer3_InterruptEnable()	IE2  |=  (1<<5)		/* 允许Timer3中断.	*/
#define 	Timer3_InterruptDisable()	IE2  &= ~(1<<5)		/* 禁止Timer3中断.	*/

#define		T3_Load(n)					TH3 = (n) / 256,	TL3 = (n) % 256
#define		T3_Load_us_1T(n)			Timer3_AsTimer(),Timer3_1T(), TH3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T3_Load_us_12T(n)			Timer3_AsTimer(),Timer3_12T(),TH3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T3_Frequency_1T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_1T(), TH3=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL3=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T3_Frequency_12T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_12T(),TH3=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL3=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer4_Run()	 			T4T3M |=  (1<<7)	/* 允许定时器4计数	*/
#define 	Timer4_Stop()	 			T4T3M &= ~(1<<7)	/* 禁止定时器4计数	*/
#define		Timer4_AsTimer()			T4T3M &= ~(1<<6)	/* 时器4用做定时器  */
#define		Timer4_AsCounter()			T4T3M |=  (1<<6)	/* 时器4用做计数器, P0.7为外部脉冲	*/
#define		Timer4_AsCounterP07()		T4T3M |=  (1<<6)	/* 时器4用做计数器, P0.7为外部脉冲	*/
#define 	Timer4_1T()					T4T3M |=  (1<<5)	/* 1T模式	*/
#define 	Timer4_12T()				T4T3M &= ~(1<<5)	/* 12T模式,	default	*/
#define		Timer4_CLKO_Enable()		T4T3M |=  (1<<4)	/* 允许T4溢出脉冲在T4(P0.6)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer4_CLKO_Disable()		T4T3M &= ~(1<<4)	/* 禁止T4溢出脉冲在T4(P0.6)脚输出	*/
#define		Timer4_CLKO_Enable_P06()	T4T3M |=  (1<<4)	/* 允许T4溢出脉冲在T4(P0.6)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer4_CLKO_Disable_P06()	T4T3M &= ~(1<<4)	/* 禁止T4溢出脉冲在T4(P0.6)脚输出	*/
#define 	Timer4_InterruptEnable()	IE2  |=  (1<<6)		/* 允许Timer4中断.	*/
#define 	Timer4_InterruptDisable()	IE2  &= ~(1<<6)		/* 禁止Timer4中断.	*/

#define		T4_Load(n)					TH4 = (n) / 256,	TL4 = (n) % 256
#define		T4_Load_us_1T(n)			Timer4_AsTimer(),Timer4_1T(), TH4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T4_Load_us_12T(n)			Timer4_AsTimer(),Timer4_12T(),TH4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T4_Frequency_1T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_1T(), TH4=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL4=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T4_Frequency_12T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_12T(),TH4=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL4=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
//====================================================================================================================

//sfr WDT_CONTR = 0xC1; //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
#define D_WDT_FLAG			(1<<7)
#define D_EN_WDT			(1<<5)
#define D_CLR_WDT			(1<<4)	/* auto clear	*/
#define D_IDLE_WDT			(1<<3)	/* WDT counter when Idle	*/
#define D_WDT_SCALE_2		0
#define D_WDT_SCALE_4		1
#define D_WDT_SCALE_8		2		/* T=393216*N/fo	*/
#define D_WDT_SCALE_16		3
#define D_WDT_SCALE_32		4
#define D_WDT_SCALE_64		5
#define D_WDT_SCALE_128		6
#define D_WDT_SCALE_256		7

#define	WDT_reset(n)	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + (n)		/* 初始化WDT，喂狗 */


//						  7     6      5    4     3      2    1     0     Reset Value
//sfr PCON   = 0x87;	SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000	 //Power Control 
//SMOD		//串口双倍速
//SMOD0
#define		LVDF		(1<<5)	/* P4.6低压检测标志 */
//POF
//GF1
//GF0
//#define 	D_PD		2		/* set 1, power down mode */
//#define 	D_IDLE		1		/* set 1, idle mode */
#define		MCU_IDLE()			PCON |= 1	/* MCU 进入 IDLE 模式 */
#define		MCU_POWER_DOWN()	PCON |= 2	/* MCU 进入 睡眠 模式 */


//sfr ISP_CMD   = 0xC5;
#define		ISP_STANDBY()	ISP_CMD = 0		/* ISP空闲命令（禁止）*/
#define		ISP_READ()		ISP_CMD = 1		/* ISP读出命令		*/
#define		ISP_WRITE()		ISP_CMD = 2		/* ISP写入命令		*/
#define		ISP_ERASE()		ISP_CMD = 3		/* ISP擦除命令		*/

//sfr ISP_TRIG  = 0xC6;
#define 	ISP_TRIG()	ISP_TRIG = 0x5A,	ISP_TRIG = 0xA5		/* ISP触发命令 */

//							  7    6    5      4    3    2    1     0    Reset Value
//sfr IAP_CONTR = 0xC7;		IAPEN SWBS SWRST CFAIL  -   WT2  WT1   WT0   0000,x000	//IAP Control Register
#define ISP_EN			(1<<7)
#define ISP_SWBS		(1<<6)
#define ISP_SWRST		(1<<5)
#define ISP_CMD_FAIL	(1<<4)
#define ISP_WAIT_1MHZ	7
#define ISP_WAIT_2MHZ	6
#define ISP_WAIT_3MHZ	5
#define ISP_WAIT_6MHZ	4
#define ISP_WAIT_12MHZ	3
#define ISP_WAIT_20MHZ	2
#define ISP_WAIT_24MHZ	1
#define ISP_WAIT_30MHZ	0

#if (MAIN_Fosc >= 24000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_30MHZ
#elif (MAIN_Fosc >= 20000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_24MHZ
#elif (MAIN_Fosc >= 12000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_20MHZ
#elif (MAIN_Fosc >= 6000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_12MHZ
#elif (MAIN_Fosc >= 3000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_6MHZ
#elif (MAIN_Fosc >= 2000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_3MHZ
#elif (MAIN_Fosc >= 1000000L)
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_2MHZ
#else
	#define		ISP_WAIT_FREQUENCY	ISP_WAIT_1MHZ
#endif



/* ADC Register */
//								7       6      5       4         3      2    1    0   Reset Value
//sfr ADC_CONTR = 0xBC;		ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHS0 0000,0000	/* AD 转换控制寄存器 */ 
//sfr ADC_RES  = 0xBD;		ADCV.9 ADCV.8 ADCV.7 ADCV.6 ADCV.5 ADCV.4 ADCV.3 ADCV.2	  0000,0000	/* A/D 转换结果高8位 */ 
//sfr ADC_RESL = 0xBE;												  ADCV.1 ADCV.0	  0000,0000	/* A/D 转换结果低2位 */
//sfr ADC_CONTR  = 0xBC;	//直接用MOV操作，不要用与或


//sfr SPCTL  = 0xCE;	SPI控制寄存器
//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		/* 1: 忽略SS脚	*/
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		/* 0: SS脚用于决定主从机	*/
#define	SPI_Enable()		SPCTL |=  (1<<6)		/* 1: 允许SPI	*/
#define	SPI_Disable()		SPCTL &= ~(1<<6)		/* 0: 禁止SPI	*/
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		/* 1: LSB先发	*/
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		/* 0: MSB先发	*/
#define	SPI_Master()		SPCTL |=  (1<<4)		/* 1: 设为主机	*/
#define	SPI_Slave()			SPCTL &= ~(1<<4)		/* 0: 设为从机	*/
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		/* 1: 空闲时SCLK为高电平	*/
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		/* 0: 空闲时SCLK为低电平	*/
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		/* 1: 	*/
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		/* 0: 	*/
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	/*设置速度, 0 -- fosc/4, 1 -- fosc/16, 2 -- fosc/64, 3 -- fosc/128	*/

//sfr SPDAT  = 0xCF; //SPI Data Register                                                     0000,0000
//sfr SPSTAT  = 0xCD;	//SPI状态寄存器
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		/* SPI传输完成标志。写入1清0。*/
#define	WCOL	0x40		/* SPI写冲突标志。写入1清0。  */

#define		SPI_USE_P12P13P14P15()	AUXR1 &= ~0x0c					/* 将SPI切换到P12(SS) P13(MOSI) P14(MISO) P15(SCLK)(上电默认)。*/
#define		SPI_USE_P24P23P22P21()	AUXR1 = (AUXR1 & ~0x0c) | 0x04	/* 将SPI切换到P24(SS) P23(MOSI) P22(MISO) P21(SCLK)。*/
#define		SPI_USE_P54P40P41P43()	AUXR1 = (AUXR1 & ~0x0c) | 0x08	/* 将SPI切换到P54(SS) P40(MOSI) P41(MISO) P43(SCLK)。*/


/*
;PCA_PWMn:    7       6     5   4   3   2     1       0
;			EBSn_1	EBSn_0	-	-	-	-	EPCnH	EPCnL
;B5-B2:		保留
;B1(EPCnH):	在PWM模式下，与CCAPnH组成9位数。
;B0(EPCnL):	在PWM模式下，与CCAPnL组成9位数。
*/
#define		PWM0_NORMAL()	PCA_PWM0 &= ~2					/* PWM0正常输出(默认)	*/
#define		PWM0_OUT_0()	PCA_PWM0 |=  2, CCAP0H = 0xff	/* PWM0一直输出0		*/
#define		PWM0_OUT_1()	PCA_PWM0 &= ~2, CCAP0H = 0		/* PWM0一直输出1		*/

#define		PWM1_NORMAL()	PCA_PWM1 &= ~2					/* PWM1正常输出(默认)	*/
#define		PWM1_OUT_0()	PCA_PWM1 |=  2, CCAP1H = 0xff	/* PWM1一直输出0		*/
#define		PWM1_OUT_1()	PCA_PWM1 &= ~2, CCAP1H = 0		/* PWM1一直输出1		*/

#define		PWM2_NORMAL()	PCA_PWM2 &= ~2					/* PWM2正常输出(默认)	*/
#define		PWM2_OUT_0()	PCA_PWM2 |=  2, CCAP2H = 0xff	/* PWM2一直输出0		*/
#define		PWM2_OUT_1()	PCA_PWM2 &= ~2, CCAP2H = 0		/* PWM2一直输出1		*/

#define		PWM3_NORMAL()	PCA_PWM3 &= ~2					/* PWM3正常输出(默认)	*/
#define		PWM3_OUT_0()	PCA_PWM3 |=  2, CCAP3H = 0xff	/* PWM3一直输出0		*/
#define		PWM3_OUT_1()	PCA_PWM3 &= ~2, CCAP3H = 0		/* PWM3一直输出1		*/


//						7     6     5     4     3     2     1     0     Reset Value
//sfr CCON   = 0xD8;	CF    CR    -     -    CCF3  CCF2  CCF1  CCF0   00xx,xx00	//PCA 控制寄存器。
sbit CCF0  = CCON^0;	/* PCA 模块0中断标志，由硬件置位，必须由软件清0。	*/
sbit CCF1  = CCON^1;	/* PCA 模块1中断标志，由硬件置位，必须由软件清0。	*/
sbit CCF2  = CCON^2;	/* PCA 模块2中断标志，由硬件置位，必须由软件清0。	*/
sbit CCF3  = CCON^3;	/* PCA 模块3中断标志，由硬件置位，必须由软件清0。	*/
sbit CR    = CCON^6;	/* 1: 允许PCA计数器计数，必须由软件清0。*/
sbit CF    = CCON^7;	/* PCA计数器溢出（CH，CL由FFFFH变为0000H）标志。PCA计数器溢出后由硬件置位，必须由软件清0。*/

//					 7     6     5     4     3     2     1     0    Reset Value
//sfr CMOD  = 0xD9;	CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,0000	//PCA 工作模式寄存器。
#define PCA_IDLE_OFF()		CMOD |=  (1<<7)				/* IDLE状态PCA停止计数。	*/
#define PCA_IDLE_ON()		CMOD &= ~(1<<7)				/* IDLE状态PCA继续计数。	*/
#define PCA_CLK_12T()		CMOD &= ~0x0E				/* PCA计数脉冲选择 fosc/12	*/
#define PCA_CLK_2T()		CMOD = (CMOD & ~0x0E) + 2	/* PCA计数脉冲选择 fosc/2	*/
#define PCA_CLK_T0()		CMOD = (CMOD & ~0x0E) + 4	/* PCA计数脉冲选择Timer0中断，Timer0可通过AUXR寄存器设置成工作在12T或1T模式。	*/
#define PCA_CLK_ECI()		CMOD = (CMOD & ~0x0E) + 6	/* PCA计数脉冲选择从ECI/P3.4脚输入的外部时钟，最大 fosc/2。	*/
#define PCA_CLK_1T()		CMOD = (CMOD & ~0x0E) + 8	/* PCA计数脉冲选择 Fosc	*/
#define PCA_CLK_4T()		CMOD = (CMOD & ~0x0E) + 10	/* PCA计数脉冲选择 Fosc/4	*/
#define PCA_CLK_6T()		CMOD = (CMOD & ~0x0E) + 12	/* PCA计数脉冲选择 Fosc/6	*/
#define PCA_CLK_8T()		CMOD = (CMOD & ~0x0E) + 14	/* PCA计数脉冲选择 Fosc/8	*/
#define PCA_INT_ENABLE()	CMOD |=  1					/* PCA计数器溢出中断允许位，1---允许CF（CCON.7）产生中断。	*/
#define PCA_INT_DISABLE()	CMOD &= ~1					/* PCA计数器溢出中断禁止。	*/

//					    7      6       5        4       3       2       1      0    Reset Value
//sfr AUXR1 = 0xA2;	  S1_S1  S1_S0  CCP_S1   CCP_S0  SPI_S1   SPI_S0    -     DPS   0100,0000	//Auxiliary Register 1

#define		PCA_USE_P12P17P16P15P14()	AUXR1 &= ~0x30					/* 将PCA/PWM切换到P12(ECI) P17(CCP0) P16(CCP1) P15(CCP2) P14(CCP3)(上电默认) */
#define		PCA_USE_P22P23P24P25P26()	AUXR1 = (AUXR1 & ~0x30) | 0x10	/* 将PCA/PWM切换到P22(ECI) P23(CCP0) P24(CCP1) P25(CCP2) P26(CCP3) */
#define		PCA_USE_P74P70P71P72P73()	AUXR1 = (AUXR1 & ~0x30) | 0x20	/* 将PCA/PWM切换到P74(ECI) P70(CCP0) P71(CCP1) P72(CCP2) P73(CCP3) */
#define		PCA_USE_P35P33P32P31P30()	AUXR1 = (AUXR1 & ~0x30) | 0x30	/* 将PCA/PWM切换到P35(ECI) P33(CCP0) P32(CCP1) P31(CCP2) P30(CCP3) */

#define		DPS_SEL1()		AUXR1 |=  1		/* 1：选择DPTR1。	*/
#define		DPS_SEL0()		AUXR1 &= ~1		/* 0：选择DPTR0(上电默认)。	*/


/*									7     6       5       4     3     2     1     0     Reset Value
//sfr CCAPM0 = 0xDA;	PWM 寄存器  -   ECOM0  CCAPP0  CCAPN0  MAT0  TOG0  PWM0  ECCF0   x000,0000	//PCA 模块0
//sfr CCAPM1 = 0xDB;	PWM 寄存器  -   ECOM1  CCAPP1  CCAPN1  MAT1  TOG1  PWM1  ECCF1   x000,0000	//PCA 模块1
//sfr CCAPM2 = 0xDC;	PWM 寄存器  -   ECOM2  CCAPP2  CCAPN2  MAT2  TOG2  PWM2  ECCF2   x000,0000	//PCA 模块2
//sfr CCAPM3 = 0xDD;	PWM 寄存器  -   ECOM3  CCAPP3  CCAPN3  MAT3  TOG3  PWM3  ECCF3   x000,0000	//PCA 模块3
;ECOMn = 1:	允许比较功能。
;CAPPn = 1:	允许上升沿触发捕捉功能。
;CAPNn = 1:	允许下降沿触发捕捉功能。
;MATn  = 1:	当匹配情况发生时，允许CCON中的CCFn置位。
;TOGn  = 1:	当匹配情况发生时，CEXn将翻转。(CEX0/PCA0/PWM0/P3.7,CEX1/PCA1/PWM1/P3.5)
;PWMn  = 1:	将CEXn设置为PWM输出。
;ECCFn = 1:	允许CCON中的CCFn触发中断。
;ECOMn CAPPn CAPNn MATn TOGn PWMn ECCFn
;  0     0     0    0    0    0     0		00H	未启用任何功能。
;  x     1     0    0    0    0     x	 	20H	16位CEXn上升沿触发捕捉功能。
;  x     0     1    0    0    0     x	 	10H	16位CEXn下降沿触发捕捉功能。
;  x     1     1    0    0    0     x	 	30H	16位CEXn/PCAn边沿（上、下沿）触发捕捉功能。
;  1     0     0    1    0    0     x	 	48H	16位软件定时器。
;  1     0     0    1    1    0     x	 	4CH	16位高速脉冲输出。
;  1     0     0    0    0    1     0		42H	8位PWM。无中断
;  1     1     0    0    0    1     1		63H	8位PWM。低变高可产生中断
;  1     0     1    0    0    1     1		53H	8位PWM。高变低可产生中断
;  1     1     1    0    0    1     1		73H	8位PWM。低变高或高变低均可产生中断
;*******************************************************************
;*******************************************************************/
#define		PCA0_none()				CCAPM0 = 0
#define		PCA0_PWM(nbit)			CCAPM0 = 0x42,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_rise_int(nbit) CCAPM0 = 0x63,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_fall_int(nbit) CCAPM0 = 0x53,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_edge_int(nbit) CCAPM0 = 0x73,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_capture_rise()		CCAPM0 = (0x20 + 1)
#define		PCA0_capture_fall()		CCAPM0 = (0x10 + 1)
#define		PCA0_capture_edge()		CCAPM0 = (0x30 + 1)
#define		PCA0_16bit_Timer()		CCAPM0 = (0x48 + 1)
#define		PCA0_High_Pulse()		CCAPM0 = (0x4C + 1)

#define		PCA1_none()				CCAPM1 = 0
#define		PCA1_PWM(nbit)			CCAPM1 = 0x42,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_rise_int(nbit) CCAPM1 = 0x63,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_fall_int(nbit) CCAPM1 = 0x53,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_edge_int(nbit) CCAPM1 = 0x73,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_capture_rise()		CCAPM1 = (0x20 + 1)
#define		PCA1_capture_fall()		CCAPM1 = (0x10 + 1)
#define		PCA1_capture_edge()		CCAPM1 = (0x30 + 1)
#define		PCA1_16bit_Timer()		CCAPM1 = (0x48 + 1)
#define		PCA1_High_Pulse()		CCAPM1 = (0x4C + 1)

#define		PCA2_none()				CCAPM2 = 0
#define		PCA2_PWM(nbit)			CCAPM2 = 0x42,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_rise_int(nbit) CCAPM2 = 0x63,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_fall_int(nbit) CCAPM2 = 0x53,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_edge_int(nbit) CCAPM2 = 0x73,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_capture_rise()		CCAPM2 = (0x20 + 1)
#define		PCA2_capture_fall()		CCAPM2 = (0x10 + 1)
#define		PCA2_capture_edge()		CCAPM2 = (0x30 + 1)
#define		PCA2_16bit_Timer()		CCAPM2 = (0x48 + 1)
#define		PCA2_High_Pulse()		CCAPM2 = (0x4C + 1)

#define		PCA3_none()				CCAPM3 = 0
#define		PCA3_PWM(nbit)			CCAPM3 = 0x42,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA3_PWM_rise_int(nbit) CCAPM3 = 0x63,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA3_PWM_fall_int(nbit) CCAPM3 = 0x53,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA3_PWM_edge_int(nbit) CCAPM3 = 0x73,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA3_capture_rise()		CCAPM3 = (0x20 + 1)
#define		PCA3_capture_fall()		CCAPM3 = (0x10 + 1)
#define		PCA3_capture_edge()		CCAPM3 = (0x30 + 1)
#define		PCA3_16bit_Timer()		CCAPM3 = (0x48 + 1)
#define		PCA3_High_Pulse()		CCAPM3 = (0x4C + 1)


/**********************************************************/
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;

/**********************************************************/
#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP(N)  NOP##N()


/**********************************************/
#define P0n_standard(bitn)			P0M1 &= ~(bitn),	P0M0 &= ~(bitn)	/* 00  */
#define P0n_push_pull(bitn)			P0M1 &= ~(bitn),	P0M0 |=  (bitn)	/* 01  */
#define P0n_pure_input(bitn)		P0M1 |=  (bitn),	P0M0 &= ~(bitn)	/* 10  */
#define P0n_open_drain(bitn)		P0M1 |=  (bitn),	P0M0 |=  (bitn)	/* 11  */

#define P1n_standard(bitn)			P1M1 &= ~(bitn),	P1M0 &= ~(bitn)
#define P1n_push_pull(bitn)			P1M1 &= ~(bitn),	P1M0 |=  (bitn)
#define P1n_pure_input(bitn)		P1M1 |=  (bitn),	P1M0 &= ~(bitn)
#define P1n_open_drain(bitn)		P1M1 |=  (bitn),	P1M0 |=  (bitn)

#define P2n_standard(bitn)			P2M1 &= ~(bitn),	P2M0 &= ~(bitn)
#define P2n_push_pull(bitn)			P2M1 &= ~(bitn),	P2M0 |=  (bitn)
#define P2n_pure_input(bitn)		P2M1 |=  (bitn),	P2M0 &= ~(bitn)
#define P2n_open_drain(bitn)		P2M1 |=  (bitn),	P2M0 |=  (bitn)

#define P3n_standard(bitn)			P3M1 &= ~(bitn),	P3M0 &= ~(bitn)
#define P3n_push_pull(bitn)			P3M1 &= ~(bitn),	P3M0 |=  (bitn)
#define P3n_pure_input(bitn)		P3M1 |=  (bitn),	P3M0 &= ~(bitn)
#define P3n_open_drain(bitn)		P3M1 |=  (bitn),	P3M0 |=  (bitn)

#define P4n_standard(bitn)			P4M1 &= ~(bitn),	P4M0 &= ~(bitn)
#define P4n_push_pull(bitn)			P4M1 &= ~(bitn),	P4M0 |=  (bitn)
#define P4n_pure_input(bitn)		P4M1 |=  (bitn),	P4M0 &= ~(bitn)
#define P4n_open_drain(bitn)		P4M1 |=  (bitn),	P4M0 |=  (bitn)

#define P5n_standard(bitn)			P5M1 &= ~(bitn),	P5M0 &= ~(bitn)
#define P5n_push_pull(bitn)			P5M1 &= ~(bitn),	P5M0 |=  (bitn)
#define P5n_pure_input(bitn)		P5M1 |=  (bitn),	P5M0 &= ~(bitn)
#define P5n_open_drain(bitn)		P5M1 |=  (bitn),	P5M0 |=  (bitn)

#define P6n_standard(bitn)			P6M1 &= ~(bitn),	P6M0 &= ~(bitn)
#define P6n_push_pull(bitn)			P6M1 &= ~(bitn),	P6M0 |=  (bitn)
#define P6n_pure_input(bitn)		P6M1 |=  (bitn),	P6M0 &= ~(bitn)
#define P6n_open_drain(bitn)		P6M1 |=  (bitn),	P6M0 |=  (bitn)

#define P7n_standard(bitn)			P7M1 &= ~(bitn),	P7M0 &= ~(bitn)
#define P7n_push_pull(bitn)			P7M1 &= ~(bitn),	P7M0 |=  (bitn)
#define P7n_pure_input(bitn)		P7M1 |=  (bitn),	P7M0 &= ~(bitn)
#define P7n_open_drain(bitn)		P7M1 |=  (bitn),	P7M0 |=  (bitn)


/****************************************************************/


//sfr INT_CLKO = 0x8F;	//附加的 SFR WAKE_CLKO (地址：0x8F)
/*
    7   6    5    4   3     2        1       0         Reset Value
    -  EX4  EX3  EX2  -   T2CLKO   T1CLKO  T0CLKO      0000,0000B
b6 -  EX4      : 外中断INT4允许
b5 -  EX3      : 外中断INT3允许
b4 -  EX2      : 外中断INT2允许
b2 - T1CLKO    : 允许 T2 溢出脉冲在P3.0脚输出，Fck1 = 1/2 T1 溢出率
b1 - T1CLKO    : 允许 T1 溢出脉冲在P3.4脚输出，Fck1 = 1/2 T1 溢出率
b0 - T0CLKO    : 允许 T0 溢出脉冲在P3.5脚输出，Fck0 = 1/2 T0 溢出率
*/

#define		LVD_InterruptEnable()		ELVD = 1
#define		LVD_InterruptDisable()		ELVD = 0


//sfr WKTCL = 0xAA;	//STC11F\10和STC15系列 唤醒定时器低字节
//sfr WKTCH = 0xAB;	//STC11F\10和STC15系列 唤醒定时器高字节
//	B7		B6	B5	B4	B3	B2	B1	B0		B7	B6	B5	B4	B3	B2	B1	B0
//	WKTEN				S11	S10	S9	S8		S7	S6	S5	S4	S3	S2	S1	S0	n * 560us
#define		WakeTimerDisable()		WKTCH &= 0x7f	/* WKTEN = 0		禁止睡眠唤醒定时器 */
#define		WakeTimerSet(scale)		WKTCL = (scale) % 256,WKTCH = (scale) / 256 | 0x80	/* WKTEN = 1	允许睡眠唤醒定时器 */



//sfr BUS_SPEED = 0xA1; //Stretch register      -   -  -  -   -   -  EXRTS1  EXRTSS0 xxxx,xx10
#define		BUS_SPEED_1T()	BUS_SPEED = 0
#define		BUS_SPEED_2T()	BUS_SPEED = 1
#define		BUS_SPEED_4T()	BUS_SPEED = 2
#define		BUS_SPEED_8T()	BUS_SPEED = 3

/*   interrupt vector */
#define		INT0_VECTOR		0
#define		TIMER0_VECTOR	1
#define		INT1_VECTOR		2
#define		TIMER1_VECTOR	3
#define		UART1_VECTOR	4
#define		ADC_VECTOR		5
#define		LVD_VECTOR		6
#define		PCA_VECTOR		7
#define		UART2_VECTOR	8
#define		SPI_VECTOR		9
#define		INT2_VECTOR		10
#define		INT3_VECTOR		11
#define		TIMER2_VECTOR	12
#define		INT4_VECTOR		16
#define		UART3_VECTOR	17
#define		UART4_VECTOR	18
#define		TIMER3_VECTOR	19
#define		TIMER4_VECTOR	20
#define		CMP_VECTOR		21
#define		PWM_VECTOR		22
#define		PWMFD_VECTOR	23
#define		I2C_VECTOR		24


#define	TRUE	1
#define	FALSE	0

//=============================================================

//========================================

#define	PolityLow			0	//低优先级中断
#define	PolityHigh			1	//高优先级中断

//========================================

#define		ENABLE		1
#define		DISABLE		0

#define		STC15F_L2K08S2	8
#define		STC15F_L2K16S2	16
#define		STC15F_L2K24S2	24
#define		STC15F_L2K32S2	32
#define		STC15F_L2K40S2	40
#define		STC15F_L2K48S2	48
#define		STC15F_L2K56S2	56
#define		STC15F_L2K60S2	60
#define		IAP15F_L2K61S2	61

#endif
