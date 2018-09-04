#include<m610409.h>
#include "rcadc.h"

/****************************************** 
RCADC_SAMPLING_MODE��Ϊ������ʽ
0x00��IN0 pin external clock input mode (initial value)
0x01��RS0-CS0 oscillation mode
0x02��RT0�CCS0 oscillation mode
0x03��RT0-1�CCS0 oscillation mode
0x04��RS0�CCT0 oscillation mode
0x05��RS1�CCS1 oscillation mode
0x06��RT1�CCS1 oscillation mode 
0x07��IN1 pin external clock input mode
0x08��Prohibited 
******************************************/
static const  unsigned char RCADC_SAMPLING_MODE[SAMP_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08
};

/****************************************** 
RCADC_SAMP_CLK_MODE��Ϊ����ʱ�� 
0x00��LSCLK (initial value)
0x01��LSCLK*2
0x02��HSCLK
0x03��1/2HSCLK
0x04��1/4HSCLK
0x05��1/8HSCLK
0x06��Setting prohibited (no clock is supplied) 

******************************************/
static const  unsigned char RCADC_SAMP_CLK_MODE[SAMP_CLK_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06
};


/********************************** 
 * ������:rcadc_intit 
 * ����: RC-ADC���ó�ʼ�� 
 * ����: P3INT:
          RCADC_P3INT_ON  (1) //����P3�� 
          RCADC_P3INT_OFF (0) //������P3��
         P4INT:
          RCADC_P4INT_ON  (1) //����P4�� 
          RCADC_P4INT_OFF (0) //������P4�� 
 * ����: int 
***********************************/
int rcadc_intit(unsigned int P3int, unsigned int P4int)
 {
  //�ж�����ģʽ�Ƿ���ȷ 
   if(P3int >(unsigned int)RCADC_P3INT_ON || P4int > (unsigned int)RCADC_P4INT_ON) {
   	 return (RCADC_DEPLOY_FAIL);
	  }   
   	//P3�����ó�ʼ��
    if(P3int == RCADC_P3INT_ON)   
     P3rcAdc_monitor_on();
    else  P3rcAdc_monitor_off(); 
    //P4�����ó�ʼ��
    if(P4int == RCADC_P4INT_ON)   
     P4rcAdc_monitor_on();
    else P4rcAdc_monitor_off();    	
	return (RCADC_DEPLOY_OK);
  }
  
/********************************** 
 * ������:rcadc_Samp_Clk_init 
 * ����: RC��/ʱ������ 
 * ����: samp:
           RCmode_value (1-9ģʽ)//����ö���еı�ʶ�� 
         clk:
           RCmode_value (1-7ģʽ)//����ö���еı�ʶ�� 
 * ����: int 
***********************************/
int rcadc_Samp_Clk_init(unsigned int samp, unsigned int clk)
 {
  unsigned char r0,r1; 
  //�ж�����ģʽ�Ƿ���ȷ 
   if(samp >= SAMP_MODE || clk >= SAMP_CLK_MODE) {
   	 return (RCADC_DEPLOY_FAIL);
	  } 
     r0 = RCADC_SAMPLING_MODE[samp]; 
     r1 = RCADC_SAMP_CLK_MODE[clk];  
   RADMOD = ((r0 << 0) | (r1 << 5));
  return (RCADC_DEPLOY_OK);
 }
 
 /********************************** 
 * ������:rcadc_RCAD_RCINT_run 
 * ����: RC������ѡ�� 
 * ����: rad:
			RCADC_A(=0) : The value is set to counter A.
			RCADC_B(=1) : The value is set to counter B. 
 * ����: int 
***********************************/ 
int rcadc_radi(unsigned int rad)
 {
   if(rad > (unsigned int)RCADC_B) {
 	 return (RCADC_DEPLOY_FAIL); 
    }
   RADI = rad;
   return (RCADC_DEPLOY_OK);	 
  }
 
 
 /********************************** 
 * ������:rcadc_RCAD_RCINT_run 
 * ����: RC������ 
 * ����: run:
	      RCADC_OFF(=0) : RC-ADC conversion stop.(�ر�) 
	      RCADC_RUN(=1) : RC-ADC conversion start.(����)  
 * ����: int 
***********************************/
int rcadc_RCAD_run(unsigned int run)
 {
 	if(run > (unsigned int)RCADC_RUN){
 	  return (RCADC_DEPLOY_FAIL);
	 } 
    RARUN = run;
    return (RCADC_DEPLOY_OK);
 }
 
