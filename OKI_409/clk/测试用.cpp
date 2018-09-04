#include<stdio.h>

//模式枚举通用 
enum CLKmode_value {
 CLK_one=0,CLK_two=1,CLK_three=2,CLK_four=3
};

#define SYSC_MODE (4) //系统时钟和外围电路（包括高速时间基准计数器）选择高速时钟
#define OUT_MODE  (4) // OUTC1和OUTC0位用来选择高速输出时钟的频率。 

#define CLK_DEPLOY_OK   (0) //成功 
#define CLK_DEPLOY_FAIL (-1)//失败 

//FCON0
#define OSCM_500KMZ  (0) //500 kHz的振荡被选中
#define OSCM_2MHZ    (1) //2  MHz的振荡被选中

//FCON1
#define SYSCLK_LSCLK (0) //低速时钟 
#define SYSCLK_HSCLK (1) //高速时钟 

#define ENO_STOP_HIGHCLK    (0) //禁用高速时钟 
#define ENO_ENABLES_HIGHCLK (1) //使能高速时钟 

#define ENM_DISABLES_LOWCLK (0) //禁用2*低速时钟 
#define ENM_ENABLES_LOWCLK  (1) //使能2*低速时钟 

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
int clk_init(unsigned int sysc, unsigned int outc, unsigned int oscm)
 {
  unsigned char r0,r1,FCON0,OSCM2;
   if(sysc >= SYSC_MODE || outc >= OUT_MODE || oscm > OSCM_2MHZ) {
    return (CLK_DEPLOY_FAIL);
    }
  
   r0 = SYSC_MODE_CLK[sysc];
   r1 = OUTC_MODE_CLK[outc];
   FCON0 = (unsigned char)((r0 << 0) |
                           (r1 << 4) );
     printf("FCON0=%d\n", FCON0);
    OSCM2 = oscm;
     printf("OSCM2=%d\n", OSCM2);
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
   unsigned int r0,r1,r2,FCON1;
    if(syscl > SYSCLK_HSCLK || enos > ENO_ENABLES_HIGHCLK || 
	   enml > ENM_ENABLES_LOWCLK) {
   	 return (CLK_DEPLOY_FAIL);	
   	 }	
   r0 = syscl;
   r1 = enos;
   r2 = enml;
   FCON1 = (unsigned char)((r0 << 0) | (r1 << 1) |
                                       (r2 << 2) );
   printf("FCON1=%d", FCON1);
   return (CLK_DEPLOY_OK);
  }

 
/*********************************
 * 功能: 按键(蜂鸣器)
 * 参数: 无
 * 返回: 无
**********************************/
void key_buzz()
 {

   MD0TMP = 0x03; // 配置蜂鸣器模式
   M0RUN = 1; // 开启蜂鸣器	
  } 
  
/*********************************
 * 功能: 开机，闹钟（蜂鸣器） 
 * 参数: 无
 * 返回: 无
**********************************/  
void ON_clk_buzz(uint del, uint *delay)
 {
   MD0TMP = 0x00; // 配置蜂鸣器模式
   M0RUN=1;  // 开启蜂鸣器
   *delay=del; 
  }  
  

  
void BUZZ_delay(uint delay)
 {
  int K; 
  if(M0RUN==1) 
   for(K=delay;K>0;K--)
    {
      if(K==1)M0RUN=0;	
    }
 }
  
int main()
 {
 	int k=2;
 	k=clk_init(CLK_two, CLK_four, OSCM_2MHZ);
 	printf("k=%d\n", k);
 	k=1;
 	k=k<<1;
 	printf("k=%d\n", k);
 	clk_fcon1_init(SYSCLK_HSCLK, ENO_ENABLES_HIGHCLK, ENM_ENABLES_LOWCLK);
 	getchar();
  }
  


