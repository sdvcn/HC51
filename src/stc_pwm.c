
#include <stcmcu.h>


#ifdef STC8
void PWM_Init()
{

}

void PWM_CR(unsigned char ch,unsigned char OP)
{
    if(CheckBIT(ch,0)) ExtSfrSet8(&PWM0CR,OP);
    if(CheckBIT(ch,1)) ExtSfrSet8(&PWM1CR,OP);
    if(CheckBIT(ch,2)) ExtSfrSet8(&PWM2CR,OP);
    if(CheckBIT(ch,3)) ExtSfrSet8(&PWM3CR,OP);
    if(CheckBIT(ch,4)) ExtSfrSet8(&PWM4CR,OP);
    if(CheckBIT(ch,5)) ExtSfrSet8(&PWM5CR,OP);
    if(CheckBIT(ch,6)) ExtSfrSet8(&PWM6CR,OP);
    if(CheckBIT(ch,7)) ExtSfrSet8(&PWM7CR,OP);
}
/*
// 锁定电平值
void PWM_SetHld(unsigned char mh,unsigned char ml)
{
    //todo:未做输入检查
    En_EAXFR();

    if(CheckBIT(mh,0) || CheckBIT(ml,0)) PWM0HLD = CheckBIT(mh,0) << 1 | CheckBIT(ml,0);
    if(CheckBIT(mh,1) || CheckBIT(ml,1)) PWM1HLD = CheckBIT(mh,1) << 1 | CheckBIT(ml,1);
    if(CheckBIT(mh,2) || CheckBIT(ml,2)) PWM2HLD = CheckBIT(mh,2) << 1 | CheckBIT(ml,2);
    if(CheckBIT(mh,3) || CheckBIT(ml,3)) PWM3HLD = CheckBIT(mh,3) << 1 | CheckBIT(ml,3);
    if(CheckBIT(mh,4) || CheckBIT(ml,4)) PWM4HLD = CheckBIT(mh,4) << 1 | CheckBIT(ml,4);
    if(CheckBIT(mh,5) || CheckBIT(ml,5)) PWM5HLD = CheckBIT(mh,5) << 1 | CheckBIT(ml,5);
    if(CheckBIT(mh,6) || CheckBIT(ml,6)) PWM6HLD = CheckBIT(mh,6) << 1 | CheckBIT(ml,6);
    if(CheckBIT(mh,7) || CheckBIT(ml,7)) PWM7HLD = CheckBIT(mh,7) << 1 | CheckBIT(ml,7);

    Di_EAXFR();
}

// 清除电平锁
void PWN_ClrN(unsigned char mio)
{
    En_EAXFR();

    if(CheckBIT(mio,0)) PWM0HLD = 0x00;
    if(CheckBIT(mio,1)) PWM1HLD = 0x00;
    if(CheckBIT(mio,2)) PWM2HLD = 0x00;
    if(CheckBIT(mio,3)) PWM3HLD = 0x00;
    if(CheckBIT(mio,4)) PWM4HLD = 0x00;
    if(CheckBIT(mio,5)) PWM5HLD = 0x00;
    if(CheckBIT(mio,6)) PWM6HLD = 0x00;
    if(CheckBIT(mio,7)) PWM7HLD = 0x00;

    Di_EAXFR();
}

*/
#endif