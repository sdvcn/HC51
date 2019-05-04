

#include <stcmcu.h>


#ifdef STC8
/*
    mio:端口组mask
    mode:IO状态

*/
void SetGPIO(unsigned char mio,ModeOP* mode)
{
    if (mio) {

        //--------------0
        if(CheckBIT(mio,0)) {
            P0M0 = mode->M0;
            P0M1 = mode->M1;
            ExtSfrSet8((size_t)&P0PU,mode->PU);
            ExtSfrSet8((size_t)&P0NCS,mode->CS);
        }
        //--------------1
        if(CheckBIT(mio,1)) {
            P1M0 = mode->M0;
            P1M1 = mode->M1;
            ExtSfrSet8((size_t)&P1PU,mode->PU);
            ExtSfrSet8((size_t)&P1NCS,mode->CS);

        }
        //--------------2
        if(CheckBIT(mio,2)) {
            P2M0 = mode->M0;
            P2M1 = mode->M1;
            ExtSfrSet8((size_t)&P2PU,mode->PU);
            ExtSfrSet8((size_t)&P2NCS,mode->CS);
        }
        //--------------3
        if(CheckBIT(mio,3)) {
            P3M0 = mode->M0;
            P3M1 = mode->M1;
            ExtSfrSet8((size_t)&P3PU,mode->PU);
            ExtSfrSet8((size_t)&P3NCS,mode->CS);
        }
        //--------------4
        if(CheckBIT(mio,4)) {
            P4M0 = mode->M0;
            P4M1 = mode->M1;
            ExtSfrSet8((size_t)&P4PU,mode->PU);
            ExtSfrSet8((size_t)&P4NCS,mode->CS);
        }
        //--------------5
        if(CheckBIT(mio,5)) {
            P5M0 = mode->M0;
            P5M1 = mode->M1;
            ExtSfrSet8((size_t)&P5PU,mode->PU);
            ExtSfrSet8((size_t)&P5NCS,mode->CS);
        }
        //--------------6
        if(CheckBIT(mio,6)) {
            P6M0 = mode->M0;
            P6M1 = mode->M1;
            ExtSfrSet8((size_t)&P6PU,mode->PU);
            ExtSfrSet8((size_t)&P6NCS,mode->CS);
        }
        //--------------7
        if(CheckBIT(mio,7)) {
            P7M0 = mode->M0;
            P7M1 = mode->M1;
            ExtSfrSet8((size_t)&P7PU,mode->PU);
            ExtSfrSet8((size_t)&P7NCS,mode->CS);
        }
        
    }
}
#endif
