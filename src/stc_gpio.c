

#include <stcmcu.h>


#ifdef STC8
void SetGPIO(unsigned char mio,ModeOP* mode)
{
    if (mio) {

        //--------------0
        if(CheckBIT(mio,0)) {
            P0M0 = mode->M0;
            P0M1 = mode->M1;
            En_EAXFR();
            P0PU = mode->PU;
            P0NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------1
        if(CheckBIT(mio,1)) {
            P1M0 = mode->M0;
            P1M1 = mode->M1;
            En_EAXFR();
            P1PU = mode->PU;
            P1NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------2
        if(CheckBIT(mio,2)) {
            P2M0 = mode->M0;
            P2M1 = mode->M1;
            En_EAXFR();
            P2PU = mode->PU;
            P2NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------3
        if(CheckBIT(mio,3)) {
            P3M0 = mode->M0;
            P3M1 = mode->M1;
            En_EAXFR();
            P3PU = mode->PU;
            P3NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------4
        if(CheckBIT(mio,4)) {
            P4M0 = mode->M0;
            P4M1 = mode->M1;
            En_EAXFR();
            P4PU = mode->PU;
            P4NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------5
        if(CheckBIT(mio,5)) {
            P5M0 = mode->M0;
            P5M1 = mode->M1;
            En_EAXFR();
            P5PU = mode->PU;
            P5NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------6
        if(CheckBIT(mio,6)) {
            P6M0 = mode->M0;
            P6M1 = mode->M1;
            En_EAXFR();
            P6PU = mode->PU;
            P6NCS = mode->CS;
            Di_EAXFR();
        }
        //--------------7
        if(CheckBIT(mio,7)) {
            P7M0 = mode->M0;
            P7M1 = mode->M1;
            En_EAXFR();
            P7PU = mode->PU;
            P7NCS = mode->CS;
            Di_EAXFR();
        }
        
    }
}
#endif
