void display(unsigned char x1,x2)
{
	P3_0 = 0;	  //��������
	P0 = x1;	  //����λѡ			 
	P3_0 = 1;	  //��������
	P3_0 = 0;	  //��������
	P0 = x2;	  //�����ѡ		
}
void dis_play0()			  //mode = 0 ����  ��ʾ
{
	switch(i)
	{
		case 0:display(0x01,seven_seg[sec%10]);break;	  //��ʾ���λ
		case 1:display(0x02,seven_seg[sec/10]);break;	  //��ʾ��ʮλ
		case 2:display(0x04,0xbf|flash);break;			  //��ʾ -	  ��˸
		case 3:display(0x08,seven_seg[min%10]);break;	  //��ʾ�ָ�λ
		case 4:display(0x10,seven_seg[min/10]);break;	  //��ʾ��ʮλ
		case 5:display(0x20,0xbf|flash);break;			  //��ʾ -    ��˸
		case 6:display(0x40,seven_seg[hour%10]);break;	  //��ʾʱ��λ
		case 7:display(0x80,seven_seg[hour/10]);break;	  //��ʾʱʮλ
	}
}
void dis_play1()			  //mode = 1 ��ʱ
{
	switch(i)
	{
		case 0:display(0x01,seven_seg[sec_t%10]);break;	  //��ʾ�����λ
		case 1:display(0x02,seven_seg[sec_t/10]);break;	  //��ʾ����ʮλ
		case 2:display(0x04,0xbf);break;				  //��ʾ -
		case 3:display(0x08,seven_seg[min_t%10]);break;	  //��ʾ���ָ�λ
		case 4:display(0x10,seven_seg[min_t/10]);break;	  //��ʾ����ʮλ
		case 5:display(0x20,0xbf);break;				  //��ʾ -
		case 6:display(0x40,seven_seg[hour_t%10]|flash);break;	 //��ʾ��ʱ��λ	   ��˸
		case 7:display(0x80,seven_seg[hour_t/10]|flash);break;	 //��ʾ��ʱʮλ	   ��˸
	}
}
void dis_play2()			  //mode = 2 ����
{
	switch(i)
	{
		case 0:display(0x01,seven_seg[sec_t%10]);break;	  //��ʾ�����λ
		case 1:display(0x02,seven_seg[sec_t/10]);break;	  //��ʾ����ʮλ
		case 2:display(0x04,0xbf);break;				  //��ʾ  -
		case 3:display(0x08,seven_seg[min_t%10]|flash);break;	  //��ʾ���ָ�λ   ��˸
		case 4:display(0x10,seven_seg[min_t/10]|flash);break;	  //��ʾ����ʮλ   ��˸
		case 5:display(0x20,0xbf);break;						  //��ʾ -
		case 6:display(0x40,seven_seg[hour_t%10]);break;		  //��ʾ��ʱ��λ
		case 7:display(0x80,seven_seg[hour_t/10]);break;		  //��ʾ��ʱʮλ
	}
}
void dis_play3()			  //mode = 3 ����
{
	switch(i)
	{
		case 0:display(0x01,seven_seg[sec_t%10]|flash);break;	  //��ʾ�����λ  ��˸
		case 1:display(0x02,seven_seg[sec_t/10]|flash);break;	  //��ʾ����ʮλ  ��˸
		case 2:display(0x04,0xbf);break;						  //��ʾ -
		case 3:display(0x08,seven_seg[min_t%10]);break;			  //��ʾ���ָ�λ
		case 4:display(0x10,seven_seg[min_t/10]);break;			  //��ʾ����ʮλ
		case 5:display(0x20,0xbf);break;						  //��ʾ -
		case 6:display(0x40,seven_seg[hour_t%10]);break;		  //��ʾ��ʱ��λ
		case 7:display(0x80,seven_seg[hour_t/10]);break;		  //��ʾ��ʱʮλ
	}
}		
void dis_play4()			  //mode = 4 ����ʱ
{
	switch(i)
	{
		case 0:display(0x01,0xbf);break;						  //��ʾ -
		case 1:display(0x02,0xbf);break;						  //��ʾ -
		case 2:display(0x04,0xbf);break;						  //��ʾ -
		case 3:display(0x08,seven_seg[min_n%10]);break;			  //��ʾ�ַָ�λ
		case 4:display(0x10,seven_seg[min_n/10]);break;			  //��ʾ�ַ�ʮλ
		case 5:display(0x20,0xbf);break;						  //��ʾ -
		case 6:display(0x40,seven_seg[hour_n%10]|flash);break;	  //��ʾ��ʱ��λ    ��˸
		case 7:display(0x80,seven_seg[hour_n/10]|flash);break;	  //��ʾ��ʱʮλ    ��˸
	}
}
void dis_play5()			  //mode = 5 ���ַ�
{
	switch(i)
	{
		case 0:display(0x01,0xbf);break;						  //��ʾ -
		case 1:display(0x02,0xbf);break;						  //��ʾ -
		case 2:display(0x04,0xbf);break;						  //��ʾ -
		case 3:display(0x08,seven_seg[min_n%10]|flash);break;	  //��ʾ�ַָ�λ    ��˸
		case 4:display(0x10,seven_seg[min_n/10]|flash);break;	  //��ʾ�ַ�ʮλ	��˸
		case 5:display(0x20,0xbf);break;						  //��ʾ -
		case 6:display(0x40,seven_seg[hour_n%10]);break;		  //��ʾ��ʱ��λ
		case 7:display(0x80,seven_seg[hour_n/10]);break;		  //��ʾ��ʱʮλ
	}
}