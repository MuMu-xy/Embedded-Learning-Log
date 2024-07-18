#include <REGX52.H>
#include "key.h"
#include "Timer0.h"
#include "LCD1602.h"
unsigned char sec=55,min=59,hou=23;
void main()
{	
	LCD_Init();
	Timer0Init();	
	LCD_ShowString(1,1,"CLOCK");
	LCD_ShowString(2,3,":");
	LCD_ShowString(2,6,":");
	while(1)
	{
		LCD_ShowNum(2,7,sec,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,1,hou,2);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count = 0;
		sec++;
		if(sec>=60)
			{
				sec = 0;
				min++;
				if(min>=60)
					{
						min = 0;
						hou++;
						if(hou>=23)
						{
							hou=0;
						}
					}
			}

	}
}