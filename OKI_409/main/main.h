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
  LCD�Ĵ�������ʪ�ȱ������
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

/* ��ʼ��ʪ�ȱ� */
const int HUM_AT[_HUM_] = {
#include _HUM_TAC_
};

/* ��ʼ��ʪ���¶ȱ� */
const int HUM_TEMP_BT[_HUM_TEMP_] = {
#include _HUM_TEMP_TBC_
};

/* ��ʼ��ʪ�Ȳ����� */
const int HUM_CAY[_HUM_][_HUM_TEMP_]= {
#include _HUM_CAIY_TCC_
};

/* ��ʼ���¶Ȳ����� */
const int TEMP_AT[TEMP_A] = {
#include _TEMP_A_TAC_
};

/* ��ʼ�������¶ȱ� */
const int TEMP_BT[TEMP_B] = {
#include _TEMP_B_TBC_
};




/**********************************
 * ����: ��ʱ
 * ����: k
 * ����: ��
**********************************/
void delayms(int k, int x)
 {
  int i,j;
   for(i=k;i>0;i--)
    for(j=x;j>0;j--);
  }

/**********************************
 * ����: ������������ʱ���� 
 * ����: ��
 * ����: ��
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
 * ����: LCD�Ĵ������� 
 * ����: ��
 * ����: ��
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
 * ����: LCD��ʼ��
 * ����: ��
 * ����: ��
**********************************/
void LcdInit(void)
   {
        
	uchar i;
	uchar *pt  = &DSPR00;  //ȡLCD��ʾ�Ĵ������׵�ַ
	
	DSPCON  = 0x00;  //�ر�LCD��ʾ
	Sample_TableCopyFunc(); //����LCD RAM����
	BIASCON = 0x00;  //����LCD����ƫ��Ϊ32KZ, 1/3BIAS,1/3��ָƫѹ��LCDҪ��ĵ�ѹΪVCC��1/3BIAS 
                           //��ʾ����VCC��GND�ֳ�4�ȷݣ�VCC��2/3VCC��1/3VCC��0
                           //1/4duty��ָһ�����ڣ���4�εĶ���������4��COM�ڣ���Ҫ���ڵ�ˢ��ֵ
	DSPMOD0 = 0x04;  //����LCD DUTY Ϊ1/5duty, ֡ƵΪ64HZ
      
	for(i=0; i<0xc0; i++)
	{	 
            *pt++ = 0x00;  //���LCD��ʾ������
           }
            
          DSPCON  = 0x03;  //LCDȫ��ʾ
          delayms(600, 110);
    }

void LCD_empty()
 {
   uchar i;
   uchar *pt  = &DSPR00;  //ȡLCD��ʾ�Ĵ������׵�ַ  
    DSPCON  = 0x00;  //�ر�LCD��ʾ
  	for(i=0; i<0xc0; i++)
	{	 
            *pt++ = 0x00;  //���LCD��ʾ������
           }
   DSPCON  = 0x02;
  }

/**********************************
 * ����: ��ʼ��TIMES2 ��������ʹ�ã� 
 * ����: ��
 * ����: ��
**********************************/
void Init_Times2(void)
{
	TM2CON0 = 4;  //�ڲ�����ʱ�� 16λ����
	TM2D = 0x8F;  //T2������234
	TM3D = 0x03;  //T3������140
	IE5 |= 0x20;  //ʹ��TM5�ж�
	TM2CON1 |= 1;  //��ʼ����
}

/**********************************
 * ����: ��ʼ��TIMES0 ������ɨ���ã� 
 * ����: ��
 * ����: ��
**********************************/
void Init_Times0(void)
{
	TM0CON0 = 4;  //�ڲ�����ʱ�� 16λ����
	TM0D = 0x8F;  //T0������234
	TM1D = 0x02;  //T1������140
	IE3 |= 2;  //ʹ��TM1�ж�
	TM0CON1 |= 1;  //��ʼ����
}
  
  
 /*********************************
 * ����: ��������ʼ��
 * ����: ��
 * ����: ��
**********************************/
void MelodyInit()
  {
     ENMLT = 1; // LSCLK*2,������ʱ������
     P22C1 = 1; 
     P22C0 = 1;
     P22MD = 1; // ���ö˿�P22λ�ڶ�����-MEL0DY
     BZMD = 1;  // MEL0DYģʽѡ��ΪBUZZER MODE, ��������ģʽ
     MD0TON = 0x01; // ���÷���������Ƶ��Ϊ2.0KHZ
     MD0LEN = 0X01; // ���÷������������� 1-3-5-7
    
  }

