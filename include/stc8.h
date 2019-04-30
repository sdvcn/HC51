#ifndef _STC8_H_
#define _STC8_H_

//#define STC8
#define STCY	6



volatile unsigned AUXR @ 0x8e;
/// P1端口配置寄存器
static volatile unsigned char	P1M1	@	0x91;
static volatile unsigned char	P1M0	@	0x92;
/// P0端口配置寄存器
static volatile unsigned char	P0M1	@	0x93;
static volatile unsigned char	P0M0	@	0x94;
/// P2端口配置寄存器
static volatile unsigned char	P2M1	@	0x95;
static volatile unsigned char	P2M0	@	0x96;
/// 串口2寄存器
static volatile unsigned char	S2CON	@	0x9A;
static volatile unsigned char	S2BUF	@	0x9B;

static volatile unsigned char	SADDR	@	0xA9;
static volatile unsigned char	WKTCL	@	0xAA;
static volatile unsigned char	WKTCH	@	0xAB;
static volatile unsigned char	S3CON	@	0xAC;
static volatile unsigned char	S3BUF	@	0xAD;
static volatile unsigned char	TA		@	0xAE;
static volatile unsigned char	IE2		@	0xAF;


/// P3端口配置寄存器
static volatile unsigned char	P3M1	@	0xB1;
static volatile unsigned char	P3M0	@	0xB2;
/// P4端口配置寄存器
static volatile unsigned char	P4M1	@	0xB3;
static volatile unsigned char	P4M0	@	0xB4;


static volatile unsigned char	P_SW2	@	0xBA;
#define EAXFR 8
#define en_EAXFR() do{SetBIT(P_SW2,EAXFR);}while(0)
#define di_EAXFR() do{ClearBIT(P_SW2,EAXFR);}while(0)

static volatile unsigned char	ADC_CONTR	@	0xBC;

///FIX 16Bit
static volatile unsigned short	ADC_RES	@	0xBD;
static volatile unsigned char	ADC_RESL	@	0xBE;
static volatile unsigned char	ADC_RESH	@	0xBF;
//
#define Adc_Result ((ADC_RESH << 8) | ADC_RESL)

//
static volatile unsigned char	IAP_DATA	@	0xC2;
static volatile unsigned int	IAP_ADDR	@	0xC3;		//fix
static volatile unsigned char	IAP_ADDRH	@	0xC3;
static volatile unsigned char	IAP_ADDRL	@	0xC4;
static volatile unsigned char	IAP_CMD	@	0xC5;
static volatile unsigned char	IAP_TRIG	@	0xC6;
static volatile unsigned char	IAP_CONTR	@	0xC7;
/// P5端口配置寄存器
static volatile unsigned char	P5M1	@	0xC9;
static volatile unsigned char	P5M0	@	0xCA;
/// P6端口配置寄存器
static volatile unsigned char	P6M1	@	0xCB;
static volatile unsigned char	P6M0	@	0xCC;

//ISP 命名兼容
static volatile unsigned char	ISP_DATA	@	0xC2;
static volatile unsigned short	ISP_ADDR	@	0xC3;		//fix
static volatile unsigned char	ISP_ADDRH	@	0xC3;
static volatile unsigned char	ISP_ADDRL	@	0xC4;
static volatile unsigned char	ISP_CMD	@	0xC5;
static volatile unsigned char	ISP_TRIG	@	0xC6;
static volatile unsigned char	ISP_CONTR	@	0xC7;



/// T2定时器
static volatile unsigned char	T2H		@	0xD6;
static volatile unsigned char	T2L		@	0xD7;

/// P7端口配置寄存器
static volatile unsigned char	P7M1	@	0xE1;
static volatile unsigned char	P7M0	@	0xE2;
// Port 4 P4
static volatile unsigned char   P4  _at_ 0xC0;
//static volatile SFR_BITS	P4_BITS @ 0xC0;
static volatile bit	P40	@ 0xC0 ^ 0;
static volatile bit	P41	@ 0xC0 ^ 1;
static volatile bit	P42	@ 0xC0 ^ 2;
static volatile bit	P43	@ 0xC0 ^ 3;
static volatile bit	P44	@ 0xC0 ^ 4;
static volatile bit	P45	@ 0xC0 ^ 5;
static volatile bit	P46	@ 0xC0 ^ 6;
static volatile bit	P47	@ 0xC0 ^ 7;

