#include<reg51.h>
#include<lcd12864.c>
uchar sec = 59;
void main(void)
{
	F12864_init();
	F12864_clear();
	while(1)
	{
		sec++;
		if(sec >= 60)sec = 0;
		dprintf_hanzi_string_1(GB_16,1,16,6,0);			//�����ƶ�8��������Ϊ1
		display_string(5,7,"sec");						 //5��ʾ����8��������7Ҳ��8����ı���
		display_num(5,6,sec);display_string(7,6,":");							
	}
}