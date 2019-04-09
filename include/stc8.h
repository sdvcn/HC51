#ifndef _STC8_H_
#define _STC8_H_




volatile unsigned AUXR @ 0x8e;


static volatile unsigned char	P_SW2	@	0xBA;
#define EAXFR 8
#define en_EAXFR() do{SetBIT(P_SW2,EAXFR);}while(0)
#define di_EAXFR() do{ClearBIT(P_SW2,EAXFR);}while(0)


idata volatile unsigned short Bandgap   @ 0xEF;
idata volatile unsigned char STCID1[7]	        @ 0xF1;
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

far volatile unsigned short PWM0T1	@ 0xFF00; 
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


//far  volatile unsigned short EBandgap   @ 0x3ff7;
code unsigned char STCID[7] @ 0xfdf9;
#if defined (_STC8A8K16S4A12)
#define OFFADDR 0xff
#elif defined (_STC8A8K32S4A12)
#elif defined (_STC8A8K60S4A12)
#elif defined (_STC8A8K64S4A12)
#else
#endif
//扩展
unsigned char ExtSfrGet(unsigned short addr){
    SetBIT(P_SW2,EAXFR);
    unsigned char r = (*(unsigned char volatile xdata *)addr);
    ClearBIT(P_SW2,EAXFR);
    return r;
}
#pragma inline ExtSfrGet

void ExtSfrSet(unsigned short addr,unsigned char nv){
    SetBIT(P_SW2,EAXFR);
    (*(unsigned char volatile xdata *)addr) = nv;
    ClearBIT(P_SW2,EAXFR);
    
}
#pragma inline ExtSfrSet

///Ext
#define DEFCLK 24000000u
#define STCCLKR (DEFCLK / CLKDIV)

#endif