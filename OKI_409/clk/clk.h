/******************************************************
   clk.h 
   
   ML610Q409，clk时钟配置函数模块；
   
   History
    2017-9-18 
******************************************************/ 
//#ifndef _CLK_H_
//#define _CLK_H_ 
#include "MacroAndConst.h"
//模式枚举通用 
enum CLKmode_value {
 CLK_one=0,CLK_two=1,CLK_three=2,CLK_four=3
};

#define SYSC_MODE (4) //系统时钟和外围电路（包括高速时间基准计数器）选择高速时钟
#define OUT_MODE  (4) // OUTC1和OUTC0位用来选择高速输出时钟的频率。 

#define CLK_DEPLOY_OK   (0) //成功 
#define CLK_DEPLOY_FAIL (-1)//失败 

//FCON0
#define OSCM_500KMZ  (0) //500 kHz的振荡被选中
#define OSCM_2MHZ    (1) //2  MHz的振荡被选中

//FCON1
#define SYSCLK_LSCLK (0) //低速时钟 
#define SYSCLK_HSCLK (1) //高速时钟 

#define ENO_STOP_HIGHCLK    (0) //禁用高速时钟 
#define ENO_ENABLES_HIGHCLK (1) //使能高速时钟 

#define ENM_DISABLES_LOWCLK (0) //禁用2*低速时钟 
#define ENM_ENABLES_LOWCLK  (1) //使能2*低速时钟 

/********************************************************************
/*                                 API
********************************************************************/
int clk_fcon0_init(unsigned int sysc, unsigned int outc, unsigned int oscm);
int clk_fcon1_init(unsigned int syscl, unsigned int enos, unsigned int enml);

void WD_Feed(); //喂狗 
int HIGH_career(); //高速时钟配置 
int LOW_career(); //低速时钟配置
int HIGH2_career();

  


// #endif /*_CLK_H_*/