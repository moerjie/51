sbit sd = P3^5;							  //������
sbit cs = P3^4;							  //Ƭѡ
sbit scl = P3^7;						  //I/O��ʱ��
/*��TLC549��ʼ��*/
void tlc549_init()
{
	cs = 1;								  //��ʼ����ʱ��
	scl = 0;
	cs = 0;
}
/*��tlc549����ת��*/
uchar tlc549_ad()
{
	uchar i,dat_temp = 0;
	tlc549_init();
	for(i = 0;i < 8;i++)				  //��ȡ�ϴβɼ�������
	{
		scl = 1;
		dat_temp = dat_temp << 1;
		if(sd)dat_temp |= 0x01;			  //��sd = 1��dat_tempȡ���λ
		scl = 0;
	}
	cs = 1;
	return(dat_temp);
}