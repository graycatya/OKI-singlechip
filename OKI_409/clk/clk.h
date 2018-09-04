/******************************************************
   clk.h 
   
   ML610Q409��clkʱ�����ú���ģ�飻
   
   History
    2017-9-18 
******************************************************/ 
//#ifndef _CLK_H_
//#define _CLK_H_ 
#include "MacroAndConst.h"
//ģʽö��ͨ�� 
enum CLKmode_value {
 CLK_one=0,CLK_two=1,CLK_three=2,CLK_four=3
};

#define SYSC_MODE (4) //ϵͳʱ�Ӻ���Χ��·����������ʱ���׼��������ѡ�����ʱ��
#define OUT_MODE  (4) // OUTC1��OUTC0λ����ѡ��������ʱ�ӵ�Ƶ�ʡ� 

#define CLK_DEPLOY_OK   (0) //�ɹ� 
#define CLK_DEPLOY_FAIL (-1)//ʧ�� 

//FCON0
#define OSCM_500KMZ  (0) //500 kHz���񵴱�ѡ��
#define OSCM_2MHZ    (1) //2  MHz���񵴱�ѡ��

//FCON1
#define SYSCLK_LSCLK (0) //����ʱ�� 
#define SYSCLK_HSCLK (1) //����ʱ�� 

#define ENO_STOP_HIGHCLK    (0) //���ø���ʱ�� 
#define ENO_ENABLES_HIGHCLK (1) //ʹ�ܸ���ʱ�� 

#define ENM_DISABLES_LOWCLK (0) //����2*����ʱ�� 
#define ENM_ENABLES_LOWCLK  (1) //ʹ��2*����ʱ�� 

/********************************************************************
/*                                 API
********************************************************************/
int clk_fcon0_init(unsigned int sysc, unsigned int outc, unsigned int oscm);
int clk_fcon1_init(unsigned int syscl, unsigned int enos, unsigned int enml);

void WD_Feed(); //ι�� 
int HIGH_career(); //����ʱ������ 
int LOW_career(); //����ʱ������
int HIGH2_career();

  


// #endif /*_CLK_H_*/