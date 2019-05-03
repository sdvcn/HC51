/*
    Debug支持头
*/
#ifndef __EXT_DEBUG_H__
#define __EXT_DEBUG_H__
#include <stdio.h>
//__FILE__
//__LINE__

#ifdef DEBUG
#define DLOG(_v) printf("Info\t%s:%d\t%s\r",__FILE__,__LINE__,_v);
#define ELOG(_v) printf("Error\t%s:%d\t%s\r",__FILE__,__LINE__,_v);
#define DLOGINT(_f,_v) printf("Error\t%s:%d\t%s[%s:0x%#X]\r",__FILE__,__LINE__,#_f,#_v,_v);
#else
#define DLOG(_v)
#define ELOG(_v)
#define DLOGINT(_f,_v)
#endif

#endif