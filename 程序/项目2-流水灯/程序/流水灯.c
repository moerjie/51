#include<reg51.h>
code unsigned char  LED[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};	   //��ˮ������
void delay(unsigned int x)	  //��ʱ����
{
	while(x--);
}
void main()
{
	unsigned char i;
	while(1)
	{
	P0 = LED[i];		  //���������ڵ�����
	delay(5000);		 //��ʱ
	i++;				//ѭ��һ�Σ�����i��1
	if(i>=8)i=0;	   //i=8������
	}

}