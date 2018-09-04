/******************************************************
   melody.h 
   
   ML610Q409，蜂鸣器配置函数模块；
   
   History
    2017-9-22 
******************************************************/ 
//#ifndef _MELODY_H_
//#define _MELODY_H_ 
#include "MacroAndConst.h"

//模式枚举通用 
enum BUZZmode_value {
 buzz_one=0,buzz_two=1,buzz_three=2,buzz_four=3,
 buzz_five=4,buzz_six=5,buzz_seven=6,buzz_eight=7,
 buzz_nine=8,buzz_ten=9,buzz_eleven=10,buzz_twelve=11,
 buzz_thirteen=12,buzz_fourteen=13,buzz_fifteen=14,
 buzz_sixteen=15
};


#define melodyTMP_mode 16 //旋律模式16种
#define buzzTMP_mode 4 //蜂鸣器模式4种 

#define melodyTON_mode_MIN (0x00) //旋律模式最小值
#define melodyTON_mode_MAX (0x7B) //旋律模式最大值 
#define buzzTON_mode 8 //蜂鸣器模式8种 

#define melodyLEN_mode_MIN (0x00) //旋律模式最小值
#define melodyLEN_mode_MAX (0x3F) //旋律模式最大值
#define buzzLEN_mode 16 //蜂鸣器模式16种 

#define MELODY_DEPLOY_OK   (0) //成功 
#define MELODY_DEPLOY_FAIL (-1)//失败 

#define MELODY_LOW  (0) //低电平状态  
#define MELODY_HIGH (1) //高电平状态 

//模式数组 
static const  unsigned char RCADC_SAMPLING_MODE[melodyTMP_mode]={
 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
 0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F 
};

/*API*/
int MD0_CON(unsigned int M0_RUN, unsigned int BZ_MD);
/*BUZZ API*/
int MD0_TMP_buzz(unsigned int MD0_TMP);
int MD0_TON_buzz(unsigned int MD0_TON);
int MD0_LEN_buzz(unsigned int MD0_LEN);
/*MELODY API*/
int MD0_TMP_melody(unsigned int MD0_TMP);
int MD0_TON_melody(unsigned char MD0_TON);
int MD0_LEN_melody(unsigned char MD0_LEN);


// #endif /*_MELODY_H_*/