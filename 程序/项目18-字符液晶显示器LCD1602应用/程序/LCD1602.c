uchar num[] = "0123456789";	   
sbit RS = P2^2;
sbit RW = P2^1;
sbit E = P2^0;	
void delay(uint x)
{
	while(x--);	
} 
/***��LCDдһ������**/
void write_command(uchar command)
{
	RW = 0;
	RS = 0;
	P0 = command;
	E = 1;
	delay(100);//�ȴ����գ����Զ�״̬����
	E = 0;
	RW = 1;
} 
/***��LCDдһ������**/
void write_data(uchar date)
{
	RW = 0;
	RS = 1;
	P0 = date;
	E = 1;
	delay(100);//�ȴ�����
	E = 0;
	RW = 1;
} 
/**��ʼ��**/
void FLCD1602_init(void)
{
	write_command(0x38);//���У�ÿ��16���ַ���ÿ���ַ���5*7����
	write_command(0x0f);//�����ʾ����˸
	//write_command(0x0c);//��겻��ʾ
	write_command(0x06);//������ַ�����
}  
/**����**/
void FLCD1602_clear()
{
	write_command(0x01);
	write_command(0x02);
}
/**��LCDд�ַ���**/
void display_string(uchar *p)
{
	while(*p)//�ַ��ǿ�
	{
		write_data(*p);//д�ַ�
		p++;             //����ָ��++
	}
}
/**��LCDд���ֱ���**/
void display_num(uchar x)
{
	write_data(num[x / 10]);
	write_data(num[x % 10]);
}
/**��λ**/
void gotoxy(uchar y,uchar x)
{
	if(y == 1)
	write_command(0x40 + x);
	else if(y == 2)
	write_command(0x80 + 0x40 + x);
}				

