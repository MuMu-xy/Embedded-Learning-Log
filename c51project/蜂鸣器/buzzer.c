#include <REGX52.H>
#include "Delay.h"


sbit Buzzer = P2^5;

unsigned int i;

void buzzeer_time (unsigned int ms)
{
	for(i=0;i<ms;i++)
		{
			Buzzer = !Buzzer;
			Delay(1);
		}
	
	
}