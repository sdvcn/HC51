/**
 * Apds-9960
*/
#ifndef _APDS9960_H_
#define _APDS9960_H_

#ifndef NCOMPILE_EXT_APDS9960

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
#define APDS9960_ENABLE         0x80                    // 使能控制寄存器
#define BIT_PON            (1ul << 0)                   // 主电源
#define BIT_AEN            (1ul << 1)                   // 环境光线
#define BIT_PEN            (1ul << 2)                   // 接近判定
#define BIT_WEN            (1ul << 3)                   // 等待延时
#define BIT_AIEN           (1ul << 4)                   // 环境光线
#define BIT_PIEN           (1ul << 5)                   // 接近中断
#define BIT_GEN            (1ul << 6)                   // 手势
/**
 * 通用供电使能
 * 7: 保留,默认写0
 * 6:
 * 5:
 * 4:
 * 3:
 * 2:ALS使能
 * 1:Adc/内部始终使能
*/
#define APDS9960_GetENABLE(_h)          IIC_ReadMem8(_h,APDS9960_ENABLE)        // 获取供电状态
#define APDS9960_SetENABLE(_h,_v)       IIC_WriteMem8(_h,APDS9960_ENABLE,_v)    // 设定供电状态
#define APDS9960_ClearENABLE(_h)        APDS9960_SetENABLE(_h,0x00)             // Apds 9960 关闭所有使能
#define APDS9960_SetGEN(_h,_v)          IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x3f) | (_v & 0x01) << 6 );    // 手势模式使能
#define APDS9960_SetPIEN(_h,_v)         IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x5f) | (_v & 0x01) << 5 );    // 中断使能
#define APDS9960_SetAIEN(_h,_v)         IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x6f) | (_v & 0x01) << 4 );    // ALS 中断使能
#define APDS9960_SetWEN(_h,_v)          IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x77) | (_v & 0x01) << 3 );    // 等待使能,同时暂停等待计时
#define APDS9960_SetPEN(_h,_v)          IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x7b) | (_v & 0x01) << 2 );    // 接近模式使能
#define APDS9960_SetAEN(_h,_v)          IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x7d) | (_v & 0x01) << 1 );    // ALS 模式使能
#define APDS9960_SetPON(_h,_v)          IIC_WriteMem8(_h,APDS9960_ENABLE,(APDS9960_GetENABLE() & 0x7e) | (_v & 0x01) << 0 );    // 主电源使能
#define APDS9960_ATIME          0x81    // 环境光 adc 中断时间
#define APDS9960_GetATIME(_h)           IIC_ReadMem8(_h,APDS9960_ATIME)
#define APDS9960_SetATIME(_h,_v)        IIC_WriteMem8(_h,APDS9960_ATIME,_v)
#define APDS9960_WTIME          0x83                                            // 延时寄存器
#define APDS9960_SetWTIME(_h,_v)        IIC_WriteMem8(_h,APDS9960_WTIME,_v)     // 设置延时寄存器

#define APDS9960_AILTL          0x84    // 环境光低阀值 L
#define APDS9960_AILTH          0x85    // 环境光低阀值 H
#define APDS9960_SetAILTL(_h,_v)        IIC_WriteMem8(_h,APDS9960_AILTL,_v)     // 设定环境光低阀值 L
#define APDS9960_SetAILTH(_h,_v)        IIC_WriteMem8(_h,APDS9960_AILTH,_v)     // 设定环境光低阀值 H
#define APDS9960_SetAILT(_h,_v)         IIC_WriteShort(_h,APDS9960_AILTL,_v)    // 设定环境光低阀值 

#define APDS9960_GetAILTL(_h)           IIC_ReadMem8(_h,APDS9960_AILTL)         // 获取设定环境光低阀值 L
#define APDS9960_GetAILTH(_h)           IIC_ReadMem8(_h,APDS9960_AILTH)         // 获取设定环境光低阀值 H
#define APDS9960_GetAILT(_h)            IIC_ReadShort(_h,APDS9960_AILTL)        // 获取设定环境光低阀值

#define APDS9960_AIHTL          0x86        // 环境光高阀值 L
#define APDS9960_AIHTH          0x87        // 环境光高阀值 H
#define APDS9960_SetAIHTL(_h,_v)        IIC_WriteMem8(_h,APDS9960_AIHTL,_v)     // 设定环境光高阀值 L
#define APDS9960_SetAIHTH(_h,_v)        IIC_WriteMem8(_h,APDS9960_AIHTH,_v)     // 设定环境光高阀值 H
#define APDS9960_SetAIHT(_h,_v)         IIC_WriteShort(_h,APDS9960_AIHTL,_v)    // 设定环境光高阀值 

