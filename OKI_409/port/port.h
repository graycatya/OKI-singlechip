/******************************************************
   port.h 
   
   ML610Q409��I/O�����ú���ģ�飻
   
   History
    2017-9-19 
******************************************************/ 
//#ifndef _PORT_H_
//#define _PORT_H_ 
#include "MacroAndConst.h"

#define PORT_DEPLOY_OK   (0) //�ɹ� 
#define PORT_DEPLOY_FAIL (-1)//ʧ�� 

#define PORT_LOW  (0) //���״̬ 
#define PORT_HIGH (1) //���״̬ 

/*PORT�˿� 0-7λ״̬*/
#define P0_MODE_LOW   (0)  //P0������Ϊ�͵�ƽ 
#define P0_MODE_HIGH   (1)  //P0������Ϊ�ߵ�ƽ 
#define P1_MODE_LOW   (0)  //P1������Ϊ�͵�ƽ 
#define P1_MODE_HIGH   (1)  //P1������Ϊ�ߵ�ƽ 
#define P2_MODE_LOW   (0)  //P2������Ϊ�͵�ƽ 
#define P2_MODE_HIGH   (1)  //P2������Ϊ�ߵ�ƽ 
#define P3_MODE_LOW   (0)  //P3������Ϊ�͵�ƽ 
#define P3_MODE_HIGH   (1)  //P3������Ϊ�ߵ�ƽ 
#define P4_MODE_LOW   (0)  //P4������Ϊ�͵�ƽ
#define P4_MODE_HIGH   (1)  //P4������Ϊ�ߵ�ƽ 
#define P5_MODE_LOW   (0)  //P5������Ϊ�͵�ƽ
#define P5_MODE_HIGH   (1)  //P5������Ϊ�ߵ�ƽ
#define P6_MODE_LOW   (0)  //P6������Ϊ�͵�ƽ
#define P6_MODE_HIGH   (1)  //P6������Ϊ�ߵ�ƽ
#define P7_MODE_LOW   (0)  //P7������Ϊ�͵�ƽ
#define P7_MODE_HIGH   (1)  //P7������Ϊ�ߵ�ƽ

/*P0�� API*/
int P0D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, unsigned int bit4); 
int PCON_0init(unsigned int bit0, unsigned int bit1, 
               unsigned int bit2, unsigned int bit3, unsigned int bit4);
int PCON_1init(unsigned int bit0, unsigned int bit1,
               unsigned int bit2, unsigned int bit3, unsigned int bit4);
int EXICON_0init(unsigned int bit0, unsigned int bit1,
                 unsigned int bit2, unsigned int bit3, unsigned int bit4);
int EXICON_1init(unsigned int bit0, unsigned int bit1,
                 unsigned int bit2, unsigned int bit3, unsigned int bit4);
int EXICON_2init(unsigned int bit0, unsigned int bit1,
                 unsigned int bit2, unsigned int bit3, unsigned int bit4);

/*P2�� API*/
int P2D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);
int P2CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);
int P2CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);
int P2MOD_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);

/*P3�� API*/
int P3D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
             unsigned int bit3, unsigned int bit4, unsigned int bit5);
int P3DIR_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
               unsigned int bit3, unsigned int bit4, unsigned int bit5);
int P3CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit3, unsigned int bit4, unsigned int bit5);
int P3CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit3, unsigned int bit4, unsigned int bit5);
int P3MOD_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
               unsigned int bit3, unsigned int bit4, unsigned int bit5);

/*P4�� API*/
int P4D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
             unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P4DIR_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P4CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P4CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P4MOD_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P4MOD_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);

/*P5�� API*/
int P5D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
             unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P5DIR_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
               unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P5CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);
int P5CON_1init(unsigned int bit0);
int P5MOD_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6);
int P5MOD_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, 
                unsigned int bit4, unsigned int bit5, unsigned int bit6);
int P5SISEL_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit3, 
                 unsigned int bit4, unsigned int bit5, unsigned int bit6, unsigned int bit7);


    
// #endif /*_PORT_H_*/