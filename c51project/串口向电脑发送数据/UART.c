#include <REGX52.H>


/**
	*@brief���ڳ�ʼ��
	*@parpm
	*@retval
  */
void UART_Init()		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xF4;		//�趨��ʱ��ֵ
	TH1 = 0xF4;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	EA = 1;
	ES = 1;
}

/**
  *@brief���ڷ���һ���ֽڵ�����
	*@parpm
	*@retval
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
}

/**
	*@brief�����жϺ���ģ��
	*@parpm
	*@retval
  
void UART_Routine() interrupt 4
{
	if(RI == 1)
	{

		RI = 0;
	}
}*/