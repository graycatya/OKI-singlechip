
#include "lcdshow.h"
#include "temphum.h" 

//12/24Сʱ����ʾ�� 
uchar TIME_system[SYSTEM][TIM][2]={
//0-23Сʱ����ʾ 
{{0x3f,0x3f},{0x3f,0x06},{0x3f,0x5b},{0x3f,0x4f},{0x3f,0x66},
 {0x3f,0x6d},{0x3f,0x7d},{0x3f,0x07},{0x3f,0x7f},{0x3f,0x6f},
 {0x06,0x3f},{0x06,0x06},{0x06,0x5b},{0x06,0x4f},{0x06,0x66},
 {0x06,0x6d},{0x06,0x7d},{0x06,0x07},{0x06,0x7f},{0x06,0x6f},
 {0x5b,0x3f},{0x5b,0x06},{0x5b,0x5b},{0x5b,0x4f}},
//12Сʱ����ʾ 
{{0x06,0x5b},{0x3f,0x06},{0x3f,0x5b},{0x3f,0x4f},{0x3f,0x66},
 {0x3f,0x6d},{0x3f,0x7d},{0x3f,0x07},{0x3f,0x7f},{0x3f,0x6f},
 {0x06,0x3f},{0x06,0x06},{0x06,0x5b},{0x3f,0x06},{0x3f,0x5b},
 {0x3f,0x4f},{0x3f,0x66},{0x3f,0x6d},{0x3f,0x7d},{0x3f,0x07},
 {0x3f,0x7f},{0x3f,0x6f},{0x06,0x3f},{0x06,0x06}}
}; 

//*��һ��������ʾ�� 
uchar week[WEK_mod][3][2]={
{{0x6D,0x01},{0x3E,0x00},{0x36,0x18}}, //SUN
{{0x36,0x50},{0x3F,0x00},{0x36,0x18}}, //MON
{{0x01,0x24},{0x3E,0x00},{0x79,0x01}}, //TUE
{{0x36,0x0A},{0x79,0x01},{0x0F,0x24}}, //WED
{{0x01,0x24},{0x76,0x01},{0x3E,0x00}}, //THU
{{0x71,0x01},{0x73,0x09},{0x09,0x24}}, //FRI
{{0x6D,0x01},{0x77,0x01},{0x01,0x24}}  //SAT
}; 

//*����ģʽ-3��ģʽ��ʾ��
uchar	NOISY0_bell[NObel_mod][2]={
{0x40,0x40}, //--
{0x00,0x37}, //N
{0x00,0x06}  //1  	
};
//*����ģʽ-3��ģʽ��ʾ�� 
uchar	NOISY1_bell[NObel_mod][3][2]={
{{0x3F,0x00},{0x71,0x01},{0x71,0x01}}, //OFF
{{0x73,0x09},{0x79,0x01},{0x73,0x01}}, //REP
{{0x00,0x00},{0x3F,0x00},{0x01,0x24}}  //OT	
}; 

//*0-9,' ','-'�������ʾ.
uchar table[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x40};  



/********************************** 
 * ����: BUZZ��˸��ʾ���� 
 * ����: P(��������ӿ�),BU_bit(BUZZ��ʾ״̬λ�ӿ�) 
 * ����: ��
**********************************/ 
void UI_BUZZ(uint P, uint BU_bit)
 {
         if(BU_bit==1)
          {
     	  	if(P==0)Buzz=LOW;  //��ʱΪBUZZ��˸ 
     	  	if(P==1)Buzz=HIGH;
     	   }
          else Buzz=LOW;
  }
  
/********************************** 
 * ����: P.��˸��ʾ���� 
 * ����: P(��������ӿ�),P_bit(P.��ʾ״̬λ�ӿ�)
 * ����: ��
**********************************/ 
void UI_P(uint P, uint P_bit)
 {
  if(P_bit==1)Clk=HIGH;
   else if(P_bit==2)Clk=LOW;	
    else if(P_bit==3)
	 {
	  if(P==0)Clk=LOW;      //��ʱΪʱ�Ӽ�����˸ 
  	   else if(P==1)Clk=HIGH; 
	  }	
  }

