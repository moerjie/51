#include<intrins.h>
#define uchar unsigned char 
#define nop _nop_()
sbit sda = P3^6;	   //sda����P3^6
sbit scl = P3^7;	  //scl����P3^7
/*I2��������*/
void start_24c04()	  //sclΪ�ߵ�ƽʱ��SDA�ɸ�������䣬��ʼ��������
{
	scl = 1;nop;	  
	sda = 1;nop;
	sda = 0;nop;
	scl = 0;
}
/*I2����ֹͣ*/
void stop_24c04()	  //sclΪ�ߵ�ƽʱ��SDA�ɵ�������䣬������������
{
	sda = 0;nop;	 
	scl = 1;nop;
	sda = 1;nop;
}
/*Ӧ�����*/
void ack_24c04()
{
	uchar i = 255;
	scl = 1;nop;
	while(sda&&i--);	   //�ȴ����صĵ͵�ƽ����û����Ӧ���ʵ���ʱ�Զ�����ִ��
	scl = 0;nop;
}
/*I2���߳�ʼ��*/
void init_24c04()
{
	sda = 1;nop;     //��̬
	scl = 0;nop;	 //��̬
}
/*��ȡһ���ֽ�*/
uchar read_onebyte_24c04()
{
	uchar i,dat;
	sda = 1;						   //�ͷ�����
	for(i = 0;i<8;i++)	              //ѭ���˴Σ��õ���λ������
	{
		scl = 1;					   //sclΪ�ߵ�ƽʱ�����sda״̬
		dat = dat<<1;				  //�ɸ�λ���λ��ȡ
		if(sda)						  //�ж�sda�Ƿ�Ϊ�ߵ�ƽ
		dat = dat|0x01;		  		  //���ǣ�dat���λ��һ��������Ϊ0
		scl = 0;					  //scl�õ͵�ƽ
	}
	sda = 1;						 //Ӧ��
	scl = 0;						 //    �ź�
	return(dat);
}
/*д��һ���ֽ�*/
void write_onebyte_24c04(uchar dat)
{
	uchar i;
	for(i=0;i<8;i++)				  //ѭ���˴Σ��õ���λ������
	{
		sda = (bit)(dat&0x80);		  //ȡ���λ
		dat = dat<<1;				  //�ɸ�λ���λд��
		scl = 1;
		scl = 0;
	}
	sda = 1;						 //Ӧ��
	scl = 0;						 //    �ź�
}
/*��ĳ����ַдһ�ֽڵ�����*/
void write_add_dat_24c04(uchar add,dat)
{
	start_24c04();					 //����
	write_onebyte_24c04(0xa0);		 //��AT24C04д����
	ack_24c04();					 //Ӧ��
	write_onebyte_24c04(add);		 //д�����ݴ�ŵ�ַ
	ack_24c04();					 //Ӧ��
	write_onebyte_24c04(dat);		 //д������
	ack_24c04();					 //Ӧ��
	stop_24c04();					 //ֹͣ
}
/*��ȡĳ����ַһ�ֽ�����*/
uchar read_add_dat_24c04(uchar add)
{
	uchar dat;
	start_24c04();					 //����
	write_onebyte_24c04(0xa0);		 //��AT24C04д����
	ack_24c04();					 //Ӧ��
	write_onebyte_24c04(add);		 //д�뽫Ҫ�������ݵ�ַ
	ack_24c04();					 //Ӧ��
	start_24c04();					 //����
	write_onebyte_24c04(0xa1);		 //��AT24C04������
	ack_24c04();					 //Ӧ��
	dat = read_onebyte_24c04();		 //��ֵ
	stop_24c04();					 //ֹͣ
	return (dat);
}