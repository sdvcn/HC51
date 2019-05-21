#ifndef _STC8_H_
#define _STC8_H_

#ifdef	__HTC8051__
#define _at_    @
#endif

//#define STC8
#define STCY	6
/**
 * 取消自带全局EA定义
 * 重新定义
*/
#ifdef ei()
#undef ei()
#endif

#ifdef di()
#undef di()
#endif

#define ei()    do{NOP();EA = 1;NOP();}while(0)
#define di()    do{NOP();EA = 0;NOP();}while(0)



volatile unsigned AUXR _at_ 0x8e;
/// P1端口配置寄存器
static volatile unsigned char	P1M1	_at_	0x91;
static volatile unsigned char	P1M0	_at_	0x92;
/// P0端口配置寄存器
static volatile unsigned char	P0M1	_at_	0x93;
static volatile unsigned char	P0M0	_at_	0x94;
/// P2端口配置寄存器
static volatile unsigned char	P2M1	_at_	0x95;
static volatile unsigned char	P2M0	_at_	0x96;
/// 串口2寄存器
static volatile unsigned char	S2CON	_at_	0x9A;
#define S2SM0       (1ul << 7)
#define S2ST4       (1ul << 6)
#define S2SM2       (1ul << 5)
#define S2REN       (1ul << 4)
#define S2TB8       (1ul << 3)
#define S2RB8       (1ul << 2)
#define S2TI        (1ul << 1)
#define S2RI        (1ul << 0)

static volatile unsigned char	S2BUF	_at_	0x9B;

static volatile unsigned char	SADDR	_at_	0xA9;
static volatile unsigned char	WKTCL	_at_	0xAA;
static volatile unsigned char	WKTCH	_at_	0xAB;
static volatile unsigned char	S3CON	_at_	0xAC;
static volatile unsigned char	S3BUF	_at_	0xAD;
static volatile unsigned char	TA		_at_	0xAE;
static volatile unsigned char	IE2		_at_	0xAF;


/// P3端口配置寄存器
static volatile unsigned char	P3M1	_at_	0xB1;
static volatile unsigned char	P3M0	_at_	0xB2;
/// P4端口配置寄存器
static volatile unsigned char	P4M1	_at_	0xB3;
static volatile unsigned char	P4M0	_at_	0xB4;

/// 优先级控制
static volatile unsigned char	IP2		_at_	0xB5;
static volatile unsigned char	IP2H	_at_	0xB6;
static volatile unsigned char	IPH		_at_	0xB7;

static volatile unsigned char	P_SW2	_at_	0xBA;
#define EAXFR 8
#define en_EAXFR() do{SetBIT(P_SW2,EAXFR);}while(0)
#define di_EAXFR() do{ClearBIT(P_SW2,EAXFR);}while(0)

static volatile unsigned char	ADC_CONTR	_at_	0xBC;

///FIX 16Bit
static volatile unsigned short	ADC_RES	_at_	0xBD;
static volatile unsigned char	ADC_RESL	_at_	0xBE;
static volatile unsigned char	ADC_RESH	_at_	0xBF;
//
#define Adc_Result ((ADC_RESH << 8) | ADC_RESL)

//
static volatile unsigned char	IAP_DATA	_at_	0xC2;
static volatile unsigned int	IAP_ADDR	_at_	0xC3;		//fix
static volatile unsigned char	IAP_ADDRH	_at_	0xC3;
static volatile unsigned char	IAP_ADDRL	_at_	0xC4;
static volatile unsigned char	IAP_CMD	_at_	0xC5;
static volatile unsigned char	IAP_TRIG	_at_	0xC6;
static volatile unsigned char	IAP_CONTR	_at_	0xC7;
/// P5端口配置寄存器
static volatile unsigned char	P5M1	_at_	0xC9;
static volatile unsigned char	P5M0	_at_	0xCA;
/// P6端口配置寄存器
static volatile unsigned char	P6M1	_at_	0xCB;
static volatile unsigned char	P6M0	_at_	0xCC;

//ISP 命名兼容
static volatile unsigned char	ISP_DATA	_at_	0xC2;
static volatile unsigned short	ISP_ADDR	_at_	0xC3;		//fix
static volatile unsigned char	ISP_ADDRH	_at_	0xC3;
static volatile unsigned char	ISP_ADDRL	_at_	0xC4;
static volatile unsigned char	ISP_CMD	_at_	0xC5;
static volatile unsigned char	ISP_TRIG	_at_	0xC6;
static volatile unsigned char	ISP_CONTR	_at_	0xC7;



/// T2定时器
static volatile unsigned char	T2H		_at_	0xD6;
static volatile unsigned char	T2L		_at_	0xD7;

