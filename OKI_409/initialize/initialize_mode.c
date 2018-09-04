#include "initialize_mode.h"
  
/**********************************
 * 功能: 初始化TIMES2 （蜂鸣器使用） 
 * 参数: 无
 * 返回: 无
**********************************/
void Init_Times2(void)
{
	TM2CON0 = 4;  //内部低速时钟 16位计数
	TM2D = 0x8F;  //T2计数到234
	TM3D = 0x03;  //T3计数到140
	IE5 |= 0x20;  //使能TM5中断
	TM2CON1 |= 1;  //开始计数
}

/**********************************
 * 功能: 初始化TIMES0 （按键扫描用） 
 * 参数: 无
 * 返回: 无
**********************************/
void Init_Times0(void)
{
	TM0CON0 = 4;  //内部低速时钟 16位计数
	TM0D = 0x8F;  //T0计数到234
	TM1D = 0x02;  //T1计数到140
	IE3 |= 2;  //使能TM1中断
	TM0CON1 |= 1;  //开始计数
}
  
  
 /*********************************
 * 功能: 蜂鸣器初始化
 * 参数: 无
 * 返回: 无
**********************************/
void MelodyInit()
  {
     ENMLT = 1; // LSCLK*2,蜂鸣器时钟配置
     P22C1 = 1; 
     P22C0 = 1;
     P22MD = 1; // 配置端口P22位第二功能-MEL0DY
     BZMD = 1;  // MEL0DY模式选择为BUZZER MODE, 即蜂鸣器模式
     MD0TON = 0x01; // 配置蜂鸣器工作频率为2.0KHZ
     MD0LEN = 0X01; // 配置蜂鸣器工作功率 1-3-5-7
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
   Init_Times2();	
  } 
  
/*********************************
 * 功能: 开机，闹钟（蜂鸣器） 
 * 参数: 无
 * 返回: 无
**********************************/  
void ON_clk_buzz()
 {

   MD0TMP = 0x00; // 配置蜂鸣器模式
   M0RUN=1;  // 开启蜂鸣器
   Init_Times2();
  } 

/*********************************
 * 功能: （蜂鸣器）模式选择 
 * 参数: x(输入的模式)，y（中断数据接口） 
        x:
		 KEY_BUZZ_mode0 (1) //按键响 
		 CLK_BUZZ_mode1 (2) //时钟响 滴 
		 CLK_BUZZ_mode2 (3) //时钟响 滴滴 
		 ON_BUZZ_mode3  (4) //开机响 滴滴滴 
		 CLK_BUZZ_mode4 (5) //时钟响 滴滴滴滴 
 * 返回: 无
**********************************/  
void BUZZ_mode(int x, int *y)
 {
   switch(x)
    {
   	  case 1: {*y=x; key_buzz(); break;} 
   	  case 2: {*y=x; ON_clk_buzz(); break;} 
   	  case 3: {*y=x; ON_clk_buzz(); break;} 
   	  case 4: {*y=x; ON_clk_buzz(); break;} 
   	  case 5: {*y=x; ON_clk_buzz(); break;} 
   	  default: { *y=0; break; }
    }
 } 
 
 
/*********************************
 * 功能: （蜂鸣器中断）频率切割 
 * 参数: x(与蜂鸣器输入的模式变量连接) 
 * 返回: 无
**********************************/  
void BUZZ_int(int x)
 {
   static int incise = 0; //响声切割
   int stop_clk = 0; //按键响计时 
   switch(x)
    {
   	  case 1: {
		   for(stop_clk=500;stop_clk--;stop_clk>0);
		     M0RUN = 0; break;} 
   	  case 2: {
	       if(M0RUN ==1 && incise++ == 3)
		     {incise = 0;M0RUN = 0; }
			  Init_Times2(); break;} 
   	  case 3: {
	       if(M0RUN ==1 && incise++ == 6)
		     {incise = 0;M0RUN = 0; }
			  Init_Times2(); break;}
   	  case 4: {
	       if(M0RUN ==1 && incise++ == 12)
		     {incise = 0;M0RUN = 0; }
			  Init_Times2(); break;} 
   	  case 5: {
	       if(M0RUN ==1 && incise++ == 16)
		     {incise = 0;M0RUN = 0; }
			  Init_Times2(); break;} 
   	  default: break; 
    }
 } 
 
 
 /*********************************
 * 功能:  按键扫描函数 （嵌入到中断里） 
 * 参数:  TR(短按标志)，Co(常按标志)，co(常按溢出), sum(按键状态接口)
 * 返回: 无
**********************************/ 
void KEY_scan(uchar *TR, uchar *Co, uchar *co, uchar *sum)
 {
   static int lay = 0;
   unsigned int kp = 0;	
   kp = KEY_scanning();
   *sum = KEY_VALUE(kp);
     if(*Co != 0x00 && ++lay >= 100) *co = *Co;
     if(*Co == 0x00) {lay = 0; /*松手*/  *co = 0x00; } 
 }
 
 
 /**********************************
 * 功能: P0口外部中断初始化
 * 参数: 无
 * 返回: 无
**********************************/
void P0_INIT()
 {
   EP00 = 0;
   P0CON0 = 0x00; //P01-2-3口为高阻抗
   P0CON1 = 0x01;
   EXICON0 = 0x01; //启用中断
   EXICON1 = 0x00;
   EXICON2 = 0x01;
   EP00 = 1;
  }
  
/**********************************
 * 功能: P5口外部低电压中断,按键初始化
 * 参数: 无
 * 返回: 无
**********************************/  
void P5_INIT()
 {
   EP5 = 0;
   P5DIR = 0;
   P5CON0 = 0;
   P5UD = 0;
   P5MOD0 = 0;
   P5MOD1 = 0;
   P5ISEL = 0x10; //打开P54口中断中断
   EP5 = 1;
 }


/**********************************
 * 功能: P3口A/D采样初始化
 * 参数: 无
 * 返回: 无
**********************************/
void Temperature3_gathering()
 {	
   P3MOD0 = 0X3F; //RC振荡监控RC-ADC销
   P3DIR = 0X1F;  //P3口IN0为输入,CS0,RCT0,RS0为输出口
   P3CON1 = 0X20; //高阻抗输入
   P3CON0 = 0X20; //高阻抗输入
  }


/**********************************
 * 功能: P4口A/D采样初始化
 * 参数: 无
 * 返回: 无
**********************************/   
void Temperature4_gathering()
  {
    P4MOD1=0;
    P4MOD0=0xF0; //RC震荡监控RC-ADC
    P4DIR=0xF0; //P4口IN1,CS1,RT1,RS1为输入口
    P4CON1 = 0XF0; 
    P4CON0 = 0XF0; 
  }