#define APDS9960_GetAIHTL(_h)           IIC_ReadMem8(_h,APDS9960_AIHTL)         // 获取设定环境光高阀值 L
#define APDS9960_GetAIHTH(_h)           IIC_ReadMem8(_h,APDS9960_AIHTH)         // 获取设定环境光高阀值 H
#define APDS9960_GetAIHT(_h)            IIC_ReadShort(_h,APDS9960_AIHTL)        // 获取设定环境光高阀值
/// 接近中断阀值
#define APDS9960_PILT           0x89        // 接近中断阀值 低
#define APDS9960_GetPILT(_h)            IIC_ReadMem8(_h,APDS9960_PILT)
#define APDS9960_SetPILT(_h,_v)         IIC_WriteMem8(_h,APDS9960_PILT,_v)
#define APDS9960_PIHT           0x8B        // 接近中断阀值 高
#define APDS9960_GetPIHT(_h)            IIC_ReadMem8(_h,APDS9960_PIHT)
#define APDS9960_SetPIHT(_h,_v)         IIC_WriteMem8(_h,APDS9960_PIHT,_v)

/// 循环测试设置 光线传感器&接近传感器
#define APDS9960_PERS           0x8C                
#define APDS9960_GetPERS(_h)      IIC_ReadMem8(_h,APDS9960_PERS)
#define APDS9960_GetPPERS(_h)     (APDS9960_GetPERS() >> 4)
#define APDS9960_GetAPRES(_h)     (APDS9960_GetPERS() & 0x0f)
/// 取值范围不大于 0x0f
#define APDS9960_SetPPERS(_h,_v)   IIC_WriteMem8(_h,APDS9960_PERS,(APDS9960_GetPERS(_h) & 0x0f) | (_v << 4))
/// ALS 传感器循环设置
/// 取值范围不大于 0x0f
#define APDS9960_SetAPRES(_h,_v)   IIC_WriteMem8(_h,APDS9960_PERS,(APDS9960_GetPERS(_h) & 0xf0) | (_v & 0x0f))

#define APDS9960_CONFIG1        0x8D
#define APDS9960_SetWLONG(_h,_v)        IIC_WriteMem8(_h,APDS9960_CONFIG1,(_v & 0x01)?0x62:0x60)      // 设置wlong,x12
#define APDS9960_GetWLONG(_h)           ((IIC_ReadMem8(_h,APDS9960_CONFIG1) & 0x02)?1ul:0ul)
/// 接近脉冲寄存器
#define APDS9960_PPULSE         0x8E
/**
 * LED脉冲宽度
 * 0:4us
 * 1:8us
 * 2:16us
 * 3:32us
*/
#define APDS9960_SetPPLEN(_h,_v)        IIC_WriteMem8(_h,APDS9960_PPULSE,IIC_ReadMem8(_h,APDS9960_PPULSE) & 0x3f | ((_v & 0x03) << 6))
/**
 * 距离传感器计数
*/
#define APDS9960_SetPPULSE(_h,_v)       IIC_WriteMem8(_h,APDS9960_PPULSE,IIC_ReadMem8(_h,APDS9960_PPULSE) & 0xc0 | (_v & 0x3f))
/**
 * 7:6  LDRIVE
 * 3:2  PGAIN
 * 1:0  AGAIN
*/
#define APDS9960_CONTROL        0x8F                // 控制寄存器
#define APDS9960_GetCONTROL(_h)         IIC_ReadMem8(_h,APDS9960_CONTROL)
/**
 * LED驱动电流
 * 0:100ma
 * 1:50ma
 * 2:25ma
 * 3:12.5ma
*/
#define APDS9960_SetLDRIVE(_h,_v)       IIC_WriteMem8(_h,APDS9960_CONTROL,((APDS9960_GetCONTROL(_h) & 0x3F) | ((_v & 0x03) << 5))) 
/**
 * 距离增益控制
 * 0:1x
 * 1:2x
 * 2:4x
 * 3:8x
*/
#define APDS9960_SetPGAIN(_h,_v)        IIC_WriteMem8(_h,APDS9960_CONTROL,((APDS9960_GetCONTROL(_h) & 0xF3) | ((_v & 0x03) << 2))) 
/**
 * 颜色可见光增益
 * 0:1x
 * 1:4x
 * 2:16x
 * 3:64x
*/
#define APDS9960_SetAGAIN(_h,_v)        IIC_WriteMem8(_h,APDS9960_CONTROL,((APDS9960_GetCONTROL(_h) & 0xFC) | ((_v & 0x03) << 0))) 

