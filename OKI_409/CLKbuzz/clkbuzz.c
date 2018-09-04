#include<m610409.h>
#include "clkbuzz.h"

/***************************************************
 * ����: ����ʱ���㷨���� 
 * ����: SHI(ʱ�ӿ�), FEN(�ֽӿ�) 
 * ����: uint 
****************************************************/
uint TIME_ALG(uint SHI, uint FEN)
  {
  	uint sum;
  	 sum = SHI*60+FEN;
    return sum;
  } 
  

/**********************************
 * ����: ������ֵ�� 
 * ����: CLK_mar(����ʱ��), ZHI(���ӵ�ֵ) 
 * ����: uint
**********************************/  
uint BUzz_CLKzhi(uint CLK_mar, uint ZHI)
 {
   uint sum;
    sum=CLK_mar+ZHI;
   return sum;	
 } 

/***************************************************
 * ����: �������жϺ��� 
 * ����: TI_zhi(ʱ�����ݽӿ�), CLK_zhi(�������ݽӿ�) 
          CLK_MO(����ģʽ�ӿ�),LCD_mod(LCD�����־λ) 
		   *key_per(������ӿ�1),*key_nop(������ӿ�2)
 * ����: ��
****************************************************/ 
void CLK_time(uint TI_zhi, uint CLK_zhi, uint CLK_MO,
               uint LCD_mod, uint *key_per , uint *key_nop, uint *BU_beg)
 { 
  static int ki=0; //��ֹ��һ���� 
  if(LCD_mod != 0 && CLK_MO != 1) 
   {
           *BU_beg=0; //SET��ȥ����һ�ΰ�����Ч
   	 if(TI_zhi == CLK_zhi) {ki=1; } //��һ��ȡ���� 
   	  else if(TI_zhi != CLK_zhi) {ki=2; } //��ʼ��ȷ��������ת 
   }
  if(LCD_mod == 0 && CLK_MO != 1) //�����������������������ʱ��ʼ�ж������Ƿ��� 
   {
         if(TI_zhi != CLK_zhi) {ki=2; *BU_beg=0; } //��һ��ȡ����
         if(TI_zhi == CLK_zhi && *BU_beg==0 && ki == 2) {*key_per=1; *key_nop=1; ki = 1;}//��ȷ�������ж�������
        
  }   
 }
 
 
/**********************************
 * ����: ���Ӱ�������ȫ�жϺ��� 
 * ����: BUZZ_rin(�������־λ), key_nop(���Ӱ����ӿ�)
 * ����: ��
**********************************/  
void BUzz_keyjudper(uint *key_nop, uint *BUZZ_deg)
  {
  	if(*key_nop == 1) 
     {
   	   *BUZZ_deg=*BUZZ_deg+1; 
            *key_nop=0;	
	   M0RUN=0;
     }   
  } 
  
/**********************************
 * ����: ���Ӱ�����ȫ�жϺ��� 
 * ����: *CLK_MO(����ģʽ�ӿ�), KEY_nop(���Ӱ����ӿ�),key_per(�������ӿ�)
 * ����: ��
**********************************/  
void BUzz_keyjudnop(uint *CLK_MO, uint *key_per, uint *KEY_nop, uint *BUZZ_deg, uint *BU_z)
  {
  if(*KEY_nop == 1)M0RUN=0;
  if(*CLK_MO == 2) 
     {
        *key_per=0;
        *KEY_nop=0;
        *BUZZ_deg=0;
        *BU_z=1;	
     }  
  if(*CLK_MO == 3) 
     {
       *key_per=0;
       *KEY_nop=0;
       *CLK_MO=1;
       *BUZZ_deg=0;		
     }   
   } 


 
 

 
