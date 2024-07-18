#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Matrixkey.h"
unsigned char keynum;//接收返回值
unsigned int password,count;
void main()
{
	LCD_Init();
	//LCD_ShowString(1,1,"dasahbi");
	while(1)
	{
			LCD_ShowString(1,2,"password ");
		keynum=Matrixkey();
		if(keynum!=0)
		{
			if(keynum<=10)
			{
				if(count<4)
				{
					password*=10;
					password+=keynum%10;//获取一位密码
				}		
			count++;
			LCD_ShowNum(2,4,password,4);//更新显示
			}
		}
		if(keynum==11)
		{
			if(password==1234)
			{
				LCD_ShowString(1,14,"ok ");
				password=0;
				count=0;
				LCD_ShowNum(2,4,password,4);//更新显示
			}
			else
				LCD_ShowString(1,14,"err");
				password=0;
				count=0;
			LCD_ShowNum(2,4,password,4);//更新显示
		}
	}	
}
