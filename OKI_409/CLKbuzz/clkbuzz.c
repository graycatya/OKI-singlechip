#include<m610409.h>
#include "clkbuzz.h"

/***************************************************
 * 功能: 闹钟时间算法函数 
 * 参数: SHI(时接口), FEN(分接口) 
 * 返回: uint 
****************************************************/
uint TIME_ALG(uint SHI, uint FEN)
  {
  	uint sum;
  	 sum = SHI*60+FEN;
    return sum;
  } 
  

/**********************************
 * 功能: 闹钟数值加 
 * 参数: CLK_mar(闹钟时间), ZHI(增加的值) 
 * 返回: uint
**********************************/  
uint BUzz_CLKzhi(uint CLK_mar, uint ZHI)
 {
   uint sum;
    sum=CLK_mar+ZHI;
   return sum;	
 } 

/***************************************************
 * 功能: 闹钟响判断函数 
 * 参数: TI_zhi(时钟数据接口), CLK_zhi(闹钟数据接口) 
          CLK_MO(闹钟模式接口),LCD_mod(LCD界面标志位) 
		   *key_per(闹钟响接口1),*key_nop(闹钟响接口2)
 * 返回: 无
****************************************************/ 
void CLK_time(uint TI_zhi, uint CLK_zhi, uint CLK_MO,
               uint LCD_mod, uint *key_per , uint *key_nop, uint *BU_beg)
 { 
  static int ki=0; //防止第一次误报 
  if(LCD_mod != 0 && CLK_MO != 1) 
   {
           *BU_beg=0; //SET键去除第一次按下无效
   	 if(TI_zhi == CLK_zhi) {ki=1; } //第一次取消误报 
   	  else if(TI_zhi != CLK_zhi) {ki=2; } //开始正确的闹钟运转 
   }
  if(LCD_mod == 0 && CLK_MO != 1) //当在主界面情况下正常计数时开始判断闹钟是否响 
   {
         if(TI_zhi != CLK_zhi) {ki=2; *BU_beg=0; } //第一次取消误报
         if(TI_zhi == CLK_zhi && *BU_beg==0 && ki == 2) {*key_per=1; *key_nop=1; ki = 1;}//正确的闹钟判断闹钟响
        
  }   
 }
 
 
/**********************************
 * 功能: 闹钟按键不完全判断函数 
 * 参数: BUZZ_rin(闹钟响标志位), key_nop(闹钟按键接口)
 * 返回: 无
**********************************/  
void BUzz_keyjudper(uint *key_nop, uint *BUZZ_deg)
  {
  	if(*key_nop == 1) 
     {
   	   *BUZZ_deg=*BUZZ_deg+1; 
            *key_nop=0;	
	   M0RUN=0;
     }   
  } 
  
/**********************************
 * 功能: 闹钟按键完全判断函数 
 * 参数: *CLK_MO(闹钟模式接口), KEY_nop(闹钟按键接口),key_per(蜂鸣器接口)
 * 返回: 无
**********************************/  
void BUzz_keyjudnop(uint *CLK_MO, uint *key_per, uint *KEY_nop, uint *BUZZ_deg, uint *BU_z)
  {
  if(*KEY_nop == 1)M0RUN=0;
  if(*CLK_MO == 2) 
     {
        *key_per=0;
        *KEY_nop=0;
        *BUZZ_deg=0;
        *BU_z=1;	
     }  
  if(*CLK_MO == 3) 
     {
       *key_per=0;
       *KEY_nop=0;
       *CLK_MO=1;
       *BUZZ_deg=0;		
     }   
   } 


 
 

 
