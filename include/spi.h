#ifndef __SPI_H__
#define __SPI_H__

#include <obj.h>

typedef struct _sSPI
{
    BaseIO  mIOs;                                       // 基础IO操作
    unsigned char mFlag;                                //
} sSPI;

#define SPI_SSIG    (1ul << 7)
#define SPI_SPEN    (1ul << 6)
#define SPI_DORD    (1ul << 5)
#define SPI_MSTR    (1ul << 4)
#define SPI_CPOL    (1ul << 3)
#define SPI_CPHA    (1ul << 2)
#define SPI_SPR1    (1ul << 1)
#define SPI_SPR0    (1ul << 0)

#define SPI_SPIF    (1ul << 7)
#define SPI_WCOL    (1ul << 6)

#define SPI_sfr_InitM(_v)   SPI_sfr_Config(SPI_SSIG|SPI_SPEN|SPI_MSTR|(_v & 0x2f))          // 强制主模式
#define SPI_sfr_InitS(_v)   SPI_sfr_Config(SPI_SSIG|SPI_SPEN|(_v & 0x2f))                   // 强制从模式
#define SPI_sfr_Init(_v)    SPI_sfr_Config(SPI_SPEN|_v)                                     // 默认
#define SPI_sfr_Disable()   SPI_sfr_Config(0x00)                                            // 关闭

void SPI_sfr_Config(unsigned char c);

void CreateSPI4Sfr(void *mio,unsigned char op);

#endif