#include "main.h"

int buzz_mo=0; //�����������
//*C/F�л��������
int counta,countb;
int temp = -600, hum = -600; //�¶���ʪ�� 
uint P_A=0,Ds_P=1,SS_YX=1; //��˸��
uint LCD_delayx=0; //ģʽ�л����� 
uint low_voltage=1; //�͵�ѹ 
uint on_off=1;  //���ػ� 
 
//2S/10S����ʱ���л�
uint MODE_2S_10S;
uint CY_allow=1; //��������λ 
uint ALG_allow=1; //�㷨��������λ

//*����ʹ�ñ�������
uchar Csum=0; //����ɨ�����ݴ��� 
uint key_sampling=0,key_C_F=0; //����ʱ�䣬���ϻ����л�

//MAX/MIN���õ��ı���
uint MAI_key=1;
uint RES_temhum=0;
uint RES_delay;

//MODE�������õ��ı���
uint MOde=0;

//SET�������õ��ı���
uint TIM_mode=0;
uint TIM_clock=0;
uint TIM_time=0; 

//12/24�������õ��ı���
uint AM_PM=0;
uint am_plcd=0;

//*ʱ����������������ʼ��
uint TEN=0,MAR=0,SEC=0; //ʱ��ʱ����
uint C_TEN=0,C_MAR=0;   //����ʱ��
uint Tyear=2017,Tmoon=3,Tday=1; //��,��,��
uint week_zhi=0; //���ڼ�
uint CLK_mode=1; //����ģʽ
uint key_noperfect=0; //���������������λ 
uint key_perfect=0;   //������LCD��ʾ����λ 
uint BUZZ_degree=0;  //���������
uint BU_deg=0; //��ȫ�ر��ж�




/**********************************
 * ����: ���ػ����� 
 * ����: ��
 * ����: ��
**********************************/ 	   
void ON_OFF()
 {
  static int K=0; 
   if(TIM_mode == 0 && key_noperfect == 0)P0_INIT();
    else
    { 
       EXICON0 = 0x00; 
       EP00 = 0;}
   if(K==1 && on_off == 1)
     {
       EXICON0 = 0x00; 
       EP00 = 0;
       K=0;
       HIGH_career();
       Init_Times0();
       Init_Times2();
       LcdInit();
       WD_Feed();
       CY_allow=1;
       RES_temhum=1; 
       MAI_key=1;
       RES_delay=6;
       DSPCON  = 0x02;
       E2H = 1;
       P0_INIT();
     }
   if(on_off == 0 && K==0)
     {
      EXICON0 = 0x00; 
      EP00 = 0;
      K=1;
      IE3=0;	
      E2H = 0;
      MAI_key=1;
       MOde=0; 
       RES_temhum=0;
       LCD_delayx=0;
       RES_delay=0;	 
      DSPCON  = 0x01;  
      delayms(250, 110);
      LOW_career();
      P0_INIT();	
     }
 } 



/**********************************
 * ����: �͵�ѹ��� 
 * ����: ��
 * ����: ��
**********************************/ 
void Low_Voltage_Detect()
 {
  static int K=0,j=0; 
  if(low_voltage==1 && K==1){
  	K=0;
  	j=0;
    Init_Times0();
    Init_Times2();
    P0_INIT();
    DSPCON  = 0x02;
  }
  if(low_voltage==0){
    K=1;
    EXICON0 = 0x10; 
    EP00 = 0;
    IE3=0;
    if(j==0){LCD_empty(); j=1;}
    if(P_A == 1)P_BAT=2;
     else P_BAT=0; 
  }
 } 


/**********************************
 * ����: A/D��������(�Ż�ǰ)
 * ����: *yicu(������ɱ�־λ),*ALG_yicu�������㷨�������ݣ�,
         te(�¶Ȳ�������), hu(ʪ�Ȳ�������)
 * ����: ��
**********************************/
void Temperature(uint MAI_k,uint RES_temhum, uint *yicu, uint *ALG_yicu, int *te, int *hu)
 {
  static int k=0;

  if(k==0 && *yicu == 1 && MAI_k == 1 && RES_temhum == 0)
   {
   if(rcadc_Samp_Clk_init(rcad_three, rcad_two)==0)
    {delayms(10, 110);
    if(rcadc_radi(RCADC_A)==0) 
     if(rcadc_RCAD_run(RCADC_RUN)==0)
      k++;
     }
   } 
  if(k==1)
   {
    if(RARUN==0 && rcadc_getResult(RCADC_A, te) == 0)
     k++;
    }
  if(k==2)
   {
   if(rcadc_Samp_Clk_init(rcad_six, rcad_two)==0)
    {delayms(10, 110);
    if(rcadc_radi(RCADC_A)==0) 
     if(rcadc_RCAD_run(RCADC_RUN)==0)
      k++;
    }
   } 
  if(k==3)
   {
    if(RARUN==0 && rcadc_getResult(RCADC_A, hu) == 0)
      {k=0; *yicu = 0; *ALG_yicu=1;}
   }
}

