/******************************************************
   time.h 
   
   ML610Q409����ʱ�����ú���ģ�飻
   
   History
    2017-9-21 
******************************************************/ 
//#ifndef _TIME_H_
//#define _TIME_H_ 
#include "MacroAndConst.h"

#define TIME_CLKMD 4  //4��ʱ��ģʽ 

#define TIME_DEPLOY_OK   (0) //�ɹ� 
#define TIME_DEPLOY_FAIL (-1)//ʧ�� 

#define TIME_LOW  (0) //�͵�ƽ״̬ 
#define TIME_HIGH (1) //�ߵ�ƽ״̬ 

#define TIME_MIN  (0x00) //��ʱ��ֵ��С 
#define TIME_MAX  (0xFF) //��ʱ��ֵ��� 

#define T2_FMA    (0x0A) //T2FAMAĬ������ 

//ģʽö��ͨ�� 
enum TIMmode_value {
 time_one=0,time_two=1,time_three=2,time_four=3
}; 

/*************************************
/*               API
*************************************/
/* ��ʱ/������ֵ���� */
int TM0D_init(unsigned char TM_0D);
int TM0C_init(unsigned char TM_0C);
int TM1D_init(unsigned char TM_1D);
int TM1C_init(unsigned char TM_1C);
int TM2D_init(unsigned char TM_2D);
int TM2C_init(unsigned char TM_2C);
int TM3D_init(unsigned char TM_0D);
int TM3C_init(unsigned char TM_0C);

/* ��ʱ�������� */
int TM0CON0_init(unsigned int T0_CS, unsigned int T0M16);
int TM1CON0_init(unsigned int T1_CS);
int TM2CON0_init(unsigned int T2_CS, unsigned int T2_M, 
                 unsigned char T2FM_A);
int TM3CON0_init(unsigned int T3_CS);

int TM0CON1_init(unsigned int T0_RUN, unsigned int T0_STAT);
int TM1CON1_init(unsigned int T1_RUN, unsigned int T1_STAT);
int TM2CON1_init(unsigned int T2_RUN, unsigned int T2_STAT);
int TM3CON1_init(unsigned int T3_RUN, unsigned int T3_STAT);


// #endif /*_TIME_H_*/