/********************************** 
 * ����: ����ʾ���� 
 * ����: YETI_VALUE�����������ݽӿڣ���BU_YT(�곣������˸״̬λ)�� 
          P����˸״̬�ӿڣ�         
 * ����: ��
**********************************/  
void UI_YE(uint YETI_VALUE, uint BU_YT, uint P)
 {
  	if(BU_YT==0)Year_Out=0x00; //��Ӣ����ʾ��year��
	if(BU_YT==1) //����ģʽ 
	 {
	 	Year_Out=0x01; //��Ӣ����ʾ��year��
    	year_time0=table[YETI_VALUE/1000]; //��ǧλ 
  	    year_time1=table[YETI_VALUE/100%10]; //���λ
    	year_time2=table[YETI_VALUE/10%10]; //��ʮλ
    	year_time3=table[YETI_VALUE%10]; //���λ 		
 	 }
    else if(BU_YT==2) //��˸ģʽ 
     {
   	  Year_Out=0x01; //��Ӣ����ʾ��year��
      if(P==0) //�� 
       {
    	year_time0=0; //��ǧλ 
  	    year_time1=0; //���λ
    	year_time2=0; //��ʮλ
    	year_time3=0; //���λ    		
   	   }
	  else if(P==1) //�� 
	   {
    	year_time0=table[YETI_VALUE/1000]; //��ǧλ 
  	    year_time1=table[YETI_VALUE/100%10]; //���λ
    	year_time2=table[YETI_VALUE/10%10]; //��ʮλ
    	year_time3=table[YETI_VALUE%10]; //���λ	   	 
       }	
     } 
 } 
 
 
/********************************** 
 * ����: ʱ��˸���� 
 * ����: TIM_VALUE��ʱ/����ʱ�������ݽӿڣ���
          TIM_ZHI(24/12Сʱѡ��),P����˸״̬�ӿڣ�     
 * ����: ��
**********************************/
 void  TIM_SHI(uint TIM_VALUE, uint TIM_ZHI, uint P)
  {
      if(P==0) //�� 
       {
       	year_time0=0; //ʱʮλ 
  	    year_time1=0; //ʱ��λ   		
   	   }
	  else if(P==1) //�� 
	   {
	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //ʱʮλ 
		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //ʱ��λ	   	 
       }    	
   }
   

/********************************** 
 * ����: ����˸���� 
 * ����: MAR_VALUE����/���ӷ��������ݽӿڣ���P����˸״̬�ӿڣ�  
 * ����: ��
**********************************/
void TIM_FEN(uint MAR_VALUE, uint P)
  {
      if(P==0) //�� 
       {
    	year_time2=0; //��ʮλ
    	year_time3=0; //�ָ�λ    		
   	   }
	  else if(P==1) //�� 
	   {
    	  year_time2=table[MAR_VALUE/10]; //��ʮλ
    	  year_time3=table[MAR_VALUE%10]; //�ָ�λ 	   	 
       }    	
   }
   
/********************************** 
 * ����: ʱ/����ʾ���� 
 * ����: TIM_VALUE��ʱ/����ʱ�������ݽӿڣ���MAR_VALUE����/���ӷ��������ݽӿڣ�
          TIM_ZHI(24/12Сʱѡ��),BU_YT(ʱ��������˸״̬λ)�� P����˸״̬�ӿڣ�     
 * ����: ��
**********************************/  
void UI_TIME(uint TIM_VALUE, uint MAR_VALUE, uint TIM_ZHI, uint BU_YT, uint P)
 {
	if(BU_YT==1) //����ģʽ 
	 {
	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //ʱʮλ 
		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //ʱ��λ
    	  year_time2=table[MAR_VALUE/10]; //��ʮλ
    	  year_time3=table[MAR_VALUE%10]; //�ָ�λ 		
 	 } 
    else if(BU_YT==2)    //ʱ��˸ģʽ	
     {
       year_time2=table[MAR_VALUE/10]; //��ʮλ
       year_time3=table[MAR_VALUE%10]; //�ָ�λ
	    TIM_SHI(TIM_VALUE, TIM_ZHI, P);
     } 
    else if(BU_YT==3)    //����˸ģʽ 
     {
	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //ʱʮλ 
		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //ʱ��λ
          TIM_FEN(MAR_VALUE, P);	
     } 
 } 
 
