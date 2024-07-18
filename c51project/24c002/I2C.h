#ifndef __I2C_H__
#define __I2C_H__

void I2C_start();
void I2C_stop();
void I2C_sendByte(unsigned char Byte);
unsigned char I2C_ReceiveByte();
void I2C_SendAck(unsigned char Ackbit);
unsigned char I2C_ReceiveACK();


#endif