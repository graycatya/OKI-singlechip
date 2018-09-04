/******************************************************
   lcdshow.h 
   
   ML610Q409��lcd��ʾ����ģ�飻
   
   History
    2017-10-9 
******************************************************/ 
//#ifndef _LCDSHOW_H_
//#define _LCDSHOW_H_ 
#include<m610409.h>
#include "MacroAndConst.h"

// ��ʶ����         �Ĵ�����    ���ܣ�                 ״̬λ��   bit7   bit6   bit5   bit4   bit3   bit2   bit1   bit0
#define Clk        DSPR00   //  ʱ��.��ʾ                1/0       ��     ��     ��     ��     ��     ��     ��   CL:1/0
#define Min_Max    DSPR01   //  �����СֵӢ��           1/0       ��     ��     ��     ��     ��     ��   Ma:1/0 Mi:1/0      
#define MonDa_Day  DSPR02   //  ������������ʾ           1/0       ��     ��     ��     ��     ��   Da:1/0 DM:1/0 MD:1/0
#define AiSe       DSPR03   //  ������������������       1/0       ��     ��     ��     ��     ��     ��   Se:1/0 AI:1/0                                                                 
#define Year_Out   DSPR04   //  ����ʾ��                 1/0       ��     ��     ��     ��     ��     ��   OU:1/0 Ye:1/0
                            //  ��Ӵ�������ʾout��                                                               
#define year_time0 DSPR05   //  ����ʱ��������ʾǧ       1/0       ��     ��     ��     ��     ��    1/0    1/0    1/0
#define year_time1 DSPR06   //  ����ʱ��������ʾ��       1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define year_time2 DSPR07   //  ����ʱ��������ʾʮ       1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define year_time3 DSPR08   //  ����ʱ��������ʾ��       1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define carry      DSPR09   //  �¶���ʾ����-����        1/0       ��     ��     ��     ��     ��     ��     ��   -��:1/0
#define Day_0      DSPR0A   //  ���ڼ�����ĸ��ʾA        1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Day_1      DSPR0B   //  ���ڼ�����ĸ��ʾB        1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0 
#define Day_2      DSPR0C   //  ���ڼ��ڶ�����ĸ��ʾA    1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Day_3      DSPR0D   //  ���ڼ��ڶ�����ĸ��ʾB    1/0       ��     ��     ��     ��    1/0     ��     ��    1/0
#define Day_4      DSPR0E   //  ���ڼ���������ĸ��ʾA    1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Day_5      DSPR0F   //  ���ڼ���������ĸ��ʾB    1/0       ��     ��    1/0    1/0    1/0    1/0     ��    1/0
#define Mon_Da0    DSPR10   //  ��_������ʮ��ʾ          1/0       ��    1/0     ��    1/0    1/0    1/0    1/0    1/0
#define Mon_Da1    DSPR11   //  ��_�����ָ���ʾ          1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Mon_Da2    DSPR12   //  ��_������ʮ��ʾ          1/0       ��    1/0     ��    1/0    1/0    1/0    1/0    1/0
#define Mon_Da3    DSPR13   //  ��_�����ָ���ʾ          1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Temp_0     DSPR14   //  �¶�������ʾ��λ         1/0       ��     ��     ��     ��     ��     ��     ��    1/0
#define Temp_1     DSPR15   //  �¶�������ʾʮλ         1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Temp_2     DSPR16   //  �¶�������ʾ��λ         1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Temp_3     DSPR17   //  �¶�������ʾС��λ       1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Hum_0      DSPR18   //  ʪ��������ʾʮλ         1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define Hum_1      DSPR19   //  ʪ��������ʾ��λ         1/0       ��    1/0    1/0    1/0    1/0    1/0    1/0    1/0
#define P_BAT      DSPR1A   //  �¶�.��͵�ѹ��ʾ        1/0       ��     ��     ��     ��     ��     ��   BA:1/0 .��:1/0
#define C_F_H      DSPR1B   //  ����_���ϣ�ʪ�Ȱٷֺ�    1/0       ��     ��     ��     ��     ��   C:1/0  F:1/0  CF%:1/0
#define Buzz       DSPR1C   //  ������ʾ                 1/0       ��     ��     ��     ��     ��     ��     ��    1/0
#define A_PM       DSPR1D   //  12/24��ʾģʽ��          1/0       ��     ��     ��     ��     ��     ��   PM:1/0 AM:1/0 


#define HIGH 1
#define LOW  0
#define SYSTEM 2 
#define TIM    24

#define WEK_mod 7 
#define NObel_mod 3 

struct Ma_Mi {
 int max_temp; //�¶����ֵ 
 int min_temp; //�¶���Сֵ 
 int max_hum;  //ʪ�����ֵ  
 int min_hum;  //ʪ����Сֵ 
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