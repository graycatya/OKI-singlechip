#include<m610409.h>
#include "ints.h"

 /**********
   中断允许 
 **********/ 

/********************************** 
 * 函数名:IE1_init
 * 功能: IE1配置初始化 
 * 参数: EP_00,EP_01,EP_02,EP_03,EP_04
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/
int IE1_init(unsigned int EP_00,unsigned int EP_01,
             unsigned int EP_02,unsigned int EP_03,
			 unsigned int EP_04)
 {
   if(EP_00 > INTS_HIGH || EP_01 > INTS_HIGH || 
      EP_02 > INTS_HIGH || EP_03 > INTS_HIGH ||
      EP_04 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	EP00 = EP_00; EP01 = EP_01;
	EP02 = EP_02; EP03 = EP_03;
	EP04 = EP_04;
   return (INTS_DEPLOY_OK);	   	
 } 

/********************************** 
 * 函数名:IE2_init
 * 功能: IE2配置初始化 
 * 参数: ESIO_0,ESIO_1,EP_5
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/
int IE2_init(unsigned int ESIO_0,unsigned int ESIO_1,
             unsigned int EP_5)
 {
   if(ESIO_0 > INTS_HIGH || ESIO_1 > INTS_HIGH || 
      EP_5 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	ESIO0 = ESIO_0; ESIO1 = ESIO_1;
	EP5 = EP_5; 
   return (INTS_DEPLOY_OK);	 	
 }

/********************************** 
 * 函数名:IE3_init
 * 功能: IE3配置初始化 
 * 参数: ETM_0,ETM_1
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/ 
int IE3_init(unsigned int ETM_0,unsigned int ETM_1)
 {
   if(ETM_0 > INTS_HIGH || ETM_1 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	ETM0 = ETM_0; ETM1 = ETM_1;
   return (INTS_DEPLOY_OK);	  	
 }
 
/********************************** 
 * 函数名:IE4_init
 * 功能: IE4配置初始化 
 * 参数: EUA_0,EMD_0,ER_AD
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/ 
int IE4_init(unsigned int EUA_0,unsigned int EMD_0,
             unsigned int ER_AD)
 {
   if(EUA_0 > INTS_HIGH || EMD_0 > INTS_HIGH || 
      ER_AD > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	EUA0 = EUA_0; EMD0 = EMD_0;
	ERAD = ER_AD; 
   return (INTS_DEPLOY_OK);	   	
 }

/********************************** 
 * 函数名:IE5_init
 * 功能: IE5配置初始化 
 * 参数: ETM_2,ETM_3
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/  
int IE5_init(unsigned int ETM_2, unsigned int ETM_3)
 {
   if(ETM_2 > INTS_HIGH || ETM_3 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	ETM2 = ETM_2; ETM3 = ETM_3;
   return (INTS_DEPLOY_OK);	 	
 }

/********************************** 
 * 函数名:IE6_init
 * 功能: IE6配置初始化 
 * 参数: EPW_0,E_128H,E_32H
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/  
int IE6_init(unsigned int EPW_0,unsigned int E_128H,
             unsigned int E_32H)
 {
   if(EPW_0 > INTS_HIGH || E_128H > INTS_HIGH || 
      E_32H > INTS_HIGH) {
 	  return (INTS_DEPLOY_FAIL);
        }  
	EPW0 = EPW_0; E128H = E_128H;
	E32H = E_32H; 
   return (INTS_DEPLOY_OK);   	
 }

/********************************** 
 * 函数名:IE7_init
 * 功能: IE7配置初始化 
 * 参数: E_16H,E_2H
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/  
int IE7_init(unsigned int E_16H, unsigned int E_2H)
 {
   if(E_16H > INTS_HIGH || E_2H > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	E16H = E_16H; E2H = E_2H;
   return (INTS_DEPLOY_OK);	 	
 }
 
 /**********
   中断请求 
 **********/ 
 
