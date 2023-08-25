#include<reg51.h>
code P1_scan[]={0x7f,0xbf,0xdf,0xef}; //����ɨ������

code key_temp_value[]={0xee,0xed,0xeb,0xe7,0xde,0xdd,
         0xdb,0xd7,0xbe,0xbd,0xbb,0xb7,0x7e,0x7d,0x7b,0x77};   //������������Ӧ��ֵ

code unsigned char seven_seg[10]={0xc0,0xf9,0xa4,0xb0,0x99,	   
           0x92,0x82,0xf8,0x80,0x90};
void delay(unsigned int x)      //��ʱ����	
{
	while(x--);
}
unsigned char key_scan()	 //����ɨ�躯��
{
	unsigned i,j;
	for(i=0;i<4;i++)		//��ÿ�����߳��ֵ͵�ƽ������ɨ�����ݣ�
	{
		P1=P1_scan[i];
		if(P1!=P1_scan[i])
		{
			delay(200);			 //����
			if(P1!=P1_scan[i])
			{
				for(j=0;j<16;j++)  //��ⰴ��ֵ
				{
					if(P1==key_temp_value[j])
					return(j);	  //���ذ���ֵ
				}
			}
		}
	}
	return(88);
}
void display(unsigned char i)
{
	P2=~0x01;P0 = seven_seg[i%10];		//��ʾ������Ÿ�λ
	delay(300);							//�ø�λ��ʾһ��ʱ��
	P2=~0x02;P0 = seven_seg[i/10];		//��ʾ�������ʮλ
	delay(300);						   //��ʮλ��ʾһ��ʱ��
	P0 = 0xff;						  //����
}
void main()
{
	unsigned char i;
	while(1)
	{
		i = key_scan();
		display(i);
	}
} 