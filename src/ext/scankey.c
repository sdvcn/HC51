#include <stcmcu.h>
#include <ext_debug.h>

#include <stc_timer.h>

#define DEFCOUNT    100

typedef struct _ScanIO{
    unsigned mTime;        // 
    unsigned mTimeOut;     // 延时
    unsigned char mLastIO;
    unsigned mCount;            // 除颤
    
    //void (*pExec)(struct _ScanIO*);
}ScanIO,*pScanIO;

void RegKey(pScanIO kio,unsigned timeout,unsigned char mask)
{
    //kio->mOP = (mask & 0x03);
    kio->mTimeOut = timeout;
}


unsigned char _ScanKey(pScanIO ios,unsigned char io)
{
    static unsigned char lastio = 0x00;
    
    if(ios->mLastIO != io){
        ios->mCount = DEFCOUNT;
        ios->mTime  = _SystemTC;
        ios->mLastIO = io;
    }
    if(ios->mCount){
        --(ios->mCount);
    }
    if(ios->mTimeOut){
        if(DiffRtc(ios->mTime) > ios->mTimeOut) {
            return 1ul;
        }else{
            return 0ul;
        }
    }

    if((ios->mCount)==0x00) return 1ul;
    return 0ul;
}


#define ScanKey(_ios,_io,_exec) while(_ScanKey(_ios,_io)){_exec;}