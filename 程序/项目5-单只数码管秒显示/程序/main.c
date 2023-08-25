#include<reg51.h>
code unsigned char seven_seg[] ={0xc0,0xf9,0xa4,0xb0,0x99,0x92,
			0x82,0xf8,0x80,0x90};
unsigned char i,cp;
/*timer0���жϷ�����*/
void timer0_isr()interrupt 1	  	//�жϷ�����
{
	TL0 = (65536-5000)%256;			//TL0���ú���
	TH0 = (65536-5000)/256;			//TH0���ú���
	cp++;							//ÿ�δ����жϣ�cp��һ
	if(cp>=200)				  //200�Σ�1s
	{
		i++;
		cp = 0;
	}
		if(i>=10)i=0;
		P0=seven_seg[i];
		
}
void timer0_init()	             //�жϳ�ʼ������
{
	TMOD = 0x01;		    	 //��ʽһ
	TL0 = (65536-5000)%256;		 //TL0 Ԥ�ã�65536ʮ�����Ƶ�8λ��
	TH0 = (65536-5000)/256;		 //TH0 Ԥ�ã�65536ʮ�����Ƹ�8λ��
	EA = 1;						 //���жϿ���
	ET0 = 1;					//T0�жϴ�
	TR0 = 1;					 //������ʱ������T0
}
void main()
{
	timer0_init();				//timer_0��ʼ��,Ϊ�ж�����׼��
	while(1);
}	   