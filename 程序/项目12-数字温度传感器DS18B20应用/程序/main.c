#include<reg51.h>									   
#include<DS18B20.c>
code uchar seven_seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uchar cp2;
uint aa,cp1;
uint temp_num,temp_num1,temp_dot,temp;
sbit P1_0=P1^0;
void timer0_isr()interrupt 1	   //�жϷ�����
{
	TH0 = (65536-2000)/256;			  //TH0���ú���
	TL0 = (65536-2000)%256;			  //TL0���ú���
	cp1++;
	if(cp1>=500)					  //1��
	{
		cp1 = 0;
		temp_num = Read_Temperature();			  //����ȡ�����¶ȸ�ֵ��temp_num
		temp_dot = c * 0.625;					   //�õ��¶ȵ�С��
		if((temp_num&0x80)==0x80)				  //����¶�Ϊ��ֵ
		{
			temp_dot = (0x0f-c)*0.625;			  //����ת��ԭ�룬С������
			temp_num1 = 0xff - temp_num;		  //����ת��ԭ�룬��������
		}
		else temp_num1 = temp_num;				  //С��ת��Ϊʮ����
	}
	P0 = 0xff;									  //����
	switch(cp2)
	{
		case 0:P1_0 = 0;P0 = 0x01;P1_0 = 1;P1_0 = 0;
		P0 = seven_seg[temp_dot];break;	      //��ʾС��
		case 1:P1_0 = 0;P0 = 0x02;P1_0 = 1;P1_0 = 0;
		P0 = 0x7f&seven_seg[temp_num1%10];break;	//��ʾ��λ����С����
		case 2:
		{
			if(temp_num<10)break;	 //����¶�С��10�ȣ��Ҳ�Ϊ��ֵ��ʮλ0����ʾ
			if((temp_num>0x80)&&(temp_num1<10))	 //����¶�С��10�ȣ���Ϊ��ֵ��ʮλ0����ʾ��ֻ��ʾ����
			{
				P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;
				P0 = 0xbf;break;
			}
			P1_0 = 0;P0 = 0x04;P1_0 = 1;P1_0 = 0;//����¶ȴ���10�ȣ�ʮλ������ʾ
			P0=seven_seg[temp_num1/10];
			break;
		}	  
		case 3:
		{
			if((temp_num>0x80)&&((temp_num1/10)>0))	   //���Ϊ��ֵ����ʮλ��Ϊ0����λ��ʾ����
			{
				P1_0 = 0;P0 = 0x08;P1_0 = 1;P1_0 = 0;
				P0 = 0xbf;
				break;	
			}
		}
	}
	cp2++;
	if(cp2>=4)cp2 = 0;		
}
void timer0_init()
{
	TMOD = 0x01;					   //��ʽһ
	TH0 = (65536-2000)/256;			   //TH0 Ԥ�ã�65536ʮ�����Ƶ�8λ��
	TL0 = (65536-2000)%256;			   //TL0 Ԥ�ã�65536ʮ�����Ƹ�8λ��
	EA = 1;							   //�ն��ܿ��ش�
	TR0 = 1;						   //��ʱ������T0����ͣ����λ��
	ET0 = 1;						   //��ʱ������T0���ж϶˿���λ��
}
void main()
{
	timer0_init();
	write_temprom(128,-55);	//��18B20���ݴ�д�ϡ������¶ȷֱ�Ϊ128��-55
	Write_OneChar(0x48);	//��18B20��rom��д����		
	while(1);
	//{
	//	temp = read_temprom;	//��DS18B20�ж�ȡ���¶ȸ�����temp 
	//}
}