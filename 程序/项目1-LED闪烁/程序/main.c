/*
 * @Author: Moerjie
 * @Data: Do not edit
 * @LastEditTime: 2023-08-28 13:38:40
 * @FilePath: \����\main.c
 */
#include<reg51.h>
sbit LED_R = P0^0;		  //LED��P0.0
sbit LED_B = P0^1;
void delay(unsigned int x)			 //��ʱ����
{
	while(x--);
}
void main()							 //������
{
	while(1)
	{
		LED_R=0;									  //P0.0����͵�ƽ��LED��
		delay(500000);							 //������ʱ��������ʱһ��ʱ��
		LED_R=1;									//P0.0����ߵ�ƽ��LED��
		delay(500000);						   //������ʱ��������ʱһ��ʱ��
		LED_B=0;
		delay(500000);
		LED_B=1;
		delay(500000);
	}
}  
