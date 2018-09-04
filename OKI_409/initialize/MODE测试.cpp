int buzz_mo=0; //蜂鸣器模式传输变量
//*C/F切换与采样用
int counta,countb;
int temp = -600, hum = -600; //温度与湿度 
uint P_A=1,Ds_P=1,SS_YX=1; //闪烁用
uint LCD_delayx=0; //模式切换计数 

//2S/10S采样时间切换
uint MODE_2S_10S;
uint CY_allow=1; //采样允许位 
uint ALG_allow=1; //算法处理允许位

//*按键使用变量定义
uchar Csum=0; //按键扫描数据传输 
uint key_sampling=0,key_C_F=0; //采样时间，摄氏华氏切换

//MAX/MIN所用到的变量
uint MAI_key=1;
uint RES_temhum=0;
uint RES_delay;

//MODE按键所用到的变量
uint MOde=0;

//SET按键所用到的变量
uint TIM_mode=0;
uint TIM_clock=0;
uint TIM_time=0; 

//12/24按键所用到的变量
uint AM_PM=0;
uint am_plcd=0;

//*时钟与万年历变量初始化
uint TEN=0,MAR=0,SEC=0; //时钟时分秒
uint C_TEN=0,C_MAR=0;   //闹钟时分
uint Tyear=2017,Tmoon=3,Tday=1; //年,月,日
uint CLK_mode=1; //闹钟模式
uint week_zhi=0;
uint BUZZ_clk=0; //闹钟LCD符号显示位


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
  static int k = 0, lock = 0;
   if(KEY_close(KEY_3) == key_close_yes) 
    if(++k <= 2)
      {
         BUZZ_mode(1, &buzz_mo);
         if(Tim_m == 0)lock = 1;    
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
 * 功能: 变量调节函数 
 * 参数: *variate(需要改变的量), often_MAX（最大值）,often_MIN(最小值)
 * 返回: 无 
**********************************/  
void var_mode(int *variate, int often_MAX, int often_MIN)
 {
 	*variate=*variate+1;
	 if(*variate>often_MAX) 
	  *variate = often_MIN;
 } 
 
/**********************************
 * 功能: MAX/MIN加功能函数 
 * 参数:  Tim_m(闹钟与时钟设置标志位)
		  Tim_c((闹钟模式标志位), Tim_t(时钟模式标志位)
 * 返回: 无
**********************************/
  void keyMAI_var(uint Tim_m, uint Tim_c, uint Tim_t, uint *weeK)
   {
   	  if(Tim_m == 1)
   	   {
   	   	 if(Tim_c == 1) var_mode(&C_TEN, 23, 0);
   	   	 else if(Tim_c == 2) var_mode(&C_MAR, 59, 0);
   	   	 else if(Tim_c == 3) var_mode(&CLK_mode, 3, 1);
   	   }
      if(Tim_m == 2)
       {
       	 if(Tim_t == 1) 
       	  {
   	  	   Tyear++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1);
          }
         if(Tim_t == 2)
          {
   	  	   Tmoon++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1);          	
          }
         if(Tim_t == 3)
          {
   	  	   Tday++;
  	       *weeK = calendar_treat(&Tyear, &Tmoon, &Tday, 1);          	
          }
         if(Tim_t == 4) var_mode(&TEN, 23, 0);
         if(Tim_t == 5) var_mode(&MAR, 59, 0);
       }
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
 * 功能: 年，时钟，闹钟功能函数  
 * 参数: *K_mod(年与时钟切换)，mode_12_24(12/24切换标志位),
          ap_m(上午，下午标志位), K_tim(显示功能允许位)  
 * 返回: 无
