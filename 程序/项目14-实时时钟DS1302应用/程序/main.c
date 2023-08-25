#include<reg51.h>
#include<ds1302.c>

unsigned char flash;
unsigned char cp1,cp2,cp3;													//�������
sbit P1_0 = P1^0;															
code unsigned char seven_seg[13] = {0xc0,0xf9,0xa4,0xb0,0x99,
										0x92,0x82,0xf8,0x80,0x90,0xbf,0xff,0x7f};			//����0~9����ʾ����
code unsigned char scan[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};		//λѡ����
bit conv;

void send(unsigned int x,unsigned int y)									//x��ʾλѡ��y��ʾ��ѡ
{
	P1_0 = 0;
	P1_0 = 1;
	P0 = scan[x];
	P1_0 = 0;																//P1.0�˿ڸߵ�ƽ����洢��P1.0Ϊ�͵�ƽ����洢
	P0 = seven_seg[y];			
}
void time0_isr(void) interrupt 1											//�����ж϶����������ʾ�����ݽ���ˢ��
{
	TH0 = (65536 - 2000) / 256;											   //TH0���ú���
	TL0 = (65536 - 2000) % 256;											  //TL0���ú���
	cp1++;
	if(cp1 >= 250)															//0.5��
	{
		cp1 = 0;
		flash = ~flash;														//������˸����
		cp2++;
		if(cp2 >= 5)
		{  
			cp2 = 0;
			conv = ~conv;												//����������ʾ����	
		}	
	}
	if(conv == 1)
	{
		P0 = 0xff;
		switch(cp3)
		{
			case 0:	send(0,sec % 10);break;								//��ʾ���λ
			case 1: send(1,sec / 10);break;								//��ʾ��ʮλ
			case 2:	if(flash)send(2,11);								//����ʾ
					else send(2,10);break;								//��ʾ -
			case 3: send(3,min % 10);break;								//��ʾ�ָ�λ
			case 4:	send(4,min / 10);break;								//��ʾ��ʮλ
			case 5:	if(flash)send(5,11);								//����ʾ
					else send(5,10);break;								//��ʾ -
			case 6:	send(6,hour % 10);break;							//��ʾСʱ��λ
			case 7:	send(7,hour / 10);break;							//��ʾСʱʮλ		
		}
	}
	else
	{	
		P0 = 0xff;														//����
		switch(cp3)
		{
			case 0:	send(0,date % 10);break;								//��ʾ���λ
		 	case 1:	send(1,date / 10);break;								//��ʾ��ʮλ
			case 2:	send(2,month % 10);break;								//��ʾ�¸�λ,
			case 3:	send(3,month / 10);break;								//��ʾ��ʮλ
			case 4:	send(4,year % 10);break;								//��ʾ���λ
			case 5:	send(5,year / 10);break;								//��ʾ��ʮλ
			case 6:	send(6,0);break;										//��ʾ0
			case 7:	send(7,2);break;										//��ʾ2
		}
	}  
	cp3++;
	if(cp3 >= 8)cp3 = 0;			
}
void timer0_init(void)														//Timer0��ʼ��
{																			//��ʽһ
	TMOD = 0x01;															//TH0 Ԥ�ã�65536ʮ�����Ƶ�8λ��
	TH0 = (65536 - 2000) / 256;												//TL0 Ԥ�ã�65536ʮ�����Ƶ�8λ��
	TL0 = (65536 - 2000) % 256;
	TR0 = 1;															   //��ʱ��T0��
	ET0 = 1;															   //����жϿ���λT0��
	EA  = 1;															   //�ܿ��ش�
}
void main(void)
{
	unsigned char i = 46;											//����������Ҫ����ʱ�䣬�����趨Ϊ46��
	i = DEC_BCD_conv(i);
	timer0_init();
	write_ds1302_add_dat(0x8e,0x00);						    	//д���������Զ�DS1302����
	write_ds1302_add_dat(0x80,0x30);								//д�룬30��
	write_ds1302_add_dat(0x82,i);							    	//д�֣�46��
	write_ds1302_add_dat(0x84,0x12);								//дʱ��12ʱ
	write_ds1302_add_dat(0x86,0x28);								//д�գ�28��
	write_ds1302_add_dat(0x88,0x05);								//д�£�5�� 
	write_ds1302_add_dat(0x8a,0x03);								//д���ڣ�������
	write_ds1302_add_dat(0x8c,0x12);								//д�꣬��20��12��
	write_ds1302_add_dat(0x8e,0x80);								//д����
	while(1)
	{
		get_ds1302_time();
	}
}
