/******************************************************
   key.h 
   
   ML610Q409��key������⹦�ܺ���ģ�飻
   
   History
    2017-9-26 
******************************************************/ 
//#ifndef _KEY_H_
//#define _KEY_H_ 
#include "MacroAndConst.h"

#define KEY_DEPLOY_OK   (0) //�ɹ� 
#define KEY_DEPLOY_FAIL (-1)//ʧ��

#define KEY_CLASH_NO (0) //�ް�����ͻ  
#define KEY_CLASH_BE (1) //������ͻ 

#define KEY_SCANNING_SORT (0)  //ɨ���� 
#define KEY_SCANNING_WALK (1)  //ɨ���� 

#define KEY_LOW  (0) //�͵�ƽ״̬  
#define KEY_HIGH (1) //�ߵ�ƽ״̬ 

#define KEY_NO (0x00) //�ް������� 
#define KEY_0 (0x01) //����0ֵ 
#define KEY_1 (0x02) //����1ֵ 
#define KEY_2 (0x04) //����2ֵ 
#define KEY_3 (0x08) //����3ֵ 

#define key_close_no   (0) //�޶̰� 
#define key_close_yes  (1) //�̰�ȷ�� 
#define key_often_no   (0) //�޳��� 
#define key_often_yes  (1) //����ȷ�� 

unsigned char Trg;  //�̰� 
unsigned char Cont; //������־ 
unsigned char cont; //������� 

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