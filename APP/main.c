

#include <stdlib.h>
#include <stdint.h>
#include "GPIO.h"
#include "SysTick.h"




volatile uint32_t seconds;

uint32_t ON_Time ;    
uint32_t OFF_Time;
uint16_t button_clicked_count;

void (*SysTick_Cbk_ptr)(void);
void SysTick_CallBack(void);
void GPT_CallBack_Handler(void);
Port_PinConfigType button,led;

int main()
{
	
	/*GPIO Init for buttons and led*/

	button.port=GPIO_F;
	button.direction=INPUT;
	button.pin=PIN0;


	led.port=GPIO_A;
	led.direction=OUTPUT;
	led.pin=PIN3;

	/*SysTick Timer Init*/
	SysTick_Init();
	SysTick_Cbk_ptr=SysTick_CallBack;
	/*enable clk to GPIO A , GPIO F*/
	 SYSCTL->RCGCGPIO |= 0x21;
	
	while(1)
	{
		
		/* number of button clicked is equal seconds count so: ON_time=2 *seconds, OFF_time=seconds*/
		if(GPIO_PORT_A_DATA==1)
		{
			button_clicked_count++;
			ON_Time= 2*button_clicked_count;
			OFF_Time=3*button_clicked_count;
		
		}
			
	
	}
	
	return 0;
}

void SysTick_CallBack(void)
{
	

	seconds++;
	
	
	if(seconds == ON_Time) 
	 
	{
	   Port_Write(&led,1);
		 seconds=0;
	}
	
	if(seconds == OFF_Time)  
	{
	  Port_Write(&led,0);
		seconds=0;
	}
		
	/*led ON
	GPIO_PORT_A_DATA=1;
	led ON
	GPIO_PORT_A_DATA=0;*/
	

}