/******************************************************
   lcdshow.h 
   
   ML610Q409，lcd显示函数模块；
   
   History
    2017-10-9 
******************************************************/ 
//#ifndef _LCDSHOW_H_
//#define _LCDSHOW_H_ 
#include<m610409.h>
#include "MacroAndConst.h"

// 标识符：         寄存器：    功能：                 状态位：   bit7   bit6   bit5   bit4   bit3   bit2   bit1   bit0
#define Clk        DSPR00   //  时钟.显示                1/0       无     无     无     无     无     无     无   CL:1/0
#define Min_Max    DSPR01   //  最大最小值英文           1/0       无     无     无     无     无     无   Ma:1/0 Mi:1/0      
#define MonDa_Day  DSPR02   //  月日与日月显示           1/0       无     无     无     无     无   Da:1/0 DM:1/0 MD:1/0
#define AiSe       DSPR03   //  设置闹钟与万年历，       1/0       无     无     无     无     无     无   Se:1/0 AI:1/0                                                                 
#define Year_Out   DSPR04   //  年显示，                 1/0       无     无     无     无     无     无   OU:1/0 Ye:1/0
                            //  外接传感器显示out。                                                               
#define year_time0 DSPR05   //  年与时钟数字显示千       1/0       无     无     无     无     无    1/0    1/0    1/0
#define year_time1 DSPR06   //  年与时钟数字显示百       1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define year_time2 DSPR07   //  年与时钟数字显示十       1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define year_time3 DSPR08   //  年与时钟数字显示个       1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define carry      DSPR09   //  温度显示负（-）号        1/0       无     无     无     无     无     无     无   -号:1/0
#define Day_0      DSPR0A   //  星期几首字母显示A        1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Day_1      DSPR0B   //  星期几首字母显示B        1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0 
#define Day_2      DSPR0C   //  星期几第二个字母显示A    1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Day_3      DSPR0D   //  星期几第二个字母显示B    1/0       无     无     无     无    1/0     无     无    1/0
#define Day_4      DSPR0E   //  星期几第三个字母显示A    1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Day_5      DSPR0F   //  星期几第三个字母显示B    1/0       无     无    1/0    1/0    1/0    1/0     无    1/0
#define Mon_Da0    DSPR10   //  月_日数字十显示          1/0       无    1/0     无    1/0    1/0    1/0    1/0    1/0
#define Mon_Da1    DSPR11   //  月_日数字个显示          1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Mon_Da2    DSPR12   //  日_月数字十显示          1/0       无    1/0     无    1/0    1/0    1/0    1/0    1/0
#define Mon_Da3    DSPR13   //  日_月数字个显示          1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Temp_0     DSPR14   //  温度数字显示百位         1/0       无     无     无     无     无     无     无    1/0
#define Temp_1     DSPR15   //  温度数字显示十位         1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Temp_2     DSPR16   //  温度数字显示个位         1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Temp_3     DSPR17   //  温度数字显示小数位       1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Hum_0      DSPR18   //  湿度数字显示十位         1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Hum_1      DSPR19   //  湿度数字显示个位         1/0       无    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define P_BAT      DSPR1A   //  温度.与低电压显示        1/0       无     无     无     无     无     无   BA:1/0 .号:1/0
#define C_F_H      DSPR1B   //  摄氏_华氏，湿度百分号    1/0       无     无     无     无     无   C:1/0  F:1/0  CF%:1/0
#define Buzz       DSPR1C   //  闹钟显示                 1/0       无     无     无     无     无     无     无    1/0
#define A_PM       DSPR1D   //  12/24显示模式。          1/0       无     无     无     无     无     无   PM:1/0 AM:1/0 


#define HIGH 1
#define LOW  0
#define SYSTEM 2 
#define TIM    24

#define WEK_mod 7 
#define NObel_mod 3 

struct Ma_Mi {
 int max_temp; //温度最大值 
 int min_temp; //温度最小值 
 int max_hum;  //湿度最大值  
 int min_hum;  //湿度最小值 
};



/*******************************************
               * API *
*******************************************/
void UI_BUZZ(uint P, uint BU_bit);
void UI_P(uint P, uint P_bit);
void UI_YE(uint YETI_VALUE, uint BU_YT, uint P);
void TIM_SHI(uint TIM_VALUE, uint TIM_ZHI, uint P); 
void TIM_FEN(uint MAR_VALUE, uint P);
void UI_TIME(uint TIM_VALUE, uint MAR_VALUE, uint TIM_ZHI, uint BU_YT, uint P);
void UI_YEAR_TIME(uint P, uint DISP_MON, uint CLK_mode, uint Mon, uint dat_AIM);
void UI_MODA(uint MO_BIT);
void UI_AIS_APM(uint AS_bit, uint AP_bit , uint mode_ap); 
void UI_all_CLMON(uint all, uint cl, uint alcl_bit);
void CIK_glint(uint P,uint da_AIM);
void UI_TEMP_HUM(uint P, int TEM_data, int HUM_data,struct Ma_Mi *T_H, uint MAI_MON, uint MAI_K, int c_f); 
void TEM_HUM_realtime(int TE_data, int HU_data);
void MAX_MIN_realtime(uint P, uint MAI_MON);
void  PICK_dataCOR(uint DATA_bit);
void DATA_INT(int TEMP_DATA, int HUM_DATA, struct Ma_Mi *M_m); 
void DATA_compare(int TEMP_DATA, int HUM_DATA, struct Ma_Mi *M_ai);


// #endif /*_LCDSHOW_H_*/