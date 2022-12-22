

#include <stdlib.h>
#include <stdint.h>
#include "/MCAL/GPIO.h"
#include "/MCAL/SysTick.h"




 //volatile uint32_t seconds;
 uint32_t ON_Time=2 ;    
 uint32_t OFF_Time=1;



int main()
{
	
	/*GPIO Init for buttons and led*/
  GPIO_RCGEnablePorts();
	
	/*SysTick Timer Init*/
	SysTick_Init();
	//SysTick_Cbk_ptr=SysTick_CallBack;
	
	GPIO_SetPin(GPIO_PortA, GPIO_Pin0, GPIO_PinOut);
	while(1)
	{
		GPIO_WriteChannel(GPIO_PortA,GPIO_Pin0, GPIO_LevelHigh);
		STK_SetWait(ON_Time);
		GPIO_WriteChannel(GPIO_PortA,GPIO_Pin0, GPIO_LevelLow);
		STK_SetWait(OFF_Time);
		/* number of button clicked is equal seconds count so: ON_time=2 *seconds, OFF_time=seconds*/

			
	
	}
	
	return 0;
}

/*void SysTick_CallBack(void)
{
	

	seconds++;
	
	
	if(seconds == ON_Time) 
	 
	{
	   //Port_Write(&led,1);
		 seconds=0;
	}
	
	if(seconds == OFF_Time)  
	{
	  //Port_Write(&led,0);
		seconds=0;
	}
		
	/*led ON
	GPIO_PORT_A_DATA=1;
	led ON
	GPIO_PORT_A_DATA=0;*/
	

//}*/