/**********************************
 * ����: ��ʪ�ȴ���
 * ����: *ALG_yicu(�㷨������), te(�¶Ȳ�������)
 	hu(ʪ�Ȳ�������), *tem(�¶ȴ������ӿ�)
         *hue(ʪ�ȴ������ӿ�)
 * ����: ��
**********************************/
void lcd_te_hum(uint yicu, uint *ALG_yicu, int te, int hu, int *tem, int *hue)
 {
  if(*ALG_yicu == 1 && yicu == 0)
   {
     *tem = H_T(te, 172, TEMP_AT, TEMP_BT);
     *hue = H_H(hu, (*tem/10), _HUM_TEMP_ , HUM_AT, HUM_TEMP_BT, HUM_CAY);
     *hue = *hue-6; 
     if(*tem < -100 && *tem > 600)*tem = -600;
      if(*hue < 10 && *hue > 99)*hue = -600;
     *ALG_yicu = 0;
     rcadc_Samp_Clk_init(rcad_three, rcad_one);
   }
 }
 

/**********************************
 * ����: ��ʪ�Ȳ���ʱ���趨 
 * ����: delay_mode(���ò���ʱ��), *yicu(��������λ)��
          ALG_yicu(�㷨����λ) 
 * ����: ��
**********************************/
 void ADC_delay(uint delay_mode, uint *yicu, uint ALG_yicu)
  {
  	static int y=16;
  	if(delay_mode == 0 && *yicu == 0)  //2S��ʱ���� 
  	 {
 	  y=20; 
 	  *yicu=1;
           }
    else if(delay_mode == 1 && *yicu == 0) 
     { 
        y--;	
        if(y==0){y=16; *yicu=1;}	
     } 
  } 


/**********************************
 * ����: ��˸��ʱ���� 
 * ����: K_s(����λ) ��*S_P(��˸λ)  
 * ����: �� 
**********************************/ 
void CLKMODE_tim(uint K_s, uint *S_P)
 {
     static int i=0; 
      if(K_s == 0)i=0;
        else if(K_s == 1)
         {
  	 i++;
    	 if(i==1)*S_P=0;
    	 if(i==2){*S_P=1; i=0;}  	 	
  	}
 }
 
/**********************************
 * ����: ��˸��ʱ���� 
 * ����: KEY_L(���������ж�)   
 * ����: �� 
**********************************/   
void CLKMODE_delay(uchar KEY_L, uint *S_P, uint *K_s)
 {
   static int k=50,i=0;
    if(KEY_L == 0x08)
	  {
	    k=45;*S_P = 1;*K_s=0;i=0;	 
	  }	 
     if(KEY_L != 0x08) 
      {
        if(--k == 0)
      	 {
           k=1;
           *K_s=1;
          }
        if(KEY_L == 0x04){k=1;*K_s=1; } 
      }
 }
 
 


/**********************************
 * ����: C/F�����л����� 
 * ����: *MA(�����Сֵ�ṹ��)
 * ����: ��
**********************************/
void key_cytime(struct Ma_Mi *MA)
 {
  
   if(key_C_F == 0)
    {
      int zhi=-600;
      PICK_dataCOR(key_C_F);
      zhi = C_FCUTOVER(temp, key_C_F);
      UI_TEMP_HUM(P_A , zhi, hum, MA, MAI_key, RES_temhum, key_C_F);
     }
   else if(key_C_F == 1)
     {
      PICK_dataCOR(key_C_F);
      UI_TEMP_HUM(P_A , temp, hum, MA, MAI_key, RES_temhum, key_C_F);
     }
 }

