/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
#include "GPIO.h"
#include <stdlib.h>



/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Port_Init(Port_PinConfigType *PortCnfgTypPtr)                                      
* \Description     :                                    
*                                                                             
* \Sync\Async      :                                               
* \Reentrancy      :                                              
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
 void Port_Init(Port_PinConfigType *PortCnfgTypPtr)
 {
	 if(PortCnfgTypPtr != NULL)
	 {
		 switch(PortCnfgTypPtr->port)
		 {
			 case GPIO_A:
				 if(PortCnfgTypPtr->direction==INPUT)
				   {
						 
						 GPIO_PORT_A_DIR   &=~(1<<PortCnfgTypPtr->pin);
					 }
				 else 
					 {
						 GPIO_PORT_A_DIR   |= (1<<PortCnfgTypPtr->pin);
					 }
				 break;
			 case GPIO_B:
				  if(PortCnfgTypPtr->direction==INPUT)
				   {
						 
						 GPIO_PORT_B_DIR   &=~(1<<PortCnfgTypPtr->pin);
					 }
				 else 
					 {
						 GPIO_PORT_B_DIR   |= (1<<PortCnfgTypPtr->pin);
					 }
				 break;
			 case GPIO_C:
				  if(PortCnfgTypPtr->direction==INPUT)
				   {
						 
						 GPIO_PORT_C_DIR   &=~(1<<PortCnfgTypPtr->pin);
					 }
				 else 
					 {
						 GPIO_PORT_C_DIR   |= (1<<PortCnfgTypPtr->pin);
					 }
				 break;
			 case GPIO_D:
				  if(PortCnfgTypPtr->direction==INPUT)
				   {
						 
						 GPIO_PORT_D_DIR   &=~(1<<PortCnfgTypPtr->pin);
					 }
				 else 
					 {
						 GPIO_PORT_D_DIR   |= (1<<PortCnfgTypPtr->pin);
					 }
				 break;
			 case GPIO_E:
				  if(PortCnfgTypPtr->direction==INPUT)
				   {
						 
						 GPIO_PORT_E_DIR   &=~(1<<PortCnfgTypPtr->pin);
					 }
				 else 
					 {
						 GPIO_PORT_E_DIR   |= (1<<PortCnfgTypPtr->pin);
					 }
				 break;
			 case GPIO_F:
				  if(PortCnfgTypPtr->direction==INPUT)
				   {
						 
						 GPIO_PORT_F_DIR   &=~(1<<PortCnfgTypPtr->pin);
					 }
				 else 
					 {
						 GPIO_PORT_F_DIR   |= (1<<PortCnfgTypPtr->pin);
					 }
				 break;
		 
		 }
	 }
	 
 }
 
 /******************************************************************************
* \Syntax          : void Port_Read(Port_PinConfigType *PortCnfgTypPtr,uint8_t *data)                                      
* \Description     :                                    
*                                                                             
* \Sync\Async      :                                               
* \Reentrancy      :                                              
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
 void Port_Read(Port_PinConfigType *PortCnfgTypPtr,uint32_t *data)
 {
	 if(PortCnfgTypPtr != NULL)
	 {
		 switch(PortCnfgTypPtr->port)
		 {
			 case GPIO_A:
				 *data = GPIO_PORT_A_DATA;
				 break;
			 
			 case GPIO_B:
				 *data = GPIO_PORT_B_DATA;
				 break;
			 
			 case GPIO_C:
				*data = GPIO_PORT_C_DATA;
				 break;
			 
			 
			 case GPIO_D:
				 *data = GPIO_PORT_D_DATA;
				 break;
			 
			 
			 case GPIO_E:
				*data = GPIO_PORT_E_DATA;
				 break;
			 
			 
			 case GPIO_F:
				 *data = GPIO_PORT_F_DATA;
				 break;
		 
		 }
	 }
 }
/******************************************************************************
* \Syntax          : void Port_Write(Port_PinConfigType *PortCnfgTypPtr,uint8_t data)                                      
* \Description     :                                    
*                                                                             
* \Sync\Async      :                                               
* \Reentrancy      :                                              
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
 void Port_Write(Port_PinConfigType *PortCnfgTypPtr,uint32_t data)
 {
	 if(PortCnfgTypPtr != NULL)
	 {
	  switch(PortCnfgTypPtr->port)
		 {
			 case GPIO_A:
				 GPIO_PORT_A_DATA = data;
				 break;
			 
			 case GPIO_B:
			GPIO_PORT_B_DATA= data;
				 break;
			 
			 case GPIO_C:
				 GPIO_PORT_C_DATA= data;
				 break;
			 
			 
			 case GPIO_D:
				 GPIO_PORT_D_DATA= data;
				 break;
			 
			 
			 case GPIO_E:
				 GPIO_PORT_E_DATA= data;
				 break;
			 
			 
			 case GPIO_F:
				 GPIO_PORT_F_DATA= data;
				 break;
		 
		 }
	 
	 }
 }
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
