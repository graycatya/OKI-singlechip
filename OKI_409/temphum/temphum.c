#include "temphum.h" 

/**********************************
 * 功能: A/D采样值换算 
 * 参数: CA_Y， CB_Y
 * 返回: sum
**********************************/
int Temp_trade(uint CA_Y, uint CB_Y)
 {
 	long int zhi=0;
 	int sum=0;
 	zhi=CB_Y;
 	sum=(zhi*1000)/CA_Y;
 	if(sum%10 >= 5)sum=sum/10+1;
 	 else sum=sum/10;
    return sum;
 } 

/**********************************
 * 功能: 摄氏度转换为华氏度 
 * 参数: zhi（温度数据） ,C_F(转换允许位)
 * 返回: zhi
**********************************/ 
int C_FCUTOVER(int zhi, int C_F)
 {
   int sum=0;
   
 	if(C_F==0)
 	  {
	   sum=((float)(zhi)*9/50+32)*100;
	    if(sum%10>=5)sum=sum/10+1;
         else sum=sum/10;
        }
    else 
      {sum=zhi;}
    return sum;
 }

/**********************************
 * 功能: A/D采样值转换为温度值函数(小数点算法)
 * 参数: TE（温度值） 
 * 返回: sum 
**********************************/    
int TEMP_ZH(int TE)
  {
      int sum;
       if(TE == -600)return TE; 
      sum=TE%10;
      if(sum>=5)sum=TE/10;
      else sum=TE/10;
      return sum;
  }


/**********************************
 * 功能: A/D采样值转换为温度值函数（反比例算法） 
 * 参数: CAI(温度采样数据), *TE（温度表）, *CA（温度采样表）, Ai（数组位置） 
 * 返回: zhi
**********************************/   
 int TE_A(int CAI,int *TE,int *CA, int Ai)
  {
     int sum=-600,c=0,d=0;
	  if(CAI > TE[Ai] && CAI < TE[Ai+1])
       {
 		  c=TE[Ai+1]-TE[Ai]+1;
 		  d=CAI-TE[Ai];
 		  sum=-(CA[Ai]*(-100)-(d*100)/c);  
    	}
	    else if(CAI == TE[Ai])
		   {
   			 sum=CA[Ai]*100;
   	    	}
	    else if(CAI == TE[Ai+1])
		   {
   			 sum=CA[Ai+1]*100;   
		   }
     return sum;
   }

/**********************************
 * 功能: A/D采样值转换为温度值函数(正比例算法)
 * 参数: CAI(温度采样数据), *TE（温度表）, *CA（温度采样表）, Ai（数组位置）  
 * 返回: zhi
**********************************/  
int TE_B(int CAI, int *TE, int *CA, int Bi)
 {
 	int sum=-600,c=0,d=0;
       if(CAI > TE[Bi] && CAI < TE[Bi+1])
		   {
   			 c=TE[Bi+1]-TE[Bi]+1;
   			 d=CAI-TE[Bi];
   			 sum=CA[Bi]*100+(d*100)/c; 
	        }
		  else if(CAI == TE[Bi])
		   {
   			 sum=CA[Bi]*100;
   	    	}
		  else if(CAI == TE[Bi+1])
		   {
   			 sum=CA[Bi+1]*100;
   		    }	
     return sum; 
   }
   


/**********************************
 * 功能: A/D采样值转换为温度值函数 
 * 参数: CAI_Y(温度采样值), SHU（温度范围）, *TEM（温度表）, *CA_Z（采样对照表） 
 * 返回: zhi
**********************************/
int H_T(int CAI_Y,int SHU, int *TEM, int *CA_Z)
 {
	int i=0;
	int zhi=-600;
  	
  for(i=0;i<SHU;i++)
    {
	  	if(i<50)
	  	 {
 	  		zhi=TE_A(CAI_Y, TEM, CA_Z, i); /*-50-0温度算法*/
     	    zhi=TEMP_ZH(zhi);
 	  		if(zhi!=-600)break;
 	  	  }
  	    else if((i>49 && i<172)) 
         {
   		    zhi=TE_B(CAI_Y, TEM, CA_Z, i); /*0-95温度算法*/
            zhi=TEMP_ZH(zhi);
		    if(zhi!=-600)break;
      	  }
      }
      
   	return zhi;  
  }
  
/**********************************
 * 功能: A/D采样值转换为湿度度值函数 
 * 参数: CAI_Y（湿度采样值）, TEMP（算法处理后的温度）, SHU（湿度范围）, *HU（湿度表）, *TE（温度表）,  H_CAY[][_HUM_]（采样对照表） 
 * 返回: zhi
**********************************/
int H_H(int CAI_Y, int TEMP, int SHU, int *HU, int *TE, uint H_CAY[][_HUM_])
 {
   int zhi=-600,i;
   if(TEMP>=0 && TEMP<=60)
     for(i=0; i<SHU; i++)
      {
       	if(TEMP==TE[i])zhi=HUM_A(CAI_Y, HU, H_CAY, i);
       	 else if(TEMP>TE[i] && TEMP<TE[i+1])
		      {
	      	   int X=0,Y=0;
  	              uint NEW_hum[1][_HUM_];
  	              X=TEMP-TE[i];
   	              Y=(X*10/4); 
   	              HUM_HS(Y, H_CAY, NEW_hum, i);

   	              zhi=HUM_A(CAI_Y, HU, NEW_hum, 0); 
      		   }
       	if(zhi!=-600)break;
       }
     return zhi;
 }
 
/**********************************
 * 功能: A/D采样值转换为湿度值函数(正比例算法)
 * 参数: CAI（湿度采样值）, *H（湿度表）, CA（采样表）, Bi（采样值对应表的位置） 
 * 返回: zhi
**********************************/  
int HUM_A(int CAI, int *H, uint CA[][_HUM_], int Bi)
 {
 	int sum=-600,j;
 	long int c=0,d=0;
     for(j=0; j<_HUM_; j++)
      {
      	if(CAI>=CA[Bi][j] && CAI<=CA[Bi][j+1])
      	 {
 	      	c=CAI-CA[Bi][j]+1;
 	      	d=(c*100)/(CA[Bi][j+1]-CA[Bi][j]);
 	      	if(d%10>5)d=d+5; //四舍五入处理 
 	      	d=(6*d)/100;
 	      	sum=H[j]+d;
 	      }
       }
     return sum; 
   }
   
/**********************************
 * 功能: 温度->湿度误差处理（建立中间区域未知表格） 
 * 参数: T_P（处理后表值）, H_z（湿度表）, NEW_h（处理后湿度表接口）, bi（表格位置传输） 
 * 返回: 无 
**********************************/     
void HUM_HS(int T_P,uint H_z[][_HUM_], uint NEW_h[1][_HUM_], int bi)
 {
  	int i=0;
	 for(i=0; i<_HUM_; i++)
	   NEW_h[0][i]=(T_P*(H_z[bi+1][i]-H_z[bi][i]))/10+H_z[bi][i];
 }