// Port 5 P5
//static volatile SFR_BITS	P5_BITS @ 0xC8;
static volatile unsigned char   P5  _at_ 0xC8;
static volatile bit	P50	@ 0xC8 ^ 0;
static volatile bit	P51	@ 0xC8 ^ 1;
static volatile bit	P52	@ 0xC8 ^ 2;
static volatile bit	P53	@ 0xC8 ^ 3;
static volatile bit	P54	@ 0xC8 ^ 4;
static volatile bit	P55	@ 0xC8 ^ 5;
static volatile bit	P56	@ 0xC8 ^ 6;
static volatile bit	P57	@ 0xC8 ^ 7;

/// P6 IO组
//static volatile SFR_BITS	P6_BITS @ 0xE8;
static volatile unsigned char   P6  _at_ 0xE8;
static volatile bit	P60	@ 0xE8 ^ 0;
static volatile bit	P61	@ 0xE8 ^ 1;
static volatile bit	P62	@ 0xE8 ^ 2;
static volatile bit	P63	@ 0xE8 ^ 3;
static volatile bit	P64	@ 0xE8 ^ 4;
static volatile bit	P65	@ 0xE8 ^ 5;
static volatile bit	P66	@ 0xE8 ^ 6;
static volatile bit	P67	@ 0xE8 ^ 7;

// Port 7 P7
//static volatile SFR_BITS	P7_BITS @ 0xF8;
static volatile unsigned char   P7  _at_ 0xF8;
static volatile bit	P70	@ 0xF8 ^ 0;
static volatile bit	P71	@ 0xF8 ^ 1;
static volatile bit	P72	@ 0xF8 ^ 2;
static volatile bit	P73	@ 0xF8 ^ 3;
static volatile bit	P74	@ 0xF8 ^ 4;
static volatile bit	P75	@ 0xF8 ^ 5;
static volatile bit	P76	@ 0xF8 ^ 6;
static volatile bit	P77	@ 0xF8 ^ 7;


//// 内存中预制
idata volatile unsigned short Bandgap   @ 0xEF;
idata volatile unsigned char STCID[7]	@ 0xF1;
idata volatile unsigned short STC32K	@ 0xF8;
idata volatile unsigned char STC22K     @ 0xFA;
idata volatile unsigned char STC24K     @ 0xFB;



//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
far volatile unsigned char CKSEL @ 0xFE00; 
far volatile unsigned char CLKDIV @ 0xFE01; 
far volatile unsigned char IRC24MCR @ 0xFE02; 
far volatile unsigned char XOSCCR @ 0xFE03; 
far volatile unsigned char IRC32KCR @ 0xFE04; 

/// 内置上拉电阻控制位
far volatile unsigned char P0PU @ 0xFE10; 
far volatile unsigned char P1PU @ 0xFE11; 
far volatile unsigned char P2PU @ 0xFE12; 
far volatile unsigned char P3PU @ 0xFE13; 
far volatile unsigned char P4PU @ 0xFE14; 
far volatile unsigned char P5PU @ 0xFE15; 
far volatile unsigned char P6PU @ 0xFE16; 
far volatile unsigned char P7PU @ 0xFE17; 

/// 施密特触发器控制位
far volatile unsigned char P0NCS @ 0xFE18; 
far volatile unsigned char P1NCS @ 0xFE19; 
far volatile unsigned char P2NCS @ 0xFE1A; 
far volatile unsigned char P3NCS @ 0xFE1B; 
far volatile unsigned char P4NCS @ 0xFE1C; 
far volatile unsigned char P5NCS @ 0xFE1D; 
far volatile unsigned char P6NCS @ 0xFE1E; 
far volatile unsigned char P7NCS @ 0xFE1F; 

