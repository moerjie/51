void delay(unsigned int x)	//��ʱ����
{
	while(x--);
}
void key()				   //��������
{
	P2_4 = 0;
	if(key_set==0)		   //���������������
	{
		delay(300);		   //����
		if(key_set==0)	   //�������������İ���
		{
			while(key_set==0);
			mode++;
			if(mode>=6)mode = 0;   //mode=0���˳�����
			hour_t = hour;
			min_t = min;
			sec_t = sec;
		}
	}
	if(key_up==0)				  //������Ӱ�������
	{
		delay(300);				  //����
		if(key_up==0)			  //������Ӱ�����İ���
		{
			while(key_up==0);
			if(mode==1)hour_t++;if(hour_t>24)hour_t = 23;hour = hour_t;
			if(mode==2)min_t++;if(min_t>60)min_t = 59;min=min_t;
			if(mode==3)sec_t++;if(sec_t>60)sec_t = 59;sec = sec_t;
			if(mode==4)hour_n++;if(hour_n>24)hour_n = 23;
			if(mode==5)min_n++;if(min_n>60)min_n = 59;

		}
	}
	if(key_down==0)				 //�����С��������
	{							 
		delay(300);				 //����
		if(key_down==0)			 //�����С������İ���
		{
			while(key_down==0);
			if(mode==1)hour_t--;if(hour_t<0)hour_t = 0;hour = hour_t;
			if(mode==2)min_t--;if(min_t<0)min_t = 0;min=min_t;
			if(mode==3)sec_t--;if(sec_t<0)sec_t = 0;sec = sec_t;
			if(mode==4)hour_n--;if(hour_n<0)hour_n = 0;
			if(mode==5)min_n--;if(min_n<0)min_n = 0;

		}
	}
}