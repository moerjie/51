#include<reg51.h>
sbit led = P2^0;
void it0_isr()interrupt 0	  //�жϷ�����
{
	led = !led;				 
}
void it0_init()			//�жϳ�ʼ��
{
	EA = 1;				//���жϿ�
	EX0 = 1;			//IT0�жϿ�
	IT0 = 1;		   //TCON�п���INT0������ʽλ��INT0�½��ش����ж�
}
void main()
{
	it0_init();	   //�ȴ��ж�
	while(1);
}