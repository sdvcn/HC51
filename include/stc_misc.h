#ifndef _STC_MISC_H_
#define _STC_MISC_H_


#if STCY == 1
#define DelayUs(_v) DelayUs_Y1(_v)
#elif STCY == 3
#define DelayUs(_v) DelayUs_Y3(_v)
#elif STCY == 5
#define DelayUs(_v) DelayUs_Y5(_v)
#elif STCY == 6
#define DelayUs(_v) DelayUs_Y6(_v)
#else
#warning No Support STCY
#endif



#endif