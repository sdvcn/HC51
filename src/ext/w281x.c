#include <stcmcu.h>
#include <i2c.h>


#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

//#define ASM_W281xIO _P7.6
//#define ASM_W281xIOH()  asm("SETB   " ___mkstr(ASM_W281xIO) )
//#define ASM_W281xIOL()  asm("CLR    " ___mkstr(ASM_W281xIO) )
//#define ASM_W281xIOC()  asm("MOV    " ___mkstr(ASM_W281xIO) ",C")
#define W281xIO         P76
#define W281xIOC(_v)    W281xIO=_v

void w281xClear(unsigned char len)
{
    asm("PUSH   _IE");
    EA = 0;
    //volatile unsigned char c;
    
     unsigned char l = 0xe0;
    do{
        W281xIOC(0);
        _delay(4);
    }while(--l);

    while(--len){
        unsigned char i = 0x08;
        do{
            W281xIOC(1);
            _delay(3);
            _delay(3);
            W281xIOC(0);
            _delay(4);
            _delay(4);
            _delay(4);
            _delay(3);
        }while(--i);

    }

    asm("POP    _IE");
}
/**
 * 工作时全局关闭中断
*/
void  w281xWrites(const char* src,unsigned char len)
{
    asm("PUSH   _IE");
    EA = 0;
    volatile unsigned char c;
    
     unsigned char l = 0xe0;
    do{
        W281xIOC(0);
        _delay(4);
    }while(--l);


    do{
        unsigned char i=8;
        c = *src++;
        do{
            //ASM_W281xIOH();
            c <<= 1;
            W281xIOC(1);
            _delay(3);
            _delay(3);
            W281xIOC(CY);
            _delay(4);
            _delay(4);
            _delay(4);
            _delay(1);
            W281xIOC(0);
            //_delay(1);
        }while(--i);
    }while(--len);

    asm("POP    _IE");

}
