/******************************************************
   port.h 
   
   ML610Q409，I/O口配置函数模块；
   
   History
    2017-9-19 
******************************************************/ 
//#ifndef _PORT_H_
//#define _PORT_H_ 
#include "MacroAndConst.h"

#define PORT_DEPLOY_OK   (0) //成功 
#define PORT_DEPLOY_FAIL (-1)//失败 

#define PORT_LOW  (0) //检查状态 
#define PORT_HIGH (1) //检查状态 

/*PORT端口 0-7位状态*/
#define P0_MODE_LOW   (0)  //P0口配置为低电平 
#define P0_MODE_HIGH   (1)  //P0口配置为高电平 
#define P1_MODE_LOW   (0)  //P1口配置为低电平 
#define P1_MODE_HIGH   (1)  //P1口配置为高电平 
#define P2_MODE_LOW   (0)  //P2口配置为低电平 
#define P2_MODE_HIGH   (1)  //P2口配置为高电平 
#define P3_MODE_LOW   (0)  //P3口配置为低电平 
#define P3_MODE_HIGH   (1)  //P3口配置为高电平 
#define P4_MODE_LOW   (0)  //P4口配置为低电平
#define P4_MODE_HIGH   (1)  //P4口配置为高电平 
#define P5_MODE_LOW   (0)  //P5口配置为低电平
#define P5_MODE_HIGH   (1)  //P5口配置为高电平
#define P6_MODE_LOW   (0)  //P6口配置为低电平
#define P6_MODE_HIGH   (1)  //P6口配置为高电平
#define P7_MODE_LOW   (0)  //P7口配置为低电平
#define P7_MODE_HIGH   (1)  //P7口配置为高电平

/*P0口 API*/
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

/*P2口 API*/
int P2D_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);
int P2CON_0init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);
int P2CON_1init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);
int P2MOD_init(unsigned int bit0, unsigned int bit1, unsigned int bit2, unsigned int bit4);

/*P3口 API*/
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

/*P4口 API*/
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

/*P5口 API*/
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