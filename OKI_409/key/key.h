/******************************************************
   key.h 
   
   ML610Q409，key按键检测功能函数模块；
   
   History
    2017-9-26 
******************************************************/ 
//#ifndef _KEY_H_
//#define _KEY_H_ 
#include "MacroAndConst.h"

#define KEY_DEPLOY_OK   (0) //成功 
#define KEY_DEPLOY_FAIL (-1)//失败

#define KEY_CLASH_NO (0) //无按键冲突  
#define KEY_CLASH_BE (1) //按键冲突 

#define KEY_SCANNING_SORT (0)  //扫描列 
#define KEY_SCANNING_WALK (1)  //扫描行 

#define KEY_LOW  (0) //低电平状态  
#define KEY_HIGH (1) //高电平状态 

#define KEY_NO (0x00) //无按键按下 
#define KEY_0 (0x01) //按键0值 
#define KEY_1 (0x02) //按键1值 
#define KEY_2 (0x04) //按键2值 
#define KEY_3 (0x08) //按键3值 

#define key_close_no   (0) //无短按 
#define key_close_yes  (1) //短按确定 
#define key_often_no   (0) //无常按 
#define key_often_yes  (1) //常按确定 

unsigned char Trg;  //短按 
unsigned char Cont; //常按标志 
unsigned char cont; //常按溢出 

/*************************************************
/*                    API
*************************************************/
unsigned int  KEY_WALK_ROW(unsigned int WR_mode);
unsigned int KEY_scanning();
unsigned char KEY_VALUE(unsigned int ke);
void KeyRead(unsigned char key_mode, uchar *Tr, uchar *Co);
unsigned int KEY_close(unsigned char ke_clo); 
unsigned int KEY_long(unsigned char ke_clo);
void KEY_independent(); 
void KEY_indepen_scan(int *cay, int *CF);

// #endif /*_KEY_H_*/