/**********************************
 * ����: ����MODE  
 * ����: *K_mod(����ʱ���л�)��*lcd_delay(��ʾ��ʱ)
         K_tim(������������λ)  
 * ����: ��
**********************************/
void key_MODE(uint *K_mod, uint *lcd_delay, uint K_tim)
 {
  static int k = 0;
   if(KEY_close(KEY_0) == key_close_yes) 
    if(++k <= 2)
      {
          
       if(K_tim == 0)
          {
           if(key_noperfect == 0)key_buzz();
         if(key_noperfect == 0 || BUZZ_degree == 5)
	      {
	        *K_mod= !*K_mod;
                  *lcd_delay=20; 
	       }
          else if(BUZZ_degree != 5) BUzz_keyjudper(&key_noperfect, &BUZZ_degree);
    	   }
        
      }
     if(cont == 0x00) k=0;
 }


/**********************************
 * ����: ����SET  
 * ����: *Tim_m(������ʱ�����ñ�־λ), 
         *Tim_c(����ģʽ��־λ), 
         *Tim_t(ʱ��ģʽ��־λ), 
   	*K_mod(��/ʱ����ʾ��־λ), 
	*MAI_Ke(�����С��ʾ��־λ)
 	*lcd_delay(LCD��ʱ)
 * ����: ��
**********************************/
void key_SET(uint *Tim_m, uint *Tim_c, uint *Tim_t, uint *K_mod, uint *MAI_Ke, uint *lcd_delay)
 {
  static int k = 0, lock = 0, Bu_k = 0;
   if(KEY_close(KEY_2) == key_close_yes) 
    if(++k <= 1)
      {
   	   if(key_noperfect == 0)key_buzz();
       if(key_perfect == 0)
       {
       *lcd_delay=120;
        if(*Tim_m == 0)lock = 1;
        if(*Tim_m == 1){*Tim_c=*Tim_c+1; if(*Tim_c == 4){*Tim_c=0;*Tim_m=0;} }
        if(*Tim_m == 2){*Tim_t=*Tim_t+1; if(*Tim_t == 6){*Tim_t=0;*Tim_m=0;} }
       }
      else 
        {
          BUzz_keyjudnop(&CLK_mode, &key_perfect, &key_noperfect, &BUZZ_degree, &BU_deg);
          Bu_k = 1;	
         }
      }
   if(KEY_long(KEY_2) == key_close_yes)
     if(*Tim_m == 0 && Bu_k == 0 && ++k <= 1) //�������� 
      {
        *lcd_delay=120;
        key_buzz();
        lock = 0;
        *Tim_m=2;
        *Tim_t=1;
        *K_mod=0; 
        *MAI_Ke=1;
      }
    if(Cont == 0 && lock == 1 && Bu_k == 0) //�̰����� 
     {
       lock = 0;
       *K_mod=0; 
       *MAI_Ke=1;
      if(*Tim_m == 0){*Tim_m=1;} 
       if(*Tim_m == 1) {*Tim_c=*Tim_c+1;}	
        if(*Tim_m == 2) {*Tim_c=0; *Tim_t=*Tim_t+1;} 
     }
     if(cont == 0x00){ k=0; Bu_k=0;}
  }
                                   
/**********************************
 * ����: ����12/24  
 * ����: *Keyhour_mode(12/24Сʱ���л�)�� key_mod(����ʾ����λ)
         Tim_mod(����/��ʱ����������λ) 
 * ����: ��
**********************************/
void key_12_24(uint *Keyhour_mode, uint key_mod, uint Tim_mod)
 {
  static int k = 0;
   if(KEY_close(KEY_1) == key_close_yes) 
    if(++k <= 2)
      {
      	if(key_mod == 0 && Tim_mod == 0) 
      	 {
 	      	if(key_noperfect == 0)key_buzz();
 	      	*Keyhour_mode = !*Keyhour_mode;
           }
      }

     if(cont == 0x00) k=0;
 }

/**********************************
 * ����: 12Сʱ�ƣ����������жϺ��� 
 * ����:  tiem_S(ʱ�����ݽӿ�)�� *ap_m(�жϱ�־λ)
 * ����: ��
**********************************/ 
void AP_Mjudge(uint tiem_S, uint *ap_m) 
 {
 	if(tiem_S < 12)*ap_m=1;
 	 else if(tiem_S >= 12)*ap_m=2;
 }

