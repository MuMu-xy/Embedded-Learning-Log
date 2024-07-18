#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "key.h"
unsigned char KeyNum,LedMode;
void main()
{
	P2 = 0xFE;
	Timer0Init();
	while(1)
	{
		KeyNum = key();
		if(KeyNum==1)
		{
			LedMode=0;
		}
		if(KeyNum==2)
		{
			LedMode=1;
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=500)
	{
		T0Count = 0;
		if(LedMode == 0)P2 = _crol_(P2,1);
	  if(LedMode == 1)P2 = _cror_(P2,1);	
	}
}