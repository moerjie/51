#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
#include<TLC549.c>
code uchar seven_seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; 
uchar cp1,cp2;
uint dat_ad;
/*T0��ʼ��*/
void timer0_ier()interrupt 1
{
	TL0 = (65536 - 5000) % 256;
	TH0 = (65536 - 5000) / 256;
	cp1++;
	if(cp1 >= 100)								  //0.5s
	{
		cp1 = 0;
		dat_ad = tlc549_ad();
		dat_ad = dat_ad * 1.96;					  //����255��Ӧģ���ѹ5V
	}
	P0 = 0xff;
	switch(cp2)
	{
		case 0: P0 = seven_seg[dat_ad % 10];P2 = 0x01;break;
		case 1: P0 = seven_seg[dat_ad / 10 % 10];P2 = 0x02;break;
		case 2: P0 = seven_seg[dat_ad / 100] & 0x7f;P2 = 0x04;break;	//����С����
	}
	cp2++;
	if(cp2 >= 3)
	cp2 = 0;
}
/*�жϷ�����*/
void timer0_init()
{
	TMOD = 0x01;
	TL0 = (65536 - 5000) % 256;
	TH0 = (65536 - 5000) / 256;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}
void main()
{
	timer0_init();
	tlc549_init();
	while(1);
}