**********************************/ 
void LCD_year_time(uint K_mod,uint mode_12_24, uint ap_m, uint K_tim)
 {
   if(K_tim == 0) //主界面 
    {
   	  AP_Mjudge(TEN, &am_plcd);
      if(K_mod == 0)
	   {
	   	 UI_MODA(2); 
	   	 UI_YE(Tyear, K_mod, 1);
   		 UI_TIME(TEN, MAR, mode_12_24, 1, 1);
                    UI_AIS_APM(K_tim, ap_m, mode_12_24);
                    UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
                    UI_all_CLMON(week_zhi, 0, 2);
                    UI_P(P_A, 3);
   	   }
	  if(K_mod == 1)
	   {
	   	 UI_MODA(2); 
   		 UI_YE(Tyear, K_mod, 1);
                    UI_AIS_APM(K_tim, 0, 0);
                    UI_YEAR_TIME(P_A, K_tim, 0, Tmoon, Tday);
                    UI_all_CLMON(week_zhi, 0, 2);
                    UI_P(P_A, 2);
   	   }	
    }
   else if(K_tim == 1) //闹钟设置界面 
     {  
        AP_Mjudge(C_TEN, &am_plcd);
        UI_MODA(K_tim);
        UI_YE(Tyear, 0, Ds_P);
        UI_all_CLMON(1, CLK_mode, K_tim);
        UI_AIS_APM(K_tim, ap_m , mode_12_24);
        if(TIM_clock == 1) 
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 2, Ds_P); 
		     CIK_glint(1, CLK_mode);
	      }
        if(TIM_clock == 2)
          {
             UI_TIME(C_TEN, C_MAR, mode_12_24, 3, Ds_P);
		     CIK_glint(1, CLK_mode);
	      }
        if(TIM_clock == 3)
          {
		     UI_TIME(C_TEN, C_MAR, mode_12_24, 1, Ds_P);
		     CIK_glint(Ds_P, CLK_mode);
	      }
   	      UI_P(Ds_P, 1);
	 }	
   else if(K_tim == 2) //时钟设置界面 
     { 
        AP_Mjudge(TEN, &am_plcd);
        UI_MODA(K_tim);
        UI_all_CLMON(week_zhi, 0, K_tim);
        if(TIM_time == 1)
         {
   	        UI_YE(Tyear, 2, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
         	UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2);
         }
        if(TIM_time == 2)
         {
         	UI_YE(Tyear, 1, Ds_P);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
		    UI_AIS_APM(K_tim, 0 , 0);
         	UI_P(Ds_P, 2);
         }       
        if(TIM_time == 3)
         {
         	UI_YE(Tyear, 1, P_A);
         	UI_YEAR_TIME(Ds_P, K_tim, TIM_time, Tmoon, Tday);
		    UI_AIS_APM(K_tim, 0 , 0);
       	    UI_P(Ds_P, 2);
         }       
        if(TIM_time == 4)
         {
         	UI_YE(Tyear, 0, P_A);
         	UI_YEAR_TIME(P_A, 0, 0, Tmoon, Tday);
         	UI_TIME(TEN, MAR, mode_12_24, 2, Ds_P);
         	UI_AIS_APM(K_tim, ap_m , mode_12_24);
         	UI_P(Ds_P, 1);
         } 
        if(TIM_time == 5)
         {
         	UI_YE(Tyear, 0, Ds_P);
         	UI_YEAR_TIME(Ds_P, 0, 0, Tmoon, Tday);
       	    UI_TIME(TEN, MAR, mode_12_24, 3, Ds_P);
       	    UI_AIS_APM(K_tim, ap_m , mode_12_24);
       	    UI_P(Ds_P, 1);
         }   
    } 
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
   if(KEY_close(KEY_2) == key_close_yes) 
    if(++k <= 2)
      {
      	if(key_mod == 0 && Tim_mod == 0) 
      	 {
 	      	BUZZ_mode(1, &buzz_mo);
 	      	*Keyhour_mode = !*Keyhour_mode;
         }
      }

     if(cont == 0x00) k=0;
 }
 

