#include<stdio.h>
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
         P52DIR = 0; P53DIR = 0; P54DIR = 1; P55DIR = 1;
         P52D = 0; P53D = 0; P54D = 1; P55D = 1; 	
   	    }
      else if(WR_mode == KEY_SCANNING_WALK)
        {
          P52DIR = 1; P53DIR = 1; P54DIR = 0; P55DIR = 0;
          P52D = 1; P53D = 1; P54D = 0; P55D = 0; 	
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
     if(KEY_WALK_ROW(KEY_SCANNING_SORT) == KEY_DEPLOY_OK)  
      if(P52D == KEY_LOW && P53D == KEY_LOW)
       {
         P54D = KEY_HIGH; P55D = KEY_HIGH;
        if(P54D == KEY_HIGH && P55D == KEY_HIGH) clash=KEY_CLASH_NO;
           else if(P54D == KEY_LOW && P55D == KEY_LOW)  clash=KEY_CLASH_BE;
         if(P54D == KEY_LOW && P55D == KEY_HIGH && clash==KEY_CLASH_NO) {k0 = 1; }
         if(P55D == KEY_LOW && P54D == KEY_HIGH && clash==KEY_CLASH_NO) {k1 = 2; }
       }
     if(KEY_WALK_ROW(KEY_SCANNING_WALK) == KEY_DEPLOY_OK) 
      if(P54D == KEY_LOW && P55D == KEY_LOW)
       {
         P52D = KEY_HIGH; P53D = KEY_HIGH;
         if(P52D == KEY_HIGH && P53D == KEY_HIGH) clash=KEY_CLASH_NO;
           else if(P52D == KEY_LOW && P53D == KEY_LOW)  clash=KEY_CLASH_BE;
         if(P52D == KEY_LOW && P53D == KEY_HIGH && clash==KEY_CLASH_NO) 
		   {k2 = 0; 
		    if(k0 != 0)sum = k0+k2;
		    if(k1 != 0)sum = k1+k2;
		    }
         if(P53D == KEY_LOW && P52D == KEY_HIGH && clash==KEY_CLASH_NO) 
		   {k3 = 2;
		    if(k0 != 0)sum = k0+k3;
		    if(k1 != 0)sum = k1+k3; 
		    }
         }
    return (sum);	
 }
   
void main()
 {
 	unsigned char k;
 	 k=KEY_VALUE(4);
 	 printf("%d", k);
 	 
 }