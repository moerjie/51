/*
 * @Author: Moerjie
 * @Data: Do not edit
 * @LastEditTime: 2023-08-28 13:38:40
 * @FilePath: \程序\main.c
 */
#include<reg51.h>
sbit LED_R = P0^0;		  //LED接P0.0
sbit LED_B = P0^1;
void delay(unsigned int x)			 //延时函数
{
	while(x--);
}
void main()							 //主函数
{
	while(1)
	{
		LED_R=0;									  //P0.0输出低电平，LED灭
		delay(500000);							 //调用延时函数，延时一段时间
		LED_R=1;									//P0.0输出高电平，LED亮
		delay(500000);						   //调用延时函数，延时一段时间
		LED_B=0;
		delay(500000);
		LED_B=1;
		delay(500000);
	}
}  