/**********************************
 * 功能: 12小时制，早上下午判断函数 
 * 参数:  tiem_S(时钟数据接口)， *ap_m(判断标志位)
 * 返回: 无
**********************************/ 
void AP_Mjudge(uint tiem_S, uint *ap_m) 
 {
 	if(tiem_S < 12)*ap_m=1;
 	 else if(tiem_S > 12)*ap_m=2;
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
 * 返回: 无
**********************************/
void key_SET(uint *Tim_m, uint *Tim_c, uint *Tim_t, uint *K_mod, uint *MAI_Ke)
 {
  static int k = 0, lock = 0;
   if(KEY_close(KEY_2) == key_close_yes) 
    if(++k <= 2)
      {
        BUZZ_mode(1, &buzz_mo);
        if(*Tim_m == 0)lock = 1;
        if(*Tim_m == 1){*Tim_c=*Tim_c+1; if(*Tim_c == 4){*Tim_c=0;*Tim_m=0;} }
        if(*Tim_m == 2){*Tim_t=*Tim_t+1; if(*Tim_t == 6){*Tim_t=0;*Tim_m=0;}	}
      }
   if(KEY_long(KEY_2) == key_close_yes)
     if(*Tim_m == 0 && ++k <= 2) //长按功能 
      {
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
	   if(*Tim_m == 0)*Tim_m=1; 
	    if(*Tim_m == 1) 
		  *Tim_c=*Tim_c+1;	

        if(*Tim_m == 2)
		 {
 		   *Tim_c=0;
		   *Tim_t=*Tim_t+1;
 		  } 
     }
     if(cont == 0x00) k=0;
  }
  
  
  
/**********************************
 * 功能: 时钟计时函数 
 * 参数: day(日),shi(时),fen(分),miao(秒)
 * 返回: 无 
**********************************/ 
void time_CLK(int *day, int *shi, int *fen, int *miao) 
 {
      if(*miao > 59){ *miao=0; *fen++;}
	  if(*fen > 59) { *fen=0; *shi++; }
	  if(*shi > 23) { *shi=0; *day++; }	
 }
 
 
/**********************************
 * 功能: 变量调节函数 
 * 参数: *variate(需要改变的量), often_MAX（最大值）,often_MIN(最小值)
 * 返回: 无 
**********************************/  
void var_mode(int *variate, int often_MAX, int often_MIN)
 {
 	*variate=*variate+1;
	 if(*variate>often_MAX) 
	  *variate = often_MIN;
 } 


/**********************************
 * 功能: 闪烁延时函数 
 * 参数: K_s(允许位) ，*S_P(闪烁位)  
 * 返回: 无 
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
 * 功能: 闪烁延时函数 
 * 参数: KEY_L(按键按下判断)   
 * 返回: 无 
**********************************/   
void CLKMODE_delay(uchar KEY_L, uint *S_P, uint *K_s)
 {
   static int k=50,i=0;
    if(KEY_L == 0x08)
	  {
	    k=50;*S_P = 1;*K_s=0;i=0;	 
	  }	 
     if(KEY_L != 0x08) 
      {
      	if(--k == 0)
      	 {
           k=1;
           *K_s=1;
         }
      }
 } 
 
/**********************************
 * 功能: 闹钟，时钟设置返回界面延时 
 * 参数: *TIM_m(闹钟与时钟设置判断)，*TIM_c(闹钟设置判断) 
         *TIM_t(时钟设置判断)，*delay(显示延时)
 * 返回: 无 
**********************************/ 
void TIME_CLK_LCDmode(uint *TIM_m, uint *TIM_c, uint *TIM_t, uint *delay) 
  {
  	if(*TIM_m != 0 && Cont == 0x00)
     {
     	*delay = *delay - 1;
     	if(*delay == 0){*TIM_m = 0; *TIM_c = 0; *TIM_t = 0;}
     }
  }
  
  
void CLK_BUZZ()
 {
 	
 } 