/**********************************
 * 功能: 按键MODE  
 * 参数: *K_mod(年与时钟切换)，*lcd_delay(显示延时)
         K_tim(按键功能允许位)  
 * 返回: 无
**********************************/
void key_MODE(uint *K_mod, uint *lcd_delay, uint K_tim)
 {
  static int k = 0;
   if(KEY_close(KEY_0) == key_close_yes) 
    if(++k <= 2)
      {
          
          if(K_tim == 0)
  	   {
               BUZZ_mode(1, &buzz_mo);
               *K_mod= !*K_mod;
               *lcd_delay=20; 
    	   }
        
      }
     if(cont == 0x00) k=0;
 }


/**********************************
 * 功能: 按键SET  
 * 参数: *Tim_m(闹钟与时钟设置标志位), 
         *Tim_c(闹钟模式标志位), 
         *Tim_t(时钟模式标志位), 
   	*K_mod(年/时钟显示标志位), 
	*MAI_Ke(最大最小显示标志位)
 	*lcd_delay(LCD延时)
 * 返回: 无
**********************************/
void key_SET(uint *Tim_m, uint *Tim_c, uint *Tim_t, uint *K_mod, uint *MAI_Ke, uint *lcd_delay)
 {
  static int k = 0, lock = 0;
   if(KEY_close(KEY_2) == key_close_yes) 
    if(++k <= 2)
      {
        *lcd_delay=120;
        BUZZ_mode(1, &buzz_mo);
        if(*Tim_m == 0)lock = 1;
        if(*Tim_m == 1){*Tim_c=*Tim_c+1; if(*Tim_c == 4){*Tim_c=0;*Tim_m=0;} }
        if(*Tim_m == 2){*Tim_t=*Tim_t+1; if(*Tim_t == 6){*Tim_t=0;*Tim_m=0;} }
      }
   if(KEY_long(KEY_2) == key_close_yes)
     if(*Tim_m == 0 && ++k <= 2) //长按功能 
      {
        *lcd_delay=120;
        BUZZ_mode(1, &buzz_mo);
        lock = 0;
        *Tim_m=2;
        *Tim_t=1;
        *K_mod=0; 
        *MAI_Ke=1;
      }
    if(lock == 1 && Cont == 0) //短按功能 
     {
       lock = 0;
       *K_mod=0; 
       *MAI_Ke=1;
	   if(*Tim_m == 0){*Tim_m=1;} 
	    if(*Tim_m == 1) {*Tim_c=*Tim_c+1;}	
        if(*Tim_m == 2)
		 { *Tim_c=0; *Tim_t=*Tim_t+1; } 
     }
     if(cont == 0x00) k=0;
  }

                                   
/**********************************
 * 功能: 按键12/24  
 * 参数: *Keyhour_mode(12/24小时制切换)， key_mod(年显示允许位)
         Tim_mod(闹钟/年时钟设置允许位) 
 * 返回: 无
**********************************/
void key_12_24(uint *Keyhour_mode, uint key_mod, uint Tim_mod)
 {
  static int k = 0;
   if(KEY_close(KEY_1) == key_close_yes) 
    if(++k <= 2)
      {
      	if(key_mod == 0 && Tim_mod == 0) 
      	 {
 	      	if(key_noperfect == 0)BUZZ_mode(1, &buzz_mo);
 	      	*Keyhour_mode = !*Keyhour_mode;
           }
      }

     if(cont == 0x00) k=0;
 }