/********************************** 
 * 函数名:IRQ0_init
 * 功能: IRQ0配置初始化 
 * 参数: QW_DT
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/
int IRQ0_init(unsigned int QW_DT)
 {
   if(QW_DT > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	QWDT = QW_DT; 
   return (INTS_DEPLOY_OK); 	
  } 


/********************************** 
 * 函数名:IRQ1_init
 * 功能: IRQ1配置初始化 
 * 参数: QP_00,QP_01,QP_02,QP_03,QP_04
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/
int IRQ1_init(unsigned int QP_00, unsigned int QP_01,
              unsigned int QP_02, unsigned int QP_03,
              unsigned int QP_04)
 {
   if(QP_00 > INTS_HIGH || QP_01 > INTS_HIGH || 
      QP_02 > INTS_HIGH || QP_03 > INTS_HIGH ||
      QP_04 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	QP00 = QP_00; QP01 = QP_01;
	QP02 = QP_02; QP03 = QP_03;
	QP04 = QP_04;
   return (INTS_DEPLOY_OK);	   	
 } 

/********************************** 
 * 函数名:IRQ2_init
 * 功能: IRQ2配置初始化 
 * 参数: QSIO_0,QSIO_1,QP_5
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/
int IRQ2_init(unsigned int QSIO_0, unsigned int QSIO_1,
              unsigned int QP_5)
 {
   if(QSIO_0 > INTS_HIGH || QSIO_1 > INTS_HIGH || 
      QP_5 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	QSIO0 = QSIO_0; QSIO1 = QSIO_1;
	QP5 = QP_5; 
   return (INTS_DEPLOY_OK);	 	
 }

/********************************** 
 * 函数名:IRQ3_init
 * 功能: IRQ3配置初始化 
 * 参数: QTM_0,QTM_1
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/ 
int IRQ3_init(unsigned int QTM_0, unsigned int QTM_1)
 {
   if(QTM_0 > INTS_HIGH || QTM_1 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	QTM0 = QTM_0; QTM1 = QTM_1;
   return (INTS_DEPLOY_OK);	  	
 }
 
/********************************** 
 * 函数名:IRQ4_init
 * 功能: IRQ4配置初始化 
 * 参数: QUA_0,QMD_0,QR_AD
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/ 
int IRQ4_init(unsigned int QUA_0, unsigned int QMD_0,
              unsigned int QR_AD)
 {
   if(QUA_0 > INTS_HIGH || QMD_0 > INTS_HIGH || 
      QR_AD > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	QUA0 = QUA_0; QMD0 = QMD_0;
	QRAD = QR_AD; 
   return (INTS_DEPLOY_OK);	   	
 }

/********************************** 
 * 函数名:IRQ5_init
 * 功能: IRQ5配置初始化 
 * 参数: QTM_2,QTM_3
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/  
int IRQ5_init(unsigned int QTM_2, unsigned int QTM_3)
 {
   if(QTM_2 > INTS_HIGH || QTM_3 > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	QTM2 = QTM_2; QTM3 = QTM_3;
   return (INTS_DEPLOY_OK);	 	
 }

/********************************** 
 * 函数名:IRQ6_init
 * 功能: IRQ6配置初始化 
 * 参数: QPW_0,Q_128H,Q_32H
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/  
int IRQ6_init(unsigned int QPW_0,unsigned int Q_128H,
              unsigned int Q_32H)
 {
   if(QPW_0 > INTS_HIGH || Q_128H > INTS_HIGH || 
      Q_32H > INTS_HIGH) {
 	  return (INTS_DEPLOY_FAIL);
        }  
	QPW0 = QPW_0; Q128H = Q_128H;
	Q32H = Q_32H; 
   return (INTS_DEPLOY_OK);   	
 }

/********************************** 
 * 函数名:IRQ7_init
 * 功能: IRQ7配置初始化 
 * 参数: Q_16H,Q_2H
         状态都有： 
              INTS_LOW  (=0) //低电平状态 
              INTS_HIGH (=1) //高电平状态
 * 返回: int 
***********************************/  
int IRQ7_init(unsigned int Q_16H, unsigned int Q_2H)
 {
   if(Q_16H > INTS_HIGH || Q_2H > INTS_HIGH) {
       	 return (INTS_DEPLOY_FAIL);
        }  
	Q16H = Q_16H; Q2H = Q_2H;
   return (INTS_DEPLOY_OK);	 	
 }