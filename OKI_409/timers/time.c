#include<m610409.h>
#include "time.h"

/******************
 0x00: LSCLK (initial value)/8-bit timer mode (initial value)
 0x01: HTBCLK / 16-bit timer mode
 0x02: External clock /(P04/T02P0CK) / Prohibited
 0x03: External clock /(P44/T02P0CK)/(P45/T13CK) / 16-bit timer frequency measurement mode
******************/
unsigned char TIME_CLK_MODE[TIME_CLKMD]={
 0x00,
 0x01,
 0x02,
 0x03}; 

/********************************** 
 * 函数名:TM0D_init 
 * 功能: TM0D配置初始电平 
 * 参数: TM_0D: 
           TIME_MIN (=0x00)<=TM_0D<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM0D_init(unsigned char TM_0D)
 {
 	if((TM_0D < (unsigned char)TIME_MIN) || 
       (TM_0D > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM0D = TM_0D;
      return (TIME_DEPLOY_OK);
       }
 }
 
/********************************** 
 * 函数名:TM1D_init 
 * 功能: TM1D配置初始电平 
 * 参数: TM_1D: 
          TIME_MIN (=0x00)<=TM_1D<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM1D_init(unsigned char TM_1D)
 {
 	if((TM_1D < (unsigned char)TIME_MIN) || 
       (TM_1D > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM1D = TM_1D;
      return (TIME_DEPLOY_OK);
       }
 }
 
/********************************** 
 * 函数名:TM2D_init 
 * 功能: TM2D配置初始电平 
 * 参数: TM_2D: 
          TIME_MIN (=0x00)<=TM_2D<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM2D_init(unsigned char TM_2D)
 {
 	if((TM_2D < (unsigned char)TIME_MIN) || 
       (TM_2D > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM2D = TM_2D;
      return (TIME_DEPLOY_OK);
       }
 }
 
/********************************** 
 * 函数名:TM3D_init 
 * 功能: TM3D配置初始电平 
 * 参数: TM_3D: 
          TIME_MIN (=0x00)<=TM_3D<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM3D_init(unsigned char TM_3D)
 {
 	if((TM_3D < (unsigned char)TIME_MIN) || 
       (TM_3D > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM3D = TM_3D;
      return (TIME_DEPLOY_OK);
       }
 }
 
 
/********************************** 
 * 函数名:TM0C_init 
 * 功能: TM0C配置初始电平 
 * 参数: TM_0C: 
           TIME_MIN (=0x00)<=TM_0C<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM0C_init(unsigned char TM_0C)
 {
 	if((TM_0C < (unsigned char)TIME_MIN) || 
       (TM_0C > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM0C = TM_0C;
      return (TIME_DEPLOY_OK);
       }
 }
 
/********************************** 
 * 函数名:TM1C_init 
 * 功能: TM1C配置初始电平 
 * 参数: TM_1C: 
          TIME_MIN (=0x00)<=TM_1C<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM1C_init(unsigned char TM_1C)
 {
 	if((TM_1C < (unsigned char)TIME_MIN) || 
       (TM_1C > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM1C = TM_1C;
      return (TIME_DEPLOY_OK);
       }
 }
 
/********************************** 
 * 函数名:TM2C_init 
 * 功能: TM2C配置初始电平 
 * 参数: TM_2C: 
          TIME_MIN (=0x00)<=TM_2C<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM2C_init(unsigned char TM_2C)
 {
 	if((TM_2C < (unsigned char)TIME_MIN) || 
       (TM_2C > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM2C = TM_2C;
      return (TIME_DEPLOY_OK);
       }
 }
 
/********************************** 
 * 函数名:TM3C_init 
 * 功能: TM3C配置初始电平 
 * 参数: TM_3C: 
          TIME_MIN (=0x00)<=TM_3C<=TIME_MAX (=0xFF)
 * 返回: int 
***********************************/
int TM3C_init(unsigned char TM_3C)
 {
 	if((TM_3C < (unsigned char)TIME_MIN) || 
       (TM_3C > (unsigned char)TIME_MAX)) {
      return (TIME_DEPLOY_FAIL);
      TM3C = TM_3C;
      return (TIME_DEPLOY_OK);
       }
 }
 
 
 
/********************************** 
 * 函数名:TM0CON0_init 
 * 功能: TM0CON0配置初始电平 
 * 参数: T0_CS: 
         time_one: LSCLK (initial value)
		 time_two: HTBCLK
		 time_three: External clock (P04/T02P0CK)
		 time_four：External clock (P44/T02P0CK)
		 T0M16:
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态 
 * 返回: int 
***********************************/
int TM0CON0_init(unsigned int T0_CS, unsigned int T0M16)
 {
   if(T0_CS > time_four || T0M16 > TIME_HIGH ){
   	return (TIME_DEPLOY_FAIL);
    }
   	TM0CON0 = TIME_CLK_MODE[T0_CS];
   	T01M16 = T0M16;
   return (TIME_DEPLOY_OK);
  }
  
  