/**********************************
 * 功能: 按键MAX/MIN  
 * 参数: *MAI_Ke(最大最小显示切换)，*RES_temhum(清零允许位) 
          *lcd_delay(显示延时数据), *res_delay(显示延时)
		  Tim_m(闹钟与时钟设置标志位)
		  Tim_c((闹钟模式标志位), Tim_t(时钟模式标志位)
 * 返回: 无
**********************************/
void key_MAX_MIN(uint *MAI_Ke, uint *RES_temhum, uint *lcd_delay, uint *res_delay, uint Tim_m, uint Tim_c, uint Tim_t)
 {
  static int k = 0,i = 0, Bu_k = 0, lock = 0;
   if(KEY_close(KEY_3) == key_close_yes) 
    if(++k <= 2)
      {
         BUZZ_mode(1, &buzz_mo);
         if(Tim_m == 0)lock = 1;
         if(Tim_m != 0){*lcd_delay=120; keyMAI_var(Tim_m, Tim_c, Tim_t, &week_zhi); }
      }
   if(KEY_long(KEY_3) == key_close_yes)
     if(++k <= 2)
      {
        lock = 0;
        if(Tim_m == 0)
         {
       	   BUZZ_mode(1, &buzz_mo);
       	   *lcd_delay=20;
             *res_delay=6;
             *RES_temhum=1; 
             MAI_key=1;
         }
       if(Tim_m != 0)
        { 
           if(++i>=1) {*lcd_delay=120; keyMAI_var(Tim_m, Tim_c, Tim_t, &week_zhi);i=0; } //长按延时
          k=0;  
        }
      }
     if(lock == 1 && Cont == 0)
      {
        lock = 0; 
        *lcd_delay=20;
        *MAI_Ke=*MAI_Ke+1; 
        if(*MAI_Ke == 4)*MAI_Ke=1;
        MAX_MIN_realtime(1, *MAI_Ke);
       }
     if(cont == 0x00) k=0;
  }  
  
  

/**********************************
 * 功能: MAX/MIN加功能函数 
 * 参数:  Tim_m(闹钟与时钟设置标志位)
		  Tim_c((闹钟模式标志位), Tim_t(时钟模式标志位)
 * 返回: 无
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
 * 功能: 按键SET  
 * 参数: *Tim_m(闹钟与时钟设置标志位), 
         *Tim_c(闹钟模式标志位), 
         *Tim_t(时钟模式标志位), 
   	*K_mod(年/时钟显示标志位), 
	*MAI_Ke(最大最小显示标志位)
 	*lcd_delay(LCD延时)
 * 返回: 无
**********************************/
void key_SET(uint *Tim_m, uint *Tim_c, uint *Tim_t, uint *K_mod, uint *MAI_Ke, uint *lcd_delay)
 {
  static int k = 0, lock = 0, Bu_k = 0;
   if(KEY_close(KEY_2) == key_close_yes) 
    if(++k <= 2)
      {
       if(key_perfect == 0)
	     {
     	   *lcd_delay=120;
	       BUZZ_mode(1, &buzz_mo);
         switch(*Tim_m)
         {
          case 0:{lock = 1; break;}
          case 1:{*Tim_c=*Tim_c+1; if(*Tim_c == 4){*Tim_c=0;*Tim_m=0;}  break;}
          case 2:{*Tim_t=*Tim_t+1; if(*Tim_t == 6){*Tim_t=0;*Tim_m=0;}	break;}
         }	
	    }
      else 
	     {
		  BUzz_keyjudnop(&CLK_mode, &key_perfect, &key_noperfect);
           Bu_k = 1;	
         }
	  }
   if(KEY_long(KEY_2) == key_close_yes)
     if(*Tim_m == 0 && Bu_k == 0 && ++k <= 2) //长按功能 
      {
        *lcd_delay=120;
        BUZZ_mode(1, &buzz_mo);
        lock = 0;
        *Tim_m=2;
        *Tim_t=1;
        *K_mod=0; 
        *MAI_Ke=1;
      }
    if(lock == 1 && Bu_k == 0 && Cont == 0) //短按功能 
     {
       lock = 0;
       *K_mod=0; 
       *MAI_Ke=1;
       switch(*Tim_m)
        {
        	case 1: {*Tim_c=*Tim_c+1; break;}
        	case 2: {*Tim_c=0; *Tim_t=*Tim_t+1; break;}
        }
      if(*Tim_m == 0)*Tim_m=1;
     }
     if(cont == 0x00){ k=0; Bu_k=0;}
  }
  
  
/**********************************
 * 功能: 按键MODE  
 * 参数: *K_mod(年与时钟切换)，*lcd_delay(显示延时)
         K_tim(按键功能允许位)  
 * 返回: 无
**********************************/
void key_MODE(uint *K_mod, uint *lcd_delay, uint K_tim)
 {
  static int k = 0;
   if(KEY_close(KEY_0) == key_close_yes) 
    if(++k <= 2)
      {
          
          if(K_tim == 0)
  	       {
               if(key_noperfect == 0)
			    {
				 BUZZ_mode(1, &buzz_mo);
				 *K_mod= !*K_mod;
                 *lcd_delay=20; 
			    }
                else BUzz_keyjudper(&key_noperfect, &BUZZ_degree);

    	   }
        
      }
     if(cont == 0x00) k=0;
 }
 
 
 
