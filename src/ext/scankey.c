#include <stcmcu.h>
#include <ext_debug.h>

#include <stc_timer.h>

#define DEFCOUNT    100
/*
typedef struct _ScanIO{
    unsigned mTick;        // 
    unsigned mTickOut;     // 延时
    unsigned char mLastIO;
    unsigned mCount;            // 除颤
    
    //void (*pExec)(struct _ScanIO*);
}ScanIO,*pScanIO;

void RegKey(pScanIO kio,unsigned timeout,unsigned char mask)
{
    //kio->mOP = (mask & 0x03);
    kio->mTickOut = timeout;
}


unsigned char _ScanKey(pScanIO ios,unsigned char io)
{
    
    if(ios->mLastIO != io){
        ios->mCount = DEFCOUNT;
        ios->mTick  = GetSystemTick();
        ios->mLastIO = io;
    }
    if(ios->mCount){
        --(ios->mCount);
    }
    if(ios->mTickOut){
        if(DiffTick(ios->mTick) > ios->mTickOut) {
            return 1ul;
        }else{
            return 0ul;
        }
    }

    if((ios->mCount)==0x00) return 1ul;
    return 0ul;
}


#define ScanKey(_ios,_io,_exec) while(_ScanKey(_ios,_io)){_exec;}

*/