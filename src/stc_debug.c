#include <string.h>
#include "ext_debug.h"


/**
 * Dump Bin to Hex
 * @size_t len = 长度
 * @char* src = 起始地址
*/
void Console_DumpHex(size_t len,char* src)
{
    unsigned char buf[16];
    unsigned char ln = 0x00;
    printf("==Dump len(%d)\n",len);

    for (size_t l=0;l < len;)
    {
        memset(buf,0x00,16);
        if((len - l) > 16) {
            ln = 16;
        }else{
            ln = (len - l);
        }

        memcpy(buf,&(src[l]),ln);
        l += ln;

        printf("|");
        for(unsigned char i=0;i<0x10;i++){
            printf(" %2.2X",buf[i]);
        }
        printf(" | ");
        for(unsigned char i=0;i<0x10;i++){
            ///过滤非ASCII字符 不支持双字节
            buf[i] &= 0x7f;
            /// 过滤控制符
            if(buf[i] < 32) buf[i] = 0x20;
            if(buf[i] == 0x7f) buf[i] = 0x20;
            printf(" %c",buf[i]);
        }
        printf(" |\n");
    }
}