/**********************************
 * 功能: 按键MAX/MIN  
 * 参数: *MAI_Ke(最大最小显示切换)，*RES_temhum(清零允许位) 
          *lcd_delay(显示延时数据), *res_delay(显示延时)
		  Tim_m(闹钟与时钟设置标志位)
		  Tim_c((闹钟模式标志位), Tim_t(时钟模式标志位)
 * 返回: 无
**********************************/
void key_MAX_MIN(uint *MAI_Ke, uint *RES_temhum, uint *lcd_delay, uint *res_delay, uint Tim_m, uint Tim_c, uint Tim_t)
 {
  static int k = 0,i = 0, Bu_k = 0, lock = 0;
   if(KEY_close(KEY_3) == key_close_yes) //短按 
    if(++k <= 2)
      {
         if(key_perfect == 0)
		  {
		  	BUZZ_mode(1, &buzz_mo);
		    if(Tim_m == 0)lock = 1;
            if(Tim_m != 0){*lcd_delay=120; keyMAI_var(Tim_m, Tim_c, Tim_t, &week_zhi); }
		   }
          else 
		  {
		    BUzz_keyjudnop(&CLK_mode, &key_perfect, &key_noperfect);
            Bu_k = 1;	
          }
      }
   if(KEY_long(KEY_3) == key_close_yes) //长按 
     if(Bu_k == 0 && ++k <= 2)
      {
        lock = 0;
        if(Tim_m == 0)
         {
       	   BUZZ_mode(1, &buzz_mo);
       	   *lcd_delay=20;
             *res_delay=6;
             *RES_temhum=1; 
             MAI_key=1;
         }
       if(Tim_m != 0)
        { 
          if(++i>=4) {*lcd_delay=120; keyMAI_var(Tim_m, Tim_c, Tim_t, &week_zhi);i=0; } //长按延时
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
 * 功能: A/D采样函数(优化前)
 * 参数: *yicu(采样完成标志位),*ALG_yicu（允许算法处理数据）,
         te(温度采样数据), hu(湿度采样数据)
 * 返回: 无
**********************************/
void Temperature(uint MAI_k,uint RES_temhum, uint *yicu, uint *ALG_yicu, int *te, int *hu)
 {
  static int k=0;

  if(k==0 && *yicu == 1 && MAI_k == 1 && RES_temhum == 0)
   {
   if(rcadc_Samp_Clk_init(rcad_three, rcad_two)==0)
    {delayms(10);
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
    {delayms(10);
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
 * 功能: 年，时钟，闹钟功能函数  
 * 参数: *K_mod(年与时钟切换)，mode_12_24(12/24切换标志位),
          ap_m(上午，下午标志位), K_tim(显示功能允许位)  
 * 返回: 无
**********************************/ 
void LCD_year_time(uint K_mod,uint mode_12_24, uint ap_m, uint K_tim)
 {
  switch(K_tim)
   {
    case 0://主界面 
    {
     AP_Mjudge(TEN, &am_plcd);
     switch(K_mod)
     {
   	  case 0:
	   {
	    UI_MODA(2); 
	    UI_YE(Tyear, K_mod, 1);
   	    UI_TIME(TEN, MAR, mode_12_24, 1, 1);
	    UI_AIS_APM(K_tim, ap_m, mode_12_24);
	    UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
	    UI_all_CLMON(week_zhi, 0, 2);
	    UI_P(P_A, 3); break;
   	   }
	  case 1:
	   {
	    UI_MODA(2); 
   	    UI_YE(Tyear, K_mod, 1);
	    UI_AIS_APM(K_tim, 0, 0);
             UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
             UI_all_CLMON(week_zhi, 0, 2);
             UI_P(P_A, 2); break;
   	   }
      }	
      break;
    }
   case 1: //闹钟设置界面 
     {  
        AP_Mjudge(C_TEN, &am_plcd);
        UI_MODA(K_tim);
        UI_YE(Tyear, 0, Ds_P);
        UI_all_CLMON(1, CLK_mode, K_tim);
        UI_AIS_APM(K_tim, ap_m , mode_12_24);
      switch(TIM_clock)
        {
         case 1: 
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 2, Ds_P); 
	         CIK_glint(1, CLK_mode); break;
	      }
         case 2:
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 3, Ds_P);
	         CIK_glint(1, CLK_mode); break;
	      }
         case 3:
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 1, Ds_P);
	         CIK_glint(Ds_P, CLK_mode); break;
	      }
     	 }
  	   UI_P(Ds_P, 1); break;
        }	
    case 2: //时钟设置界面 
     { 
       AP_Mjudge(TEN, &am_plcd);
       UI_MODA(K_tim);
       UI_all_CLMON(week_zhi, 0, K_tim);
       switch(TIM_time)
        {
        case 1:
         {
	UI_YE(Tyear, 2, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
         	UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }
        case 2:
         {
         	UI_YE(Tyear, 1, Ds_P);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
	UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }       
        case 3:
         {
         	UI_YE(Tyear, 1, P_A);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
	UI_AIS_APM(K_tim, 0 , 0);
       	UI_P(Ds_P, 2); break;
         }       
        case 4:
         {
         	UI_YE(Tyear, 0, P_A);
         	UI_YEAR_TIME(P_A, 0, 0, Tmoon, Tday);
         	UI_TIME(TEN, MAR, mode_12_24, 2, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
         	UI_P(Ds_P, 1); break;
         } 
        case 5:
         {
         	UI_YE(Tyear, 0, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
       	UI_TIME(TEN, MAR, mode_12_24, 3, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
       	UI_P(Ds_P, 1); break;
         } 
        } 
	  break;	 
     } 
   }
}


/**********************************
 * 功能: A/D采样函数(优化后) 
 * 参数: *yicu(采样完成标志位),*ALG_yicu（允许算法处理数据）,
         te(温度采样数据), hu(湿度采样数据)
 * 返回: 无
**********************************/
void Temperature(uint MAI_k,uint RES_temhum, uint *yicu, uint *ALG_yicu, int *te, int *hu)
 {
  static int k=0;
  switch(k)
   {
  case 0:
   	 {
	   if(*yicu == 1 && MAI_k == 1 && RES_temhum == 0)
          {
         if(rcadc_Samp_Clk_init(rcad_three, rcad_two)==0)
          {delayms(10);
           if(rcadc_radi(RCADC_A)==0) 
           if(rcadc_RCAD_run(RCADC_RUN)==0)
           k++;
           }
         } 
      break;
     }
  case 1:
   {
    if(RARUN==0 && rcadc_getResult(RCADC_A, te) == 0)k++;
	 break; 
    }
  case 2:
   {
   if(rcadc_Samp_Clk_init(rcad_six, rcad_two)==0)
    {delayms(10);
    if(rcadc_radi(RCADC_A)==0) 
     if(rcadc_RCAD_run(RCADC_RUN)==0)k++;
    }
    break;
   } 
  case 3:
   {
    if(RARUN==0 && rcadc_getResult(RCADC_A, hu) == 0)
      {k=0; *yicu = 0; *ALG_yicu=1;}break;
   }
  }
}




/**********************************
 * 功能: 年，时钟，闹钟功能函数  
 * 参数: *K_mod(年与时钟切换)，mode_12_24(12/24切换标志位),
          ap_m(上午，下午标志位), K_tim(显示功能允许位)  
 * 返回: 无
**********************************/ 
void LCD_year_time(uint K_mod,uint mode_12_24, uint ap_m, uint K_tim)
 {
  switch(K_tim)
   {
    case 0://主界面 
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
   case 1: //闹钟设置界面 
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
    case 2: //时钟设置界面 
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





      switch(TIM_clock)
        {
         case 1: 
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 2, Ds_P); 
	         CIK_glint(1, CLK_mode); break;
	      }
         case 2:
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 3, Ds_P);
	         CIK_glint(1, CLK_mode); break;
	      }
         case 3:
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 1, Ds_P);
	         CIK_glint(Ds_P, CLK_mode); break;
	      }
     	 }

  	if(TIM_clock == 1 || TIM_clock == 2 || TIM_clock == 3)
    {
  	  if(TIM_clock == 1 || TIM_clock == 2)	
  	   {
  	   	 if(TIM_clock == 1)UI_TIME(C_TEN, C_MAR, mode_12_24, 2, Ds_P); 
  	   	 if(TIM_clock == 2)UI_TIME(C_TEN, C_MAR, mode_12_24, 3, Ds_P);
   	  	 CIK_glint(1, CLK_mode); break;
   	   }
   	   else {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 1, Ds_P);
	         CIK_glint(Ds_P, CLK_mode);    	   	
   	     }
  	 } 




















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
 	UI_P(Ds_P, 2); break;
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
  	 UI_P(Ds_P, 1); break;
  }









       switch(TIM_time)
        {
        case 1:
         {
        	UI_YE(Tyear, 2, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
         	UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }
        case 2:
         {
         	UI_YE(Tyear, 1, Ds_P);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
	        UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }       
        case 3:
         {
         	UI_YE(Tyear, 1, P_A);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
        	UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2); break;
         }       
        case 4:
         {
         	UI_YE(Tyear, 0, P_A);
         	UI_YEAR_TIME(P_A, 0, 0, Tmoon, Tday);
         	UI_TIME(TEN, MAR, mode_12_24, 2, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
         	UI_P(Ds_P, 1); break;
         } 
        case 5:
         {
         	UI_YE(Tyear, 0, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
       	UI_TIME(TEN, MAR, mode_12_24, 3, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
       	UI_P(Ds_P, 1); break;
         } 
        } 
        
        
        
        
 	switch(Buzz_X)
 	 {
 	 	case 1:{ZHI=2; break;}
 	 	case 2:{ZHI=8; break;}
 	 	case 3:{ZHI=13; break;}
 	 	case 4:{ZHI=17; break;}
 	 }
	 if(Buzz_X==1)ZHI=2;
	  else 
	   {
	    if(Buzz_X==2)ZHI=8;
	    if(Buzz_X==3)ZHI=13;
	    if(Buzz_X==4)ZHI=17;
	   }
	   
/**********************************
 * 功能: 开关机函数 
 * 参数: 无
 * 返回: 无
**********************************/ 	   
void ON_OFF()
 {
  static int K=0; 
   if(on_off == 1 && K==0)
     {
       Init_Times0();
       Init_Times2();
       LcdInit();
       WD_Feed();
       CY_allow=1;
       DSPCON  = 0x02;
       E2H = 1;
	   K=1;	
     }
   if(on_off == 0 && K==1)
     {	
      K=0;
	  E2H = 0;	 
	  temp = -600; hum = -600;
      DSPCON  = 0x01;  
     }
 } 
 
 
/**********************************
 * 功能: 低电压检测 
 * 参数: 无
 * 返回: 无
**********************************/ 
void Low_Voltage_Detect()
 {
  static int K=0; 
  if(low_voltage==1 && K==0){
  	K=1;
  	E2H = 1;
    Init_Times0();
    Init_Times2();
  	P0_INIT();
    DSPCON  = 0x02;
  }
  if(low_voltage==0 && K==1){
  	K=0;
    EXICON0 = 0x00; 
    EP00 = 0;
    E2H = 0;
    IE3=0;
  	DSPCON  = 0x03; 
  }
 } 
 
 
Clk=0      
Min_Max=0      
MonDa_Day    
AiSe                                 
Year_Out                                                                                  
year_time0  
year_time1  
year_time2   
year_time3  
carry      
Day_0        
Day_1       
Day_2      
Day_3      
Day_4     
Day_5      
Mon_Da0     
Mon_Da1     
Mon_Da2    
Mon_Da3      
Temp_0      
Temp_1    
Temp_2      
Temp_3       
Hum_0       
Hum_1     
P_BAT      
C_F_H     
Buzz  
A_PM       