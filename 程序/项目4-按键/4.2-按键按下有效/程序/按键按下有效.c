#include<reg51.h>
sbit key1 = P2^0;		  //P2.0�ڽӰ���
sbit led = P0^0;		 //P0.0�ڽ�LED
void delay(unsigned int x) //��ʱ����
{
	while(x--);
}
void key()
{
	if(key1==0)			 //�����������
	{
		delay(500);		    //����
		if(key1==0)	       //�����İ���
		{
		led=!led;		   
		delay(5000);	  //��ʱ
		}
	}
}
void main()
{
	P0 = 0x00;		   //��P0.0��ȫΪ�͵�ƽ
	while(1)
	{
		key();		   //���ð�������
	}
}	
