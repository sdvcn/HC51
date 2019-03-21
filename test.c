#include <8051.h>
#include <stcmcu.h>

typedef void (* LFun)(char* s);

struct{
	unsigned v1:4;
	unsigned v2:4;
}tss;

struct OP
{
	unsigned char mode;
	unsigned char len;
	unsigned char* ptr;
};
void rr(char *s)
{
	if(P0){
		NOP();
	}
	NOP();
}


void main()
{
	LFun ff1 = rr;

	ushort v1 = &rr;
	if(v1){
		P0 = v1;
		P1 = v1 >> 8;
	}

	ff1("sss");

	while(1);
}
