#include <string.h>
#include "ext_debug.h"


/**
 * Dump Bin to Hex
*/
void Console_DumpHex(size_t len,char* src)
{
    unsigned char buf[16];
    unsigned char ln = 0x00;

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
            if(buf[i] == 0x00) buf[i] = 0x20;
            printf(" %c",buf[i]);
        }
        printf(" |\n");
    }

    //printf(DumpTxt,123);
}