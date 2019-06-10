#include <stcmcu.h>
#include <i2c.h>


#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

#define ASM_W281xIO _P7.6
#define ASM_W281xIOH()  asm("SETB   " ___mkstr(ASM_W281xIO) )
#define ASM_W281xIOL()  asm("CLR    " ___mkstr(ASM_W281xIO) )
#define ASM_W281xIOC()  asm("MOV    " ___mkstr(ASM_W281xIO) ",C")

/**
 * 使用STC8扩展指针完成
 * 工作时全局关闭中断
*/
void  w281xwrites(const char* src,unsigned char len)
{
    asm("PUSH   _IE");
    asm("CLR    _EA");
    
    //asm("MOV    DPL1,R6");
    //asm("MOV    DPH1,R7");
    //reset    
    unsigned char l = 0xe0;
    do{
        ASM_W281xIOL();
        asm("NOP2");
        asm("NOP2");
    }while(--l);

    DPH1 = ((size_t)src >> 8);
    DPL1 = (size_t)src;

    asm("MOV     _DPS,#00011001B");

    do{
        unsigned char i=8;
        //asm("MOVX    A,@DPTR");
        asm("CLR    A");
        asm("movc	a,@a+dptr");
        do{
            ASM_W281xIOH();
            asm("RLC    A");
            asm("NOP2");
            asm("NOP2");
            asm("NOP");
            //asm("JC ")
            ASM_W281xIOC();
            asm("CLR    C");
            asm("NOP2");
            asm("NOP2");
            asm("NOP2");
            asm("NOP2");
            asm("NOP");
            ASM_W281xIOL();
            asm("NOP");
        }while(--i);
    }while(--len);
    asm("MOV     _DPS,#00000000B");
    asm("POP    _IE");
}
