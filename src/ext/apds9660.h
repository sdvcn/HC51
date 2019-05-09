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
/// 环境光阀值 L
#define APDS9960_AILTL          0x84
#define APDS9960_AILTH          0x85
/// 环境光阀值 H
#define APDS9960_AIHTL          0x86
#define APDS9960_AIHTH          0x87
/// 接近中断阀值
#define APDS9960_PILT           0x89
#define APDS9960_PIHT           0x8B

/// 循环测试设置 光线传感器&接近传感器
#define APDS9960_PERS           0x8C                
#define APDS9960_CONFIG1        0x8D
/// 接近脉冲寄存器
#define APDS9960_PPULSE         0x8E

#define APDS9960_CONTROL        0x8F
#define APDS9960_CONFIG2        0x90
#define APDS9960_ID             0x92                //[*R] 器件编号
#define APDS9960_STATUS         0x93                //[*R] 器件状态
#define APDS9960_CDATAL         0x94                //[*R] 环境光L
#define APDS9960_CDATAH         0x95                //[*R] 环境光H
#define APDS9960_RDATAL         0x96                //[*R] 红色数据L
#define APDS9960_RDATAH         0x97                //[*R] 红色数据H
#define APDS9960_GDATAL         0x98                //[*R] 绿色数据L
#define APDS9960_GDATAH         0x99                //[*R] 绿色数据H
#define APDS9960_BDATAL         0x9A                //[*R] 蓝色数据L
#define APDS9960_BDATAH         0x9B                //[*R] 蓝色数据H
#define APDS9960_PDATA          0x9C                //[*R] 距离数据


#define APDS9960_POFFSET_UR     0x9D
#define APDS9960_POFFSET_DL     0x9E
#define APDS9960_CONFIG3        0x9F

#define APDS9960_GPENTH         0xA0            // 手势进入阀值寄存器
#define APDS9960_GEXTH          0xA1            // 手势退出阀值寄存器
#define APDS9960_GCONF1         0xA2            // 手势配置寄存器1
#define APDS9960_GCONF2         0xA3            // 手势配置寄存器2
#define APDS9960_GOFFSET_U      0xA4            // 手势传感器 U 偏移设置 -127 ~ 127
#define APDS9960_GOFFSET_D      0xA5            // 手势传感器 D 偏移设置 -127 ~ 127
#define APDS9960_GOFFSET_L      0xA7            // 手势传感器 L 偏移设置 -127 ~ 127
#define APDS9960_GOFFSET_R      0xA9            // 手势传感器 R 偏移设置 -127 ~ 127
#define APDS9960_GPULSE         0xA6            // 手势 脉冲 & 计数 寄存器
#define APDS9960_GCONF3         0xAA
/// 手势设定 
#define APDS9960_GCONF4         0xAB            // 手势配置寄存器4 GIEM:手势中断/GMODE:手势模式/GFIFO_CLR:数据清理
/// 手势寄存器缓冲数量
#define APDS9960_GFLVL          0xAE
/// 手势状态
#define APDS9960_GSTATUS        0xAF            // R : 
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
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Apds9960 写寄存器数据
void APDS9960_Write(unsigned char reg,unsigned len,char* src);
/// Apds9960 读数据
void APDS9960_Read(unsigned len,char* dst);
/// Apds9960 读寄存器
unsigned char APDS9960_ReadReg(unsigned char reg,unsigned len,char* dst);
/// 读8位
unsigned char APDS9960_ReadReg8(unsigned char reg);
/// 读16位
//#define APDS9960_ReadReg16(_v) ((APDS9960_ReadReg8(_v+1) << 8) | (APDS9960_ReadReg8(_v)))
unsigned short APDS9960_ReadReg16(unsigned char reg);
/// 写8位
void APDS9960_WriteReg8(unsigned char reg,unsigned char val);
/// 写16位
//#define APDS9960_WriteReg16(_r,_v) do{APDS9960_WriteReg8((_r),(_v)&0x00ff);APDS9960_WriteReg8((_r)+1,((_v) & 0xff00) >> 8);}while(0) 
void APDS9960_WriteReg16(unsigned char reg,unsigned short val);
//-----------------------------------------------------------------------------
#define APDS9960_GetENABLE()        APDS9960_ReadReg8(APDS9960_ENABLE)
//#define APDS9960_SetENABLE(_v)      APDS9960_WriteReg8(APDS9960_ENABLE,_v);
/// Apds 9960 关闭所有使能
#define APDS9960_ClearENABLE()      APDS9960_WriteReg8(APDS9960_ENABLE,0x00);
/// 手势模式使能
#define APDS9960_SetGEN(_v)         APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x3f) | (_v & 0x01) << 6 );
/// 中断使能
#define APDS9960_SetPIEN(_v)        APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x5f) | (_v & 0x01) << 5 );
/// ALS 中断使能
#define APDS9960_SetAIEN(_v)        APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x6f) | (_v & 0x01) << 4 );
/// 等待使能,同时暂停等待计时
#define APDS9960_SetWEN(_v)         APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x77) | (_v & 0x01) << 3 );
/// 接近模式使能
#define APDS9960_SetPEN(_v)         APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x7b) | (_v & 0x01) << 2 );
/// ALS 模式使能
#define APDS9960_SetAEN(_v)         APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x7d) | (_v & 0x01) << 1 );
/// 主电源使能
#define APDS9960_SetPON(_v)         APDS9960_WriteReg8(APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x7e) | (_v & 0x01) << 0 );

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
/// 手势模式 清除GFIFO,GINT,GVALID等.
#define APDS9960_ClearGFIFO()       APDS9960_WriteReg8(APDS9960_GCONF4,(APDS9960_GetGCONF4() & 0x03) | 0x04 );
/// 手势模式 中断开关
#define APDS9960_SetGIEN(_v)          APDS9960_WriteReg8(APDS9960_GCONF4,(APDS9960_GetGCONF4() & 0x05) | (_v & 0x01) << 1);
/// 手势模式 ALS 与 手势 切换.
#define APDS9960_SetGMODE(_v)         APDS9960_WriteReg8(APDS9960_GCONF4,(APDS9960_GetGCONF4() & 0x06) | (_v & 0x01) << 0);
//#define APDS9960_ClearGFIFO()       APDS9960_WriteReg8(APDS9960_GCONF4,APDS9960_GetGCONF4()|0x04)



