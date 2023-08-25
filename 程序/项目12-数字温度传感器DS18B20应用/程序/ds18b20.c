/*delay��10��Լ����50΢�� */
#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int 
sbit DQ=P1^2;
void delay(unsigned char x)
{
	while(x--);
}
/*��ʼ������*/
void init_ds18b02()
{
	uchar x = 255;
	DQ = 1;				  //����DQ��1
	DQ = 0;				  //DQ����
	delay(80);			  //��ʱ480-960us
	DQ = 1;				  //�ͷ�����
	while(DQ&&x--);		  //�ȴ����صĵ͵�ƽ����û����Ӧ���ʵ���ʱ�Զ�����ִ��
	delay(20);			  //��ʱ
}
/*��18B20��дһ���ֽ� */
void Write_OneChar(uchar dat)
{
	uchar i = 0;
	for(i=8;i>0;i--)	  //ѭ��8�εó�����
	{	
		DQ = 0;			  //DQ���õ͵�ƽ
		DQ = dat&0x01;	  //ȡ���λ
		delay(10);		  //��ʱ��Լ15us
		DQ = 1;			  //�ͷ�����
		dat = dat>>1;	  //�ɵ�λ���λ��������
	}
	delay(8);
}
/*��18B20�ж�һ���ֽ� */
uchar Read_OneChar(void)
{
	uchar i = 0;
	uchar dat = 0;
	for(i=8;i>0;i--)	  //ѭ��8�εó�����
	{
		DQ = 0;			  //���������ź�
		dat = dat>>1;
		DQ = 1;			  //�ͷ�����
		if(DQ)			  //�ж������Ƿ�Ϊ�ߵ�ƽ
		dat = dat|0x80;	  //���ǣ�dat���λ��1��������0
		delay(10);		  //��ʱ
	}
	return(dat);
}
/*���¶� */
uchar a,b,c;
uchar Read_Temperature()
{
	uchar i = 0,t = 0;
	init_ds18b02();			    //����DS18B20
	Write_OneChar(0xcc);		//���������кŵĲ���
	Write_OneChar(0x44);		//�����¶�ת��
	init_ds18b02();				//����DS18B20
	Write_OneChar(0xcc);		//���������кŵĲ���
	Write_OneChar(0xbe);		//��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ�����ǰ�������¶�
	a = Read_OneChar();			//��ȡ�¶ȵ�λ
	b = Read_OneChar();			//��ȡ�¶ȸ�λ
	c = 0x0f&a;					//�õ�С������
	a = a>>4;					//��λ����4λ
	b = b<<4;					//��λ����4λ
	t = a|b;					//�õ�8λ�¶ȵ��������֣����λ1Ϊ����λ
	return (t);

}
/*�����¶�������*/
void  write_temprom(uchar temp_up_set,uchar temp_down_set)
{
	init_ds18b02();			    //����DS18B20
	Write_OneChar(0xcc);		//���������кŵĲ���
	Write_OneChar(0x4e);		//׼��д�ݴ���
	Write_OneChar(temp_up_set);	//д���¶�����	
	Write_OneChar(temp_down_set);	//д���¶�����
	Write_OneChar(0x7f);
	init_ds18b02();			    //����DS18B20
	Write_OneChar(0xcc);		//���������кŵĲ���
	Write_OneChar(0x48);		//�����ݴ�����ROM��
	init_ds18b02();			    //����DS18B20
	Write_OneChar(0xcc);		//���������кŵĲ���
	Write_OneChar(0xb8);		//�ص�E2PROM	
}				   
/*��ȡ�¶�������*/
uchar temp_up,temp_down;
void read_temprom()
{
	uchar i;
    init_ds18b02();			    //����DS18B20
	Write_OneChar(0xcc);		//���������кŵĲ���
	Write_OneChar(0xbe);		//��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
	i = Read_OneChar();			//��0��ַ�Ĵ������ӵ�
	i = Read_OneChar();			//��1��ַ�Ĵ������ӵ�
	temp_up = Read_OneChar();	//��2��ַ�Ĵ���
	temp_down = Read_OneChar();	//��3��ַ�Ĵ���
}		 