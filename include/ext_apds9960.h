/**
 * Apds-9960
*/

#ifndef _EXT_APDS9960_H_
#define _EXT_APDS9960_H_







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