/// P7端口配置寄存器
static volatile unsigned char	P7M1	_at_	0xE1;
static volatile unsigned char	P7M0	_at_	0xE2;

/// STC8 增强双数据指针
static volatile unsigned char	DPS 	_at_	0xE3;
static volatile unsigned char	DPL1	_at_	0xE4;
static volatile unsigned char	DPH1	_at_	0xE5;

// Port 4 P4
static volatile unsigned char   P4  _at_ 0xC0;
//static volatile SFR_BITS	P4_BITS _at_ 0xC0;
static volatile bit	P40	_at_ 0xC0 ^ 0;
static volatile bit	P41	_at_ 0xC0 ^ 1;
static volatile bit	P42	_at_ 0xC0 ^ 2;
static volatile bit	P43	_at_ 0xC0 ^ 3;
static volatile bit	P44	_at_ 0xC0 ^ 4;
static volatile bit	P45	_at_ 0xC0 ^ 5;
static volatile bit	P46	_at_ 0xC0 ^ 6;
static volatile bit	P47	_at_ 0xC0 ^ 7;

// Port 5 P5
//static volatile SFR_BITS	P5_BITS _at_ 0xC8;
static volatile unsigned char   P5  _at_ 0xC8;
static volatile bit	P50	_at_ 0xC8 ^ 0;
static volatile bit	P51	_at_ 0xC8 ^ 1;
static volatile bit	P52	_at_ 0xC8 ^ 2;
static volatile bit	P53	_at_ 0xC8 ^ 3;
static volatile bit	P54	_at_ 0xC8 ^ 4;
static volatile bit	P55	_at_ 0xC8 ^ 5;
static volatile bit	P56	_at_ 0xC8 ^ 6;
static volatile bit	P57	_at_ 0xC8 ^ 7;

/// P6 IO组
//static volatile SFR_BITS	P6_BITS _at_ 0xE8;
static volatile unsigned char   P6  _at_ 0xE8;
static volatile bit	P60	_at_ 0xE8 ^ 0;
static volatile bit	P61	_at_ 0xE8 ^ 1;
static volatile bit	P62	_at_ 0xE8 ^ 2;
static volatile bit	P63	_at_ 0xE8 ^ 3;
static volatile bit	P64	_at_ 0xE8 ^ 4;
static volatile bit	P65	_at_ 0xE8 ^ 5;
static volatile bit	P66	_at_ 0xE8 ^ 6;
static volatile bit	P67	_at_ 0xE8 ^ 7;

// Port 7 P7
//static volatile SFR_BITS	P7_BITS _at_ 0xF8;
static volatile unsigned char   P7  _at_ 0xF8;
static volatile bit	P70	_at_ 0xF8 ^ 0;
static volatile bit	P71	_at_ 0xF8 ^ 1;
static volatile bit	P72	_at_ 0xF8 ^ 2;
static volatile bit	P73	_at_ 0xF8 ^ 3;
static volatile bit	P74	_at_ 0xF8 ^ 4;
static volatile bit	P75	_at_ 0xF8 ^ 5;
static volatile bit	P76	_at_ 0xF8 ^ 6;
static volatile bit	P77	_at_ 0xF8 ^ 7;


//// 内存中预制
idata volatile unsigned short Bandgap   _at_ 0xEF;
idata volatile unsigned char STCID[7]	_at_ 0xF1;
idata volatile unsigned short STC32K	_at_ 0xF8;
idata volatile unsigned char STC22K     _at_ 0xFA;
idata volatile unsigned char STC24K     _at_ 0xFB;



//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
far volatile unsigned char CKSEL _at_ 0xFE00; 
far volatile unsigned char CLKDIV _at_ 0xFE01; 
far volatile unsigned char IRC24MCR _at_ 0xFE02; 
far volatile unsigned char XOSCCR _at_ 0xFE03; 
far volatile unsigned char IRC32KCR _at_ 0xFE04; 

/// 内置上拉电阻控制位
far volatile unsigned char P0PU _at_ 0xFE10; 
far volatile unsigned char P1PU _at_ 0xFE11; 
far volatile unsigned char P2PU _at_ 0xFE12; 
far volatile unsigned char P3PU _at_ 0xFE13; 
far volatile unsigned char P4PU _at_ 0xFE14; 
far volatile unsigned char P5PU _at_ 0xFE15; 
far volatile unsigned char P6PU _at_ 0xFE16; 
far volatile unsigned char P7PU _at_ 0xFE17; 

/// 施密特触发器控制位
far volatile unsigned char P0NCS _at_ 0xFE18; 
far volatile unsigned char P1NCS _at_ 0xFE19; 
far volatile unsigned char P2NCS _at_ 0xFE1A; 
far volatile unsigned char P3NCS _at_ 0xFE1B; 
far volatile unsigned char P4NCS _at_ 0xFE1C; 
far volatile unsigned char P5NCS _at_ 0xFE1D; 
far volatile unsigned char P6NCS _at_ 0xFE1E; 
far volatile unsigned char P7NCS _at_ 0xFE1F; 

