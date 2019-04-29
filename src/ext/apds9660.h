#ifndef _APDS9960_H_
#define _APDS9960_H_

/* Acceptable device IDs */
#define APDS9960_ID_1           0xAB        //ADPS-9960
#define APDS9960_ID_2           0x9C 
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

//----------------------------------------
extern unsigned char APDS9960_ReadReg8(unsigned char reg);
extern unsigned short APDS9960_ReadReg16(unsigned char reg);
extern void APDS9960_WriteReg8(unsigned char reg,unsigned char val);
extern void APDS9960_WriteReg16(unsigned char reg,unsigned short val);

#define ExecIForce()    APDS9960_WriteReg8(APDS9960_IFORCE,0x00)
#define ExecPiClear()   APDS9960_WriteReg8(APDS9960_PICLEAR,0x00)
#define ExecCiClear()   APDS9960_WriteReg8(APDS9960_CICLEAR,0x00)
#define ExecAiClear()   APDS9960_WriteReg8(APDS9960_AICLEAR,0x00)

//--------------

#define Get_APDS9960_ENABLE() APDS9960_ReadReg8(APDS9960_ENABLE)
#define Put_APDS9960_ENABLE(_v) APDS9960_WriteReg8(APDS9960_ENABLE,_v)

#define Get_APDS9960_ATIME() APDS9960_ReadReg8(APDS9960_ATIME)
#define Get_APDS9960_WTIME() APDS9960_ReadReg8(APDS9960_WTIME)
#define Get_APDS9960_AILT() APDS9960_ReadReg16(APDS9960_AILTL)
#define Get_APDS9960_AIHT() APDS9960_ReadReg16(APDS9960_AIHTL)

#define Get_APDS9960_PILT() APDS9960_ReadReg8(APDS9960_PILT)
#define Get_APDS9960_PIHT() APDS9960_ReadReg8(APDS9960_PIHT)

#define Get_APDS9960_PERS() APDS9960_ReadReg8(APDS9960_PERS)

//----------------------------------------

#endif