#define APDS9960_CONFIG2        0x90
#define APDS9960_GetCONFIG2(_h)         IIC_ReadMem8(_h,APDS9960_CONFIG2)
#define APDS9960_SetCONFIG2(_h,_v)      IIC_WriteMem8(_h,APDS9960_CONFIG2,_v)
#define APDS9960_GetPSIEN(_h)           CheckBIT(APDS9960_GetCONFIG2(_h),7)
#define APDS9960_SetPSIEN(_h,_v)        APDS9960_SetCONFIG2(_h,(APDS9960_GetCONFIG2(_h)&0x70)|((_v&0x01)<<7)|0x01)
#define APDS9960_GetCPSIEN(_h)          CheckBIT(APDS9960_GetCONFIG2(_h),6)
#define APDS9960_SetCPSIEN(_h,_v)       APDS9960_SetCONFIG2(_h,(APDS9960_GetCONFIG2(_h)&0xB0)|((_v&0x01)<<6)|0x01)
#define APDS9960_GetLedBoost(_h)        ((APDS9960_GetCONFIG2(_h) &  0xCF) >> 4)
#define APDS9960_SetLedBoost(_h,_v)     APDS9960_SetCONFIG2(_h,(APDS9960_GetCONFIG2(_h)&0xC0)|((_v&0x02)<<4)|0x01)    // Led Boost 设置 

#define APDS9960_ID             0x92                //[*R] 器件编号
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
#define APDS9960_STATUS         0x93                //[*R] 器件状态
#define APDS9960_GetSTATUS(_h)  IIC_ReadMem8(_h,APDS9960_STATUS)        // 获取寄存器状态
#define APDS9960_GetCPSAT(_h)   CheckBIT(APDS9960_GetSTATUS(_h),7)      // 可见光传感器
#define APDS9960_GetPGSAT(_h)   CheckBIT(APDS9960_GetSTATUS(_h),6)      // 距离传感器
#define APDS9960_GetPINT(_h)    CheckBIT(APDS9960_GetSTATUS(_h),5)      // 距离传感器中断
#define APDS9960_GetAINT(_h)    CheckBIT(APDS9960_GetSTATUS(_h),4)      // ALS 传感器中断
#define APDS9960_GetGINT(_h)    CheckBIT(APDS9960_GetSTATUS(_h),2)      // 手势传感器中断
#define APDS9960_GetPVALID(_h)  CheckBIT(APDS9960_GetSTATUS(_h),1)      // PVDATA数据中断位
#define APDS9960_GetAVALID(_h)  CheckBIT(APDS9960_GetSTATUS(_h),0)      // AVALID数据中断位
/**
 * 环境光寄存器
*/
#define APDS9960_CDATAL         0x94                                    //[*R] 环境光L
#define APDS9960_GetCDATAL(_h)  IIC_ReadMem8(_h,APDS9960_CDATAL)        // 读取环境光低
#define APDS9960_CDATAH         0x95                                    //[*R] 环境光H
#define APDS9960_GetCDATAH(_h)  IIC_ReadMem8(_h,APDS9960_CDATAH)        // 读取环境光高
#define APDS9960_GetCDATA(_h)   IIC_ReadShort(_h,APDS9960_CDATAL)       // 读取环境光
#define APDS9960_RDATAL         0x96                                    //[*R] 红色数据L
#define APDS9960_GetRDATAL(_h)  IIC_ReadMem8(_h,APDS9960_RDATAL)        // 读取红色低
#define APDS9960_RDATAH         0x97                                    //[*R] 红色数据H
#define APDS9960_GetRDATAH(_h)  IIC_ReadMem8(_h,APDS9960_RDATAH)        // 读取红色高
#define APDS9960_GetRDATA(_h)   IIC_ReadShort(_h,APDS9960_RDATAL)       // 读取红色
#define APDS9960_GDATAL         0x98                                    //[*R] 绿色数据L
#define APDS9960_GetGDATAL(_h)  IIC_ReadMem8(_h,APDS9960_GDATAL)        // 读取绿色低
#define APDS9960_GDATAH         0x99                                    //[*R] 绿色数据H
#define APDS9960_GetGDATAH(_h)  IIC_ReadMem8(_h,APDS9960_GDATAH)        // 读取绿色高
#define APDS9960_GetGDATA(_h)   IIC_ReadShort(_h,APDS9960_GDATAL)       // 读取绿色
#define APDS9960_BDATAL         0x9A                                    //[*R] 蓝色数据L
#define APDS9960_GetBDATAL(_h)  IIC_ReadMem8(_h,APDS9960_BDATAL)        // 读取蓝色低
#define APDS9960_BDATAH         0x9B                                    //[*R] 蓝色数据H
#define APDS9960_GetBDATAH(_h)  IIC_ReadMem8(_h,APDS9960_BDATAH)        // 读取蓝色高
#define APDS9960_GetBDATA(_h)   IIC_ReadShort(_h,APDS9960_BDATAL)       // 读取蓝色
#define APDS9960_PDATA          0x9C                                    //[*R] 距离数据
#define APDS9960_GetPData(_h)   IIC_ReadMem8(_h,APDS9960_PDATA)         // 读取距离寄存器




