#ifndef __OBJ_H__
#define __OBJ_H__
/**
 * 通用IO部分
 * 必须初始化
 * 无具体实现
 * 派生为主
*/
typedef struct _BaseIO
{
	unsigned char (*pRead)(void*);						// 读字节
	unsigned (*pReads)(void*,char*,unsigned);		// 写字符串
	void (*pWrite)(void*,unsigned char);				// 写字节
	unsigned (*pWrites)(void*,const char*,unsigned);	// 读字符串
	void (*pSeek)(void*,signed);						// 移动
    void (*pClose)(void*);                                   //

}BaseIO;

#define pIO(_h)                         ((BaseIO*)_h)                   // 类型转换
#define iWrite(_h,_v)                pIO(_h)->pWrite(_h,_v)          	// 写入字符
#define iWrites(_h,_s,_l)            pIO(_h)->pWrite(_h,_s,_l)       	// 写入字符串
#define iRead(_h)                    pIO(_h)->pRead(_h)              	// 读取字符
#define iReads(_h,_d,_l)             pIO(_h)->pReads(_h,_d,_l)       	// 读取字符串
#define iClose(_h)                   pIO(_h)->pClose(_h)             	// 

#endif /* __OBJ_H__ */