/**********************************
 * ����: ����MAX/MIN  
 * ����: *MAI_Ke(�����С��ʾ�л�)��*RES_temhum(��������λ) 
          *lcd_delay(��ʾ��ʱ����), *res_delay(��ʾ��ʱ)
		  Tim_m(������ʱ�����ñ�־λ)
		  Tim_c((����ģʽ��־λ), Tim_t(ʱ��ģʽ��־λ)
 * ����: ��
**********************************/
void key_MAX_MIN(uint *MAI_Ke, uint *RES_temhum, uint *lcd_delay, uint *res_delay, uint Tim_m, uint Tim_c, uint Tim_t)
 {
  static int k = 0,i = 0, Bu_k = 0, lock = 0;
   if(KEY_close(KEY_3) == key_close_yes) //�̰� 
    if(++k <= 2)
      {
      	 if(key_noperfect == 0)key_buzz();
         if(key_perfect == 0 || BUZZ_degree == 5)
		  {
		    if(Tim_m == 0)lock = 1;
            if(Tim_m != 0){*lcd_delay=120; keyMAI_var(Tim_m, Tim_c, Tim_t, &week_zhi); }
		   }
          else if(BUZZ_degree != 5)
		  {
	        BUzz_keyjudnop(&CLK_mode, &key_perfect, &key_noperfect, &BUZZ_degree, &BU_deg);
            Bu_k = 1;	
          }
      }
   if(KEY_long(KEY_3) == key_close_yes) //���� 
     if(Bu_k == 0 && ++k <= 1)
      {
        lock = 0;
        if(Tim_m == 0)
         {
       	   key_buzz();
       	   *lcd_delay=20;
             *res_delay=6;
             *RES_temhum=1; 
             MAI_key=1;
         }
       if(Tim_m != 0)
        { 
          if(++i>=2) {*lcd_delay=120; keyMAI_var(Tim_m, Tim_c, Tim_t, &week_zhi);i=0; } //������ʱ
          k=0;  
        }
      }
     if(lock == 1 && Bu_k == 0 && Cont == 0)
      {
        lock = 0; 
        *lcd_delay=20;
        *MAI_Ke=*MAI_Ke+1; 
        if(*MAI_Ke == 4)*MAI_Ke=1;
        MAX_MIN_realtime(1, *MAI_Ke);
       }
     if(cont == 0x00){ k=0; Bu_k=0;} 
  }



/**********************************
 * ����: MAX/MIN�ӹ��ܺ��� 
 * ����:  Tim_m(������ʱ�����ñ�־λ)
		  Tim_c((����ģʽ��־λ), Tim_t(ʱ��ģʽ��־λ)
 * ����: ��
**********************************/
  void keyMAI_var(uint Tim_m, uint Tim_c, uint Tim_t, uint *weeK)
   {
  switch(Tim_m)
    {
      case 1:
       {
 	    switch(Tim_c)
   	      {  
   	         case  1: {var_mode(&C_TEN, 23, 0); if(CLK_mode == 1)CLK_mode=2; break;}
   	         case  2: {var_mode(&C_MAR, 59, 0); if(CLK_mode == 1)CLK_mode=2; break;}
   	         case  3: {var_mode(&CLK_mode, 3, 1); break;} 
   	       } 
   	       break;
   	   }
      case 2:
       {
       	switch(Tim_t) 
       	 { 
         case 1:
       	  {
   	  	   Tyear++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1); break;
          }
         case 2:
          {
   	  	   Tmoon++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1); break;        	
          }
         case 3:
          {
   	  	   Tday++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1); break;         	
          }
         case 4: {var_mode(&TEN, 23, 0); break; }
         case 5: {var_mode(&MAR, 59, 0); SEC=0; break; }
         } 
         break; 
       }
    }
   } 

   
 