#define APDS9960_POFFSET_UR     0x9D
#define APDS9960_POFFSET_DL     0x9E
#define APDS9960_CONFIG3        0x9F

#define APDS9960_GPENTH         0xA0                // 手势进入阀值寄存器
#define APDS9960_GEXTH          0xA1                // 手势退出阀值寄存器
#define APDS9960_GCONF1         0xA2                // 手势配置寄存器1
#define APDS9960_GCONF2         0xA3                // 手势配置寄存器2
#define APDS9960_GOFFSET_U      0xA4                // 手势传感器 U 偏移设置 -127 ~ 127
#define APDS9960_GOFFSET_D      0xA5                // 手势传感器 D 偏移设置 -127 ~ 127
#define APDS9960_GOFFSET_L      0xA7                // 手势传感器 L 偏移设置 -127 ~ 127
#define APDS9960_GOFFSET_R      0xA9                // 手势传感器 R 偏移设置 -127 ~ 127
#define APDS9960_GPULSE         0xA6                // 手势 脉冲 & 计数 寄存器
#define APDS9960_GCONF3         0xAA
/**
 * 手势模式 选择手势接受用传感器
 * 0 = 上下/左右 同时生效
 * 1 = 上下 有效 左右无效
 * 2 = 左右 有效 上下无效
 * 3 = 上下/左右 同时生效
*/
#define APDS9960_SetGDIMS(_h,_v)   IIC_WriteMem8(_h,APDS9960_GCONF3,(_v & 0x03));
/// 手势设定 
#define APDS9960_GCONF4         0xAB                // 手势配置寄存器4 GIEM:手势中断/GMODE:手势模式/GFIFO_CLR:数据清理
#define APDS9960_GetGCONF4(_h)          IIC_ReadMem8(_h,APDS9960_GCONF4)
#define APDS9960_ClearGFIFO(_h)         IIC_WriteMem8(_h,APDS9960_GCONF4,(APDS9960_GetGCONF4(_h) & 0x03) | 0x04 )                   // 手势模式 清除GFIFO,GINT,GVALID等.
#define APDS9960_SetGIEN(_h,_v)         IIC_WriteMem8(_h,APDS9960_GCONF4,(APDS9960_GetGCONF4(_h) & 0x05) | (_v & 0x01) << 1)        // 手势模式 中断开关
#define APDS9960_SetGMODE(_h,_v)        IIC_WriteMem8(_h,APDS9960_GCONF4,(APDS9960_GetGCONF4(_h) & 0x06) | (_v & 0x01) << 0)        // 手势模式 ALS 与 手势 切换.       
#define APDS9960_GFLVL          0xAE                //[*R] 手势寄存器缓冲数量
#define APDS9960_GetGFLVL(_h)       IIC_ReadMem8(_h,APDS9960_GFLVL)     // 获取手势FIFO寄存器量
#define APDS9960_GSTATUS        0xAF                //[*R] 手势状态寄存器
#define APDS9960_GetGFOV(_h)        CheckBIT(IIC_ReadMem8(_h,APDS9960_GSTATUS),1)       // 手势FIFO寄存器溢出
#define APDS9960_GetGVALID(_h)      CheckBIT(IIC_ReadMem8(_h,APDS9960_GSTATUS),0)       // 判定手势FIFO寄存器存在数据

/// 强制中断
#define APDS9960_IFORCE         0xE4
/// 接近中断清除
#define APDS9960_PICLEAR        0xE5
#define APDS9960_ClearPI(_h)    IIC_WriteMem8(_h,APDS9960_PICLEAR,0xff)                 // 清除距离传感器中断
/// ALS 通道中断清除
#define APDS9960_CICLEAR        0xE6
#define APDS9960_ClearCI(_h)    IIC_WriteMem8(_h,APDS9960_CICLEAR,0xff)                 // 清除Als 传感器中断
/// 全部非手势中断清除
#define APDS9960_AICLEAR        0xE7
#define APDS9960_ClearAI(_h)    IIC_WriteMem8(_h,APDS9960_AICLEAR,0xff)                 // 全部非手势中断清除

