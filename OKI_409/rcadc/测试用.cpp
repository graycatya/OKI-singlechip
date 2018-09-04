#include<stdio.h>

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/
#define SAMP_MODE (9) //采样模式有9种模式 
#define SAMP_CLK_MODE (7) //采样时钟有8种模式 
/*=== 配置后的返回的状态 ===*/
#define RCADC_DEPLOY_OK   (0) //成功 
#define RCADC_DEPLOY_FAIL (-1)//失败  

#define RCADC_START (1) //开始 
#define RCADC_STOP  (0) //停止 

#define RCADC_A		(0) //A计数器 
#define RCADC_B     (1) //B计数器    

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
    
/****************************************** 
RCADC_SAMPLING_MODE：为采样方式
0x00：IN0 pin external clock input mode1 (initial value) 
0x01：RS0-CS0 oscillation mode2
0x02：RT0–CS0 oscillation mode3
0x03：RT0-1–CS0 oscillation mode4
0x04：RS0–CT0 oscillation mode5
0x05：RS1–CS1 oscillation mode6
0x06：RT1–CS1 oscillation mode7 
0x07：IN1 pin external clock input mode8
0x08：Prohibited 
******************************************/
unsigned char RCADC_SAMPLING_MODE[SAMP_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08
};

/****************************************** 
RCADC_SAMP_CLK_MODE：为采样时钟 
0x00：LSCLK (initial value)
0x01：LSCLK×2             
0x02：HSCLK
0x03：1/2HSCLK
0x04：1/4HSCLK
0x05：1/8HSCLK
0x06：Setting prohibited (no clock is supplied) 

******************************************/
unsigned char RCADC_SAMP_CLK_MODE[SAMP_CLK_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06
};

/********************************** 
 * 函数名:rcadc_Samp_Clk_init 
 * 功能: RC震荡/时钟设置 
 * 参数: samp:
           RCmode_value (1-9模式)//输入枚举中的标识符 
         clk:
           RCmode_value (1-7模式)//输入枚举中的标识符 
 * 返回: int 
***********************************/
int rcadc_Samp_Clk_init(unsigned int samp, unsigned int clk)
 {
  unsigned char r0,r1,RADMOD; 
  //判断输入模式是否正确 
   if(samp > SAMP_MODE || clk > SAMP_CLK_MODE) {
   	 return (RCADC_DEPLOY_FAIL);
	  } 
     r0 = RCADC_SAMPLING_MODE[samp]; 
     r1 = RCADC_SAMP_CLK_MODE[clk];  
   RADMOD = ((r0 << 0) | (r1 << 5));
   printf("RADMOD=%d\n", RADMOD); 
  return (RCADC_DEPLOY_OK);
 }
 
 int main()
  {
  	int ZHI;
	  ZHI=rcadc_Samp_Clk_init(rcad_seven, rcad_six); 
	 printf("ZHI=%d\n",ZHI);
	 getchar(); 
  } 