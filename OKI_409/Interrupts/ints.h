/******************************************************
   ints.h 
   
   ML610Q409，中断配置函数模块；
   
   History
    2017-9-21 
******************************************************/ 
//#ifndef _INTS_H_
//#define _INTS_H_ 
#include "MacroAndConst.h"

#define INTS_DEPLOY_OK   (0) //成功 
#define INTS_DEPLOY_FAIL (-1)//失败 

#define INTS_LOW  (0) //低电平状态 
#define INTS_HIGH (1) //高电平状态 


/******************************************
 **                 API
*******************************************/
/* 中断允许 */
int IE1_init(unsigned int EP_00,unsigned int EP_01,
             unsigned int EP_02,unsigned int EP_03,
             unsigned int EP_04);
int IE2_init(unsigned int ESIO_0,unsigned int ESIO_1,
             unsigned int EP_5);
int IE3_init(unsigned int ETM_0,unsigned int ETM_1);
int IE4_init(unsigned int EUA_0,unsigned int EMD_0,
             unsigned int ER_AD);
int IE5_init(unsigned int ETM_2, unsigned int ETM_3);
int IE6_init(unsigned int EPW_0,unsigned int E_128H,
             unsigned int E_32H);
int IE7_init(unsigned int E_16H, unsigned int E_2H);

/* 中断请求 */ 
int IRQ0_init(unsigned int QW_DT);
int IRQ1_init(unsigned int QP_00, unsigned int QP_01,
              unsigned int QP_02, unsigned int QP_03,
              unsigned int QP_04);
int IRQ2_init(unsigned int QSIO_0, unsigned int QSIO_1,
              unsigned int QP_5);
int IRQ3_init(unsigned int QTM_0, unsigned int QTM_1);
int IRQ4_init(unsigned int QUA_0, unsigned int QMD_0,
              unsigned int QR_AD);
int IRQ5_init(unsigned int QTM_2, unsigned int QTM_3);
int IRQ6_init(unsigned int QPW_0,unsigned int Q_128H,
              unsigned int Q_32H);
int IRQ7_init(unsigned int Q_16H, unsigned int Q_2H);


// #endif /*_INTS_H_*/