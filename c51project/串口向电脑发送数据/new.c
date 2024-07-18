#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

void main()
{
	UART_Init();

	while(1)
	{

	}
}

void UART_Routine() interrupt 4
{
	if(RI == 1)
	{

		RI = 0;
	}