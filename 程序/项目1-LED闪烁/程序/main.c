#include<reg51.h>
sbit LED = P0^0;		  //LED��P0.0
void delay(unsigned int x)			 //��ʱ����
{
	while(x--);
}
void main()							 //������
{
	while(1)
	{
	LED=0;									  //P0.0����͵�ƽ��LED��
	delay(500000);							 //������ʱ��������ʱһ��ʱ��
	LED=1;									//P0.0����ߵ�ƽ��LED��
	delay(500000);						   //������ʱ��������ʱһ��ʱ��
	}
}  
