#include<reg51.h>
#include<intrins.h>
#include<adc0832.c>
code uchar seven_seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x82,0xf8,0x80,0x90};
uchar cp1,cp2,dat_ad;
void timer0_init()					//�жϳ�ʼ������
{
	TMOD = 0x01;					
	TL0 = 0x78;
	TH0 = 0xec;
	EA = 1;
	TR0 = 1;
	ET0 = 1;
}
void timer0_isr()interrupt 1	    //�жϷ�����
{
	TL0 = 0x78;
	TH0 = 0xec;
	cp1++;
	if(cp1>100)						//0.5s
	{
		cp1 = 0;
		dat_ad=adc0832_ch0();		//adc0832ת��һ��
	}
	P0 = 0xff;						//����
	switch(cp2)
	{
		case 0:P0 = seven_seg[dat_ad%10];P2 = 0x01;break;
	    case 1:P0 = seven_seg[dat_ad%100/10];P2 = 0x02;break;
		case 2:P0 = seven_seg[dat_ad/100];P2 = 0x04;break;
	}
	cp2++;
	if(cp2>=3)
	cp2 = 0;
}
void main()
{
	timer0_init();
	adc0832_init();
	while(1);
}