//-----------------------------------------------------------------------------
#define APDS9960_GetCONFIG2()       APDS9960_ReadReg8(APDS9960_CONFIG2)
#define APDS9960_GetCONTROL()       APDS9960_ReadReg8(APDS9960_CONTROL)
//-----------------------------------------------------------------------------
/// Led Boost 设置 
#define APDS9960_LedBoost(_v)       APDS9960_WriteReg8(APDS9960_CONFIG2,((APDS9960_GetCONFIG2() & 0xCF) | ((_v & 0x03) << 4)))
/// LED 驱动电流控制
#define APDS9960_LedDrive(_v)       APDS9960_WriteReg8(APDS9960_CONTROL,((APDS9960_GetCONTROL() & 0x3F) | ((_v & 0x03) << 5)))
/// 接近增益控制
#define APDS9960_SetProximityGain(_v)   APDS9960_WriteReg8(APDS9960_CONTROL,((APDS9960_GetCONTROL() & 0xF3) | ((_v & 0x03) << 2)))
/// 颜色增益控制
#define APDS9960_SetAmbientLightGain(_v)   APDS9960_WriteReg8(APDS9960_CONTROL,((APDS9960_GetCONTROL() & 0xFC) | ((_v & 0x03) << 0)))
/// 接近中断阀值 低
#define APDS9960_SetProxIntLowThresh(_v)   APDS9960_WriteReg8(APDS9960_PILT,_v)
#define APDS9960_GetProxIntLowThresh()   APDS9960_ReadReg8(APDS9960_PILT)
/// 接近中断阀值 高
#define APDS9960_SetProxIntHighThresh(_v)   APDS9960_WriteReg8(APDS9960_PIHT,_v)
#define APDS9960_GetProxIntHighThresh()   APDS9960_ReadReg8(APDS9960_PIHT)

