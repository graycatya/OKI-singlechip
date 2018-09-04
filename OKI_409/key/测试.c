
/**********************************
 * ����: A/D��������
 * ����: *yicu(������ɱ�־λ),*ALG_yicu�������㷨�������ݣ�,
         te(�¶Ȳ�������), hu(ʪ�Ȳ�������)
 * ����: ��
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
 * ����: ��ʪ�ȴ���
 * ����: *ALG_yicu(�㷨������), te(�¶Ȳ�������)
 	hu(ʪ�Ȳ�������), *tem(�¶ȴ������ӿ�)
         *hue(ʪ�ȴ������ӿ�)
 * ����: ��
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
 * ����: ��ʪ�Ȳ���ʱ���趨 
 * ����: delay_mode(���ò���ʱ��), *yicu(��������λ)��
         ALG_yicu(�㷨����λ) 
 * ����: ��
**********************************/
 void ADC_delay(uint delay_mode, uint *yicu, uint ALG_yicu)
  {
  	static int x=4,y=20;
  	if(delay_mode == 0 && *yicu == 0)  //2S��ʱ���� 
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
 * ����: ��ʪ�ȴ���
 * ����: ��
 * ����: ��
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