/**********************************
 * ����: �꣬ʱ�ӣ����ӹ��ܺ���  
 * ����: *K_mod(����ʱ���л�)��mode_12_24(12/24�л���־λ),
          ap_m(���磬�����־λ), K_tim(��ʾ��������λ)  
 * ����: ��
**********************************/ 
void LCD_year_time(uint K_mod,uint mode_12_24, uint ap_m, uint K_tim)
 {
  switch(K_tim)
   {
    case 0://������ 
    {
     UI_MODA(2); 
     AP_Mjudge(TEN, &am_plcd);
     UI_YE(Tyear, K_mod, 1);
     UI_all_CLMON(week_zhi, 0, 2);
     UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
     switch(K_mod)
     {
   	  case 0:
	   {
   	    UI_TIME(TEN, MAR, mode_12_24, 1, 1);
	    UI_AIS_APM(K_tim, ap_m, mode_12_24);
	    UI_P(P_A, 3); break;
   	   }
	  case 1:
	   { 
	    UI_AIS_APM(K_tim, 0, 0);
        UI_P(P_A, 2); break;
   	   }
      }	
      break;
    }
   case 1: //�������ý��� 
     {  
        AP_Mjudge(C_TEN, &am_plcd);
        UI_MODA(K_tim);
        UI_YE(Tyear, 0, Ds_P);
        UI_all_CLMON(1, CLK_mode, K_tim);
        UI_AIS_APM(K_tim, ap_m , mode_12_24);
	  	if(TIM_clock == 1 || TIM_clock == 2 || TIM_clock == 3)
	    {
	  	  if(TIM_clock == 1 || TIM_clock == 2)	
	  	   {
	  	   	 if(TIM_clock == 1)UI_TIME(C_TEN, C_MAR, mode_12_24, 2, Ds_P); 
	  	   	 if(TIM_clock == 2)UI_TIME(C_TEN, C_MAR, mode_12_24, 3, Ds_P);
	   	  	 CIK_glint(1, CLK_mode);
	   	   }
	   	   else {
	             UI_TIME(C_TEN, C_MAR, mode_12_24, 1, Ds_P);
		         CIK_glint(Ds_P, CLK_mode);    	   	
	   	     }
  		 } 
  	   UI_P(Ds_P, 1); break;
        }	
    case 2: //ʱ�����ý��� 
     { 
       AP_Mjudge(TEN, &am_plcd);
       UI_MODA(K_tim);
       UI_all_CLMON(week_zhi, 0, K_tim);
	  if(TIM_time == 1 || TIM_time == 2 || TIM_time == 3) 
	     {
	 	if(TIM_time == 1){
	       UI_YE(Tyear, 2, Ds_P);
	       UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
		 }
	    if(TIM_time == 2 || TIM_time == 3)
	     {
	   	  if(TIM_time == 2)UI_YE(Tyear, 1, Ds_P);
	   	  if(TIM_time == 3)UI_YE(Tyear, 1, P_A);
	   	  UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);    	
	     }
	 	UI_AIS_APM(K_tim, 0 , 0);
	 	UI_P(Ds_P, 2);
	 }
	 if(TIM_time == 4 || TIM_time == 5)
	  {
	  	 if(TIM_time == 4)
	      {UI_YE(Tyear, 0, P_A);
	       UI_YEAR_TIME(P_A, 0, 0, Tmoon, Tday);
		   UI_TIME(TEN, MAR, mode_12_24, 2, Ds_P);}
	  	 if(TIM_time == 5)
		   {UI_YE(Tyear, 0, Ds_P);
		    UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
		    UI_TIME(TEN, MAR, mode_12_24, 3, Ds_P);}
	 	 UI_AIS_APM(K_tim, ap_m , mode_12_24);
	  	 UI_P(Ds_P, 1);
	  }
	  break;	 
     } 
   }
}


/**********************************
 * ����: ��ʪ�������������Сֵ��ʾ��ʱ 
 * ����: *MAI_Ke(�����С��ʾ�л�)��*K_mod(����ʱ����ʾ�л�),*RES_temhum(��������λ) 
         *delay(��ʾ��ʱ����), *R_delay(��λ��ʾ��ʱ)
 * ����: ��
**********************************/  
void MAI_LDCdelay(uint *MAI_Ke, uint *K_mod, uint *RES_temhum, uint *delay, uint *R_delay)
 {
    if(*MAI_Ke != 1 || *K_mod == 1) 
     {
   	*delay=*delay-1;
   	if(*delay==0){*MAI_Ke = 1; *K_mod = 0;}
     }
    if(*RES_temhum == 1)
     {
       	*R_delay=*R_delay-1;
       	if(*R_delay==0) {*RES_temhum = 0;}
     }
 }

