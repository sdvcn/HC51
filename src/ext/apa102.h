#ifndef __APA102_H__
#define __APA102_H__

#ifndef NCOMPILE_EXT_APA102

typedef struct _apa102
{
    unsigned char mGlobal;
    unsigned char mBlue;
    unsigned char mGreen;
    unsigned char mRed;
}apa102, *papa102;


void apa102Gen(papa102 src,unsigned len);

void apa102Write4iic(const papa102 src,unsigned len);
void apa102WriteEmu(const papa102 src,unsigned len);

#endif // NCOMPILE_EXT_W281X
#endif