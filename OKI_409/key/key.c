#include<m610409.h> 
#include "key.h"


/********************************** 
 * 函数名:KEY_WALK_ROW
 * 功能: 行列扫描切换 
 * 参数: WR_mode：
           KEY_SCANNING_SORT (0)  //扫描列 
           KEY_SCANNING_WALK (1)  //扫描行
 * 返回: unsigned int
***********************************/
unsigned int  KEY_WALK_ROW(unsigned int WR_mode)
  {
  	if(WR_mode > (unsigned int)KEY_SCANNING_WALK) {
	  	return ((unsigned int)KEY_DEPLOY_FAIL);
	  }
	  if(WR_mode == KEY_SCANNING_SORT)
	   {
         P50DIR = 0; P51DIR = 0; P52DIR = 1; P53DIR = 1;
         P50D = 0; P51D = 0; P52D = 1; P53D = 1; 	
   	    }
      else if(WR_mode == KEY_SCANNING_WALK)
        {
          P50DIR = 1; P51DIR = 1; P52DIR = 0; P53DIR = 0;
          P50D = 1; P51D = 1; P52D = 0; P53D = 0; 	
         }
     return (KEY_DEPLOY_OK); 
   }

/********************************** 
 * 函数名:KEY_WALK_ROW
 * 功能: 按键扫描 
 * 参数: 无 
 * 返回: unsigned int
***********************************/
unsigned int KEY_scanning()
 {
   unsigned int k0=0,k1=0,k2=0,k3=0,sum=0;
   static int clash=KEY_CLASH_NO;
      //第一步赋值算法 
     if(KEY_WALK_ROW(KEY_SCANNING_SORT) == KEY_DEPLOY_OK)  
      if(P50D == KEY_LOW && P51D == KEY_LOW)
       {
         P52D = KEY_HIGH; P53D = KEY_HIGH;
        if(P52D == KEY_HIGH && P53D == KEY_HIGH) clash=KEY_CLASH_NO;
           else if(P52D == KEY_LOW && P53D == KEY_LOW)  clash=KEY_CLASH_BE;
         if(P52D == KEY_LOW && P53D == KEY_HIGH && clash==KEY_CLASH_NO) {k0 = 1; }
         if(P53D == KEY_LOW && P52D == KEY_HIGH && clash==KEY_CLASH_NO) {k1 = 2; }
       }
      //第二步赋值算法  
     if(KEY_WALK_ROW(KEY_SCANNING_WALK) == KEY_DEPLOY_OK) 
      if(P52D == KEY_LOW && P53D == KEY_LOW)
       {
         P50D = KEY_HIGH; P51D = KEY_HIGH;
         if(P50D == KEY_HIGH && P51D == KEY_HIGH) clash=KEY_CLASH_NO;
           else if(P50D == KEY_LOW && P51D == KEY_LOW)  clash=KEY_CLASH_BE;
         if(P50D == KEY_LOW && P51D == KEY_HIGH && clash==KEY_CLASH_NO) 
		   {k2 = 0; 
		    if(k0 != 0)sum = k0+k2;
		    if(k1 != 0)sum = k1+k2;
		    }
         if(P51D == KEY_LOW && P50D == KEY_HIGH && clash==KEY_CLASH_NO) 
		   {k3 = 2;
		    if(k0 != 0)sum = k0+k3;
		    if(k1 != 0)sum = k1+k3; 
		    }
         }
    return (sum);	
 }


/********************************** 
 * 函数名:KEY_VALUE 
 * 功能: 扫描后的值转化为16进制 
 * 参数: ke
 * 返回: unsigned char
***********************************/
 unsigned char KEY_VALUE(unsigned int ke)
   {
   	unsigned char sum;
   	 switch(ke)
   	  {
  	   case 1: sum=(unsigned char)KEY_0;break;
	   case 2: sum=(unsigned char)KEY_1;break;
	   case 3: sum=(unsigned char)KEY_2;break;
	   case 4: sum=(unsigned char)KEY_3;break;
	   default : sum=(unsigned char)KEY_NO;	
 	   }
     return sum;
   }
   

/********************************** 
 * 函数名:KeyRead
 * 功能: 按键状态判断 
 * 参数: key_mode， *Tr， *Co 
 * 返回: 无
***********************************/
void KeyRead(unsigned char key_mode, uchar *Tr, uchar *Co)
 {
 	unsigned char ReadData = key_mode^0x00; //1
 	*Tr = ReadData & (ReadData ^ Cont); //2
 	*Co = ReadData; //3	
 } 
 
/********************************** 
 * 函数名:KEY_close
 * 功能: 按键状态判断 
 * 参数: ke_clo:
            KEY_0 (0x01) //按键0值 
            KEY_1 (0x02) //按键1值 
            KEY_2 (0x04) //按键2值 
            KEY_3 (0x08) //按键3值 
		     
 * 返回: unsigned int
***********************************/
unsigned int KEY_close(unsigned char ke_clo)
 {
   if(Trg == ke_clo) return ((unsigned int)key_close_yes);
    else return ((unsigned int)key_close_no); 
 }
 
 
/********************************** 
 * 函数名:KEY_long
 * 功能: 按键状态判断 
 * 参数: ke_clo:
            KEY_0 (0x01) //按键0值 
            KEY_1 (0x02) //按键1值 
            KEY_2 (0x04) //按键2值 
            KEY_3 (0x08) //按键3值 
		     
 * 返回: unsigned int
***********************************/
unsigned int KEY_long(unsigned char ke_clo)
 {
   if(cont == ke_clo) return ((unsigned int)key_close_yes);
    else return ((unsigned int)key_close_no); 
 }
 
 
 
/********************************** 
 * 函数名:KEY_independent
 * 功能: P56,P57独立按键初始化 
 * 参数: 无 
 * 返回: 无 
***********************************/ 
void KEY_independent()
 {
 	P56DIR = 1; P57DIR = 1;
 } 
 
/********************************** 
 * 函数名:KEY_indepen_scan
 * 功能: P56,P57独立按键扫描 
 * 参数: 无 
 * 返回: 无 
***********************************/  
void KEY_indepen_scan(uint *cay, uint *CF)
 {
 	if(P56D == 0) *CF = KEY_LOW;
	  else *CF = KEY_HIGH; 
 	if(P57D == 0) *cay = KEY_LOW;
	  else *cay = KEY_HIGH; 
 }