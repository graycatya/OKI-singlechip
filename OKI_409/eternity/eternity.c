#include "eternity.h"


/**********************************
 * ����: ����������ƽ���㷨 
 * ����: ye
 * ����: int
**********************************/
int year(int ye)
 {
 	if(ye%400==0 || ye%100!=0 && ye%4==0)
 	  return 366;
  else
      return 365;
 }  
  
/**********************************
 * ����: �����������������㷨 
 * ����: mon(��),day���գ�,ye��0�굽20xx�걾���������,
          kv��ƽ/����2������״̬λ����da��12�������飩 
 * ����: week
**********************************/  
int date(int mon, int day, long int ye, int kv, int da[][12])
 { 
    int i;
    int begin,week;
        if(mon>1)
         for(i=0;i<mon-1;i++)  
           ye+=da[kv][i];
        week=(ye+day)%7;     //��ʾ����mon��day��Ϊ���ڼ�  
     return week;
  } 
  
/**********************************
 * ����: ʱ�Ӽ�ʱ���� 
 * ����: day(��),shi(ʱ),fen(��),miao(��)
 * ����: �� 
**********************************/ 
void time_CLK(int *day, int *shi, int *fen, int *miao) 
 {
      if(*miao > 59){ *miao=0; *fen=*fen+1;}
	  if(*fen > 59) { *fen=0; *shi=*shi+1; }
	  if(*shi > 23) { *shi=0; *day=*day+1; }	
 }
 
 
/**********************************
 * ����: �������ں��� 
 * ����: *variate(��Ҫ�ı����), often_MAX�����ֵ��,often_MIN(��Сֵ)
 * ����: �� 
**********************************/  
void var_mode(int *variate, int often_MAX, int often_MIN)
 {
 	*variate=*variate+1;
	 if(*variate>often_MAX) 
	  *variate = often_MIN;
 } 

/**********************************
 * ����: ��������ʱ������ 
 * ����: yea(��),ye_z���㷨��ʼ��ݣ�
 * ����: �� 
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
 * ����: ������������ 
 * ����: yea(��)��moon(��)��dayet(��),mode(����������ģʽ) 
 * ����: �� 
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
	for(i=ye_x;i<*yea;i++)  //*��2000�꿪ʼ 
      sum+=year(i);		
    week=date(*moon, *dayet, sum, r_p, days);
    return week;
   } 