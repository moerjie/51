#include<reg51.h>
#include<DEFINE.c>
#include<KEY.c>
#include<DISPLAY.c>
void timer_isr()interrupt 1			  //�жϷ�����
{
	TL0 = (65536-2000) %256;			  //TL0���ú���
	TH0 = (65536-2000)/256;			  //TH0���ú���
	cp++;
	if(cp>=250)       //0.5s
	{
		cp1++;
		cp = 0;
		flash = ~flash;        //0.5s  - ��˸
		if(cp1>=2)    //1s
		{
			if(mode==0)		   //����ʱ��ʱ��ֹͣ
			sec++;
			cp1 = 0;
			if(sec>=60)     //1min
			{
				min++;
				sec = 0;
				if(min>60)	 //1h
				{
					hour++;
					min = 0;
					if(hour>=24)hour = 0;
				}
			}
		}
	}
	P0 = 0xff;    //����
	switch(mode)
	{
		case 0:dis_play0();break;  //����
		case 1:dis_play1();break;  //��ʱ
		case 2:dis_play2();break;  //����
		case 3:dis_play3();break;  //����
		case 4:dis_play4();break;  //����ʱ
		case 5:dis_play5();break;  //���ַ�
	}
	i++;
	if(i>=8)i = 0;	
}
void timer0_init()				   //�жϳ�ʼ������
{
	TMOD = 0x01;				  //��ʽһ
	TL0 = (65536-2000)%256;		  //TL0 Ԥ�ã�65536ʮ�����Ƶ�8λ��
	TH0 = (65536-2000)/256;		  //TH0 Ԥ�ã�65536ʮ�����Ƹ�8λ��
	EA = 1;							//CPU�жϿ��� �����жϴ�
	ET0 = 1;						//��ʱ������T0������ն˿���λ��T0�жϴ�
	TR0 = 1;						//��ʱ������T0����ͣ����λ������T0
}
void main()
{
	timer0_init();				   //timer0��ʼ����Ϊ�ж���׼��
	while(1)
	{
		key();
		if(hour == hour_n && min == min_n)	   //���ӵ�ʱ�䣬��������
		{
			P3_2 = !P3_2;
			delay(50);
		}
	}
}