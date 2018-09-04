#include<m610409.h> 
#include "key.h"


/********************************** 
 * ������:KEY_WALK_ROW
 * ����: ����ɨ���л� 
 * ����: WR_mode��
           KEY_SCANNING_SORT (0)  //ɨ���� 
           KEY_SCANNING_WALK (1)  //ɨ����
 * ����: unsigned int
***********************************/
unsigned int  KEY_WALK_ROW(unsigned int WR_mode)
  {
  	if(WR_mode > (unsigned int)KEY_SCANNING_WALK) {
	  	return ((unsigned int)KEY_DEPLOY_FAIL);
	  }
	  if(WR_mode == KEY_SCANNING_SORT)
	   {
         P50DIR = 0; P51DIR = 0; P52DIR = 1; P53DIR = 1;
         P50D = 0; P51D = 0; P52D = 1; P53D = 1; 	
   	    }
      else if(WR_mode == KEY_SCANNING_WALK)
        {
          P50DIR = 1; P51DIR = 1; P52DIR = 0; P53DIR = 0;
          P50D = 1; P51D = 1; P52D = 0; P53D = 0; 	
         }
     return (KEY_DEPLOY_OK); 
   }

/********************************** 
 * ������:KEY_WALK_ROW
 * ����: ����ɨ�� 
 * ����: �� 
 * ����: unsigned int
***********************************/
unsigned int KEY_scanning()
 {
   unsigned int k0=0,k1=0,k2=0,k3=0,sum=0;
   static int clash=KEY_CLASH_NO;
      //��һ����ֵ�㷨 
     if(KEY_WALK_ROW(KEY_SCANNING_SORT) == KEY_DEPLOY_OK)  
      if(P50D == KEY_LOW && P51D == KEY_LOW)
       {
         P52D = KEY_HIGH; P53D = KEY_HIGH;
        if(P52D == KEY_HIGH && P53D == KEY_HIGH) clash=KEY_CLASH_NO;
           else if(P52D == KEY_LOW && P53D == KEY_LOW)  clash=KEY_CLASH_BE;
         if(P52D == KEY_LOW && P53D == KEY_HIGH && clash==KEY_CLASH_NO) {k0 = 1; }
         if(P53D == KEY_LOW && P52D == KEY_HIGH && clash==KEY_CLASH_NO) {k1 = 2; }
       }
      //�ڶ�����ֵ�㷨  
     if(KEY_WALK_ROW(KEY_SCANNING_WALK) == KEY_DEPLOY_OK) 
      if(P52D == KEY_LOW && P53D == KEY_LOW)
       {
         P50D = KEY_HIGH; P51D = KEY_HIGH;
         if(P50D == KEY_HIGH && P51D == KEY_HIGH) clash=KEY_CLASH_NO;
           else if(P50D == KEY_LOW && P51D == KEY_LOW)  clash=KEY_CLASH_BE;
         if(P50D == KEY_LOW && P51D == KEY_HIGH && clash==KEY_CLASH_NO) 
		   {k2 = 0; 
		    if(k0 != 0)sum = k0+k2;
		    if(k1 != 0)sum = k1+k2;
		    }
         if(P51D == KEY_LOW && P50D == KEY_HIGH && clash==KEY_CLASH_NO) 
		   {k3 = 2;
		    if(k0 != 0)sum = k0+k3;
		    if(k1 != 0)sum = k1+k3; 
		    }
         }
    return (sum);	
 }


/********************************** 
 * ������:KEY_VALUE 
 * ����: ɨ����ֵת��Ϊ16���� 
 * ����: ke
 * ����: unsigned char
***********************************/
 unsigned char KEY_VALUE(unsigned int ke)
   {
   	unsigned char sum;
   	 switch(ke)
   	  {
  	   case 1: sum=(unsigned char)KEY_0;break;
	   case 2: sum=(unsigned char)KEY_1;break;
	   case 3: sum=(unsigned char)KEY_2;break;
	   case 4: sum=(unsigned char)KEY_3;break;
	   default : sum=(unsigned char)KEY_NO;	
 	   }
     return sum;
   }
   

/********************************** 
 * ������:KeyRead
 * ����: ����״̬�ж� 
 * ����: key_mode�� *Tr�� *Co 
 * ����: ��
***********************************/
void KeyRead(unsigned char key_mode, uchar *Tr, uchar *Co)
 {
 	unsigned char ReadData = key_mode^0x00; //1
 	*Tr = ReadData & (ReadData ^ Cont); //2
 	*Co = ReadData; //3	
 } 
 
/********************************** 
 * ������:KEY_close
 * ����: ����״̬�ж� 
 * ����: ke_clo:
            KEY_0 (0x01) //����0ֵ 
            KEY_1 (0x02) //����1ֵ 
            KEY_2 (0x04) //����2ֵ 
            KEY_3 (0x08) //����3ֵ 
		     
 * ����: unsigned int
***********************************/
unsigned int KEY_close(unsigned char ke_clo)
 {
   if(Trg == ke_clo) return ((unsigned int)key_close_yes);
    else return ((unsigned int)key_close_no); 
 }
 
 
/********************************** 
 * ������:KEY_long
 * ����: ����״̬�ж� 
 * ����: ke_clo:
            KEY_0 (0x01) //����0ֵ 
            KEY_1 (0x02) //����1ֵ 
            KEY_2 (0x04) //����2ֵ 
            KEY_3 (0x08) //����3ֵ 
		     
 * ����: unsigned int
***********************************/
unsigned int KEY_long(unsigned char ke_clo)
 {
   if(cont == ke_clo) return ((unsigned int)key_close_yes);
    else return ((unsigned int)key_close_no); 
 }
 
 
 
/********************************** 
 * ������:KEY_independent
 * ����: P56,P57����������ʼ�� 
 * ����: �� 
 * ����: �� 
***********************************/ 
void KEY_independent()
 {
 	P56DIR = 1; P57DIR = 1;
 } 
 
/********************************** 
 * ������:KEY_indepen_scan
 * ����: P56,P57��������ɨ�� 
 * ����: �� 
 * ����: �� 
***********************************/  
void KEY_indepen_scan(uint *cay, uint *CF)
 {
 	if(P56D == 0) *CF = KEY_LOW;
	  else *CF = KEY_HIGH; 
 	if(P57D == 0) *cay = KEY_LOW;
	  else *cay = KEY_HIGH; 
 }