/**********************************
 * ����: ���ӣ�ʱ�����÷��ؽ�����ʱ 
 * ����: *TIM_m(������ʱ�������ж�)��*TIM_c(���������ж�) 
         *TIM_t(ʱ�������ж�)��*delay(��ʾ��ʱ)
 * ����: �� 
**********************************/ 
void TIME_CLK_LCDmode(uint *TIM_m, uint *TIM_c, uint *TIM_t, uint *delay) 
  {
  	if(*TIM_m != 0 && Cont == 0x00)
     {
     	*delay = *delay - 1;
     	if(*delay == 0){*TIM_m = 0; *TIM_c = 0; *TIM_t = 0;}
     }
  }


/**********************************
 * ����: ���ֵ��Сֵ�����븴λ 
 * ����:  AL_yic(�㷨����ӿ�)
          *RES_temhum(��������λ), *Ma_i(�����Сֵ�ṹ��), 
          TEmp(�¶Ƚӿ�), HUm(ʪ�Ƚӿ�) 
 * ����: ��
**********************************/ 
struct Ma_Mi MAXI_mode(uint AL_yic, uint *RES_temhum, struct Ma_Mi Ma_i, int TEmp, int HUm)
  {
  	static int k=1;
	  if(k == 1 && AL_yic == 0) {k=0; DATA_INT(temp, hum, &Ma_i);} 
	  if(k== 0 && *RES_temhum == 1) DATA_INT(temp, hum, &Ma_i);
	  if(k== 0 && *RES_temhum == 0) DATA_compare(temp, hum, &Ma_i);
          return Ma_i;
  }

/**********************************
 * ����: ���ӹ��ܺ��� 
 * ����: CLK_MO(����ģʽ�ӿ�), 
         key_per(����LCD�رսӿ�)p_s(��˸��)  
 * ����: ��
**********************************/  
void CLK_BUzzLCD(uint CLK_MO, uint key_per, uint p_s)
 {
   if(key_per == 0)
    { 
   	switch(CLK_MO) 
   	 {
 	  case 1: UI_BUZZ(1, 0);break;
	  case 2: case 3: UI_BUZZ(1, 1);break; 	
     }
    }
   if(key_per == 1)
    {
      UI_BUZZ(p_s, key_per);	
    } 
 }
 
/**********************************
 * ����: �������봦���� 
 * ����: MIAO(��ӿ�), P(��˸�ӿ�)
 * ����: ��
**********************************/ 
void alarm_MIAOTIM(uint MIAO, uint P)
 {
  static int K=0;
    if(P == 0)
     {
      if(K==0)
      {
      K=1;
      if(MIAO <= 10){ BUZZ_mode(1, &buzz_mo); }  
      if(MIAO > 10 && MIAO <= 20){BUZZ_mode(2, &buzz_mo);  }
      if(MIAO > 20 && MIAO <= 30){BUZZ_mode(4, &buzz_mo);  }
      if(MIAO > 30) M0RUN=1;
      } 
     }
    else K=0;
 }

/**********************************
 * ����: ���Ӵ����� 
 * ����: CLK_mo(����ģʽ), BUZZ_freq(���Ӵ���)��P(��˸�ӿ�) 
 * ����: ��
**********************************/ 
void BUzz_CLKfun(uint BUZZ_freq, uint P)
 {
 	uint sum0=0,sum1=0,sum2=0,sum3=0; 
 	switch(BUZZ_freq)
 	 {
 	 	case 0: //0���ж� 
 	 	 { sum0=0; break; }
 	 	case 1:
 	 	 { sum0=5; break; }
 	 	case 2:
 	 	 { sum0=10; break; } 					
 	 	case 3:
 	 	 { sum0=15; break; } 
 	 	case 4:
 	 	 { sum0=20; break; } 
 	          case 5:
 	 	 { sum0=25; break; }  
 	  }
 	 	   CLK_BUzzLCD(CLK_mode, key_perfect, P);
 	 	   sum1=TIME_ALG(TEN, MAR);
 	 	   sum2=BUzz_CLKzhi(C_MAR, sum0);
 	 	   sum3=TIME_ALG(C_TEN, sum2);
 	 	   CLK_time(sum1, sum3, CLK_mode, TIM_mode, &key_perfect, &key_noperfect, &BU_deg);
                  if(key_noperfect == 1)
                    {	
          	  if(sum1-sum3 == 2)
		   { BUzz_keyjudnop(&CLK_mode, &key_perfect, &key_noperfect, &BUZZ_degree, &BU_deg); M0RUN=0;}
	            else if(sum1-sum3 < 1) {  alarm_MIAOTIM(SEC, P);	}   
                    }
  }

