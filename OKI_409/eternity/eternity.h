/******************************************************
  eternity.h 
   
   ML610Q409，万年历时钟函数模块；
   
   History
    2017-10-13 
******************************************************/ 
//#ifndef _ETERNITY_H_
//#define _ETERNITY_H_ 
#include "MacroAndConst.h"


/*************************
       * API *
*************************/
int year(int ye);
int date(int mon, int day, long int ye, int kv, int da[][12]);
int calendar_treat(int *yea, int *moon, int *dayet, int mode);
void time_CLK(int *day, int *shi, int *fen, int *miao);
void var_mode(int *variate, int often_MAX, int often_MIN);
long int year_judge(int yea , int *ye_z);

// #endif /*_ETERNITY_H_*/