#include<intrins.h>
#define uchar unsigned char 
#define nop  _nop_()
sbit CS = P3^0;
sbit CLK = P3^1;
sbit DIDO = P3^2;
/*��ADC0832��ʼ������*/
void adc0832_init(void)
{
	CS = 1;nop;	                              
	CLK = 1;
	CS = 0;
}
/*��ת��ch0ͨ����ģ���ź�*/
uchar adc0832_ch0(void)
{
	uchar dat1,i;
	adc0832_init();
	DIDO = 1;CLK = 0;nop;CLK = 1;nop;		  //��һ���½��أ�DI����Ϊ�ߵ�ƽ����ʾ��ʼ�ź�
	DIDO = 1;CLK = 0;nop;CLK = 1;nop;		  //�ڶ����½���
	DIDO = 0;CLK = 0;nop;CLK = 1;nop;	      //�������½��أ�����1,0��ѡ��ͨ��ch0
	DIDO = 1;								  //�ͷ�����
	for(i = 0;i<8;i++)						  //��4���½��ص���11���½���
	{										 
		CLK = 0;nop;						  //
		if(DIDO)dat1 = dat1|0x01;			  //���λ��1
		CLK = 1;nop;						  //
		dat1 = dat1<<1;						  //���ƣ�����������λ
	}
	return(dat1);
	CS = 1;
}