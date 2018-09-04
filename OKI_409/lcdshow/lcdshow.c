
#include "lcdshow.h"
#include "temphum.h" 

//12/24小时制显示码 
uchar TIME_system[SYSTEM][TIM][2]={
//0-23小时制显示 
{{0x3f,0x3f},{0x3f,0x06},{0x3f,0x5b},{0x3f,0x4f},{0x3f,0x66},
 {0x3f,0x6d},{0x3f,0x7d},{0x3f,0x07},{0x3f,0x7f},{0x3f,0x6f},
 {0x06,0x3f},{0x06,0x06},{0x06,0x5b},{0x06,0x4f},{0x06,0x66},
 {0x06,0x6d},{0x06,0x7d},{0x06,0x07},{0x06,0x7f},{0x06,0x6f},
 {0x5b,0x3f},{0x5b,0x06},{0x5b,0x5b},{0x5b,0x4f}},
//12小时制显示 
{{0x06,0x5b},{0x3f,0x06},{0x3f,0x5b},{0x3f,0x4f},{0x3f,0x66},
 {0x3f,0x6d},{0x3f,0x7d},{0x3f,0x07},{0x3f,0x7f},{0x3f,0x6f},
 {0x06,0x3f},{0x06,0x06},{0x06,0x5b},{0x3f,0x06},{0x3f,0x5b},
 {0x3f,0x4f},{0x3f,0x66},{0x3f,0x6d},{0x3f,0x7d},{0x3f,0x07},
 {0x3f,0x7f},{0x3f,0x6f},{0x06,0x3f},{0x06,0x06}}
}; 

//*周一至周日显示码 
uchar week[WEK_mod][3][2]={
{{0x6D,0x01},{0x3E,0x00},{0x36,0x18}}, //SUN
{{0x36,0x50},{0x3F,0x00},{0x36,0x18}}, //MON
{{0x01,0x24},{0x3E,0x00},{0x79,0x01}}, //TUE
{{0x36,0x0A},{0x79,0x01},{0x0F,0x24}}, //WED
{{0x01,0x24},{0x76,0x01},{0x3E,0x00}}, //THU
{{0x71,0x01},{0x73,0x09},{0x09,0x24}}, //FRI
{{0x6D,0x01},{0x77,0x01},{0x01,0x24}}  //SAT
}; 

//*闹钟模式-3种模式显示码
uchar	NOISY0_bell[NObel_mod][2]={
{0x40,0x40}, //--
{0x00,0x37}, //N
{0x00,0x06}  //1  	
};
//*闹钟模式-3种模式显示码 
uchar	NOISY1_bell[NObel_mod][3][2]={
{{0x3F,0x00},{0x71,0x01},{0x71,0x01}}, //OFF
{{0x73,0x09},{0x79,0x01},{0x73,0x01}}, //REP
{{0x00,0x00},{0x3F,0x00},{0x01,0x24}}  //OT	
}; 

//*0-9,' ','-'数码管显示.
uchar table[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x40};  



/********************************** 
 * 功能: BUZZ闪烁显示函数 
 * 参数: P(与计数器接口),BU_bit(BUZZ显示状态位接口) 
 * 返回: 无
**********************************/ 
void UI_BUZZ(uint P, uint BU_bit)
 {
         if(BU_bit==1)
          {
     	  	if(P==0)Buzz=LOW;  //此时为BUZZ闪烁 
     	  	if(P==1)Buzz=HIGH;
     	   }
          else Buzz=LOW;
  }
  
/********************************** 
 * 功能: P.闪烁显示函数 
 * 参数: P(与计数器接口),P_bit(P.显示状态位接口)
 * 返回: 无
**********************************/ 
void UI_P(uint P, uint P_bit)
 {
  if(P_bit==1)Clk=HIGH;
   else if(P_bit==2)Clk=LOW;	
    else if(P_bit==3)
	 {
	  if(P==0)Clk=LOW;      //此时为时钟计数闪烁 
  	   else if(P==1)Clk=HIGH; 
	  }	
  }

/********************************** 
 * 功能: 年显示函数 
 * 参数: YETI_VALUE（年整型数据接口），BU_YT(年常亮与闪烁状态位)， 
          P（闪烁状态接口）         
 * 返回: 无
**********************************/  
void UI_YE(uint YETI_VALUE, uint BU_YT, uint P)
 {
  	if(BU_YT==0)Year_Out=0x00; //年英文显示（year）
	if(BU_YT==1) //常亮模式 
	 {
	 	Year_Out=0x01; //年英文显示（year）
    	year_time0=table[YETI_VALUE/1000]; //年千位 
  	    year_time1=table[YETI_VALUE/100%10]; //年百位
    	year_time2=table[YETI_VALUE/10%10]; //年十位
    	year_time3=table[YETI_VALUE%10]; //年个位 		
 	 }
    else if(BU_YT==2) //闪烁模式 
     {
   	  Year_Out=0x01; //年英文显示（year）
      if(P==0) //灭 
       {
    	year_time0=0; //年千位 
  	    year_time1=0; //年百位
    	year_time2=0; //年十位
    	year_time3=0; //年个位    		
   	   }
	  else if(P==1) //亮 
	   {
    	year_time0=table[YETI_VALUE/1000]; //年千位 
  	    year_time1=table[YETI_VALUE/100%10]; //年百位
    	year_time2=table[YETI_VALUE/10%10]; //年十位
    	year_time3=table[YETI_VALUE%10]; //年个位	   	 
       }	
     } 
 } 
 
 