/********************************** 
 * ����: �£�����ʾ���� 
 * ����: P(��������ӿ�),DISP_MON(������/ʱ��/��������ģʽ�ӿ�),
          CLK_mode(����ʱ�����ñ�־λ), Mon(���������ݽӿ�)��
		  dat_AIM(����������/����ģʽ״̬���ݽӿ�) 
 * ����: ��
**********************************/  
void UI_YEAR_TIME(uint P, uint DISP_MON, uint CLK_mode, uint Mon, uint dat_AIM)
 {
   if(DISP_MON==0) //��/�ճ��� 
    {   
      if(Mon/10==0) Mon_Da0=LOW;
     else Mon_Da0=table[Mon/10];
      Mon_Da1=table[Mon%10]; 
      if(dat_AIM/10==0) Mon_Da2=LOW;
     else Mon_Da2=table[dat_AIM/10]; 
      Mon_Da3=table[dat_AIM%10]; 
     }
  if(DISP_MON == 2)
   {
   if(CLK_mode == 2) //����˸/�ճ��� 
    {
   	  if(dat_AIM/10==0) Mon_Da2=LOW;
       else Mon_Da2=table[dat_AIM/10]; 
       Mon_Da3=table[dat_AIM%10];    	  
  	  if(P==0)
  	   {
        Mon_Da0=0;
        Mon_Da1=0;  	   	 
	    } 
  	   else if(P==1)
       {
   	    if(Mon/10==0) Mon_Da0=LOW;
         else Mon_Da0=table[Mon/10]; 
          Mon_Da1=table[Mon%10];
	    }	
	 } 
   else if(CLK_mode==3) //����˸/�³��� 
    {
      if(Mon/10==0) Mon_Da0=LOW;
       else Mon_Da0=table[Mon/10]; 
        Mon_Da1=table[Mon%10]; 
  	  if(P==0)
  	   {
        Mon_Da2=0;
        Mon_Da3=0;  	   	 
	    } 
  	   else if(P==1)
       {
   	  if(dat_AIM/10==0) Mon_Da2=LOW;
       else Mon_Da2=table[dat_AIM/10]; 
       Mon_Da3=table[dat_AIM%10];
	    }   	
	 } 
   }
  if(DISP_MON==1) //����ģʽ��˸ 
    {
      if(CLK_mode == 3)CIK_glint(P, dat_AIM);
    } 
  }
  
/********************************** 
 * ����: ��_��Ӣ����ʾ���� 
 * ����:  MO_BIT(����Ӣ��������ʾ״̬λ�ӿ�)
 * ����: ��
**********************************/   
void UI_MODA(uint MO_BIT)
 {
   if(MO_BIT==1)MonDa_Day=0; 
    else if(MO_BIT==2)MonDa_Day=0x05;	
  } 

/********************************** 
 * ����:  AIMset_APMӢ����ʾ���� 
 * ����:  AS_bit(AIMset��ʾ״̬λ�ӿ�)��AP_bit(���������־λ) 
          mode_ap(12/24��ʾ״̬����) 
 * ����: ��
**********************************/   
void UI_AIS_APM(uint AS_bit, uint AP_bit , uint mode_ap)
 {
   if(AS_bit==1)AiSe=0x03; //AIMset���� 
    else if(AS_bit==2)AiSe=0x02;//set���� 
	 else AiSe=LOW;//��
	 
   if(mode_ap == 1) //12/24�����ж� 
    { 
   if(AP_bit==1)A_PM=0x01; //AM���� 
    else if(AP_bit==2)A_PM =0x02;//PM���� 
    } 
	 else A_PM=LOW;//��	
  } 
  
