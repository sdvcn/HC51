/**
 * Apds-9960
*/

#ifndef _EXT_APDS9960_H_
#define _EXT_APDS9960_H_

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

/* 启动使能 */
/// 主电源
#define APDS9960_PON            (1ul << 0)
/// 环境光线
#define APDS9960_AEN            (1ul << 1)
/// 接近判定
#define APDS9960_PEN            (1ul << 2)
/// 等待延时
#define APDS9960_WEN            (1ul << 3)
/// 环境光线
#define APSD9960_AIEN           (1ul << 4)
/// 接近中断
#define APDS9960_PIEN           (1ul << 5)
/// 手势
#define APDS9960_GEN            (1ul << 6)
///
//#define APDS9960_GVALID         0b00000001
/* Default values */
#define DEFAULT_ATIME           219     // 103ms
#define DEFAULT_WTIME           246     // 27ms
#define DEFAULT_PROX_PPULSE     0x87    // 16us, 8 pulses
#define DEFAULT_GESTURE_PPULSE  0x89    // 16us, 10 pulses
#define DEFAULT_POFFSET_UR      0       // 0 offset
#define DEFAULT_POFFSET_DL      0       // 0 offset      
#define DEFAULT_CONFIG1         0x60    // No 12x wait (WTIME) factor
#define DEFAULT_LDRIVE          LED_DRIVE_100MA
#define DEFAULT_PGAIN           PGAIN_4X
#define DEFAULT_AGAIN           AGAIN_4X
#define DEFAULT_PILT            0       // Low proximity threshold
#define DEFAULT_PIHT            50      // High proximity threshold
#define DEFAULT_AILT            0xFFFF  // Force interrupt for calibration
#define DEFAULT_AIHT            0
#define DEFAULT_PERS            0x11    // 2 consecutive prox or ALS for int.
#define DEFAULT_CONFIG2         0x01    // No saturation interrupts or LED boost  
#define DEFAULT_CONFIG3         0       // Enable all photodiodes, no SAI
#define DEFAULT_GPENTH          40      // Threshold for entering gesture mode
#define DEFAULT_GEXTH           30      // Threshold for exiting gesture mode    
#define DEFAULT_GCONF1          0x40    // 4 gesture events for int., 1 for exit
#define DEFAULT_GGAIN           GGAIN_4X
#define DEFAULT_GLDRIVE         LED_DRIVE_100MA
#define DEFAULT_GWTIME          GWTIME_2_8MS
#define DEFAULT_GOFFSET         0       // No offset scaling for gesture mode
#define DEFAULT_GPULSE          0xC9    // 32us, 10 pulses
#define DEFAULT_GCONF3          0       // All photodiodes active during gesture
#define DEFAULT_GIEN            0       // Disable gesture interrupts

/**
 * 宏定义
*/


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
/**
 * 清理ALS中断
*/
#define APDS9960_ClearCI()          APDS9960_WriteReg8(APDS9960_CICLEAR,0xff)
/**
 * 清理ALS中断
*/
#define APDS9960_ClearPI()          APDS9960_WriteReg8(APDS9960_PICLEAR,0xff)
/**
 * 清理所有非手势中断
*/
#define APDS9960_ClearInt()         APDS9960_WriteReg8(APDS9960_AICLEAR,0xff)

#define APDS9960_GetGCONF4()        APDS9960_ReadReg8(APDS9960_GCONF4)
#define APDS9960_ClearGFIFO()       APDS9960_WriteReg8(APDS9960_GCONF4,APDS9960_GetGCONF4()|0x04)

// 关闭主电源
#define APDS9960_Power(_v)          APDS9960_WriteReg8(APDS9960_ENABLE,_v)
#define APDS9960_PowerOFF()         APDS9960_Power(0x00)

#define APDS9960_GetCONFIG2()       APDS9960_ReadReg8(APDS9960_CONFIG2)

/// Led Boost 设置 
#define APDS9960_LedBoost(_v)       APDS9960_WriteReg8(APDS9960_CONFIG2,((APDS9960_GetCONFIG2() & 0xCF) | ((_v & 0x03) << 4)))

/// 获取器件ID
#define APDS9960_GetID()            APDS9960_ReadReg8(APDS9960_ID)

/// 检查器件
#define APDS9960_Check(_v)            (APDS9960_GetID()==(_v)))




///Apds9960 写寄存器数据
extern void APDS9960_Write(unsigned char reg,unsigned len,char* src);
///Apds9960 读数据
extern void APDS9960_Read(unsigned len,char* dst);
///Apds9960 读寄存器
extern void APDS9960_ReadReg(unsigned char reg,unsigned len,char* dst);
///检测器件
//extern bool APDS9960_Check();
extern unsigned char APDS9960_ReadGesture();
extern void APDS9960_GestureSensor();

/// 初始化
extern void APDS9960_Init();

#endif