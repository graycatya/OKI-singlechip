/******************************************************
 rcadc.h 
   
   ML610Q409��RC-ADC����ģ�飻
   
   History
    2017-9-14
******************************************************/ 
//#ifndef _RCADC_H_
//#define _RCADC_H_    
#include "MacroAndConst.h"

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/
#define SAMP_MODE (10) //����ģʽ��9��ģʽ 
#define SAMP_CLK_MODE (8) //����ʱ����8��ģʽ 
/*=== ���ú�ķ��ص�״̬ ===*/
#define RCADC_DEPLOY_OK   (0) //�ɹ� 
#define RCADC_DEPLOY_FAIL (-1)//ʧ��  

#define RCADC_START (1) //��ʼ 
#define RCADC_STOP  (0) //ֹͣ 

#define RCADC_A		(0) //A������ 
#define RCADC_B     (1) //B������    

/* run */
#define RCADC_OFF	( 0x00u )
#define RCADC_RUN	( 0x01u )
#define RCADCINT_START (1) //���� 
#define RCADCINT_STOP  (0) //ֹͣ 
#define RCADC_P3INT_ON  (1) //����P3�� 
#define RCADC_P3INT_OFF (0) //������P3�� 
#define RCADC_P4INT_ON  (1) //����P4�� 
#define RCADC_P4INT_OFF (0) //������P4��  

//ģʽö��ͨ�� 
enum RCmode_value {
 rcad_one=0,rcad_two=1,rcad_three=2,rcad_four=3,
 rcad_five=4,rcad_six=5,rcad_seven=6,rcad_eight=7,
 rcad_nine=8 
}; 
    



 
void P3rcAdc_monitor_on(void);
void P3rcAdc_monitor_off(void);
void P4rcAdc_monitor_on(void);
void P4rcAdc_monitor_off(void);
 
int rcadc_intit(int P3int, int P4int); 
int rcadc_Samp_Clk_init(unsigned int samp, unsigned int clk);
int rcadc_radi(unsigned int rad);
int rcadc_RCAD_run(unsigned char run);
int rcadc_RCINT_run(unsigned char INIT); 
int rcadc_getResult(unsigned char cntNo, unsigned int *result);


// #endif /*_RCADC_H_*/
