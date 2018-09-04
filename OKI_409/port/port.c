#include<m610409.h>
#include "port.h"

/**********************************
**P0�����ú��� 
**********************************/ 

/********************************** 
 * ������:P0D_init 
 * ����: P0�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int P0D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P00D = bit0; P01D = bit1;
	P02D = bit2; P03D = bit3;
	P04D = bit4;
   return (PORT_DEPLOY_OK);
  }
  
  
/********************************** 
 * ������:PCON_0init 
 * ����: P0CON�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
 * ����: int 
***********************************/
int PCON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P00C0 = bit0; P01C0 = bit1;
	P02C0 = bit2; P03C0 = bit3;
	P04C0 = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  

/********************************** 
 * ������:PCON_1init 
 * ����: P0CON�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
 * ����: int 
***********************************/
int PCON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P00C1 = bit0; P01C1 = bit1;
	P02C1 = bit2; P03C1 = bit3;
	P04C1 = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  
/********************************** 
 * ������:EXICON_0init 
 * ����: P0EXICON�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
 * ����: int 
***********************************/
int EXICON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P00E0 = bit0; P01E0 = bit1;
	P02E0 = bit2; P03E0 = bit3;
	P04E0 = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  

/********************************** 
 * ������:EXICON_1init 
 * ����: P0EXICON�����ó�ʼ�� 
  * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int EXICON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P00E1 = bit0; P01E1 = bit1;
	P02E1 = bit2; P03E1 = bit3;
	P04E1 = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  
/********************************** 
 * ������:EXICON_2init 
 * ����: P0EXICON�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int EXICON_2init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P00SM = bit0; P01SM = bit1;
	P02SM = bit2; P03SM = bit3;
	P04SM = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  
/**********************************
**P2�����ú��� 
**********************************/ 
  
/********************************** 
 * ������:P2D_init 
 * ����: P2�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int P2D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }   	
	P20D = bit0; P21D = bit1;
	P22D = bit2; P24D = bit4;
   return (PORT_DEPLOY_OK);    
  }
  
/********************************** 
 * ������:P2CON_0init 
 * ����: P2CON�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
 * ����: int 
***********************************/
int P2CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P20C0 = bit0; P21C0 = bit1;
	P22C0 = bit2; P24C0 = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  
/********************************** 
 * ������:P2CON_1init 
 * ����: P2CON�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
 * ����: int 
***********************************/
int P2CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P20C1 = bit0; P21C1 = bit1;
	P22C1 = bit2; P24C1 = bit4;
   return (PORT_DEPLOY_OK);		 	
  }
  
/********************************** 
 * ������:P2MOD_init
 * ����: P2MOD�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
 * ����: int 
***********************************/  
int P2MOD_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit4 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }  
	P20MD = bit0; P21MD = bit1;
	P22MD = bit2; P24MD = bit4;
   return (PORT_DEPLOY_OK);	   	
  }

  
/**********************************
**P3�����ú��� 
**********************************/  


/********************************** 
 * ������:P3D_init
 * ����: P3D�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int P3D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
             unsigned int bit3, unsigned int bit4, unsigned int bit5)
{
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL); 
	   	}
	P30D = bit0; P31D = bit1;
	P32D = bit2; P33D = bit3;
	P34D = bit4; P35D = bit5;
   return (PORT_DEPLOY_OK);		
  }
  
/********************************** 
 * ������:P3DIR_init
 * ����: P3DIR�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int P3DIR_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
               unsigned int bit3, unsigned int bit4, unsigned int bit5)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL); 
	   	}
	P30DIR = bit0; P31DIR = bit1;
	P32DIR = bit2; P33DIR = bit3;
	P34DIR = bit4; P35DIR = bit5;
   return (PORT_DEPLOY_OK);	
  }
  
/********************************** 
 * ������:P3CON_0init
 * ����: P3CON0�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/
int P3CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit3, unsigned int bit4, unsigned int bit5)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL); 
	   	} 
	P30C0 = bit0; P31C0 = bit1;
	P32C0 = bit2; P33C0 = bit3;
	P34C0 = bit4; P35C0 = bit5;
   return (PORT_DEPLOY_OK);		
  }

/********************************** 
 * ������:P3CON_1init
 * ����: P3CON1�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/ 
int P3CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit3, unsigned int bit4, unsigned int bit5)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL); 
	   	}
	P30C1 = bit0; P31C1 = bit1;
	P32C1 = bit2; P33C1 = bit3;
	P34C1 = bit4; P35C1 = bit5;
   return (PORT_DEPLOY_OK);	   	
  }

/********************************** 
 * ������:P3MOD_0init
 * ����: P3MOD0�����ó�ʼ�� 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
 * ����: int 
***********************************/ 
int P3MOD_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
               unsigned int bit3, unsigned int bit4, unsigned int bit5)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
	   	bit4 > PORT_HIGH || bit5 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL); 
	   	}
	P30MD0 = bit0; P31MD0 = bit1;
	P32MD0 = bit2; P33MD0 = bit3;
	P34MD0 = bit4; P35MD0 = bit5;
   return (PORT_DEPLOY_OK);	   	
  }
  
  