/// 光线传感器阀值 低
#define APDS9960_SetLightIntLowThreshold(_v)    APDS9960_WriteReg16(APDS9960_AILTL,_v);
#define APDS9960_GetLightIntLowThreshold()      APDS9960_ReadReg16(APDS9960_AILTL)

/// 光线传感器阀值 高
#define APDS9960_SetLightIntHighThreshold(_v)    APDS9960_WriteReg16(APDS9960_AIHTL,_v);
#define APDS9960_GetLightIntHighThreshold()      APDS9960_ReadReg16(APDS9960_AIHTL)


#define APDS9960_GetPERS()      APDS9960_ReadReg8(APDS9960_PERS)
#define APDS9960_GetPPERS()     (APDS9960_GetPERS() >> 4)
#define APDS9960_GetAPRES()     (APDS9960_GetPERS() & 0x0f)
/// 接近传感器循环设置
/// 取值范围不大于 0x0f
#define APDS9960_SetPPERS(_v)   APDS9960_WriteReg8(APDS9960_PERS,(APDS9960_GetPERS() & 0x0f) | (_v << 4))
/// ALS 传感器循环设置
/// 取值范围不大于 0x0f
#define APDS9960_SetAPRES(_v)   APDS9960_WriteReg8(APDS9960_PERS,(APDS9960_GetPERS() & 0xf0) | (_v & 0x0f))

/// 接近中断
#define APDS9960_SetPSIEN()     APDS9960_WriteReg8(APDS9960_CONFIG2,(APDS9960_GetCONFIG2() & 0x7f) | (_v & 0xfe ) << 7 ) ;
/// ALS 中断
#define APDS9960_SetCPSIEN()    APDS9960_WriteReg8(APDS9960_CONFIG2,(APDS9960_GetCONFIG2() & 0xbf) | (_v & 0xfe ) << 6 ) ;

/// 手势进入
#define APDS9960_SetGestureEnterThresh(_v)  APDS9960_WriteReg8(APDS9960_GPENTH,_v)
/// 手势离开
#define APDS9960_SetGestureExitThresh(_v) APDS9960_WriteReg8(APDS9960_GEXTH,_v)

/// 获取手势配置寄存器1
#define APDS9960_GetGCONF1()    APDS9960_ReadReg8(APDS9960_GCONF1)
/**
 * ????
 * 手势模式 中断前提交FIFO数量
 * 0 = 1 
 * 1 = 4
 * 2 = 8
 * 3 = 16
*/
#define APDS9960_SetGFIFOTH(_v) APDS9960_WriteReg8(APDS9960_GCONF1, (APDS9960_GetGCONF1() & 0x3f) | (_v & 0xfc) << 6 )
/**
 * 
*/
#define APDS9960_SetGEXMSK(_v)  APDS9960_WriteReg8(APDS9960_GCONF1, (APDS9960_GetGCONF1() & 0xc3) | (_v & 0xf0) << 2 )
#define APDS9960_SetGEXPERS(_v) APDS9960_WriteReg8(APDS9960_GCONF1, (APDS9960_GetGCONF1() & 0xfc) | (_v & 0xfc) << 0 )

/// 获取手势配置寄存器2
#define APDS9960_GetGCONF2()    APDS9960_ReadReg8(APDS9960_GCONF2)
/**
 * 手势模式 距离增益
 * 0 = 1x
 * 1 = 2x
 * 2 = 4x
 * 3 = 8x
*/
#define APDS9960_SetGGAIN(_v) APDS9960_WriteReg8(APDS9960_GCONF2, (APDS9960_GetGCONF2() & 0x1f) | (_v & 0xfc) << 5 )
/**
 * 手势模式 LED驱动能力
 * 0 = 100 mA
 * 1 = 50 mA
 * 2 = 25 mA
 * 3 = 12.5 mA
*/
#define APDS9960_SetGLDRIVE(_v) APDS9960_WriteReg8(APDS9960_GCONF2, (APDS9960_GetGCONF2() & 0x73) | (_v & 0xfc) << 3 )
/**
 * 手势模式 检测时间间隔
 * 0 = 0 ms
 * 1 = 2.8 ms
 * 3 = 8.4 ms
 * 4 = 14 ms
 * 5 = 22.4 ms
 * 6 = 30.8 ms
 * 7 = 39.2 ms
*/
#define APDS9960_SetGWTIME(_v) APDS9960_WriteReg8(APDS9960_GCONF2, (APDS9960_GetGCONF2() & 0x7c) | (_v & 0xf8) << 0 )

