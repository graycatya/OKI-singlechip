#include<m610409.h>
#include "rcadc.h"

/****************************************** 
RCADC_SAMPLING_MODE：为采样方式
0x00：IN0 pin external clock input mode (initial value)
0x01：RS0-CS0 oscillation mode
0x02：RT0–CS0 oscillation mode
0x03：RT0-1–CS0 oscillation mode
0x04：RS0–CT0 oscillation mode
0x05：RS1–CS1 oscillation mode
0x06：RT1–CS1 oscillation mode 
0x07：IN1 pin external clock input mode
0x08：Prohibited 
******************************************/
static const  unsigned char RCADC_SAMPLING_MODE[SAMP_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08
};

/****************************************** 
RCADC_SAMP_CLK_MODE：为采样时钟 
0x00：LSCLK (initial value)
0x01：LSCLK*2
0x02：HSCLK
0x03：1/2HSCLK
0x04：1/4HSCLK
0x05：1/8HSCLK
0x06：Setting prohibited (no clock is supplied) 

******************************************/
static const  unsigned char RCADC_SAMP_CLK_MODE[SAMP_CLK_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06
};


/********************************** 
 * 函数名:rcadc_intit 
 * 功能: RC-ADC配置初始化 
 * 参数: P3INT:
          RCADC_P3INT_ON  (1) //配置P3口 
          RCADC_P3INT_OFF (0) //不配置P3口
         P4INT:
          RCADC_P4INT_ON  (1) //配置P4口 
          RCADC_P4INT_OFF (0) //不配置P4口 
 * 返回: int 
***********************************/
int rcadc_intit(unsigned int P3int, unsigned int P4int)
 {
  //判断输入模式是否正确 
   if(P3int >(unsigned int)RCADC_P3INT_ON || P4int > (unsigned int)RCADC_P4INT_ON) {
   	 return (RCADC_DEPLOY_FAIL);
	  }   
   	//P3口配置初始化
    if(P3int == RCADC_P3INT_ON)   
     P3rcAdc_monitor_on();
    else  P3rcAdc_monitor_off(); 
    //P4口配置初始化
    if(P4int == RCADC_P4INT_ON)   
     P4rcAdc_monitor_on();
    else P4rcAdc_monitor_off();    	
	return (RCADC_DEPLOY_OK);
  }
  
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
  unsigned char r0,r1; 
  //判断输入模式是否正确 
   if(samp >= SAMP_MODE || clk >= SAMP_CLK_MODE) {
   	 return (RCADC_DEPLOY_FAIL);
	  } 
     r0 = RCADC_SAMPLING_MODE[samp]; 
     r1 = RCADC_SAMP_CLK_MODE[clk];  
   RADMOD = ((r0 << 0) | (r1 << 5));
  return (RCADC_DEPLOY_OK);
 }
 
 /********************************** 
 * 函数名:rcadc_RCAD_RCINT_run 
 * 功能: RC计数器选择 
 * 参数: rad:
			RCADC_A(=0) : The value is set to counter A.
			RCADC_B(=1) : The value is set to counter B. 
 * 返回: int 
***********************************/ 
int rcadc_radi(unsigned int rad)
 {
   if(rad > (unsigned int)RCADC_B) {
 	 return (RCADC_DEPLOY_FAIL); 
    }
   RADI = rad;
   return (RCADC_DEPLOY_OK);	 
  }
 
 
 /********************************** 
 * 函数名:rcadc_RCAD_RCINT_run 
 * 功能: RC震荡启动 
 * 参数: run:
	      RCADC_OFF(=0) : RC-ADC conversion stop.(关闭) 
	      RCADC_RUN(=1) : RC-ADC conversion start.(启动)  
 * 返回: int 
***********************************/
int rcadc_RCAD_run(unsigned int run)
 {
 	if(run > (unsigned int)RCADC_RUN){
 	  return (RCADC_DEPLOY_FAIL);
	 } 
    RARUN = run;
    return (RCADC_DEPLOY_OK);
 }
 
/********************************** 
 * 函数名:rcadc_RCAD_RCINT_run 
 * 功能: RC中断启动 
 * 参数: INIT:
	      RCADC_OFF(=0) : RC-ADC conversion stop.(关闭) 
	      RCADCINT_START(=1) : RC-ADC conversion start.(启动)  
 * 返回: int 
***********************************/ 
 int rcadc_RCINT_run(unsigned int INIT)
  {
  	if(INIT > (unsigned int)RCADCINT_START) {
	  return (RCADC_DEPLOY_FAIL);	
	  }
     QRAD = INIT;
     return (RCADC_DEPLOY_OK);
   }
   
  
   
/*******************************************************************************
	Routine Name(函数名):	rcadc_getResult
	Form(函数格式):			int rcAdc_getResult( unsigned char cntNo, unsigned short *result )
	Parameters():		unsigned char cntNo : 
						RCADC_A(=0) : The value is set to counter A.
						RCADC_B(=1) : The value is set to counter B.
					unsigned short *result : Area where conversion result is stored.
	Return value:	int
						RCADC_R_OK(=0) : It succeeded in the acquisition of the conversion result.
						RCADC_DEPLOY_FAIL(=-1) : Parameter cntNo is outside the range.
	Description:	The conversion result is acquired.
******************************************************************************/
int rcadc_getResult(unsigned int cntNo, unsigned int *result)
 {
   	unsigned char r0,r1; //用来接收采样的值：409为8位处理器
	if(cntNo > (unsigned int)RCADC_B) {
	 return (RCADC_DEPLOY_FAIL); //返回-1
	 }
	 /*=== register check. ===*/ //参数 检查 
	 if(cntNo == (unsigned int)RCADC_A) {
 	   r0 = RADCB0;
	   r1 = RADCB1;	
 	   }
	 else {
 	   r0 = RADCA0;
	   r1 = RADCA1;	
 	   } 
     /*=== set value. ===*/
     *result = (unsigned int)((((unsigned char)r0) << 0) |
                              (((unsigned char)r1) << 8) );
     RADCB0=0;
     RADCB1=0;
     RADCA0=0;
     RADCA1=0;
     return (RCADC_DEPLOY_OK);
 }
  
   

/********************************** 
 * 函数名:P3rcAdc_monitor_on 
 * 功能: P3初始化 
 * 参数: void 
 * 返回: void
***********************************/
void P3rcAdc_monitor_on( void )
{
	P3DIR = 0x1F;		 
	P3CON0 = 0x20;
	P3CON1 = 0x20;		 
	P3MOD0 = 0x3F;     
}

/********************************** 
 * 函数名:P3rcAdc_monitor_off
 * 功能: P3初始化 
 * 参数: void 
 * 返回: void
***********************************/
void P3rcAdc_monitor_off( void )
{
	P3DIR = 0;		
	P3CON0 = 0;
	P3CON1 = 0;		
	P3MOD0 = 0;    
}

/********************************** 
 * 函数名:P4rcAdc_monitor_on 
 * 功能: P4初始化 
 * 参数: void 
 * 返回: void
***********************************/
void P4rcAdc_monitor_on( void )
{
	P4DIR = 0xF0;		
	P4CON0 = 0;
	P4CON1 = 0;		
	P4MOD0 = 0xF0; 
	P4MOD1 = 0;      
}

/********************************** 
 * 函数名:P4rcAdc_monitor_off 
 * 功能: P4初始化 
 * 参数: void 
 * 返回: void
***********************************/
void P4rcAdc_monitor_off( void )
{
	P4DIR = 0;		
	P4CON0 = 0;
	P4CON1 = 0;		
	P4MOD0 = 0; 
	P4MOD1 = 0;     
}