/********************************** 
 * 函数名:TM1CON0_init 
 * 功能: TM1CON0配置初始电平 
 * 参数: T1_CS: 
         time_one: LSCLK (initial value)
		 time_two: HTBCLK
		 time_three: Prohibited
		 time_four：External clock (P45/T13CK)
		 T0M16:
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态 
 * 返回: int 
***********************************/
int TM1CON0_init(unsigned int T1_CS)
 {
   if(T1_CS > time_four){
   	return (TIME_DEPLOY_FAIL);
    }
   	TM1CON0 = TIME_CLK_MODE[T1_CS];
   return (TIME_DEPLOY_OK);
  }
  
  
/********************************** 
 * 函数名:TM2CON0_init
 * 功能: TM2CON0配置初始电平 
 * 参数: T2_CS: 
          time_one: LSCLK (initial value)
		  time_two: HTBCLK
		  time_three: External clock (P04/T02P0CK)
		  time_four：External clock (P44/T02P0CK)
		 T2_M:
          time_one: 8-bit timer mode (initial value)
		  time_two: 16-bit timer mode
		  time_three: Prohibited
		  time_four：16-bit timer frequency measurement mode
         T2FM_A:
          T2_FMA;
 * 返回: int 
***********************************/
int TM2CON0_init(unsigned int T2_CS, unsigned int T2_M, 
                 unsigned char T2FM_A)
 {
  unsigned char r0,r1,r2;
   if((T2_CS > time_four) || (T2_M > time_four) ||
   	  (T2FM_A != (unsigned char)T2_FMA)){
   	return (TIME_DEPLOY_FAIL);
    }
   r0 = TIME_CLK_MODE[T2_CS];
   r1 = TIME_CLK_MODE[T2_M];
   r2 = (unsigned char)T2_FMA;
   TM2CON0 = ((r0 << 0) | (r1 << 2) | (r2 << 4));
   return (TIME_DEPLOY_OK);
  }
  
/********************************** 
 * 函数名:TM3CON0_init
 * 功能: TM3CON0配置初始电平 
 * 参数: T3_CS: 
          time_one: LSCLK (initial value)
		  time_two: HTBCLK
		  time_three: Prohibited
		  time_four：External clock (P45/T13CK)
 * 返回: int 
***********************************/
int TM3CON0_init(unsigned int T3_CS)
 {

   if(T3_CS > time_four){
   	return (TIME_DEPLOY_FAIL);
    }
   TM3CON0 = TIME_CLK_MODE[T3_CS];
   return (TIME_DEPLOY_OK);
  }
  
  
  
/********************************** 
 * 函数名:TM0CON1_init
 * 功能: TM0CON1配置初始电平 
 * 参数: T0_RUN: 
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态           
         T0_STAT:
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态          
 * 返回: int 
***********************************/
int TM0CON1_init(unsigned int T0_RUN, unsigned int T0_STAT)
 {
 	if((T0_RUN > TIME_HIGH) || (T0_STAT > TIME_HIGH)) {
      return (TIME_DEPLOY_FAIL);
 	}
      T0RUN = T0_RUN;
      T0STAT = T0_STAT;
      return (TIME_DEPLOY_OK);
 }
 

/********************************** 
 * 函数名:TM1CON1_init
 * 功能: TM1CON1配置初始电平 
 * 参数: T1_RUN: 
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态           
         T1_STAT:
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态          
 * 返回: int 
***********************************/
int TM1CON1_init(unsigned int T1_RUN, unsigned int T1_STAT)
 {
 	if((T1_RUN > TIME_HIGH) || (T1_STAT > TIME_HIGH)) {
      return (TIME_DEPLOY_FAIL);
 	}
      T1RUN = T1_RUN;
      T1STAT = T1_STAT;
      return (TIME_DEPLOY_OK);
 }


/********************************** 
 * 函数名:TM2CON1_init
 * 功能: TM2CON1配置初始电平 
 * 参数: T2_RUN: 
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态           
         T2_STAT:
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态          
 * 返回: int 
***********************************/
int TM2CON1_init(unsigned int T2_RUN, unsigned int T2_STAT)
 {
 	if((T2_RUN > TIME_HIGH) || (T2_STAT > TIME_HIGH)) {
      return (TIME_DEPLOY_FAIL);
 	}
      T2RUN = T2_RUN;
      T2STAT = T2_STAT;
      return (TIME_DEPLOY_OK);
 }
 
/********************************** 
 * 函数名:TM3CON1_init
 * 功能: TM3CON1配置初始电平 
 * 参数: T3_RUN: 
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态           
         T3_STAT:
           TIME_LOW  (=0) //低电平状态 
           TIME_HIGH (=1) //高电平状态          
 * 返回: int 
***********************************/
int TM3CON1_init(unsigned int T3_RUN, unsigned int T3_STAT)
 {
 	if((T3_RUN > TIME_HIGH) || (T3_STAT > TIME_HIGH)) {
      return (TIME_DEPLOY_FAIL);
 	}
      T3RUN = T3_RUN;
      T3STAT = T3_STAT;
      return (TIME_DEPLOY_OK);
 }