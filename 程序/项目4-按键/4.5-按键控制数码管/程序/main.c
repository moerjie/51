#include<reg51.h>
sbit key1 = P3^4;
code unsigned char seven_seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay(unsigned int x)	 //��ʱ����
{
	while(x--);
}
void key()		 //����������̧����Ч
{
	unsigned char i;
	if(key1==0)						   //��������
	{
		delay(300);					   //����
		if(key1==0)							 //��İ���
		{
			while(key1==0) ;			//�ȴ�̧��
			P0=seven_seg[i]; 			//��������ѡ������
			i++;						
			if(i>=10)i=0;
		}
	}
}
void main()
{
	P2=0x00;					//������ȡ��
	while(1)
	{
		key();					
	}
}