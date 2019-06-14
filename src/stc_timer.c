#include <stcmcu.h>
#include <ext_debug.h>

static volatile unsigned _SystemTC;


void timer3_isr() using 1 _at_  0x0b
{
    ++_SystemTC;
}

unsigned DiffRtc(unsigned t0)
{
    unsigned r = _SystemTC - t0;
    if(r & 0x8000) r = ~r;
    return r;
}