#define APDS9960_GetGPULSE()    APDS9960_ReadReg8(APDS9960_GPULSE)
/**
 * 手势模式 LED 脉冲宽度
 * 0 = 4/us
 * 1 = 8/us (Default)
 * 2 = 16/us
 * 3 = 32/us
*/
#define APDS9960_SetGPLEN(_v)   APDS9960_WriteReg8(APDS9960_GPULSE, (APDS9960_GetGPULSE() & 0x3f) | (_v & 0xfc) << 6 )
/**
 * 手势模式 LDR 脉冲计数
 * 赋值为 val + 1
*/
#define APDS9960_SetGPULSE(_v)   APDS9960_WriteReg8(APDS9960_GPULSE, (APDS9960_GetGPULSE() & 0xc0) | (_v & 0x3f) << 0 )
/**
 * 手势模式 选择手势接受用传感器
 * 0 = 上下/左右 同时生效
 * 1 = 上下 有效 左右无效
 * 2 = 左右 有效 上下无效
 * 3 = 上下/左右 同时生效
*/
#define APDS9960_SetGDIMS(_v)   APDS9960_WriteReg8(APDS9960_GCONF3,(_v & 0x03));
/// 手势FIFO寄存器溢出
#define APDS9960_GetGFOV()      ((APDS9960_ReadReg8(APDS9960_GSTATUS) & 0x02) >> 1 )
/// 手势FIFO寄存器存在数据
#define APDS9960_GetGVALID()    (APDS9960_ReadReg8(APDS9960_GSTATUS) & 0x01)

#define APDS9960_GetATIME() APDS9960_ReadReg8(APDS9960_ATIME)
#define APDS9960_SetATIME(_v) APDS9960_WriteReg8(APDS9960_ATIME,_v)
/**
 * 获取器件状态
 * (1ul << 7) CPSAT 光线传感器 清除寄存器 0xe6
 * (1ul << 6) PGSAT 接近传感器 清除寄存器 0xe5
 * (1ul << 5) PINT  接近传感器中断
 * (1ul << 4) AINT  ALS 传感器中断
 * (1ul << 3) 保留
 * (1ul << 2) GINT  手势传感器中断 fifo 全部清空时自动重置
 * (1ul << 1) PVALID PDATA 中数据读取后重置
 * (1ul << 0) AVALID 0x94~0x9b 中数据被读取后重置
*/
#define APDS9960_GetSTATUS() APDS9960_ReadReg8(APDS9960_STATUS)
//-----------------------------------------------------------------------------
/// 初始化APDS-9960
void APDS9960_Init();

unsigned char APDS9960_ReadGesture();
/// 开启手势模式
void APDS9960_EnableGestureSensor(unsigned char itr);
/// 关闭手势模式
void APDS9960_DisableGestureSensor();

//-------------
//void APDS9960_GestureSensor();
//void APDS9960_ReadGesture();
//--------------
/*
#define Get_APDS9960_ENABLE() APDS9960_ReadReg8(APDS9960_ENABLE)
#define Put_APDS9960_ENABLE(_v) APDS9960_WriteReg8(APDS9960_ENABLE,_v)

///


#define Get_APDS9960_WTIME() APDS9960_ReadReg8(APDS9960_WTIME)
#define Get_APDS9960_AILT() APDS9960_ReadReg16(APDS9960_AILTL)
#define Get_APDS9960_AIHT() APDS9960_ReadReg16(APDS9960_AIHTL)

#define Get_APDS9960_PILT() APDS9960_ReadReg8(APDS9960_PILT)
#define Get_APDS9960_PIHT() APDS9960_ReadReg8(APDS9960_PIHT)

#define Get_APDS9960_PERS() APDS9960_ReadReg8(APDS9960_PERS)

*/

//----------------------------------------
/// 开启APDS-9960 I2c访问
//unsigned char ADPS9960_I2c_En();

/// 停止APDS-9960 I2c访问
//unsigned char ADPS9960_I2c_Di();


#endif