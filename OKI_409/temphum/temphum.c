#include "temphum.h" 

/**********************************
 * ����: A/D����ֵ���� 
 * ����: CA_Y�� CB_Y
 * ����: sum
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
 * ����: ���϶�ת��Ϊ���϶� 
 * ����: zhi���¶����ݣ� ,C_F(ת������λ)
 * ����: zhi
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
 * ����: A/D����ֵת��Ϊ�¶�ֵ����(С�����㷨)
 * ����: TE���¶�ֵ�� 
 * ����: sum 
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
 * ����: A/D����ֵת��Ϊ�¶�ֵ�������������㷨�� 
 * ����: CAI(�¶Ȳ�������), *TE���¶ȱ�, *CA���¶Ȳ�����, Ai������λ�ã� 
 * ����: zhi
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
 * ����: A/D����ֵת��Ϊ�¶�ֵ����(�������㷨)
 * ����: CAI(�¶Ȳ�������), *TE���¶ȱ�, *CA���¶Ȳ�����, Ai������λ�ã�  
 * ����: zhi
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
 * ����: A/D����ֵת��Ϊ�¶�ֵ���� 
 * ����: CAI_Y(�¶Ȳ���ֵ), SHU���¶ȷ�Χ��, *TEM���¶ȱ�, *CA_Z���������ձ� 
 * ����: zhi
**********************************/
int H_T(int CAI_Y,int SHU, int *TEM, int *CA_Z)
 {
	int i=0;
	int zhi=-600;
  	
  for(i=0;i<SHU;i++)
    {
	  	if(i<50)
	  	 {
 	  		zhi=TE_A(CAI_Y, TEM, CA_Z, i); /*-50-0�¶��㷨*/
     	    zhi=TEMP_ZH(zhi);
 	  		if(zhi!=-600)break;
 	  	  }
  	    else if((i>49 && i<172)) 
         {
   		    zhi=TE_B(CAI_Y, TEM, CA_Z, i); /*0-95�¶��㷨*/
            zhi=TEMP_ZH(zhi);
		    if(zhi!=-600)break;
      	  }
      }
      
   	return zhi;  
  }
  
/**********************************
 * ����: A/D����ֵת��Ϊʪ�ȶ�ֵ���� 
 * ����: CAI_Y��ʪ�Ȳ���ֵ��, TEMP���㷨�������¶ȣ�, SHU��ʪ�ȷ�Χ��, *HU��ʪ�ȱ�, *TE���¶ȱ�,  H_CAY[][_HUM_]���������ձ� 
 * ����: zhi
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
 * ����: A/D����ֵת��Ϊʪ��ֵ����(�������㷨)
 * ����: CAI��ʪ�Ȳ���ֵ��, *H��ʪ�ȱ�, CA��������, Bi������ֵ��Ӧ���λ�ã� 
 * ����: zhi
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
 	      	if(d%10>5)d=d+5; //�������봦�� 
 	      	d=(6*d)/100;
 	      	sum=H[j]+d;
 	      }
       }
     return sum; 
   }
   
/**********************************
 * ����: �¶�->ʪ�����������м�����δ֪��� 
 * ����: T_P��������ֵ��, H_z��ʪ�ȱ�, NEW_h�������ʪ�ȱ�ӿڣ�, bi�����λ�ô��䣩 
 * ����: �� 
**********************************/     
void HUM_HS(int T_P,uint H_z[][_HUM_], uint NEW_h[1][_HUM_], int bi)
 {
  	int i=0;
	 for(i=0; i<_HUM_; i++)
	   NEW_h[0][i]=(T_P*(H_z[bi+1][i]-H_z[bi][i]))/10+H_z[bi][i];
 }

