#include<reg51.h>
#include<AT24C04.c>
void delay(unsigned int x )
{
	while(x--);
}
void main()
{
	init_24c04();						 //I2���߳�ʼ������
	while(1)
	{
		write_add_dat_24c04(1,0x0f);	 //д���ַ1����������0x0f
		delay(300);						 //��ʱ
		write_add_dat_24c04(2,0xf0);	 //д���ַ������������0xf0
		delay(300);						 //��ʱ
		P0 = read_add_dat_24c04(1);		 //����ַ1����������0x0f������ʾ
		delay(50000);					 //��ʱ
		P0 = read_add_dat_24c04(2);		 //����ַ������������0xf0������ʾ
		delay(50000);					 //��ʱ
	}
}