#include <REGX52.H>
#include <INTRINS.H>
void Delay(unsigned int xms)		//��ʱ����
{
	unsigned char i, j;
	while(xms--)
			{
	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
			}			
}
unsigned char lednum;
void main()
{
	P2=~0x01;
	while(1)
	{
		if(P3_1==0)
			{
				Delay(20);
				while(P3_1==0);
				Delay(20);
				lednum++;
				if(lednum>8)
					lednum =0;
					P2=~(0x01<<lednum);				
			}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(lednum==0)
				lednum=7;
			else
				lednum--;
			P2=~(0x01<<lednum);	
		}
	}
}

//	unsigned int lednum=0;
//while(1)
//{
//	if(P3_1==0)
//	{
//		Delay(20);
//		while(P3_1==0);
//		Delay(20);
//		lednum++;
//		P2=~lednum;
//		
//	}
//}
//*******************************************
//while(1)
//	{
//	if(P3_1==0)
//		{
//			Delay(20);//������������
//			while(P3_1==0)�жϰ����Ƿ��������
//			Delay(20);
//			P2_0=~P2_0;ȡ��
//		}
//	}
//*********************************************
//	P2=0xFE;
	
//	
//	while(1)
//	{
//		if(P3_1==0)
//		{
//			P2_0=0;
//		}
//		else
//		{
//			P2_0=1;***���������ɿ�Ϩ��
//		}
//	}