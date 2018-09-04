#include<m610409.h>
#include "clk.h"
#include "ints.h"
#include "rcadc.h"
#include "key.h"
#include "lcdshow.h"
#include "temphum.h"
//#include "time.h"
#include "eternity.h"
#include "clkbuzz.h"
#include "MacroAndConst.h"

/*********************************
  LCD寄存器，温湿度表格配置
*********************************/
#define _TEMP_A_TAC_ "TEMP_A.tac"  
#define _TEMP_B_TBC_ "TEMP_B.tbc" 
#define  _HUM_TAC_  "HUM.tac"
#define  _HUM_TEMP_TBC_  "HUM_TEMP.tbc"
#define  _HUM_CAIY_TCC_  "HUM_CAIY.tcc"
#define  _INIT_TBL_FILE_TAC_ "lcdImgAtU8_170823_170928.tac"
#define  _INIT_TBL_FILE_TBC_ "lcdImgAtU8_170823_170928.tbc"
#define DSxCnA_NUM 320
#define DSxCnB_NUM 320

/* Initialization table for Display Allocation Register A */
const unsigned char DSxCnA[DSxCnA_NUM] = {
#include _INIT_TBL_FILE_TAC_
};

/* Initialization table for Display Allocation Register B */
const unsigned char DSxCnB[DSxCnB_NUM] = {
#include _INIT_TBL_FILE_TBC_
};

/* 初始化湿度表 */
const int HUM_AT[_HUM_] = {
#include _HUM_TAC_
};

/* 初始化湿度温度表 */
const int HUM_TEMP_BT[_HUM_TEMP_] = {
#include _HUM_TEMP_TBC_
};

/* 初始化湿度采样表 */
const int HUM_CAY[_HUM_][_HUM_TEMP_]= {
#include _HUM_CAIY_TCC_
};

/* 初始化温度采样表 */
const int TEMP_AT[TEMP_A] = {
#include _TEMP_A_TAC_
};

/* 初始化摄氏温度表 */
const int TEMP_BT[TEMP_B] = {
#include _TEMP_B_TBC_
};




/**********************************
 * 功能: 延时
 * 参数: k
 * 返回: 无
**********************************/
void delayms(int k, int x)
 {
  int i,j;
   for(i=k;i>0;i--)
    for(j=x;j>0;j--);
  }

/**********************************
 * 功能: 按键蜂鸣器延时函数 
 * 参数: 无
 * 返回: 无
**********************************/ 
void KEY_delay()
 {
   static uint X=0;
   if(MD0TMP == 0x02 && M0RUN == 1) 
    {
      delayms(10, 110);
      X=0;
      M0RUN = 0;
     }
  }

/**********************************
 * 功能: LCD寄存器配置 
 * 参数: 无
 * 返回: 无
**********************************/
/* Copy function to Display Allocation Register A and B */
void Sample_TableCopyFunc(void)
{
    volatile unsigned char __near * p;
    int i;
    
    /* TYPE3 */
    //DADM1 = 1;
    
    /* DASN clears */
    DASN = 0;
    
    /* Copy to Display Allocation Register A */
    p = &DS0C0A;
    for(i=0; i<DSxCnA_NUM; i++, p++)
    {
        *p = DSxCnA[i];
    }
    
    /* Copy to Display Allocation Register B */
    p = &DS0C0B;
    for(i=0; i<DSxCnB_NUM; i++, p++)
    {
        *p = DSxCnB[i];
    }
    
    /* DASN sets */
    DASN = 1;

    return;
}

/**********************************
 * 功能: LCD初始化
 * 参数: 无
 * 返回: 无
**********************************/
void LcdInit(void)
   {
        
	uchar i;
	uchar *pt  = &DSPR00;  //取LCD显示寄存器区首地址
	
	DSPCON  = 0x00;  //关闭LCD显示
	Sample_TableCopyFunc(); //分配LCD RAM数据
	BIASCON = 0x00;  //配置LCD工作偏置为32KZ, 1/3BIAS,1/3是指偏压，LCD要求的电压为VCC，1/3BIAS 
                           //表示，将VCC到GND分成4等份：VCC，2/3VCC，1/3VCC和0
                           //1/4duty是指一个周期，如4段的段码屏，有4个COM口，需要周期地刷新值
	DSPMOD0 = 0x04;  //配置LCD DUTY 为1/5duty, 帧频为64HZ
      
	for(i=0; i<0xc0; i++)
	{	 
            *pt++ = 0x00;  //清空LCD显示区数据
           }
            
          DSPCON  = 0x03;  //LCD全显示
          delayms(600, 110);
    }

void LCD_empty()
 {
   uchar i;
   uchar *pt  = &DSPR00;  //取LCD显示寄存器区首地址  
    DSPCON  = 0x00;  //关闭LCD显示
  	for(i=0; i<0xc0; i++)
	{	 
            *pt++ = 0x00;  //清空LCD显示区数据
           }
   DSPCON  = 0x02;
  }

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
   MD0TMP = 0x02; // 配置蜂鸣器模式
   M0RUN = 1; // 开启蜂鸣器	
  }   


  
/*********************************
 * 功能: 开机，闹钟（蜂鸣器） 
 * 参数: 无
 * 返回: 无
**********************************/  
void ON_clk_buzz()
 {
   MD0TMP = 0x00; // 配置蜂鸣器模式  
   T8HZ=1;
   M0RUN=1;
   Init_Times2();
  }  

/*********************************
 * 功能: （蜂鸣器）模式选择 
 * 参数: x(输入的模式)，y（中断数据接口） 
        x:
		 CLK_BUZZ_mode1 (2) //时钟响 滴 
		 CLK_BUZZ_mode2 (3) //时钟响 滴滴 
		 ON_BUZZ_mode3  (4) //开机响 滴滴滴 
		 CLK_BUZZ_mode4 (5) //时钟响 滴滴滴滴 
 * 返回: 无
**********************************/  
void BUZZ_mode(int x, int *y)
 {
    *y=x; 
    ON_clk_buzz(); 
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
  if(M0RUN == 1)
   switch(x)
    {
            case 1: 
	      { delayms(30, 110);M0RUN = 0;  break;}
   	  case 2: 
                { delayms(75, 110);M0RUN = 0;  break;}
   	  case 3: 
	      { delayms(115, 110);M0RUN = 0;  break;}
   	  case 4: 
                { delayms(148, 110);M0RUN = 0;  break;}
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
     if(*Co == 0x00) {lay = 0; /*松手*/  *co = 0x00;} 
 }
 
 
 /**********************************
 * 功能: P0口外部中断初始化
 * 参数: 无
 * 返回: 无
**********************************/
void P0_INIT()
 {
   EP00 = 0; EP04 = 0;
   P0CON0 = 0x00; //P01-2-3口为高阻抗
   P0CON1 = 0x11;
   EXICON0 = 0x11; //启用中断
   EXICON1 = 0x10;
   EXICON2 = 0x11;
   EP00 = 1; EP04 = 1;
  }
  
/**********************************
 * 功能: P5口外部低电压中断,按键初始化
 * 参数: 无
 * 返回: 无
**********************************/  
void P5_INIT()
 {
   P5DIR = 0x00;
   P5CON0 = 0x00;
   P5UD = 0;
   P5MOD0 = 0;
   P5MOD1 = 0;
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