/**********************************
 * ����: ����ģ��
 * ����: ��
 * ����: ��
**********************************/
void key_module()
 {
   key_MODE(&MOde, &LCD_delayx, TIM_mode);
   key_SET(&TIM_mode, &TIM_clock, &TIM_time, &MOde, &MAI_key, &LCD_delayx);
   key_12_24(&AM_PM, MOde, TIM_mode);
   key_MAX_MIN(&MAI_key, &RES_temhum, &LCD_delayx, &RES_delay, TIM_mode, TIM_clock, TIM_time);
 }

void main()
 {
 struct Ma_Mi data_COM;
 HIGH_career();  //ʱ��ģʽ������ɺ�����ʼ��
 WDTMOD = 0x03; // ����ι�� 8ms
     
     MelodyInit();
     Init_Times0();
     LcdInit(); 
     Temperature3_gathering();
     Temperature4_gathering();
     P0_INIT();  
     P5_INIT();
     __EI();      //�������ж�
     BUZZ_mode(3, &buzz_mo);
     DSPCON  = 0x02;
     E2H = 1;      //ʹ��T2HZ�ж�
     QP04=1;
   
  while(1)
   {     
    WD_Feed();
    ON_OFF();
    Low_Voltage_Detect();
   if(on_off == 1 && low_voltage == 1)
    {
     /*Temperature(MAI_key, RES_temhum, &CY_allow, &ALG_allow , &counta, &countb);
     lcd_te_hum(CY_allow, &ALG_allow, counta, countb, &temp, &hum);
     data_COM = MAXI_mode(ALG_allow, &RES_temhum, data_COM, temp, hum);
     key_cytime(&data_COM);
     week_zhi = calendar_treat(&Tyear, &Tmoon, &Tday, 0);
     LCD_year_time(MOde, AM_PM, am_plcd, TIM_mode);
     BUzz_CLKfun(BUZZ_degree, P_A);
     key_module();
     KEY_delay();
     KeyRead(Csum, &Trg, &Cont);*/
     
    }

   }
 }


#pragma interrupt T2HZInt T2HINT  2  //���Ź���ʱ��500ms ����Ϊ2, �����жϱ������жϴ��
static void T2HZInt(void)
{
    
    static uint clock=0;	
   __EI();  //�����жϱ������жϴ��
    clock++;
    if(clock==1)P_A=1;
    if(clock==2){P_A=0; SEC++;}
    if(clock==2)clock=0;
    time_CLK(&Tday, &TEN, &MAR, &SEC);
    CLKMODE_tim(SS_YX, &Ds_P);
    TIME_CLK_LCDmode(&TIM_mode, &TIM_clock, &TIM_time, &LCD_delayx);
    ADC_delay(key_sampling, &CY_allow, ALG_allow);
    MAI_LDCdelay(&MAI_key, &MOde, &RES_temhum, &LCD_delayx, &RES_delay);
}

#pragma interrupt P00int  P00INT  2  //���ػ��ж�
static void P00int(void)
{
   EXICON0 = 0x00; 
   EP00 = 0;
   HIGH_career();
   delayms(50, 110);
   key_buzz();
   KEY_delay();
   if(on_off ==1)on_off=0;
    else if(on_off ==0)on_off=1;
  P0_INIT();
 

}

#pragma interrupt P04int  P04INT  2 //�͵�ѹ�ж�
static void P04int(void)
{
 //low_voltage = !low_voltage;
  if(P04D == 0)low_voltage=0;
   else if(P04D == 1) low_voltage=1; 
}


#pragma interrupt TM3int  TM3INT  2 //�������ж�
static void TM3int(void)
{
  __EI();  //�����жϱ������жϴ��
  IE5 = 0;
  TM2CON1 = 0;
  TM2D = 0; 
  TM3D = 0;
  BUZZ_int(buzz_mo);
}


#pragma interrupt TM1int  TM1INT  2 //����ɨ���ж�
static void TM1int(void)
 {
  static int lay = 0;
   unsigned int kp = 0;
  __EI();  //�����жϱ������жϴ��
  IE3 = 0;  
  TM0CON1 = 0;
  KEY_scan( &Trg, &Cont, &cont, &Csum);	
  KEY_independent();
  KEY_indepen_scan( &key_sampling, &key_C_F);
  Init_Times0();
  CLKMODE_delay(Cont, &Ds_P, &SS_YX);
}
