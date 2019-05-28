

#include <stcmcu.h>
#include <stc8_gpio.h>

#include <ext_debug.h>

typedef struct _IOMODE
{
    unsigned char M0;
    unsigned char M1;
} IOMODE;


/**
 * 设置端口工作模式
 * Example:
 * GPIO_Mode(&P0,0xff)
 * 
 * 返回已设置状态
*/
unsigned short GPIO_Mode(size_t io,unsigned short mode)
{
    IOMODE *pmode = (IOMODE*)&mode;
    if(io == PtrAddr(&P0)){
        P0M0 = pmode->M0;
        P0M1 = pmode->M1;
        pmode->M0 = P0M0;
        pmode->M1 = P0M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P1)){
        P1M0 = pmode->M0;
        P1M1 = pmode->M1;
        pmode->M0 = P1M0;
        pmode->M1 = P1M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P2)){
        P2M0 = pmode->M0;
        P2M1 = pmode->M1;
        pmode->M0 = P2M0;
        pmode->M1 = P2M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P3)){
        P3M0 = pmode->M0;
        P3M1 = pmode->M1;
        pmode->M0 = P3M0;
        pmode->M1 = P3M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P4)){
        P4M0 = pmode->M0;
        P4M1 = pmode->M1;
        pmode->M0 = P4M0;
        pmode->M1 = P4M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P5)){
        P5M0 = pmode->M0;
        P5M1 = pmode->M1;
        pmode->M0 = P5M0;
        pmode->M1 = P5M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P6)){
        P6M0 = pmode->M0;
        P6M1 = pmode->M1;
        pmode->M0 = P6M0;
        pmode->M1 = P6M1;
        return *(unsigned short *)&mode;
    }
    if(io == PtrAddr(&P7)){
        P7M0 = pmode->M0;
        P7M1 = pmode->M1;
        pmode->M0 = P7M0;
        pmode->M1 = P7M1;
        return *(unsigned short *)&mode;
    }
    return 0x00;
}

/**
 * 设置端口上拉电阻
 * Example:
 * GPIO_PU(&P0,0xff)
 * 
 * 返回已设置状态
*/
unsigned char GPIO_PU(size_t io,unsigned char mask)
{
    if(io == PtrAddr(&P0)){
        ExtSfrSet8(&P0PU,mask);
        return ExtSfrGet8(&P0PU);
    }
    if(io == PtrAddr(&P1)){
        ExtSfrSet8(&P1PU,mask);
        return ExtSfrGet8(&P1PU);
    }
    if(io == PtrAddr(&P2)){
        ExtSfrSet8(&P2PU,mask);
        return ExtSfrGet8(&P2PU);
    }
    if(io == PtrAddr(&P3)){
        ExtSfrSet8(&P3PU,mask);
        return ExtSfrGet8(&P3PU);
    }
    if(io == PtrAddr(&P4)){
        ExtSfrSet8(&P4PU,mask);
        return ExtSfrGet8(&P4PU);
    }
    if(io == PtrAddr(&P5)){
        ExtSfrSet8(&P5PU,mask);
        return ExtSfrGet8(&P5PU);
    }
    if(io == PtrAddr(&P6)){
        ExtSfrSet8(&P6PU,mask);
        return ExtSfrGet8(&P6PU);
    }
    if(io == PtrAddr(&P7)){
        ExtSfrSet8(&P7PU,mask);
        return ExtSfrGet8(&P7PU);
    }
    return 0x00;
}

/**
 * 设置端口斯密特触发
 * Example:
 * GPIO_NCS(&P0,0xff)
 * 
 * 返回已设置状态
*/
unsigned char GPIO_NCS(size_t io,unsigned char mask)
{
    if(io == PtrAddr(&P0)){
        ExtSfrSet8(&P0NCS,mask);
        return ExtSfrGet8(&P0NCS);
    }
    if(io == PtrAddr(&P1)){
        ExtSfrSet8(&P1NCS,mask);
        return ExtSfrGet8(&P1NCS);
    }
    if(io == PtrAddr(&P2)){
        ExtSfrSet8(&P2NCS,mask);
        return ExtSfrGet8(&P2NCS);
    }
    if(io == PtrAddr(&P3)){
        ExtSfrSet8(&P3NCS,mask);
        return ExtSfrGet8(&P3NCS);
    }
    if(io == PtrAddr(&P4)){
        ExtSfrSet8(&P4NCS,mask);
        return ExtSfrGet8(&P4NCS);
    }
    if(io == PtrAddr(&P5)){
        ExtSfrSet8(&P5NCS,mask);
        return ExtSfrGet8(&P5NCS);
    }
    if(io == PtrAddr(&P6)){
        ExtSfrSet8(&P6NCS,mask);
        return ExtSfrGet8(&P6NCS);
    }
    if(io == PtrAddr(&P7)){
        ExtSfrSet8(&P7NCS,mask);
        return ExtSfrGet8(&P7NCS);
    }
    return 0x00;
}


