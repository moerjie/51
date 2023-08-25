#include <reg51.h>
#define uchar unsigned char								//�� unsigned char �궨��Ϊ uchar
#define uint unsigned int								//�� unsigned int �궨��Ϊ uint
uchar month,year,date,sec,min,hour,week;
sbit rst = P3^4;										//���帴λ/Ƭѡ�߽�P3.4
sbit sclk = P3^7;										//���崮��ʱ�����Ž�P3.7
sbit sda = P3^5;										//���崮��������������˽�P3.5
/*��DS1302��ʼ��*/
void ds1302_init(void)
{
	rst = 0;										   //rstΪ�͵�ƽ
	sclk = 0;										   //sclkΪ�͵�ƽʱ�����ܽ�rst��Ϊ�ߵ�ƽ
	rst = 1;										   //rstΪ�ߵ�ƽ
}
/*��DS1302д1�ֽں���*/
void write_ds1302_onebyte(unsigned char dat)	   
{
	unsigned char i;
	for(i = 0;i < 8;i++)							   //ѭ��8�Σ��ó�һ�ֽ�����
	{
		sda = (bit)(dat & 0x01);					  //ǿ��ȡ���λ
		sclk = 0;									  //�͵�ƽ          ������д������
		sclk = 1;									 //�ߵ�ƽ
		dat = dat >> 1;								 //�����ɵ͵�������
	}
}
/*��DS1302��һ�ֽں���*/
uchar read_ds1302_onebyte(void)		
{
	unsigned char i,dat;
	for(i = 0;i < 8;i++)							 //ѭ��8�Σ��ó�һ�ֽ�����
	{
		sclk = 1;									//�͵�ƽ            �½��ض�������
		sclk = 0;									//�ߵ�ƽ
		dat = dat >> 1;								//�ɵ͵��߶���
		if(sda)dat = dat | 0x80;					//���������������1����1ȡ�����������λ
	}
	return(dat);								   //�����ݷ���
}
/*��DS1302��ĳһ��ַдһ�ֽں���*/
void write_ds1302_add_dat(unsigned char add,unsigned char dat)
{
	ds1302_init();			 //����
	write_ds1302_onebyte(add);	//д������
	write_ds1302_onebyte(dat);	//д������
	sclk = 1;					//��ʱ�ӵ�ƽ������֪״̬
	rst = 0;					//��ֹ���ݴ���
}
/*��DS1302��ĳһ��ַ��һ�ֽں���*/
uchar read_ds1302_add(unsigned char add)	//��1302������								
{
   unsigned char dat_temp;
	ds1302_init();				  //����
	write_ds1302_onebyte(add);			//д����
	dat_temp = read_ds1302_onebyte();  //������
	sclk = 1;						  //��ʱ�ӵ�ƽ������֪״̬
	rst = 0;						 //��ֹ���ݴ���
	return(dat_temp);			   //�����ݷ���
}
/*8421BCD�뵽ʮ����ת��*/
uchar BCD_DEC_conv(unsigned char x)
{
	unsigned char dec;
	dec =  0x0f & x;				//��������λ
	x = x >> 4;			   		   //����λ��Ϊ����λ
	dec	= dec + x * 10;			  //ת��Ϊʮ����
	return(dec);
}
/*ʮ����ת����8421BCD��*/
uchar DEC_BCD_conv(unsigned char x)
{
	unsigned char bcd;
	bcd =  x % 10;		  		  //ȡ�࣬����λ
	x = x / 10;					  //ȡ��������λ
	x = x << 4;					  //����λ��Ϊ����λ
	bcd	= bcd | x ;				  //�����㣬�ó�BCD��
	return(bcd);
}
/*���ʱ����Ϣ����*/
void get_ds1302_time(void)													//��ȡ1302��ʱ�����ݣ�ʱ���֡��룩������time1������
{
	unsigned char d;
	d = read_ds1302_add(0x81);												//����
	sec = BCD_DEC_conv(d);													//�õ���	
	d = read_ds1302_add(0x83);												//����
	min = BCD_DEC_conv(d);													//�õ���
	d = read_ds1302_add(0x85);												//��Сʱ
	hour = BCD_DEC_conv(d);													//�õ�Сʱ
	d = read_ds1302_add(0x87);												//����
	date = BCD_DEC_conv(d);													//�õ���
   	d = read_ds1302_add(0x89);												//����
	month = BCD_DEC_conv(d);												//�õ���
	d = read_ds1302_add(0x8b);												//������
	week = BCD_DEC_conv(d);													//�õ�����
	d = read_ds1302_add(0x8d);												//����
	year = BCD_DEC_conv(d);													//�õ���		
}