/*********************************
 * ����: ����(������)
 * ����: ��
 * ����: ��
**********************************/
void key_buzz()
 {
   MD0TMP = 0x02; // ���÷�����ģʽ
   M0RUN = 1; // ����������	
  }   


  
/*********************************
 * ����: ���������ӣ��������� 
 * ����: ��
 * ����: ��
**********************************/  
void ON_clk_buzz()
 {
   MD0TMP = 0x00; // ���÷�����ģʽ  
   T8HZ=1;
   M0RUN=1;
   Init_Times2();
  }  

/*********************************
 * ����: ����������ģʽѡ�� 
 * ����: x(�����ģʽ)��y���ж����ݽӿڣ� 
        x:
		 CLK_BUZZ_mode1 (2) //ʱ���� �� 
		 CLK_BUZZ_mode2 (3) //ʱ���� �ε� 
		 ON_BUZZ_mode3  (4) //������ �εε� 
		 CLK_BUZZ_mode4 (5) //ʱ���� �εεε� 
 * ����: ��
**********************************/  
void BUZZ_mode(int x, int *y)
 {
    *y=x; 
    ON_clk_buzz(); 
  } 
 
 
/*********************************
 * ����: ���������жϣ�Ƶ���и� 
 * ����: x(������������ģʽ��������) 
 * ����: ��
**********************************/  
void BUZZ_int(int x)
 {
   static int incise = 0; //�����и�
   int stop_clk = 0; //�������ʱ 
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
 * ����:  ����ɨ�躯�� ��Ƕ�뵽�ж�� 
 * ����:  TR(�̰���־)��Co(������־)��co(�������), sum(����״̬�ӿ�)
 * ����: ��
**********************************/ 
void KEY_scan(uchar *TR, uchar *Co, uchar *co, uchar *sum)
 {
   static int lay = 0;
   unsigned int kp = 0;	
   kp = KEY_scanning();
   *sum = KEY_VALUE(kp);
     if(*Co != 0x00 && ++lay >= 100) *co = *Co;
     if(*Co == 0x00) {lay = 0; /*����*/  *co = 0x00;} 
 }
 
 
 /**********************************
 * ����: P0���ⲿ�жϳ�ʼ��
 * ����: ��
 * ����: ��
**********************************/
void P0_INIT()
 {
   EP00 = 0; EP04 = 0;
   P0CON0 = 0x00; //P01-2-3��Ϊ���迹
   P0CON1 = 0x11;
   EXICON0 = 0x11; //�����ж�
   EXICON1 = 0x10;
   EXICON2 = 0x11;
   EP00 = 1; EP04 = 1;
  }
  
/**********************************
 * ����: P5���ⲿ�͵�ѹ�ж�,������ʼ��
 * ����: ��
 * ����: ��
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
 * ����: P3��A/D������ʼ��
 * ����: ��
 * ����: ��
**********************************/
void Temperature3_gathering()
 {	
   P3MOD0 = 0X3F; //RC�񵴼��RC-ADC��
   P3DIR = 0X1F;  //P3��IN0Ϊ����,CS0,RCT0,RS0Ϊ�����
   P3CON1 = 0X20; //���迹����
   P3CON0 = 0X20; //���迹����
  }


/**********************************
 * ����: P4��A/D������ʼ��
 * ����: ��
 * ����: ��
**********************************/   
void Temperature4_gathering()
  {
    P4MOD1=0;
    P4MOD0=0xF0; //RC�𵴼��RC-ADC
    P4DIR=0xF0; //P4��IN1,CS1,RT1,RS1Ϊ�����
    P4CON1 = 0XF0; 
    P4CON0 = 0XF0; 
  }


