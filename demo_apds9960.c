#include <stcmcu.h>
#include <ext_debug.h>
#include <i2c.h>
#include <stc8_gpio.h>

#include "./src/ext/apds9660.h"

static void Uart2Init(void)		//115200bps@23.996MHz
{
	// 优先级处理
	//IP2H |= 0x01;
	//IP2  |= 0x01;

	//P0 = 0xf0;
	//S2CON = 0x48;		//8位数据,可变波特率
	S2CON = (S2REN);
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = 0xCC;		//设定定时初值
	T2H = 0xFF;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
	//IE2 = 0x01;
}

sI2c mI2c;

void main()
{
    Select24M();                            // 稳定频率
    Uart2Init();                            // 初始化串口2
    EA = 1;                                 // 开启全局中断
    DLOG("Init system");

    //IIC端口初始化
    GPIO_SetMode(&P3,2,1);                  // 推挽
    GPIO_SetMode(&P3,3,2);                  // 高阻
    GPIO_SetNCS(&P3,3,1);                   // 施密特
    GPIO_SetPU(&P3,3,1);                    // 内置上拉
    //器件中断
    //GPIO_SetPU(&P7,7,1);                    // 内置上拉
    //GPIO_SetMode(&P7,7,2);                  // 高阻
    
    CreateIICM4Sfr(&mI2c);                  // 寄存器方式初始化IIC
    SI2c_Speed(&mI2c,400000ul);             // IIC总线速度设置
    SI2c_SelectPort(&mI2c,3);               // IIC端口选择
    I2c_SetAddr(&mI2c,0x39);                // 目标端口设置

/**
 * 空闲->距离->手势->等待->颜色/感光->空闲
 * 初始化9960
 * 接受距离传感器中断
 * 循环匹配手势
 * 判定环境光线
 * 
*/
    // 9960初始化
    DLOG("Init Apds9960");
    APDS9960_ClearENABLE(&mI2c);                // 关闭9960
    APDS9960_SetATIME(&mI2c,182);
    APDS9960_SetWTIME(&mI2c,0);                 // 等待时间寄存器
    APDS9960_SetAILT(&mI2c,1000);
    APDS9960_SetAIHT(&mI2c,20000);

    APDS9960_SetPILT(&mI2c,10);
    APDS9960_SetPIHT(&mI2c,200);

    APDS9960_SetLDRIVE(&mI2c,3);                // 红外LED 电流控制
    APDS9960_SetPGAIN(&mI2c,1);                 // 距离增益
    APDS9960_SetAGAIN(&mI2c,1);                 // 颜色可见光增益

    APDS9960_SetPPERS(&mI2c,0x0F);
    APDS9960_SetAPRES(&mI2c,0x0F);

    APDS9960_SetPPLEN(&mI2c,3);
    APDS9960_SetPPULSE(&mI2c,63);

    //APDS9960_SetPSIEN(&mI2c,1);

    //APDS9960_SetCPSIEN(h,0x01);

    APDS9960_SetENABLE(&mI2c,BIT_PON | BIT_PEN );  // 开启
    DLOG("main LOOP");
    do{
        if(P76 = P77 == 0){
            DLOGINT(GetSTATUS,APDS9960_GetSTATUS(&mI2c));

            if(APDS9960_GetCPSAT(&mI2c))
            {
                assert(0);
                APDS9960_ClearCI(&mI2c);
                while(!APDS9960_GetAVALID(&mI2c));
                Apds_Dump(&mI2c);
            }
            if(APDS9960_GetPINT(&mI2c))
            {
                assert(0)
                DLOGINT("PDATA",APDS9960_GetPData(&mI2c));
                APDS9960_ClearPI(&mI2c);
            }
            APDS9960_ClearAI(&mI2c);
            //APDS9960_ClearGFIFO(&mI2c);

            Apds_Dump(&mI2c);
        }        

    }while(1);
}