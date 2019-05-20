#ifndef __SPI_H__
#define __SPI_H__

typedef struct
{
    unsigned char (*pError)();                          // 获取错误
    void (*pCommand)(unsigned char);                    // 命令
    void (*pWrite)(unsigned char);                      // 写入字节
    unsigned (*pWrites)(unsigned,unsigned char*);       // 写入字符串
    unsigned char (*pRead)();                           // 读出字节
    unsigned (*pReads)(unsigned,unsigned char*);        // 读出字符串
    unsigned (*pSeek)(signed);                          // 移动 *有符号整数
} sSPI;

void CreateSPI4Sfr(sSPI *mio,unsigned char op);

#endif