/**********************************
**P4�����ú��� 
**********************************/   


/********************************** 
 * ������:P4D_init 
 * ����: P4�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P4D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
             unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P40D = bit0; P41D = bit1;
	P42D = bit2; P43D = bit3;
	P44D = bit4; P45D = bit5;
	P46D = bit6; P47D = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P4DIR_init 
 * ����: P4DIR�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P4DIR_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P40DIR = bit0; P41DIR = bit1;
	P42DIR = bit2; P43DIR = bit3;
	P44DIR = bit4; P45DIR = bit5;
	P46DIR = bit6; P47DIR = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P4CON_0init
 * ����: P4CON_0�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P4CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P40C0 = bit0; P41C0 = bit1;
	P42C0 = bit2; P43C0 = bit3;
	P44C0 = bit4; P45C0 = bit5;
	P46C0 = bit6; P47C0 = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P4CON_1init
 * ����: P4CON_1�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P4CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P40C1 = bit0; P41C1 = bit1;
	P42C1 = bit2; P43C1 = bit3;
	P44C1 = bit4; P45C1 = bit5;
	P46C1 = bit6; P47C1 = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P4MOD_0init
 * ����: P4MOD_0�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P4MOD_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P40MD0 = bit0; P41MD0 = bit1;
	P42MD0 = bit2; P43MD0 = bit3;
	P44MD0 = bit4; P45MD0 = bit5;
	P46MD0 = bit6; P47MD0 = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P4MOD_1init
 * ����: P4MOD_1�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P4MOD_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P40MD1 = bit0; P41MD1 = bit1;
	P42MD1 = bit2; P43MD1 = bit3;
	P44MD1 = bit4; P45MD1 = bit5;
	P46MD1 = bit6; P47MD1 = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
  
/**********************************
**P5�����ú��� 
**********************************/ 


/********************************** 
 * ������:P5D_init 
 * ����: P5�����ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P5D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
             unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P50D = bit0; P51D = bit1;
	P52D = bit2; P53D = bit3;
	P54D = bit4; P55D = bit5;
	P56D = bit6; P57D = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P5DIR_init 
 * ����: P5DIR���ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P5DIR_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P50DIR = bit0; P51DIR = bit1;
	P52DIR = bit2; P53DIR = bit3;
	P54DIR = bit4; P55DIR = bit5;
	P56DIR = bit6; P57DIR = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  

/********************************** 
 * ������:P5CON_0init
 * ����: P5CON_0���ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P5CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P50C0 = bit0; P51C0 = bit1;
	P52C0 = bit2; P53C0 = bit3;
	P54C0 = bit4; P55C0 = bit5;
	P56C0 = bit6; P57C0 = bit7;
   return (PORT_DEPLOY_OK);   	
  }
  
  
/********************************** 
 * ������:P5CON_1init
 * ����: P5CON_1���ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P5CON_1init(unsigned int bit0)
 {
   if(bit0 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P5UD = bit0; 
   return (PORT_DEPLOY_OK);   	
  }
  
/********************************** 
 * ������:P5MOD_0init
 * ����: P5MOD_0���ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ             
 * ����: int 
***********************************/
int P5MOD_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH ||
         bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
          bit6 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P50MD0 = bit0; P51MD0 = bit1;
	P52MD0 = bit2; 
	P54MD0 = bit4; P55MD0 = bit5;
	P56MD0 = bit6; 
   return (PORT_DEPLOY_OK);   	
  }
  

/********************************** 
 * ������:P5MOD_1init
 * ����: P5MOD_1���ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
        
 * ����: int 
***********************************/
int P5MOD_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
         bit6 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P50MD1 = bit0; P51MD1 = bit1;
	P52MD1 = bit2; 
	P54MD1 = bit4; P55MD1 = bit5;
	P56MD1 = bit6; 
   return (PORT_DEPLOY_OK);   	
  }
  

/********************************** 
 * ������:P5SISEL_init
 * ����: P5SISEL���ó�ʼ��ƽ 
 * ����: bit0:
           P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
           P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
         bit1:
           P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
           P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
         bit2:
           P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
           P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
         bit3:
           P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
           P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
         bit4:
           P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit5:
           P5_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P5_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
         bit6:
           P6_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P6_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ  
         bit7:
           P7_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ 
           P7_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ           
 * ����: int 
***********************************/
int P5SISEL_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7)
 {
   if(bit0 > PORT_HIGH || bit1 > PORT_HIGH || 
       bit2 > PORT_HIGH || bit3 > PORT_HIGH ||
        bit4 > PORT_HIGH || bit5 > PORT_HIGH ||
	     bit6 > PORT_HIGH || bit7 > PORT_HIGH) {
       	 return (PORT_DEPLOY_FAIL);
        }
	P50IS = bit0; P51IS = bit1;
	P52IS = bit2; P53IS = bit3;
	P54IS = bit4; P55IS = bit5;
	P56IS = bit6; P57IS = bit7;
   return (PORT_DEPLOY_OK);   	
  }