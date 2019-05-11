#ifndef _STC15_H_
#define _STC15_H_

/**
 * 取消自带全局EA定义
 * 重新定义
*/
#ifdef ei()
#undef ei()
#endif

#ifdef di()
#undef di()
#endif

#define ei()    do{NOP();EA = 1;NOP();}while(0)
#define di()    do{NOP();EA = 0;NOP();}while(0)

#endif