#define APDS9960_GFIFO_U        0xFC                //[*R] 手势 上
#define APDS9960_GFIFO_D        0xFD                //[*R] 手势 下
#define APDS9960_GFIFO_L        0xFE                //[*R] 手势 左
#define APDS9960_GFIFO_R        0xFF                //[*R] 手势 右
//-----------------------------------------------------------------------------
/* 启动使能 */



//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
/// 环境光线







//-----------------------------------------------------------------------------
/**
 * 距离相关
*/


//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------





/// 手势进入
#define APDS9960_SetGestureEnterThresh(_v)  IIC_WriteMem8(_h,APDS9960_GPENTH,_v)
/// 手势离开
#define APDS9960_SetGestureExitThresh(_v) IIC_WriteMem8(_h,APDS9960_GEXTH,_v)

/// 获取手势配置寄存器1
#define APDS9960_GetGCONF1()    IIC_ReadMem8(_h,APDS9960_GCONF1)
/**
 * ????
 * 手势模式 中断前提交FIFO数量
 * 0 = 1 
 * 1 = 4
 * 2 = 8
 * 3 = 16
*/
#define APDS9960_SetGFIFOTH(_v) IIC_WriteMem8(_h,APDS9960_GCONF1, (APDS9960_GetGCONF1() & 0x3f) | (_v & 0xfc) << 6 )
/**
 * 
*/
#define APDS9960_SetGEXMSK(_v)  IIC_WriteMem8(_h,APDS9960_GCONF1, (APDS9960_GetGCONF1() & 0xc3) | (_v & 0xf0) << 2 )
#define APDS9960_SetGEXPERS(_v) IIC_WriteMem8(_h,APDS9960_GCONF1, (APDS9960_GetGCONF1() & 0xfc) | (_v & 0xfc) << 0 )

/// 获取手势配置寄存器2
#define APDS9960_GetGCONF2()    IIC_ReadMem8(_h,APDS9960_GCONF2)
/**
 * 手势模式 距离增益
 * 0 = 1x
 * 1 = 2x
 * 2 = 4x
 * 3 = 8x
*/
#define APDS9960_SetGGAIN(_v) IIC_WriteMem8(_h,APDS9960_GCONF2, (APDS9960_GetGCONF2() & 0x1f) | (_v & 0xfc) << 5 )
/**
 * 手势模式 LED驱动能力
 * 0 = 100 mA
 * 1 = 50 mA
 * 2 = 25 mA
 * 3 = 12.5 mA
*/
#define APDS9960_SetGLDRIVE(_h,_v) IIC_WriteMem8(_h,APDS9960_GCONF2, (APDS9960_GetGCONF2() & 0x73) | (_v & 0xfc) << 3 )
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
#define APDS9960_SetGWTIME(_v) IIC_WriteMem8(_h,APDS9960_GCONF2, (APDS9960_GetGCONF2() & 0x7c) | (_v & 0xf8) << 0 )

#define APDS9960_GetGPULSE()    IIC_ReadMem8(_h,APDS9960_GPULSE)
/**
 * 手势模式 LED 脉冲宽度
 * 0 = 4/us
 * 1 = 8/us (Default)
 * 2 = 16/us
 * 3 = 32/us
*/
#define APDS9960_SetGPLEN(_v)   IIC_WriteMem8(_h,APDS9960_GPULSE, (APDS9960_GetGPULSE() & 0x3f) | (_v & 0xfc) << 6 )
/**
 * 手势模式 LDR 脉冲计数
 * 赋值为 val + 1
*/
#define APDS9960_SetGPULSE(_v)   IIC_WriteMem8(_h,APDS9960_GPULSE, (APDS9960_GetGPULSE() & 0xc0) | (_v & 0x3f) << 0 )




//-----------------------------------------------------------------------------
/// 初始化APDS-9960
void APDS9960_Init();

unsigned char APDS9960_ReadGesture();
/// 开启手势模式
void APDS9960_EnableGestureSensor(unsigned char itr);
/// 关闭手势模式
void APDS9960_DisableGestureSensor();

//-----------------------------------------------------------------------------



void Apds_irsSW(sI2c* h);
unsigned char ApdsCheckID(sI2c* h);

void Apds_InitALS(sI2c *h);
//void Apds_ReadD(sI2c *h);
void Apds_Dump(sI2c* h);

#endif // NCOMPILE_EXT_APDS9960
#endif
