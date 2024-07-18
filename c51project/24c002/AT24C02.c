#include <REGX52.H>
#include "I2C.h"

#define AT24C02_ADDRESS 	0xA0

void AT24C02_WriteByte(unsigned char Address,Data)
{	
	I2C_start();
	I2C_sendByte(AT24C02_ADDRESS);
	I2C_ReceiveACK();
	I2C_sendByte(Address);
	I2C_ReceiveACK();
	I2C_sendByte(Data);
	I2C_ReceiveACK();
	I2C_stop();
}

unsigned char AT24C02_ReadByte(unsigned char Address)
{	
	unsigned char Data;
	I2C_start();
	I2C_sendByte(AT24C02_ADDRESS);
	I2C_ReceiveACK();
	I2C_sendByte(Address);
	I2C_ReceiveACK();
	I2C_start();
	I2C_sendByte(AT24C02_ADDRESS|0x01);
	I2C_ReceiveACK();
	Data = I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_stop();

	return Data;
}