/********************************** 
 * 功能: 时闪烁函数 
 * 参数: TIM_VALUE（时/闹钟时整型数据接口），
          TIM_ZHI(24/12小时选择),P（闪烁状态接口）     
 * 返回: 无
**********************************/
 void  TIM_SHI(uint TIM_VALUE, uint TIM_ZHI, uint P)
  {
      if(P==0) //灭 
       {
       	year_time0=0; //时十位 
  	    year_time1=0; //时个位   		
   	   }
	  else if(P==1) //亮 
	   {
	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //时个位	   	 
       }    	
   }
   

/********************************** 
 * 功能: 分闪烁函数 
 * 参数: MAR_VALUE（分/闹钟分整型数据接口），P（闪烁状态接口）  
 * 返回: 无
**********************************/
void TIM_FEN(uint MAR_VALUE, uint P)
  {
      if(P==0) //灭 
       {
    	year_time2=0; //分十位
    	year_time3=0; //分个位    		
   	   }
	  else if(P==1) //亮 
	   {
    	  year_time2=table[MAR_VALUE/10]; //分十位
    	  year_time3=table[MAR_VALUE%10]; //分个位 	   	 
       }    	
   }
   
/********************************** 
 * 功能: 时/分显示函数 
 * 参数: TIM_VALUE（时/闹钟时整型数据接口），MAR_VALUE（分/闹钟分整型数据接口）
          TIM_ZHI(24/12小时选择),BU_YT(时常亮与闪烁状态位)， P（闪烁状态接口）     
 * 返回: 无
**********************************/  
void UI_TIME(uint TIM_VALUE, uint MAR_VALUE, uint TIM_ZHI, uint BU_YT, uint P)
 {
	if(BU_YT==1) //常亮模式 
	 {
	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //时个位
    	  year_time2=table[MAR_VALUE/10]; //分十位
    	  year_time3=table[MAR_VALUE%10]; //分个位 		
 	 } 
    else if(BU_YT==2)    //时闪烁模式	
     {
       year_time2=table[MAR_VALUE/10]; //分十位
       year_time3=table[MAR_VALUE%10]; //分个位
	    TIM_SHI(TIM_VALUE, TIM_ZHI, P);
     } 
    else if(BU_YT==3)    //分闪烁模式 
     {
	 	if(TIME_system[TIM_ZHI][TIM_VALUE][0]==0x3f) year_time0=LOW; //时十位 
		 else year_time0=TIME_system[TIM_ZHI][TIM_VALUE][0];
  	      year_time1=TIME_system[TIM_ZHI][TIM_VALUE][1]; //时个位
          TIM_FEN(MAR_VALUE, P);	
     } 
 } 
 
/********************************** 
 * 功能: 月，日显示函数 
 * 参数: P(与计数器接口),DISP_MON(与日历/时钟/闹钟设置模式接口),
          CLK_mode(闹钟时钟设置标志位), Mon(月整型数据接口)，
		  dat_AIM(日整型数据/闹钟模式状态数据接口) 
 * 返回: 无
**********************************/  
void UI_YEAR_TIME(uint P, uint DISP_MON, uint CLK_mode, uint Mon, uint dat_AIM)
 {
   if(DISP_MON==0) //月/日常亮 
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
   if(CLK_mode == 2) //月闪烁/日常亮 
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
   else if(CLK_mode==3) //日闪烁/月常亮 
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
  if(DISP_MON==1) //闹钟模式闪烁 
    {
      if(CLK_mode == 3)CIK_glint(P, dat_AIM);
    } 
  }
  
/********************************** 
 * 功能: 月_日英文显示函数 
 * 参数:  MO_BIT(月日英文亮灭显示状态位接口)
 * 返回: 无
**********************************/   
void UI_MODA(uint MO_BIT)
 {
   if(MO_BIT==1)MonDa_Day=0; 
    else if(MO_BIT==2)MonDa_Day=0x05;	
  } 

/********************************** 
 * 功能:  AIMset_APM英文显示函数 
 * 参数:  AS_bit(AIMset显示状态位接口)，AP_bit(早上下午标志位) 
          mode_ap(12/24显示状态允许) 
 * 返回: 无
**********************************/   
void UI_AIS_APM(uint AS_bit, uint AP_bit , uint mode_ap)
 {
   if(AS_bit==1)AiSe=0x03; //AIMset常亮 
    else if(AS_bit==2)AiSe=0x02;//set常亮 
	 else AiSe=LOW;//灭
	 
   if(mode_ap == 1) //12/24允许判断 
    { 
   if(AP_bit==1)A_PM=0x01; //AM常亮 
    else if(AP_bit==2)A_PM =0x02;//PM常亮 
    } 
	 else A_PM=LOW;//灭	
  } 
  
