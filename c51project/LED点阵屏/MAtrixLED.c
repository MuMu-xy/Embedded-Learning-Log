#include <REGX52.H>
#include "Delay.h"
sbit SER = P3^4;
sbit SCL = P3^6;
sbit RCL = P3^5;

#define MATRIX_LED_PORT P0
/*点阵屏初始化*/
void Matrix_Init()
{
		SCL = 0;
	RCL = 0;
}

/**
	*@brief			74hc595写入一个字节
	*@parpm			写入的字节	
	*@retval		无
  */
void _74HC595_(unsigned char num)
{
	unsigned int i;
	for(i=0;i<8;i++)
	{
		SER = num&(0x80>>i);
		SCL = 1;
		SCL = 0;
	}
	RCL = 1;
	RCL = 0;
}

/**
	*@brief		lcd点阵屏写入一个数据
	*@parpm		column列数范围（0~7），num选择列显示的数据（高位在上），1亮0灭
	*@retval	无
  */
void Matrix(unsigned char column,num)
{
	_74HC595_(num);
	MATRIX_LED_PORT = ~(0x80 >> column);
	Delay(1);
	MATRIX_LED_PORT = 0xFF;
}