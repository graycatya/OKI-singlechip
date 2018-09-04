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
 * 函数名:clk_init 
 * 功能: CLK配置初始化 
 * 参数: sysc:
            CLKmode_value{CLK_one...CLK_four}
             输入枚举模式 1-4 
         outc:
            CLKmode_value{CLK_one...CLK_four}
             输入枚举模式 1-4
         oscm:
            OSCM_500KMZ  (=0) //500 kHz的振荡被选中
            OSCM_2MHZ    (=1) //2  MHz的振荡被选中
 * 返回: int 
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
 * 函数名:clk_init 
 * 功能: CLK配置初始化 
 * 参数: syscl:
             SYSCLK_LSCLK (=0) //低速时钟 
             SYSCLK_HSCLK (=1) //高速时钟
         enos:
             ENO_STOP_HIGHCLK    (=0) //禁用高速时钟 
             ENO_ENABLES_HIGHCLK (=1) //使能高速时钟 
         enml:
             ENM_DISABLES_LOWCLK (=0) //禁用2*低速时钟 
             ENM_ENABLES_LOWCLK  (=1) //使能2*低速时钟 
 * 返回: int 
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
 * 功能: 看门狗 喂狗
 * 参数: 无
 * 返回: 无
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
 * 功能: 设置系统时钟
 * 参数: 无
 * 返回: 0为成功，-1为失败 
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