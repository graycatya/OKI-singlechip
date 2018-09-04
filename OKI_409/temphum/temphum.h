/******************************************************
 temphum.h 
   
   ML610Q409，温湿度算法函数模块；
   
   History
    2017-10-10
******************************************************/ 
//#ifndef _TEMPHUM_H_
//#define _TEMPHUM_H_  
#include "MacroAndConst.h"

#define TEMP_A 172
#define TEMP_B 172
#define  _HUM_  21
#define  _HUM_TEMP_ 13 

/*************************************
                * API *
*************************************/
int C_FCUTOVER(int zhi, int C_F);
int TEMP_ZH(int TE);
int TE_A(int CAI,int *TE,int *CA, int Ai);
int TE_B(int CAI, int *TE, int *CA, int Bi);
int H_T(int CAI_Y,int SHU, int *TEM, int *CA_Z);
int H_H(int CAI_Y, int TEMP, int SHU, int *HU, int *TE, uint H_CAY[][_HUM_]);
int HUM_A(int CAI, int *H, uint CA[][_HUM_], int Bi);
void HUM_HS(int T_P,uint H_z[][_HUM_], uint NEW_h[1][_HUM_], int bi);
int Temp_trade(uint CA_Y, uint CB_Y);

// #endif /*_TEMPHUM_H_*/