/********************************** 
 * ������:rcadc_RCAD_RCINT_run 
 * ����: RC�ж����� 
 * ����: INIT:
	      RCADC_OFF(=0) : RC-ADC conversion stop.(�ر�) 
	      RCADCINT_START(=1) : RC-ADC conversion start.(����)  
 * ����: int 
***********************************/ 
 int rcadc_RCINT_run(unsigned int INIT)
  {
  	if(INIT > (unsigned int)RCADCINT_START) {
	  return (RCADC_DEPLOY_FAIL);	
	  }
     QRAD = INIT;
     return (RCADC_DEPLOY_OK);
   }
   
  
   
/*******************************************************************************
	Routine Name(������):	rcadc_getResult
	Form(������ʽ):			int rcAdc_getResult( unsigned char cntNo, unsigned short *result )
	Parameters():		unsigned char cntNo : 
						RCADC_A(=0) : The value is set to counter A.
						RCADC_B(=1) : The value is set to counter B.
					unsigned short *result : Area where conversion result is stored.
	Return value:	int
						RCADC_R_OK(=0) : It succeeded in the acquisition of the conversion result.
						RCADC_DEPLOY_FAIL(=-1) : Parameter cntNo is outside the range.
	Description:	The conversion result is acquired.
******************************************************************************/
int rcadc_getResult(unsigned int cntNo, unsigned int *result)
 {
   	unsigned char r0,r1; //�������ղ�����ֵ��409Ϊ8λ������
	if(cntNo > (unsigned int)RCADC_B) {
	 return (RCADC_DEPLOY_FAIL); //����-1
	 }
	 /*=== register check. ===*/ //���� ��� 
	 if(cntNo == (unsigned int)RCADC_A) {
 	   r0 = RADCB0;
	   r1 = RADCB1;	
 	   }
	 else {
 	   r0 = RADCA0;
	   r1 = RADCA1;	
 	   } 
     /*=== set value. ===*/
     *result = (unsigned int)((((unsigned char)r0) << 0) |
                              (((unsigned char)r1) << 8) );
     RADCB0=0;
     RADCB1=0;
     RADCA0=0;
     RADCA1=0;
     return (RCADC_DEPLOY_OK);
 }
  
   

/********************************** 
 * ������:P3rcAdc_monitor_on 
 * ����: P3��ʼ�� 
 * ����: void 
 * ����: void
***********************************/
void P3rcAdc_monitor_on( void )
{
	P3DIR = 0x1F;		 
	P3CON0 = 0x20;
	P3CON1 = 0x20;		 
	P3MOD0 = 0x3F;     
}

/********************************** 
 * ������:P3rcAdc_monitor_off
 * ����: P3��ʼ�� 
 * ����: void 
 * ����: void
***********************************/
void P3rcAdc_monitor_off( void )
{
	P3DIR = 0;		
	P3CON0 = 0;
	P3CON1 = 0;		
	P3MOD0 = 0;    
}

/********************************** 
 * ������:P4rcAdc_monitor_on 
 * ����: P4��ʼ�� 
 * ����: void 
 * ����: void
***********************************/
void P4rcAdc_monitor_on( void )
{
	P4DIR = 0xF0;		
	P4CON0 = 0;
	P4CON1 = 0;		
	P4MOD0 = 0xF0; 
	P4MOD1 = 0;      
}

/********************************** 
 * ������:P4rcAdc_monitor_off 
 * ����: P4��ʼ�� 
 * ����: void 
 * ����: void
***********************************/
void P4rcAdc_monitor_off( void )
{
	P4DIR = 0;		
	P4CON0 = 0;
	P4CON1 = 0;		
	P4MOD0 = 0; 
	P4MOD1 = 0;     
}