/********************************** 
 * ����:  ����ģʽ/��1-7Ӣ����ʾ���� 
 * ����:  all(��1-7���ݽӿ�)��cl(����ģʽ״̬�ӿ� 3��״̬)��
           alcl_bit(����ģʽ/��1-7��ʾģʽ״̬λ) 
 * ����: ��
**********************************/    
void UI_all_CLMON(uint all, uint cl, uint alcl_bit)
 {
   if(alcl_bit==1)
    {
   	  Day_0=NOISY1_bell[cl-1][0][0]; 
	  Day_1=NOISY1_bell[cl-1][0][1];  
	  Day_2=NOISY1_bell[cl-1][1][0];  
	  Day_3=NOISY1_bell[cl-1][1][1];  
	  Day_4=NOISY1_bell[cl-1][2][0];  
	  Day_5=NOISY1_bell[cl-1][2][1]; 	
     }
   else if(alcl_bit==2)
    {
          Day_0=week[all][0][0]; 
	  Day_1=week[all][0][1]; 
	  Day_2=week[all][1][0]; 
	  Day_3=week[all][1][1]; 
	  Day_4=week[all][2][0]; 
	  Day_5=week[all][2][1]; 	
	 }	
  } 
  
/********************************** 
 * ����: ����ģʽ��˸���� 
 * ����:  P(��������ӿ�),da_AIM(����������/����ģʽ״̬���ݽӿ�)
 * ����: ��
**********************************/  
void CIK_glint(uint P,uint da_AIM)
 {
      Mon_Da0=0;
      Mon_Da1=0; 
   	  if(P==0)
  	   {
        Mon_Da2=0;
        Mon_Da3=0;  	   	 
	    } 
	  else if(P==1)	
	   {  //LCD ����Ӣ����˸ 
         Mon_Da2=NOISY0_bell[da_AIM-1][0];
         Mon_Da3=NOISY0_bell[da_AIM-1][1]; 					    		   		   
	    }   	
  } 
  
/********************************** 
 * ����: �����С/ʵʱ��ʪ��ģʽ�ӿ���ʾ���� 
 * ����: P(��������ӿ�),TEM_data��ʵʱ�¶����ݽӿڣ���HUM_data��ʵʩʪ�����ݽӿڣ� 
          *T_H(��ʪ�������С���ݽṹ��ӿ�),MAI_MON(�����С/ʵʱ��ʪ������ģʽ�ӿ�)
          MAI_K(��λ��ʾ�ӿ�)��c_f(C/F�㷨�л�)
 * ����: ��
**********************************/ 
void UI_TEMP_HUM(uint P, int TEM_data, int HUM_data,struct Ma_Mi *T_H, uint MAI_MON, uint MAI_K, int c_f)
  {
  	if(MAI_MON==1 && MAI_K==0) //��ʾʵʱ��ʪ�� 
     {
   	   
       TEM_HUM_realtime(TEM_data, HUM_data);  
  	  } 
    else if(MAI_MON==2 && MAI_K==0) //��ʾ��С��ʪ��  
     {	  
       TEM_HUM_realtime(C_FCUTOVER(T_H->min_temp, c_f), T_H->min_hum);	
        
      }
    else if(MAI_MON==3 && MAI_K==0) //��ʾ�����ʪ�� 
     {
       TEM_HUM_realtime(C_FCUTOVER(T_H->max_temp, c_f), T_H->max_hum);	
             	
      }
    if(MAI_K==1) //�������С��ʾ
	 {
 	   TEM_HUM_realtime(-600, -600);
	  } 
	  MAX_MIN_realtime(P, MAI_MON);
  } 
  
