/**
 * Debug支持头
 * 不能在时序要求严谨部分执行,会扰乱时序
*/
#ifndef __EXT_DEBUG_H__
#define __EXT_DEBUG_H__
#include <stdio.h>
//__FILE__
//__LINE__

#ifdef DEBUG
const char* Txt_Info="[%s:%d]\tInfo:%s\n";
const char* Txt_Error="[%s:%d]\tError:%s\n";
const char* Txt_I2Hex="[%s:%d]\tTracert:%s[%s:0x%2.2X]\n";

#define DLOG(_v) printf(Txt_Info,__FILE__,__LINE__,_v);
#define ELOG(_v) printf(Txt_Error,__FILE__,__LINE__,_v);
//#define ELOGV(_f) printf(Txt_Error,__FILE__,__LINE__,_v);
#define DLOGINT(_f,_v) printf(Txt_I2Hex,__FILE__,__LINE__,#_f,#_v,_v);
#else
#define DLOG(_v)
#define ELOG(_v)
#define DLOGINT(_f,_v)
#endif

#endif