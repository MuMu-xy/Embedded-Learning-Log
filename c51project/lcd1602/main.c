#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
 void main()
 {
	 int result=0;
	 LCD_Init();
	 //LCD_ShowChar(1,1,'A');
	 //LCD_ShowString(1,3,"LOVE XIOAJING");
	 //LCD_ShowNum(1,1,);
	 
	 while(1)
	 {
		 result ++;
		 Delay(1500);
		 LCD_ShowNum(1,1,result,3);
	 }
 }