far volatile unsigned char I2CCFG	@ 0xFE80; 
#define ENI2C   (1ul << 7)
#define MSSL    (1ul << 6)
far volatile unsigned char I2CMSCR	@ 0xFE81; 
far volatile unsigned char I2CMSST	@ 0xFE82; 
#define MSBUSY  (1ul << 7)
#define MSIF    (1ul << 6)
#define MSACKI  (1ul << 1)
#define MSACKO  (1ul << 0)

far volatile unsigned char I2CSLCR	@ 0xFE83; 
#define EMSI    (1ul << 7)



far volatile unsigned char I2CSLST	@ 0xFE84; 
far volatile unsigned char I2CSLADR	@ 0xFE85; 
far volatile unsigned char I2CTxD	@ 0xFE86; 
far volatile unsigned char I2CRxD	@ 0xFE87; 
far volatile unsigned char I2CMSAUX	@ 0xFE88;

/// PWM0 翻转点设置计数值寄存器
far volatile unsigned short PWM0T1	@ 0xFF00; 
far volatile unsigned char PWM0T1H	@ 0xFF00; 
far volatile unsigned char PWM0T1L	@ 0xFF01; 

far volatile unsigned short PWM0T2	@ 0xFF02; 
far volatile unsigned char PWM0T2H	@ 0xFF02; 
far volatile unsigned char PWM0T2L	@ 0xFF03; 
/// PWM0 通道控制寄存器
far volatile unsigned char PWM0CR	@ 0xFF04; 
/// PWM0 通道电平保持控制器寄存器
far volatile unsigned char PWM0HLD	@ 0xFF05; 
/// PWM1 翻转点设置计数值寄存器
far volatile unsigned short PWM1T1	@ 0xFF10; 
far volatile unsigned char PWM1T1H	@ 0xFF10; 
far volatile unsigned char PWM1T1L	@ 0xFF11; 

far volatile unsigned short PWM1T2	@ 0xFF12; 
far volatile unsigned char PWM1T2H	@ 0xFF12; 
far volatile unsigned char PWM1T2L	@ 0xFF13; 
/// PWM1 通道控制寄存器
far volatile unsigned char PWM1CR	@ 0xFF14; 
/// PWM1 通道电平保持控制器寄存器
far volatile unsigned char PWM1HLD	@ 0xFF15; 

/// PWM2 翻转点设置计数值寄存器
far volatile unsigned short PWM2T1	@ 0xFF20; 
far volatile unsigned char PWM2T1H	@ 0xFF20; 
far volatile unsigned char PWM2T1L	@ 0xFF21; 

far volatile unsigned short PWM2T2	@ 0xFF22; 
far volatile unsigned char PWM2T2H	@ 0xFF22; 
far volatile unsigned char PWM2T2L	@ 0xFF23; 
/// PWM2 通道控制寄存器
far volatile unsigned char PWM2CR	@ 0xFF24; 
/// PWM2 通道电平保持控制器寄存器
far volatile unsigned char PWM2HLD	@ 0xFF25; 

/// PWM3 翻转点设置计数值寄存器
far volatile unsigned short PWM3T1	@ 0xFF30; 
far volatile unsigned char PWM3T1H	@ 0xFF30; 
far volatile unsigned char PWM3T1L	@ 0xFF31; 

far volatile unsigned short PWM3T2	@ 0xFF32; 
far volatile unsigned char PWM3T2H	@ 0xFF32; 
far volatile unsigned char PWM3T2L	@ 0xFF33; 
/// PWM3 通道控制寄存器
far volatile unsigned char PWM3CR	@ 0xFF34; 
/// PWM3 通道电平保持控制器寄存器
far volatile unsigned char PWM3HLD	@ 0xFF35; 

/// PWM4 翻转点设置计数值寄存器
far volatile unsigned short PWM4T1	@ 0xFF40; 
far volatile unsigned char PWM4T1H	@ 0xFF40; 
far volatile unsigned char PWM4T1L	@ 0xFF41; 

