#include <REGX52.H>
#include "Delay.h"
sbit SER = P3^4;
sbit SCL = P3^6;
sbit RCL = P3^5;

#define MATRIX_LED_PORT P0
/*��������ʼ��*/
void Matrix_Init()
{
		SCL = 0;
	RCL = 0;
}

/**
	*@brief			74hc595д��һ���ֽ�
	*@parpm			д����ֽ�	
	*@retval		��
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
	*@brief		lcd������д��һ������
	*@parpm		column������Χ��0~7����numѡ������ʾ�����ݣ���λ���ϣ���1��0��
	*@retval	��
  */
void Matrix(unsigned char column,num)
{
	_74HC595_(num);
	MATRIX_LED_PORT = ~(0x80 >> column);
	Delay(1);
	MATRIX_LED_PORT = 0xFF;
}