/******************************************************
 rcadc.h 
   
   ML610Q409，RC-ADC函数模块；
   
   History
    2017-9-14
******************************************************/ 
//#ifndef _RCADC_H_
//#define _RCADC_H_    
#include "MacroAndConst.h"

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/
#define SAMP_MODE (10) //采样模式有9种模式 
#define SAMP_CLK_MODE (8) //采样时钟有8种模式 
/*=== 配置后的返回的状态 ===*/
#define RCADC_DEPLOY_OK   (0) //成功 
#define RCADC_DEPLOY_FAIL (-1)//失败  

#define RCADC_START (1) //开始 
#define RCADC_STOP  (0) //停止 

#define RCADC_A		(0) //A计数器 
#define RCADC_B     (1) //B计数器    

/* run */
#define RCADC_OFF	( 0x00u )
#define RCADC_RUN	( 0x01u )
#define RCADCINT_START (1) //启用 
#define RCADCINT_STOP  (0) //停止 
#define RCADC_P3INT_ON  (1) //配置P3口 
#define RCADC_P3INT_OFF (0) //不配置P3口 
#define RCADC_P4INT_ON  (1) //配置P4口 
#define RCADC_P4INT_OFF (0) //不配置P4口  

//模式枚举通用 
enum RCmode_value {
 rcad_one=0,rcad_two=1,rcad_three=2,rcad_four=3,
 rcad_five=4,rcad_six=5,rcad_seven=6,rcad_eight=7,
 rcad_nine=8 
}; 
    



 
void P3rcAdc_monitor_on(void);
void P3rcAdc_monitor_off(void);
void P4rcAdc_monitor_on(void);
void P4rcAdc_monitor_off(void);
 
int rcadc_intit(int P3int, int P4int); 
int rcadc_Samp_Clk_init(unsigned int samp, unsigned int clk);
int rcadc_radi(unsigned int rad);
int rcadc_RCAD_run(unsigned char run);
int rcadc_RCINT_run(unsigned char INIT); 
int rcadc_getResult(unsigned char cntNo, unsigned int *result);


// #endif /*_RCADC_H_*/
