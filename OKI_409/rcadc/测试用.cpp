#include<stdio.h>

/*############################################################################*/
/*#                                  Macro                                   #*/
/*############################################################################*/
#define SAMP_MODE (9) //����ģʽ��9��ģʽ 
#define SAMP_CLK_MODE (7) //����ʱ����8��ģʽ 
/*=== ���ú�ķ��ص�״̬ ===*/
#define RCADC_DEPLOY_OK   (0) //�ɹ� 
#define RCADC_DEPLOY_FAIL (-1)//ʧ��  

#define RCADC_START (1) //��ʼ 
#define RCADC_STOP  (0) //ֹͣ 

#define RCADC_A		(0) //A������ 
#define RCADC_B     (1) //B������    

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
    
/****************************************** 
RCADC_SAMPLING_MODE��Ϊ������ʽ
0x00��IN0 pin external clock input mode1 (initial value) 
0x01��RS0-CS0 oscillation mode2
0x02��RT0�CCS0 oscillation mode3
0x03��RT0-1�CCS0 oscillation mode4
0x04��RS0�CCT0 oscillation mode5
0x05��RS1�CCS1 oscillation mode6
0x06��RT1�CCS1 oscillation mode7 
0x07��IN1 pin external clock input mode8
0x08��Prohibited 
******************************************/
unsigned char RCADC_SAMPLING_MODE[SAMP_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08
};

/****************************************** 
RCADC_SAMP_CLK_MODE��Ϊ����ʱ�� 
0x00��LSCLK (initial value)
0x01��LSCLK��2             
0x02��HSCLK
0x03��1/2HSCLK
0x04��1/4HSCLK
0x05��1/8HSCLK
0x06��Setting prohibited (no clock is supplied) 

******************************************/
unsigned char RCADC_SAMP_CLK_MODE[SAMP_CLK_MODE]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06
};

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
  unsigned char r0,r1,RADMOD; 
  //�ж�����ģʽ�Ƿ���ȷ 
   if(samp > SAMP_MODE || clk > SAMP_CLK_MODE) {
   	 return (RCADC_DEPLOY_FAIL);
	  } 
     r0 = RCADC_SAMPLING_MODE[samp]; 
     r1 = RCADC_SAMP_CLK_MODE[clk];  
   RADMOD = ((r0 << 0) | (r1 << 5));
   printf("RADMOD=%d\n", RADMOD); 
  return (RCADC_DEPLOY_OK);
 }
 
 int main()
  {
  	int ZHI;
	  ZHI=rcadc_Samp_Clk_init(rcad_seven, rcad_six); 
	 printf("ZHI=%d\n",ZHI);
	 getchar(); 
  } 