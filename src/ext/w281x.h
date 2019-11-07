#ifndef __W281X_H__
#define __W281X_H__


#define W281x_T1        4
#define W281x_T2        22
#define W281x_T3        5
#define W281x_Reset     0x2A00

typedef struct _sW281x{
    unsigned char Green;
    unsigned char Read;
    unsigned char Blue;
}sW281x,*PW281x;


void w281xSet(PW281x dst,sW281x v,unsigned len);

#endif  //end