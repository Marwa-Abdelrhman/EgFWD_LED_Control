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
#include "/MCal/GPIO.h"
#include <stdlib.h>
#include "bit_maths.h"



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
* \Syntax          : GPIO_RCGEnablePorts(void)       
* \Description     : RCG func to enable GPIO Port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_RCGEnablePorts(void)
{
	SET_BIT(RCGCGPIO , RCGPortA);
	SET_BIT(RCGCGPIO , RCGPortB);
	SET_BIT(RCGCGPIO , RCGPortC);
	SET_BIT(RCGCGPIO , RCGPortD);
	SET_BIT(RCGCGPIO , RCGPortE);
	SET_BIT(RCGCGPIO , RCGPortF);
}

/******************************************************************************
* \Syntax          : GPIO_SetPin(GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_PinType PinDi)       
* \Description     : func to set pin Dirction                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_PinType PinDi)                  
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void GPIO_SetPin(GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_PinType PinDi)
{
	switch(PortId)
	{
		case GPIO_PortA : 
					SET_BIT(GPIOA->DEN , PinId);
					if(PinDi == GPIO_PinOut)
						SET_BIT(GPIOA->DIR , PinId);
					else
						CLR_BIT(GPIOA->DIR , PinId);
					break;
		case GPIO_PortB :
					SET_BIT(GPIOB->DEN , PinId);
					if(PinDi == GPIO_PinOut)
						SET_BIT(GPIOB->DIR , PinId);
					else
						CLR_BIT(GPIOB->DIR , PinId);
					break;
		case GPIO_PortC :
					SET_BIT(GPIOC->DEN , PinId);
					if(PinDi == GPIO_PinOut)
						SET_BIT(GPIOC->DIR , PinId);
					else
						CLR_BIT(GPIOC->DIR , PinId);
					break;
		case GPIO_PortD :
					SET_BIT(GPIOD->DEN , PinId);
					if(PinDi == GPIO_PinOut)
						SET_BIT(GPIOD->DIR , PinId);
					else
						CLR_BIT(GPIOD->DIR , PinId);
					break;
		case GPIO_PortE :
					SET_BIT(GPIOE->DEN , PinId);
					if(PinDi == GPIO_PinOut)
						SET_BIT(GPIOE->DIR , PinId);
					else
						CLR_BIT(GPIOE->DIR , PinId);
					break;
		case GPIO_PortF :
					SET_BIT(GPIOF->DEN , PinId);
					if(PinDi == GPIO_PinOut)
						SET_BIT(GPIOF->DIR , PinId);
					else
						CLR_BIT(GPIOF->DIR , PinId);
					break;
					
			
	}
}

/******************************************************************************
* \Syntax          : void GPIO_WriteChannel(GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_LevelType Level)        
* \Description     : func to set pin value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_LevelType Level)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_WriteChannel(GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_LevelType Level)
{
	switch(PortId)
	{
		case GPIO_PortA : 
					
					if(Level == GPIO_LevelHigh)
						SET_BIT(GPIOA->DATA , PinId);
					else
						CLR_BIT(GPIOA->DATA , PinId);
					break;
		case GPIO_PortB :
					
					if(Level == GPIO_LevelHigh)
						SET_BIT(GPIOB->DATA , PinId);
					else
						CLR_BIT(GPIOB->DATA , PinId);
					break;
		case GPIO_PortC :
					if(Level == GPIO_LevelHigh)
						SET_BIT(GPIOC->DATA , PinId);
					else
						CLR_BIT(GPIOC->DATA , PinId);
					break;
		case GPIO_PortD :
					if(Level == GPIO_LevelHigh)
						SET_BIT(GPIOD->DATA , PinId);
					else
						CLR_BIT(GPIOD->DATA , PinId);
					break;
		case GPIO_PortE :
					if(Level == GPIO_LevelHigh)
						SET_BIT(GPIOE->DATA , PinId);
					else
						CLR_BIT(GPIOE->DATA , PinId);
					break;
		case GPIO_PortF :
					if(Level == GPIO_LevelHigh)
						SET_BIT(GPIOF->DATA , PinId);
					else
						CLR_BIT(GPIOF->DATA , PinId);
					break;
		
		
	}
}
/******************************************************************************
* \Syntax          : GPIO_ReadChannel(GPIO_PortType PortId, GPIO_PinNo PinId)        
* \Description     : func to read pin value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (GPIO_PortType PortId, GPIO_PinNo PinId)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
GPIO_LevelType GPIO_ReadChannel(GPIO_PortType PortId, GPIO_PinNo PinId)
{
	GPIO_LevelType PinValue;
	switch(PortId)
	{
		case GPIO_PortA :PinValue = GET_BIT(GPIOA->DATA , PinId); break;
		case GPIO_PortB :PinValue = GET_BIT(GPIOB->DATA , PinId); break;
		case GPIO_PortC :PinValue = GET_BIT(GPIOC->DATA , PinId); break;
		case GPIO_PortD :PinValue = GET_BIT(GPIOD->DATA , PinId); break;
		case GPIO_PortE :PinValue = GET_BIT(GPIOE->DATA , PinId); break;
		case GPIO_PortF :PinValue = GET_BIT(GPIOF->DATA , PinId); break;
		default :	break;
	}
	return PinValue;
}

/******************************************************************************
* \Syntax          : uint8_t GPIO_ReadPort(GPIO_PortType PortId)       
* \Description     : func to read port value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (GPIO_PortType PortId)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
uint8_t GPIO_ReadPort(GPIO_PortType PortId)
{
	uint8_t PortValue;
	switch(PortId)
    {
    case GPIO_PortA :PortValue = GPIOA->DATA;	break;
    case GPIO_PortB :PortValue = GPIOB->DATA;	break;
    case GPIO_PortC :PortValue = GPIOC->DATA;	break;
    case GPIO_PortD :PortValue = GPIOD->DATA;	break;
    case GPIO_PortE :PortValue = GPIOE->DATA; break;
    case GPIO_PortF :PortValue = GPIOF->DATA;	break;
    default :	break;
    }
    return PortValue;
}

/******************************************************************************
* \Syntax          : GPIO_WritePort(GPIO_PortType PortId, uint8_t Value)      
* \Description     : func to Write on port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (GPIO_PortType PortId, uint8_t Value)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_WritePort(GPIO_PortType PortId, uint8_t Value)
{
	switch(PortId)
    {
    case GPIO_PortA :GPIOA->DATA = Value;	break;
    case GPIO_PortB :GPIOB->DATA = Value;	break;
    case GPIO_PortC :GPIOC->DATA = Value;	break;
    case GPIO_PortD :GPIOD->DATA = Value;	break;
    case GPIO_PortE :GPIOE->DATA = Value; break;
    case GPIO_PortF :GPIOF->DATA = Value;	break;
    default :	break;
	}
}

/******************************************************************************
* \Syntax          : void GPIO_FlipChannel(GPIO_PortType PortId, GPIO_PinNo PinId)        
* \Description     : to Toggle the channel value                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : GPIO_PortType PortId, GPIO_PinNo PinId                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_FlipChannel(GPIO_PortType PortId, GPIO_PinNo PinId)
{
	switch(PortId)
    {
    case GPIO_PortA :TOG_BIT(GPIOA->DATA, PinId);	break;
    case GPIO_PortB :TOG_BIT(GPIOB->DATA, PinId);	break;
    case GPIO_PortC :TOG_BIT(GPIOC->DATA, PinId);	break;
    case GPIO_PortD :TOG_BIT(GPIOD->DATA, PinId);	break;
    case GPIO_PortE :TOG_BIT(GPIOE->DATA, PinId);	break;
    case GPIO_PortF :TOG_BIT(GPIOF->DATA, PinId);	break;
    default :	break;
    }
}
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