far volatile unsigned char I2CCFG	_at_ 0xFE80; 
#define ENI2C   (1ul << 7)
#define MSSL    (1ul << 6)
far volatile unsigned char I2CMSCR	_at_ 0xFE81; 
far volatile unsigned char I2CMSST	_at_ 0xFE82; 
#define MSBUSY  (1ul << 7)
#define MSIF    (1ul << 6)
#define MSACKI  (1ul << 1)
#define MSACKO  (1ul << 0)

far volatile unsigned char I2CSLCR	_at_ 0xFE83; 
#define EMSI    (1ul << 7)



far volatile unsigned char I2CSLST	_at_ 0xFE84; 
far volatile unsigned char I2CSLADR	_at_ 0xFE85; 
far volatile unsigned char I2CTxD	_at_ 0xFE86; 
far volatile unsigned char I2CRxD	_at_ 0xFE87; 
/// I2c 主机辅助控制寄存器 to I2c.h
far volatile unsigned char I2CMSAUX	_at_ 0xFE88;

/// PWM0 翻转点设置计数值寄存器
far volatile unsigned short PWM0T1	_at_ 0xFF00; 
far volatile unsigned char PWM0T1H	_at_ 0xFF00; 
far volatile unsigned char PWM0T1L	_at_ 0xFF01; 

far volatile unsigned short PWM0T2	_at_ 0xFF02; 
far volatile unsigned char PWM0T2H	_at_ 0xFF02; 
far volatile unsigned char PWM0T2L	_at_ 0xFF03; 
/// PWM0 通道控制寄存器
far volatile unsigned char PWM0CR	_at_ 0xFF04; 
/// PWM0 通道电平保持控制器寄存器
far volatile unsigned char PWM0HLD	_at_ 0xFF05; 
/// PWM1 翻转点设置计数值寄存器
far volatile unsigned short PWM1T1	_at_ 0xFF10; 
far volatile unsigned char PWM1T1H	_at_ 0xFF10; 
far volatile unsigned char PWM1T1L	_at_ 0xFF11; 

far volatile unsigned short PWM1T2	_at_ 0xFF12; 
far volatile unsigned char PWM1T2H	_at_ 0xFF12; 
far volatile unsigned char PWM1T2L	_at_ 0xFF13; 
/// PWM1 通道控制寄存器
far volatile unsigned char PWM1CR	_at_ 0xFF14; 
/// PWM1 通道电平保持控制器寄存器
far volatile unsigned char PWM1HLD	_at_ 0xFF15; 

/// PWM2 翻转点设置计数值寄存器
far volatile unsigned short PWM2T1	_at_ 0xFF20; 
far volatile unsigned char PWM2T1H	_at_ 0xFF20; 
far volatile unsigned char PWM2T1L	_at_ 0xFF21; 

far volatile unsigned short PWM2T2	_at_ 0xFF22; 
far volatile unsigned char PWM2T2H	_at_ 0xFF22; 
far volatile unsigned char PWM2T2L	_at_ 0xFF23; 
/// PWM2 通道控制寄存器
far volatile unsigned char PWM2CR	_at_ 0xFF24; 
/// PWM2 通道电平保持控制器寄存器
far volatile unsigned char PWM2HLD	_at_ 0xFF25; 

/// PWM3 翻转点设置计数值寄存器
far volatile unsigned short PWM3T1	_at_ 0xFF30; 
far volatile unsigned char PWM3T1H	_at_ 0xFF30; 
far volatile unsigned char PWM3T1L	_at_ 0xFF31; 

far volatile unsigned short PWM3T2	_at_ 0xFF32; 
far volatile unsigned char PWM3T2H	_at_ 0xFF32; 
far volatile unsigned char PWM3T2L	_at_ 0xFF33; 
/// PWM3 通道控制寄存器
far volatile unsigned char PWM3CR	_at_ 0xFF34; 
/// PWM3 通道电平保持控制器寄存器
far volatile unsigned char PWM3HLD	_at_ 0xFF35; 

/// PWM4 翻转点设置计数值寄存器
far volatile unsigned short PWM4T1	_at_ 0xFF40; 
far volatile unsigned char PWM4T1H	_at_ 0xFF40; 
far volatile unsigned char PWM4T1L	_at_ 0xFF41; 