/********************************** 
 * 功能:  闹钟模式/周1-7英文显示函数 
 * 参数:  all(周1-7数据接口)，cl(闹钟模式状态接口 3种状态)，
           alcl_bit(闹钟模式/周1-7显示模式状态位) 
 * 返回: 无
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
 * 功能: 闹钟模式闪烁函数 
 * 参数:  P(与计数器接口),da_AIM(日整型数据/闹钟模式状态数据接口)
 * 返回: 无
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
	   {  //LCD 闹钟英文闪烁 
         Mon_Da2=NOISY0_bell[da_AIM-1][0];
         Mon_Da3=NOISY0_bell[da_AIM-1][1]; 					    		   		   
	    }   	
  } 
  
/********************************** 
 * 功能: 最大最小/实时温湿度模式接口显示函数 
 * 参数: P(与计数器接口),TEM_data（实时温度数据接口），HUM_data（实施湿度数据接口） 
          *T_H(温湿度最大最小数据结构体接口),MAI_MON(最大最小/实时温湿度设置模式接口)
          MAI_K(复位显示接口)，c_f(C/F算法切换)
 * 返回: 无
**********************************/ 
void UI_TEMP_HUM(uint P, int TEM_data, int HUM_data,struct Ma_Mi *T_H, uint MAI_MON, uint MAI_K, int c_f)
  {
  	if(MAI_MON==1 && MAI_K==0) //显示实时温湿度 
     {
   	   
       TEM_HUM_realtime(TEM_data, HUM_data);  
  	  } 
    else if(MAI_MON==2 && MAI_K==0) //显示最小温湿度  
     {	  
       TEM_HUM_realtime(C_FCUTOVER(T_H->min_temp, c_f), T_H->min_hum);	
        
      }
    else if(MAI_MON==3 && MAI_K==0) //显示最大温湿度 
     {
       TEM_HUM_realtime(C_FCUTOVER(T_H->max_temp, c_f), T_H->max_hum);	
             	
      }
    if(MAI_K==1) //重置最大小显示
	 {
 	   TEM_HUM_realtime(-600, -600);
	  } 
	  MAX_MIN_realtime(P, MAI_MON);
  } 
  
/********************************** 
 * 功能: 温湿度显示函数 
 * 参数: TE_data（温度数据接口），HU_data（湿度数据接口） 
 * 返回: 无
**********************************/   
void TEM_HUM_realtime(int TE_data, int HU_data)
 {
 	//实时温度处理显示 
 	if(TE_data>-600)
	 { 
     if(TE_data<0)carry=HIGH; //负号 
      else if(TE_data>=0)carry=LOW;      
     if(TE_data>=1000)Temp_0=HIGH; //过了100后 
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
  	 //实时湿度处理显示
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
 * 功能: 最大最小闪烁函数 
 * 参数: P(与计数器接口), MAI_MON(最大最小/实时温湿度设置模式接口)
 * 返回: 无
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
 * 功能: C/F,%显示函数(独立的温湿度显示函数)
 * 参数:  DATA_bit(C_F切换按键状态接口) 
 * 返回: 无
**********************************/   
void  PICK_dataCOR(uint DATA_bit)
 {
   P_BAT=0x01; 
   if(DATA_bit==1)C_F_H=0x05; //C度显示 
    else if(DATA_bit==0)C_F_H=0x03;	//F度显示 
  }


/********************************** 
 * 功能: 最大最小值初始化 
 * 参数: TEMP_DATA（温度数据接口），HUM_DATA（湿度数据接口），
         *M_m（结构体温湿度整体赋值） 
 * 返回: struct Ma_Mi * （初始化后的值用结构体整体返回） 
**********************************/ 
void DATA_INT(int TEMP_DATA, int HUM_DATA, struct Ma_Mi *M_m)
 {
   	M_m->min_temp=TEMP_DATA;
   	M_m->max_temp=TEMP_DATA;
   	M_m->min_hum=HUM_DATA;
   	M_m->max_hum=HUM_DATA;
  }

/********************************** 
 * 功能: 最大最小值数据比较 
 * 参数: TEMP_DATA（温度数据接口），HUM_DATA（湿度数据接口），
         *M_ai（结构体温湿度整体赋值） 
 * 返回: struct Ma_Mi * （比较后的值用结构体整体返回） 
**********************************/ 
void DATA_compare(int TEMP_DATA, int HUM_DATA, struct Ma_Mi *M_ai)
 {
   	if(TEMP_DATA < M_ai->min_temp)M_ai->min_temp=TEMP_DATA;
   	if(TEMP_DATA > M_ai->max_temp)M_ai->max_temp=TEMP_DATA;
   	if(HUM_DATA < M_ai->min_hum)M_ai->min_hum=HUM_DATA;
   	if(HUM_DATA > M_ai->max_hum)M_ai->max_hum=HUM_DATA;
  }
  
