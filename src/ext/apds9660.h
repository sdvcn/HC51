/**
 * 废弃
*/
#ifndef _APDS9960_H_
#define _APDS9960_H_

/* Acceptable device IDs */
#define APDS9960_ID_1           0xAB        //ADPS-9960
#define APDS9960_ID_2           0x9C 


//----------------------------------------
extern unsigned char APDS9960_ReadReg8(unsigned char reg);
extern unsigned short APDS9960_ReadReg16(unsigned char reg);
extern void APDS9960_WriteReg8(unsigned char reg,unsigned char val);
extern void APDS9960_WriteReg16(unsigned char reg,unsigned short val);

#define ExecIForce()    APDS9960_WriteReg8(APDS9960_IFORCE,0x00)
#define ExecPiClear()   APDS9960_WriteReg8(APDS9960_PICLEAR,0x00)
#define ExecCiClear()   APDS9960_WriteReg8(APDS9960_CICLEAR,0x00)
#define ExecAiClear()   APDS9960_WriteReg8(APDS9960_AICLEAR,0x00)
//-------------
extern void APDS9960_GestureSensor();
//extern void APDS9960_ReadGesture();
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
/// 开启APDS-9960 I2c访问
//unsigned char ADPS9960_I2c_En();

/// 停止APDS-9960 I2c访问
//unsigned char ADPS9960_I2c_Di();

void APDS9960_Init();

#endif