far volatile unsigned short PWM4T2	_at_ 0xFF42; 
far volatile unsigned char PWM4T2H	_at_ 0xFF42; 
far volatile unsigned char PWM4T2L	_at_ 0xFF43; 
/// PWM4 通道控制寄存器
far volatile unsigned char PWM4CR	_at_ 0xFF44; 
/// PWM4 通道电平保持控制器寄存器
far volatile unsigned char PWM4HLD	_at_ 0xFF45; 

/// PWM5 翻转点设置计数值寄存器
far volatile unsigned short PWM5T1	_at_ 0xFF50; 
far volatile unsigned char PWM5T1H	_at_ 0xFF50; 
far volatile unsigned char PWM5T1L	_at_ 0xFF51; 

far volatile unsigned short PWM5T2	_at_ 0xFF52; 
far volatile unsigned char PWM5T2H	_at_ 0xFF52; 
far volatile unsigned char PWM5T2L	_at_ 0xFF53; 
/// PWM5 通道控制寄存器
far volatile unsigned char PWM5CR	_at_ 0xFF54; 
/// PWM5 通道电平保持控制器寄存器
far volatile unsigned char PWM5HLD	_at_ 0xFF55; 

/// PWM6 翻转点设置计数值寄存器
far volatile unsigned short PWM6T1	_at_ 0xFF60; 
far volatile unsigned char PWM6T1H	_at_ 0xFF60; 
far volatile unsigned char PWM6T1L	_at_ 0xFF61; 

far volatile unsigned short PWM6T2	_at_ 0xFF62; 
far volatile unsigned char PWM6T2H	_at_ 0xFF62; 
far volatile unsigned char PWM6T2L	_at_ 0xFF63; 
/// PWM6 通道控制寄存器
far volatile unsigned char PWM6CR	_at_ 0xFF64; 
/// PWM6 通道电平保持控制器寄存器
far volatile unsigned char PWM6HLD	_at_ 0xFF65; 

/// PWM7 翻转点设置计数值寄存器
far volatile unsigned short PWM7T1	_at_ 0xFF70; 
far volatile unsigned char PWM7T1H	_at_ 0xFF70; 
far volatile unsigned char PWM7T1L	_at_ 0xFF71; 

far volatile unsigned short PWM7T2	_at_ 0xFF72; 
far volatile unsigned char PWM7T2H	_at_ 0xFF72; 
far volatile unsigned char PWM7T2L	_at_ 0xFF73; 
/// PWM7 通道控制寄存器
far volatile unsigned char PWM7CR	_at_ 0xFF74; 
/// PWM7 通道电平保持控制器寄存器
far volatile unsigned char PWM7HLD	_at_ 0xFF75; 

/// PWM计数器寄存器
far volatile unsigned short PWMC	_at_ 0xFFF0; 
far volatile unsigned char PWMCH	_at_ 0xFFF0; 
far volatile unsigned char PWMCL	_at_ 0xFFF1; 

/// PWM 时钟选择寄存器
far volatile unsigned char PWMCKS	_at_ 0xFFF2; 

/// PWM 触发 ADC 计数器 寄存器
far volatile unsigned char TADCP	_at_ 0xFFF3; 
far volatile unsigned char TADCPH	_at_ 0xFFF3; 
far volatile unsigned char TADCPL	_at_ 0xFFF4; 


near static xdata unsigned char rv[512] _at_ 0xFE00;

//far  volatile unsigned short EBandgap   _at_ 0x3ff7;
code unsigned char STCID_ROM[7] _at_ 0xfdf9;
#if defined (_STC8A8K16S4A12)
#define OFFADDR 0xff
#elif defined (_STC8A8K32S4A12)
#elif defined (_STC8A8K60S4A12)
#elif defined (_STC8A8K64S4A12)
#else
#endif

///-------------------------------
/**
 * 扩展寄存器操作
*/
///扩展寄存器状态
//#define EaxFRST() CheckBIT(P_SW2,EAXFR)

///组合使用
//#define En_EAXFR() do{bit _oldEaxfr = CheckBIT(P_SW2,EAXFR); SetBIT(P_SW2,EAXFR)
//#define Di_EAXFR() if(!_oldEaxfr) ClearBIT(P_SW2,EAXFR);}while(0)

///Ext
unsigned char ExtSfrGet8(size_t addr);
unsigned short ExtSfrGet16(size_t addr);
void ExtSfrSet8(size_t addr,unsigned char nv);
void ExtSfrSet16(size_t addr,unsigned short nv);
#define ExtSfrClear(_a,_b) ExtSfrSet8(_a,(ExtSfrGet8(_a) & ~(_b)))



#define DEFCLK 24000000u
#define STCCLKR (DEFCLK )

/**
 * GPIO
*/
typedef struct {
    unsigned char M0;
    unsigned char M1;
    unsigned char PU;
    unsigned char CS;
} ModeOP;

#endif