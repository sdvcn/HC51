/**
 * Apds-9960
*/
#ifndef _APDS9960_H_
#define _APDS9960_H_

/**
 * Apds-9960总线地址
*/
#ifndef APDS9960_ADDRES
#define APDS9960_ADDRES 0x39
#endif
/**
 * Apds-9960 总线速度
*/
#ifndef I2C_SPEED
#define I2C_SPEED 0x30
#endif


/**
 * 9960基础定义
*/
/* APDS-9960 register addresses */
#define APDS9960_ENABLE         0x80
/// 环境光 adc 中断时间
#define APDS9960_ATIME          0x81
/// 延时
#define APDS9960_WTIME          0x83
/// 环境光阀值
#define APDS9960_AILTL          0x84
#define APDS9960_AILTH          0x85

#define APDS9960_AIHTL          0x86
#define APDS9960_AIHTH          0x87
/// 接近中断阀值
#define APDS9960_PILT           0x89
#define APDS9960_PIHT           0x8B

#define APDS9960_PERS           0x8C
#define APDS9960_CONFIG1        0x8D
/// 接近脉冲寄存器
#define APDS9960_PPULSE         0x8E

#define APDS9960_CONTROL        0x8F
#define APDS9960_CONFIG2        0x90
/// 驱动器编号
#define APDS9960_ID             0x92
/// 驱动器状态
#define APDS9960_STATUS         0x93
///
#define APDS9960_CDATAL         0x94
#define APDS9960_CDATAH         0x95
/// 红通道数据
#define APDS9960_RDATAL         0x96
#define APDS9960_RDATAH         0x97
/// 绿通道数据
#define APDS9960_GDATAL         0x98
#define APDS9960_GDATAH         0x99
/// 蓝通道数据
#define APDS9960_BDATAL         0x9A
#define APDS9960_BDATAH         0x9B
/// 接近通道数据
#define APDS9960_PDATA          0x9C


#define APDS9960_POFFSET_UR     0x9D
#define APDS9960_POFFSET_DL     0x9E
#define APDS9960_CONFIG3        0x9F
#define APDS9960_GPENTH         0xA0
#define APDS9960_GEXTH          0xA1
#define APDS9960_GCONF1         0xA2
#define APDS9960_GCONF2         0xA3
#define APDS9960_GOFFSET_U      0xA4
#define APDS9960_GOFFSET_D      0xA5
#define APDS9960_GOFFSET_L      0xA7
#define APDS9960_GOFFSET_R      0xA9
#define APDS9960_GPULSE         0xA6
#define APDS9960_GCONF3         0xAA
/// 手势设定 
#define APDS9960_GCONF4         0xAB
/// 手势寄存器缓冲数量
#define APDS9960_GFLVL          0xAE
/// 手势状态
#define APDS9960_GSTATUS        0xAF
/// 强制中断
#define APDS9960_IFORCE         0xE4
/// 接近中断清除
#define APDS9960_PICLEAR        0xE5
/// ALS 通道中断清除
#define APDS9960_CICLEAR        0xE6
/// 全部非手势中断清除
#define APDS9960_AICLEAR        0xE7
/// 手势 上
#define APDS9960_GFIFO_U        0xFC
/// 手势 下
#define APDS9960_GFIFO_D        0xFD
/// 手势 左
#define APDS9960_GFIFO_L        0xFE
/// 手势 右
#define APDS9960_GFIFO_R        0xFF


/// 环境光线
/**
 * 获取环境光线值
*/
#define APDS9960_Light_Ambient()    APDS9960_ReadReg16(APDS9960_CDATAL)
/**
 * 获取红色环境光线值
*/
#define APDS9960_Light_Red()        APDS9960_ReadReg16(APDS9960_RDATAL)
/**
 * 获取绿色环境光线值
*/
#define APDS9960_Light_Green()      APDS9960_ReadReg16(APDS9960_GDATAL)
/**
 * 获取蓝色环境光线值
*/
#define APDS9960_Light_blue()       APDS9960_ReadReg16(APDS9960_BDATAL)




#define APDS9960_GetGCONF4()        APDS9960_ReadReg8(APDS9960_GCONF4)
#define APDS9960_ClearGFIFO()       APDS9960_WriteReg8(APDS9960_GCONF4,APDS9960_GetGCONF4()|0x04)








/*
#define ExecIForce()    APDS9960_WriteReg8(APDS9960_IFORCE,0x00)
#define ExecPiClear()   APDS9960_WriteReg8(APDS9960_PICLEAR,0x00)
#define ExecCiClear()   APDS9960_WriteReg8(APDS9960_CICLEAR,0x00)
#define ExecAiClear()   APDS9960_WriteReg8(APDS9960_AICLEAR,0x00)
*/


///Apds9960 写寄存器数据
void APDS9960_Write(unsigned char reg,unsigned len,char* src);
///Apds9960 读数据
void APDS9960_Read(unsigned len,char* dst);
///Apds9960 读寄存器
unsigned char APDS9960_ReadReg(unsigned char reg,unsigned len,char* dst);
///检测器件
unsigned char APDS9960_ReadGesture();
void APDS9960_GestureSensor();

/// 初始化
void APDS9960_Init();


//////////////////////
//----------------------------------------
unsigned char APDS9960_ReadReg8(unsigned char reg);
unsigned short APDS9960_ReadReg16(unsigned char reg);
void APDS9960_WriteReg8(unsigned char reg,unsigned char val);
void APDS9960_WriteReg16(unsigned char reg,unsigned short val);


//-------------
void APDS9960_GestureSensor();
//void APDS9960_ReadGesture();
//--------------

#define Get_APDS9960_ENABLE() APDS9960_ReadReg8(APDS9960_ENABLE)
#define Put_APDS9960_ENABLE(_v) APDS9960_WriteReg8(APDS9960_ENABLE,_v)

///
#define Get_APDS9960_ATIME() APDS9960_ReadReg8(APDS9960_ATIME)
#define Set_APDS9960_ATIME(_v) APDS9960_WriteReg8(APDS9960_ATIME,_v)

#define Get_APDS9960_WTIME() APDS9960_ReadReg8(APDS9960_WTIME)
#define Get_APDS9960_AILT() APDS9960_ReadReg16(APDS9960_AILTL)
#define Get_APDS9960_AIHT() APDS9960_ReadReg16(APDS9960_AIHTL)

#define Get_APDS9960_PILT() APDS9960_ReadReg8(APDS9960_PILT)
#define Get_APDS9960_PIHT() APDS9960_ReadReg8(APDS9960_PIHT)

#define Get_APDS9960_PERS() APDS9960_ReadReg8(APDS9960_PERS)

//----------------------------------------
/// 开启APDS-9960 I2c访问
//unsigned char ADPS9960_I2c_En();

/// 停止APDS-9960 I2c访问
//unsigned char ADPS9960_I2c_Di();


#endif