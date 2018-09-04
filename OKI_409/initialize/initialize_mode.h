/******************************************************
   initialize_mode.h 
   
   ML610Q409，initialize_mode配置函数模块；
   
   History
    2017-10-12 
******************************************************/ 
//#ifndef _INITIALIZE_MODE_H_
//#define _INITIALIZE_MODE_H_ 
#include<m610409.h>
#include "clk.h"
#include "ints.h"
#include "port.h"
#include "rcadc.h"
#include "key.h"
#include "lcdshow.h"
#include "temphum.h"
#include "time.h"
#include "MacroAndConst.h"


#define KEY_BUZZ_mode0 (1) //按键响 
#define CLK_BUZZ_mode1 (2) //时钟响 滴 
#define CLK_BUZZ_mode2 (3) //时钟响 滴滴 
#define ON_BUZZ_mode3  (4) //开机响 滴滴滴 
#define CLK_BUZZ_mode4 (5) //时钟响 滴滴滴滴 



/******************************
        * API *
******************************/
void WD_Feed(); //喂狗 
int HIGH_career(); //高速时钟配置 
int LOCK_career(); //低速时钟配置
int LOCK1_career();
/* 蜂鸣器配置，与运行函数 */
void Init_Times2(void);
void Init_Times0(void);
void MelodyInit(); 
void key_buzz();
void ON_clk_buzz();
void BUZZ_mode(int x, int *y);
void BUZZ_int(int x);
/*************************/

void KEY_scan(uchar *TR, uchar *Co, uchar *co, uchar *sum); //按键扫描 

void P0_INIT(); 
void P5_INIT();
// #endif /*_INITIALIZE_MODE_*/