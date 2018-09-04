#include<m610409.h>
#include "melody.h"

/********************************** 
 * 函数名:MD0_CON 
 * 功能: MD0_CON配置初始电平 
 * 参数: M0_RUN:
           MELODY_LOW  (0) //检查状态 
           MELODY_HIGH (1) //检查状态    
		 BZ_MD:  
           MELODY_LOW  (0) //低电平状态 
           MELODY_HIGH (1) //高电平状态    
 * 返回: int 
***********************************/
int MD0_CON(unsigned int M0_RUN, unsigned int BZ_MD)
 {
  if((M0_RUN > MELODY_HIGH) || (BZ_MD > MELODY_HIGH)) {
   return (MELODY_DEPLOY_FAIL);	
   }
   M0RUN = M0_RUN;
   BZMD = BZ_MD;
   return (MELODY_DEPLOY_OK);
  }
  
/********************************** 
 * 函数名:MD0_TMP_buzz
 * 功能: MD0_TMP配置初始电平 
 * 参数: MD0_TMP:
          BUZZmode_value 1-4； 
          1.Intermittent sound 1 output (initial value)
          2.Intermittent sound 2 output
          3.Single sound output
          4.Continuous sound output
 * 返回: int 
***********************************/
int MD0_TMP_buzz(unsigned int MD0_TMP)
 {
  if(MD0_TMP >= buzzTMP_mode) {
   return (MELODY_DEPLOY_FAIL);	
   }
   MD0TMP = RCADC_SAMPLING_MODE[MD0_TMP]; 
   return (MELODY_DEPLOY_OK);
  }
  
  
/********************************** 
 * 函数名:MD0_TON_buzz
 * 功能: MD0_TON配置初始电平 
 * 参数: MD0_TON:
          BUZZmode_value 1-8； 
          1.4.096 kHz (initial value)
          2.2.048kHz
          3.1.365kHz
          4.1.024kHz
          5.819Hz
          6.683Hz
          7.585Hz
          8.512Hz
 * 返回: int 
***********************************/
int MD0_TON_buzz(unsigned int MD0_TON)
 {
  if(MD0_TON >= buzzTON_mode) {
   return (MELODY_DEPLOY_FAIL);	
   }
   MD0TON = RCADC_SAMPLING_MODE[MD0_TON]; 
   return (MELODY_DEPLOY_OK);
  }
  
/********************************** 
 * 函数名:MD0_LEN_buzz
 * 功能: MD0_LEN配置初始电平 
 * 参数: MD0_LEN:
          BUZZmode_value 1-16； 
          1.1/16 DUTY (initial value)
          2.1/16DUTY
          3.2/16DUTY
          4.3/16DUTY
          5.4/16DUTY
          6.5/16DUTY
          7.6/16DUTY
          8.7/16DUTY
          9.8/16DUTY
          10.9/16DUTY
          11.10/16DUTY
          12.11/16DUTY
          13.12/16DUTY
          14.13/16DUTY
          15.14/16DUTY
          16.15/16DUTY
 * 返回: int 
***********************************/
int MD0_LEN_buzz(unsigned int MD0_LEN)
 {
  if(MD0_LEN >= buzzLEN_mode) {
   return (MELODY_DEPLOY_FAIL);	
   }
   MD0LEN = RCADC_SAMPLING_MODE[MD0_LEN]; 
   return (MELODY_DEPLOY_OK);
  }
  
  
/********************************** 
 * 函数名:MD0_TMP_melody
 * 功能: MD0_TMP_melody配置初始电平 
 * 参数: MD0_TMP:
          BUZZmode_value 1-16； 
 * 返回: int 
***********************************/
int MD0_TMP_melody(unsigned int MD0_TMP)
 {
  if(MD0_TMP >= melodyTMP_mode) {
   return (MELODY_DEPLOY_FAIL);	
   }
   MD0TMP = RCADC_SAMPLING_MODE[MD0_TMP]; 
   return (MELODY_DEPLOY_OK);
  }
  
/********************************** 
 * 函数名:MD0_TON_melody
 * 功能: MD0_TON_melody配置初始电平 
 * 参数: MD0_TON:
     melodyTON_mode_MIN (0x00)<= MD0_TON <= melodyTON_mode_MAX (0x7B) 
 * 返回: int 
***********************************/
int MD0_TON_melody(unsigned char MD0_TON)
 {
  if((MD0_TON >= (unsigned char)melodyTON_mode_MIN)||
  	 (MD0_TON <= (unsigned char)melodyTON_mode_MAX)) {
   return (MELODY_DEPLOY_FAIL);	
   }
   MD0TON = MD0_TON; 
   return (MELODY_DEPLOY_OK);
  }
  
/********************************** 
 * 函数名:MD0_LEN_melody
 * 功能: MD0_LEN_melody配置初始电平 
 * 参数: MD0_LEN:
      melodyLEN_mode_MIN (0x00)<= MD0_TON <= melodyLEN_mode_MAX (0x3F)  
 * 返回: int 
***********************************/
int MD0_LEN_melody(unsigned char MD0_LEN)
 {
  if((MD0_LEN >= (unsigned char)melodyLEN_mode_MIN)||
  	 (MD0_LEN <= (unsigned char)melodyLEN_mode_MAX)) {
   return (MELODY_DEPLOY_FAIL);	
   }
   MD0LEN = MD0_LEN; 
   return (MELODY_DEPLOY_OK);
  }