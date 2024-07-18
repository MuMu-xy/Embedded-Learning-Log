#include <REGX52.H>
#include "Delay.h"
#include "key.h"
#include "Nixie.h"
#include "buzzer.h"

	
unsigned char keynum;
void main()
{		
	Nixie(1,keynum);
	Timer0Init();
	while(1)
	{
		keynum = Key();
		if(keynum)
		{		
			buzzeer_time(500);
				Nixie(1,keynum);

		}

	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值

}