#include <REGX52.H>

sbit I2C_SDA = P2^0;
sbit I2C_SCL = P2^1;

void I2C_start()
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

void I2C_stop()
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

void I2C_sendByte(unsigned char Byte)
{
	unsigned char i;
	for(i = 0;i < 8;i++)
	{
		I2C_SDA = Byte&(0x80>>i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

unsigned char I2C_ReceiveByte()
{
	unsigned char Byte,i;
	I2C_SDA = 1;
	for(i = 0;i < 8;i++)
	{
		I2C_SCL = 1;
		if(	I2C_SDA)
		{
			Byte |= (0x80 >> i);
		}
		I2C_SCL = 0;
	}
	return Byte;
}

void I2C_SendAck(unsigned char Ackbit)
{
	I2C_SDA = Ackbit;
	I2C_SCL = 1;
	I2C_SCL = 0;
	
}

unsigned char I2C_ReceiveACK()
{
	unsigned char ACKbit;
	I2C_SDA = 1;
	I2C_SCL = 1;
	ACKbit = I2C_SDA;
	I2C_SCL = 0;
	return ACKbit;
}