far volatile unsigned short PWM4T2	@ 0xFF42; 
far volatile unsigned char PWM4T2H	@ 0xFF42; 
far volatile unsigned char PWM4T2L	@ 0xFF43; 
/// PWM4 通道控制寄存器
far volatile unsigned char PWM4CR	@ 0xFF44; 
/// PWM4 通道电平保持控制器寄存器
far volatile unsigned char PWM4HLD	@ 0xFF45; 

/// PWM5 翻转点设置计数值寄存器
far volatile unsigned short PWM5T1	@ 0xFF50; 
far volatile unsigned char PWM5T1H	@ 0xFF50; 
far volatile unsigned char PWM5T1L	@ 0xFF51; 

far volatile unsigned short PWM5T2	@ 0xFF52; 
far volatile unsigned char PWM5T2H	@ 0xFF52; 
far volatile unsigned char PWM5T2L	@ 0xFF53; 
/// PWM5 通道控制寄存器
far volatile unsigned char PWM5CR	@ 0xFF54; 
/// PWM5 通道电平保持控制器寄存器
far volatile unsigned char PWM5HLD	@ 0xFF55; 

/// PWM6 翻转点设置计数值寄存器
far volatile unsigned short PWM6T1	@ 0xFF60; 
far volatile unsigned char PWM6T1H	@ 0xFF60; 
far volatile unsigned char PWM6T1L	@ 0xFF61; 

far volatile unsigned short PWM6T2	@ 0xFF62; 
far volatile unsigned char PWM6T2H	@ 0xFF62; 
far volatile unsigned char PWM6T2L	@ 0xFF63; 
/// PWM6 通道控制寄存器
far volatile unsigned char PWM6CR	@ 0xFF64; 
/// PWM6 通道电平保持控制器寄存器
far volatile unsigned char PWM6HLD	@ 0xFF65; 

/// PWM7 翻转点设置计数值寄存器
far volatile unsigned short PWM7T1	@ 0xFF70; 
far volatile unsigned char PWM7T1H	@ 0xFF70; 
far volatile unsigned char PWM7T1L	@ 0xFF71; 

far volatile unsigned short PWM7T2	@ 0xFF72; 
far volatile unsigned char PWM7T2H	@ 0xFF72; 
far volatile unsigned char PWM7T2L	@ 0xFF73; 
/// PWM7 通道控制寄存器
far volatile unsigned char PWM7CR	@ 0xFF74; 
/// PWM7 通道电平保持控制器寄存器
far volatile unsigned char PWM7HLD	@ 0xFF75; 

/// PWM计数器寄存器
far volatile unsigned short PWMC	@ 0xFFF0; 
far volatile unsigned char PWMCH	@ 0xFFF0; 
far volatile unsigned char PWMCL	@ 0xFFF1; 

/// PWM 时钟选择寄存器
far volatile unsigned char PWMCKS	@ 0xFFF2; 

/// PWM 触发 ADC 计数器 寄存器
far volatile unsigned char TADCP	@ 0xFFF3; 
far volatile unsigned char TADCPH	@ 0xFFF3; 
far volatile unsigned char TADCPL	@ 0xFFF4; 


//far  volatile unsigned short EBandgap   @ 0x3ff7;
code unsigned char STCID_ROM[7] @ 0xfdf9;
#if defined (_STC8A8K16S4A12)
#define OFFADDR 0xff
#elif defined (_STC8A8K32S4A12)
#elif defined (_STC8A8K60S4A12)
#elif defined (_STC8A8K64S4A12)
#else
#endif

///-------------------------------
///组合使用
#define En_EAXFR() do{bit _oldEaxfr = CheckBIT(P_SW2,EAXFR); SetBIT(P_SW2,EAXFR)
#define Di_EAXFR() if(!_oldEaxfr) ClearBIT(P_SW2,EAXFR);}while(0)
///Ext
extern unsigned char ExtSfrGet(unsigned short addr);
extern void ExtSfrSet(unsigned short addr,unsigned char nv);


//#pragma inline(ExtSfrGet)
//#pragma inline(ExtSfrSet)

#define DEFCLK 24000000u
#define STCCLKR (DEFCLK )

#endif