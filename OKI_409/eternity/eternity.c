#include "eternity.h"


/**********************************
 * 功能: 万年历闰年平年算法 
 * 参数: ye
 * 返回: int
**********************************/
int year(int ye)
 {
 	if(ye%400==0 || ye%100!=0 && ye%4==0)
 	  return 366;
  else
      return 365;
 }  
  
/**********************************
 * 功能: 万年历天数，星期算法 
 * 参数: mon(月),day（日）,ye（0年到20xx年本天的天数）,
          kv（平/润年2月天数状态位），da（12个月数组） 
 * 返回: week
**********************************/  
int date(int mon, int day, long int ye, int kv, int da[][12])
 { 
    int i;
    int begin,week;
        if(mon>1)
         for(i=0;i<mon-1;i++)  
           ye+=da[kv][i];
        week=(ye+day)%7;     //表示该年mon月day日为星期几  
     return week;
  } 
  
/**********************************
 * 功能: 时钟计时函数 
 * 参数: day(日),shi(时),fen(分),miao(秒)
 * 返回: 无 
**********************************/ 
void time_CLK(int *day, int *shi, int *fen, int *miao) 
 {
      if(*miao > 59){ *miao=0; *fen=*fen+1;}
	  if(*fen > 59) { *fen=0; *shi=*shi+1; }
	  if(*shi > 23) { *shi=0; *day=*day+1; }	
 }
 
 
/**********************************
 * 功能: 变量调节函数 
 * 参数: *variate(需要改变的量), often_MAX（最大值）,often_MIN(最小值)
 * 返回: 无 
**********************************/  
void var_mode(int *variate, int often_MAX, int often_MIN)
 {
 	*variate=*variate+1;
	 if(*variate>often_MAX) 
	  *variate = often_MIN;
 } 

/**********************************
 * 功能: 万年历延时处理函数 
 * 参数: yea(年),ye_z（算法开始年份）
 * 返回: 无 
**********************************/
long int year_judge(int yea , int *ye_z)
   {
 	 long int zhi=0;
 	  if(yea >= 2000 && yea < 2010) {zhi = 730119; *ye_z=2000;}
 	  if(yea >= 2010 && yea < 2020) {zhi = 733772; *ye_z=2010;}
 	  if(yea >= 2020 && yea < 2030) {zhi = 737424; *ye_z=2020;}
 	  if(yea >= 2030 && yea < 2040) {zhi = 741077; *ye_z=2030;}
 	  if(yea >= 2040 && yea < 2050) {zhi = 744729; *ye_z=2040;}
 	  if(yea >= 2050 && yea < 2060) {zhi = 748382; *ye_z=2050;}
 	  if(yea >= 2060 && yea < 2070) {zhi = 752034; *ye_z=2060;}
 	  if(yea >= 2070 && yea < 2080) {zhi = 755687; *ye_z=2070;}
 	  if(yea >= 2080 && yea < 2090) {zhi = 759339; *ye_z=2080;}
 	  if(yea >= 2090 && yea <= 2099){zhi = 762992; *ye_z=2090;}
 	  return zhi;
   } 

/**********************************
 * 功能: 万年历处理函数 
 * 参数: yea(年)，moon(月)，dayet(日),mode(万年历计算模式) 
 * 返回: 无 
**********************************/
int calendar_treat(int *yea, int *moon, int *dayet, int mode)
  {
  	int i,j,r_p=0,week,ye_x; 
  	long int sum=0;
    int days[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
   	 {31,29,31,30,31,30,31,31,30,31,30,31}};
     sum= year_judge(*yea, &ye_x);
    if(year(*yea)==366) r_p=1;
	 else  r_p=0; 
   if(mode == 0)
    {
     if(*dayet>days[r_p][*moon-1]){ *dayet=1; *moon=*moon+1;} 
     if(*moon>12){ *moon=1; *yea=*yea+1; }
     if(*yea>2099)*yea=2000;	  	
    }
    else if(mode == 1)
    {
     if(*yea>2099){*yea=2000; ye_x=2000; }	
     if(*moon>12)*moon=1;
	 if(*dayet>days[r_p][*moon-1])*dayet=1;    	
    }  	
	for(i=ye_x;i<*yea;i++)  //*从2000年开始 
      sum+=year(i);		
    week=date(*moon, *dayet, sum, r_p, days);
    return week;
   } 