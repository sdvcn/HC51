#include <stcmcu.h>


#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

#define ASM_W281xIO _P7.6
#define ASM_W281xIOH()  asm("SETB   " ___mkstr(ASM_W281xIO) )
#define ASM_W281xIOL()  asm("CLR    " ___mkstr(ASM_W281xIO) )
#define ASM_W281xIOC()  asm("MOV    " ___mkstr(ASM_W281xIO) ",C")

void w281writes( volatile const char* src,unsigned char len)
{
    //volatile unsigned char c = 0x00;

    //SetDPS()
    

    asm("PUSH   _IE");
    asm("CLR    _EA");
    asm("MOV     _TA,#0AAH");
    asm("MOV     _TA,#55H");
    asm("MOV     _DPS,#00001000B");
    asm("NOP");
    //src++;
    //if(*src){};
    asm("MOV    DPL,R6");
    asm("MOV    DPH,R7");

    //asm("MOV    DPTR,w281writes@src");

    //asm("WLOOP1:");
    do{
        //c = *src++;
        //asm("MOV    R3,writes@c");
        //asm("MOV    A,#0fh");
        asm("MOVX    A,@DPTR");
        asm("MOV    R2,#8");
        unsigned char i = 8;
        do{

        }while(--i);

        asm("WLOOP2:");
            asm("JC     WLOOP3");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("WLOOP3:");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            ASM_W281xIOH();
            asm("RLC    A");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            ASM_W281xIOC();
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            asm("NOP");
            ASM_W281xIOL();
        asm("DJNZ R2,WLOOP2");

    //asm("DJNZ R5,WLOOP1");
    }while(--len);
    asm("POP    _IE");
}

void  wwa(const char* src,unsigned char len)
{
    asm("PUSH   _IE");
    asm("CLR    _EA");
    
    //asm("MOV    DPL1,R6");
    //asm("MOV    DPH1,R7");

    DPH1 = ((size_t)src >> 8);
    DPL1 = (size_t)src;
    asm("MOV     _DPS,#00011001B");

    do{
        unsigned char i=8;
        //asm("MOVX    A,@DPTR");
        asm("CLR    A");
        asm("movc	a,@a+dptr")
        do{
            ASM_W281xIOH();
            asm("RLC    A");
            ASM_W281xIOC();
            asm("NOP");

            ASM_W281xIOL();
        }while(--i);
    }while(--len);
    asm("MOV     _DPS,#00000000B");
    asm("POP    _IE");
}