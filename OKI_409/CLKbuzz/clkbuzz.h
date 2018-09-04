/******************************************************
   clkbuzz.h 
   
   ML610Q409，clk闹钟函数模块；
   
   History
    2017-10-26 
******************************************************/ 
//#ifndef _CLKBUZZ_H_
//#define _CLKBUZZ_H_ 
#include<m610409.h>
#include "MacroAndConst.h"

#define CLK_BUZZ_RING   (0) //成功 
#define CLK_BUZZ_FAIL (-1)//失败 


/* API */
uint TIME_ALG(uint SHI, uint FEN);
uint BUzz_CLKzhi(uint CLK_mar, uint ZHI);
void CLK_time(uint TI_zhi, uint CLK_zhi, uint CLK_MO,
               uint LCD_mod, uint *key_per , uint *key_nop, uint *BU_beg);
void BUzz_keyjudper(uint *key_nop, uint *BUZZ_deg);
void BUzz_keyjudnop(uint *CLK_MO, uint *key_per, uint *KEY_nop, uint *BUZZ_deg, uint *BU_z);
//void BUzz_CLKMOD(uint BUZZ_m,uint *buzz_MOD, uint P_d);

// #endif /*_CLKBUZZ_H_*/