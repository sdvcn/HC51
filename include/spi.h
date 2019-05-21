#ifndef __SPI_H__
#define __SPI_H__

#include <obj.h>

typedef struct _sSPI
{
    BaseIO  mIOs;                                       // 基础IO操作
    unsigned char mFlag;                                //
} sSPI;


void CreateSPI4Sfr(void *mio,unsigned char op);

#endif