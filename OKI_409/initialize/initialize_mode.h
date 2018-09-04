/******************************************************
   initialize_mode.h 
   
   ML610Q409��initialize_mode���ú���ģ�飻
   
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


#define KEY_BUZZ_mode0 (1) //������ 
#define CLK_BUZZ_mode1 (2) //ʱ���� �� 
#define CLK_BUZZ_mode2 (3) //ʱ���� �ε� 
#define ON_BUZZ_mode3  (4) //������ �εε� 
#define CLK_BUZZ_mode4 (5) //ʱ���� �εεε� 



/******************************
        * API *
******************************/
void WD_Feed(); //ι�� 
int HIGH_career(); //����ʱ������ 
int LOCK_career(); //����ʱ������
int LOCK1_career();
/* ���������ã������к��� */
void Init_Times2(void);
void Init_Times0(void);
void MelodyInit(); 
void key_buzz();
void ON_clk_buzz();
void BUZZ_mode(int x, int *y);
void BUZZ_int(int x);
/*************************/

void KEY_scan(uchar *TR, uchar *Co, uchar *co, uchar *sum); //����ɨ�� 

void P0_INIT(); 
void P5_INIT();
// #endif /*_INITIALIZE_MODE_*/