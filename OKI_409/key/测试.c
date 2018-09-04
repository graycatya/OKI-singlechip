
/**********************************
 * 功能: A/D采样函数
 * 参数: *yicu(采样完成标志位),*ALG_yicu（允许算法处理数据）,
         te(温度采样数据), hu(湿度采样数据)
 * 返回: 无
**********************************/
void Temperature(uint *yicu, uint *ALG_yicu, int *te, int *hu)
 {
  static int k=0;

  if(k==0 && *yicu == 1)
   {
   if(rcadc_Samp_Clk_init(rcad_three, rcad_two)==0)
    if(rcadc_radi(RCADC_A)==0) 
     if(rcadc_RCAD_run(RCADC_RUN)==0)
      k++;
   } 
  if(k==1)
   {
    if(RARUN==0 && rcadc_getResult(RCADC_A, te) == 0)
     k++;
    }
  if(k==2)
   {
   if(rcadc_Samp_Clk_init(rcad_six, rcad_two)==0)
    if(rcadc_radi(RCADC_A)==0) 
     if(rcadc_RCAD_run(RCADC_RUN)==0)
      k++;
   } 
  if(k==3)
   {
    if(RARUN==0 && rcadc_getResult(RCADC_A, hu) == 0)
      {k=0; *yicu = 0; *ALG_yicu=1;}
    }
}

/**********************************
 * 功能: 温湿度处理
 * 参数: *ALG_yicu(算法允许处理), te(温度采样数据)
 	hu(湿度采样数据), *tem(温度处理后传输接口)
         *hue(湿度处理后传输接口)
 * 返回: 无
**********************************/
void lcd_te_hum(uint *ALG_yicu, int te, int hu, int *tem, int *hue)
 {
  if(*ALG_yicu == 1)
   {
     *tem = H_T(te, 172, TEMP_AT, TEMP_BT);
     *hue = H_H(hu, (*tem/10), _HUM_TEMP_ , HUM_AT, HUM_TEMP_BT, HUM_CAY);
      *ALG_yicu = 0;
   }
 }
 
 /**********************************
 * 功能: 温湿度采样时间设定 
 * 参数: delay_mode(设置采样时间), *yicu(采样允许位)，
         ALG_yicu(算法允许位) 
 * 返回: 无
**********************************/
 void ADC_delay(uint delay_mode, uint *yicu, uint ALG_yicu)
  {
  	static int x=4,y=20;
  	if(delay_mode == 0 && *yicu == 0)  //2S延时采样 
  	 {
 	  y=20; 
 	  if(ALG_yicu == 0) x--;	
 	    if(x==0){x=4; *yicu=1;}
     }
    else if(delay_mode == 1 && *yicu == 0) 
     {
  	  x=4; 
      if(ALG_yicu == 0) y--;	
 	    if(x==0){y=20; *yicu=1;}	
	 } 
  } 
 








/**********************************
 * 功能: 温湿度处理
 * 参数: 无
 * 返回: 无
**********************************/
void lcd_te_hum(uint *yicu, int *tem, int *hu)
 {
   if(*yicu == 1)
   {
     *tem = H_T(*tem, 172, TEMP_AT, TEMP_BT);
      *hu = H_H(countb, (*tem/10), _HUM_TEMP_ , HUM_AT, HUM_TEMP_BT, HUM_CAY);
      *yicu = 0;
   }
   PICK_dataCOR(1);
   TEM_HUM_realtime(*tem , *hu);
  }