/********************************** 
 * ����: ��ʪ����ʾ���� 
 * ����: TE_data���¶����ݽӿڣ���HU_data��ʪ�����ݽӿڣ� 
 * ����: ��
**********************************/   
void TEM_HUM_realtime(int TE_data, int HU_data)
 {
 	//ʵʱ�¶ȴ�����ʾ 
 	if(TE_data>-600)
	 { 
     if(TE_data<0)carry=HIGH; //���� 
      else if(TE_data>=0)carry=LOW;      
     if(TE_data>=1000)Temp_0=HIGH; //����100�� 
      else if(TE_data<1000)Temp_0=LOW;
     if(TE_data<100)Temp_1=LOW;
 	  else Temp_1=table[TE_data/100%10]; 
  	       Temp_2=table[TE_data/10%10]; 
  	       Temp_3=table[TE_data%10]; 
	  }
     else 
      {
       Temp_1=table[11]; 
  	   Temp_2=table[11]; 
  	   Temp_3=table[11];	
       }
  	 //ʵʱʪ�ȴ�����ʾ
  	 if(HU_data>-600)
  	  {
  	  if(HU_data<10)Hum_0=LOW;
  	   else if(HU_data>=10)Hum_0=table[HU_data/10];
  	   Hum_1=table[HU_data%10];	
  	  }
     else
      {
   	   Hum_0=table[11];
  	   Hum_1=table[11];
      }
  } 

/********************************** 
 * ����: �����С��˸���� 
 * ����: P(��������ӿ�), MAI_MON(�����С/ʵʱ��ʪ������ģʽ�ӿ�)
 * ����: ��
**********************************/   
void MAX_MIN_realtime(uint P, uint MAI_MON)
 {
  	if(MAI_MON==1) Min_Max=LOW;
     else if(MAI_MON==2)
	  {
  	    if(P==0)Min_Max=LOW;
	   	 else if(P==1) Min_Max=0x01;
	   }
	 else if(MAI_MON==3)
	  {
  	    if(P==0)Min_Max=LOW;
	   	 else if(P==1) Min_Max=0x02;
	   }  
  }
  
/********************************** 
 * ����: C/F,%��ʾ����(��������ʪ����ʾ����)
 * ����:  DATA_bit(C_F�л�����״̬�ӿ�) 
 * ����: ��
**********************************/   
void  PICK_dataCOR(uint DATA_bit)
 {
   P_BAT=0x01; 
   if(DATA_bit==1)C_F_H=0x05; //C����ʾ 
    else if(DATA_bit==0)C_F_H=0x03;	//F����ʾ 
  }


/********************************** 
 * ����: �����Сֵ��ʼ�� 
 * ����: TEMP_DATA���¶����ݽӿڣ���HUM_DATA��ʪ�����ݽӿڣ���
         *M_m���ṹ����ʪ�����帳ֵ�� 
 * ����: struct Ma_Mi * ����ʼ�����ֵ�ýṹ�����巵�أ� 
**********************************/ 
void DATA_INT(int TEMP_DATA, int HUM_DATA, struct Ma_Mi *M_m)
 {
   	M_m->min_temp=TEMP_DATA;
   	M_m->max_temp=TEMP_DATA;
   	M_m->min_hum=HUM_DATA;
   	M_m->max_hum=HUM_DATA;
  }

/********************************** 
 * ����: �����Сֵ���ݱȽ� 
 * ����: TEMP_DATA���¶����ݽӿڣ���HUM_DATA��ʪ�����ݽӿڣ���
         *M_ai���ṹ����ʪ�����帳ֵ�� 
 * ����: struct Ma_Mi * ���ȽϺ��ֵ�ýṹ�����巵�أ� 
**********************************/ 
void DATA_compare(int TEMP_DATA, int HUM_DATA, struct Ma_Mi *M_ai)
 {
   	if(TEMP_DATA < M_ai->min_temp)M_ai->min_temp=TEMP_DATA;
   	if(TEMP_DATA > M_ai->max_temp)M_ai->max_temp=TEMP_DATA;
   	if(HUM_DATA < M_ai->min_hum)M_ai->min_hum=HUM_DATA;
   	if(HUM_DATA > M_ai->max_hum)M_ai->max_hum=HUM_DATA;
  }
  
