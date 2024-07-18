#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main()
{

	 while(1)
	 {
					Nixie(1,1); 
							//Delay(400);
		 			Nixie(2,0); 
		 					//Delay(400);
		 			Nixie(3,0); 
		 					//Delay(400);
		 			Nixie(4,8); 
		 					//Delay(400);
		 			Nixie(5,6); 
		 					//Delay(400);
	 }
}