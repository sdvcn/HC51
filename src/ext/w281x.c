#include <stcmcu.h>
#include "w281x.h"

#ifdef COMPILE_EXT_W281X


#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

// 端口定义
#define W281xIO         P76
#define W281xIOC(_v)    W281xIO=_v

/**
 * 工作时全局关闭中断
*/
void  w281xWrites(const char* src,unsigned len)
{
    volatile unsigned char c;
    volatile unsigned char l;
    
    W281xIOC(0);
    asm("push ie");
    di();  
    _delay(W281x_Reset);

    c = *src++;

    //asm("WLOOP:");
    while(len--)
    {
        //7
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //6
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //5
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //4
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //3
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //2
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //1
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        W281xIOC(CY);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        W281xIOC(0);
        asm("NOP");asm("NOP");asm("NOP");asm("NOP");
        //0 放弃最低为设置
        W281xIOC(1);
        c <<= 1;
        asm("nop");
        asm("nop");
        W281xIOC(0);
        c = *src++;
        /*
        
        if(CY){
            c = *src++;
            asm("NOP");asm("NOP");asm("NOP");asm("NOP");
            W281xIOC(0);
        }else{
            W281xIOC(0);
            c = *src++;
        }
        */
        //asm("djnz r1,W1LOOP");
        //c = *src++;
    }
    //asm("djnz r4,WLOOP");
    W281xIOC(1);
    asm("POP    _IE");  
}
void w281xSet(PW281x dst,sW281x v,unsigned len)
{
    while(len--){
        *dst = v;
        dst++;
    }

}


#endif //COMPILE_EXT_W281X