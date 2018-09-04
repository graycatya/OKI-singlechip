#include<m610409.h>
#include "clk.h"

/*************************
SYSC-
0x00:OSCLK
0x01:1/2OSCLK
0x02:1/4OSCLK
0x03:1/8OSCLK (initial value)
*************************/
unsigned char SYSC_MODE_CLK[SYSC_MODE]={
 0x00,0x01,0x02,0x03	
}; 
/*************************
OUTC-
0x00:OSCLK
0x01:1/2OSCLK
0x02:1/4OSCLK
0x03:1/8OSCLK (initial value)
*************************/
unsigned char OUTC_MODE_CLK[OUT_MODE]={
 0x00,0x01,0x02,0x03	
};




/********************************** 
 * ������:clk_init 
 * ����: CLK���ó�ʼ�� 
 * ����: sysc:
            CLKmode_value{CLK_one...CLK_four}
             ����ö��ģʽ 1-4 
         outc:
            CLKmode_value{CLK_one...CLK_four}
             ����ö��ģʽ 1-4
         oscm:
            OSCM_500KMZ  (=0) //500 kHz���񵴱�ѡ��
            OSCM_2MHZ    (=1) //2  MHz���񵴱�ѡ��
 * ����: int 
***********************************/
int clk_fcon0_init(unsigned int sysc, unsigned int outc, unsigned int oscm)
 {
  unsigned char r0,r1;
   if(sysc >= SYSC_MODE || outc >= OUT_MODE || oscm > OSCM_2MHZ) {
    return (CLK_DEPLOY_FAIL);
    }
  
   r0 = SYSC_MODE_CLK[sysc];
   r1 = OUTC_MODE_CLK[outc];
   FCON0 = (unsigned char)((r0 << 0) |
                           (r1 << 4) );
    OSCM2 = oscm;
   return (CLK_DEPLOY_OK);
  }
  
/********************************** 
 * ������:clk_init 
 * ����: CLK���ó�ʼ�� 
 * ����: syscl:
             SYSCLK_LSCLK (=0) //����ʱ�� 
             SYSCLK_HSCLK (=1) //����ʱ��
         enos:
             ENO_STOP_HIGHCLK    (=0) //���ø���ʱ�� 
             ENO_ENABLES_HIGHCLK (=1) //ʹ�ܸ���ʱ�� 
         enml:
             ENM_DISABLES_LOWCLK (=0) //����2*����ʱ�� 
             ENM_ENABLES_LOWCLK  (=1) //ʹ��2*����ʱ�� 
 * ����: int 
***********************************/
int clk_fcon1_init(unsigned int syscl, unsigned int enos, unsigned int enml)
 {
   unsigned int r0,r1,r2;
    if(syscl > SYSCLK_HSCLK || enos > ENO_ENABLES_HIGHCLK || 
	   enml > ENM_ENABLES_LOWCLK) {
   	 return (CLK_DEPLOY_FAIL);	
   	 }	
   r0 = syscl;
   r1 = enos;
   r2 = enml;
   FCON1 = (unsigned char)((r0 << 0) | (r1 << 1) |
                                       (r2 << 2) );
   return (CLK_DEPLOY_OK);
  }


/**********************************
 * ����: ���Ź� ι��
 * ����: ��
 * ����: ��
**********************************/
void WD_Feed()
 {
  do
   {
    WDTCON = 0x5a;
     }while(WDP != 1);
    WDTCON = 0xa5;
   }


/**********************************
 * ����: ����ϵͳʱ��
 * ����: ��
 * ����: 0Ϊ�ɹ���-1Ϊʧ�� 
**********************************/
int HIGH_career()
 {
   if(clk_fcon0_init(CLK_four, CLK_four, OSCM_2MHZ) == CLK_DEPLOY_OK)
     return clk_fcon1_init(SYSCLK_HSCLK, ENO_ENABLES_HIGHCLK, ENM_ENABLES_LOWCLK);
     return (CLK_DEPLOY_FAIL);
  }

int HIGH2_career()
 {
   if(clk_fcon0_init(CLK_one, CLK_one, OSCM_2MHZ) == CLK_DEPLOY_OK)
     return clk_fcon1_init(SYSCLK_HSCLK, ENO_ENABLES_HIGHCLK, ENM_ENABLES_LOWCLK);
     return (CLK_DEPLOY_FAIL);
  }


int LOW_career()
 {
   if(clk_fcon0_init(CLK_four, CLK_four, OSCM_2MHZ) == CLK_DEPLOY_OK)
     return clk_fcon1_init(SYSCLK_LSCLK, ENO_STOP_HIGHCLK, ENM_DISABLES_LOWCLK);
     return (CLK_DEPLOY_FAIL);
  }