/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef  GPIO_H
#define  GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include <stdint.h>

#include "TM4C123GH6PM.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PIN0 									0
#define PIN1 									1
#define PIN2 									2
#define PIN3 									3
#define PIN4									4
#define PIN5 									5
#define PIN6 									6
#define PIN7 									7




#define GPIODIR_OFFSET 					      0x400

#define GPIODATA_OFFSET 							0x000



#define GPIO_A_AHB 						((volatile uint32_t *)(0x40058000))

#define GPIO_B_AHB 						((volatile uint32_t *)(0x40059000))

#define GPIO_C_AHB 						((volatile uint32_t *)(0x4005A000))

#define GPIO_D_AHB 						((volatile uint32_t *)(0x4005B000))

#define GPIO_E_AHB 						((volatile uint32_t *)(0x4005C000))

#define GPIO_F_AHB 						((volatile uint32_t *)(0x4005D000))
	



#define GPIO_PORT_A_DIR              *(GPIO_A_AHB+GPIODIR_OFFSET)

#define GPIO_PORT_B_DIR              *(GPIO_B_AHB+GPIODIR_OFFSET)

#define GPIO_PORT_C_DIR              *(GPIO_C_AHB+GPIODIR_OFFSET)

#define GPIO_PORT_D_DIR              *(GPIO_D_AHB+GPIODIR_OFFSET)

#define GPIO_PORT_E_DIR              *(GPIO_E_AHB+GPIODIR_OFFSET)

#define GPIO_PORT_F_DIR              *(GPIO_F_AHB+GPIODIR_OFFSET)



#define GPIO_PORT_A_DATA             *(GPIO_A_AHB+ GPIODATA_OFFSET)

#define GPIO_PORT_B_DATA             *(GPIO_B_AHB+ GPIODATA_OFFSET)

#define GPIO_PORT_C_DATA             *(GPIO_C_AHB+ GPIODATA_OFFSET)

#define GPIO_PORT_D_DATA             *(GPIO_D_AHB+ GPIODATA_OFFSET)

#define GPIO_PORT_E_DATA             *(GPIO_E_AHB+ GPIODATA_OFFSET)

#define GPIO_PORT_F_DATA             *(GPIO_F_AHB+ GPIODATA_OFFSET)


	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef enum {
	
		INPUT,
		OUTPUT	
	
}Port_PinDirectionType;


typedef enum
{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F
	

}Port_PINType;

typedef struct {

	Port_PINType port;
	Port_PinDirectionType direction;
	uint8_t pin;

}Port_PinConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
 void Port_Init(Port_PinConfigType *PortCnfgTypPtr);

/******************************************************************************
* \Syntax          : void Port_Read(Port_PinConfigType *PortCnfgTypPtr,uint32_t *data)                                      
* \Description     :                                    
*                                                                             
* \Sync\Async      :                                               
* \Reentrancy      :                                              
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
 void Port_Read(Port_PinConfigType *PortCnfgTypPtr,uint32_t *data);
/******************************************************************************
* \Syntax          : void Port_Write(Port_PinConfigType *PortCnfgTypPtr,uint32_t data)                                      
* \Description     :                                    
*                                                                             
* \Sync\Async      :                                               
* \Reentrancy      :                                              
* \Parameters (in) :                     
* \Parameters (out):                                                       
* \Return value:   : None
*******************************************************************************/
 void Port_Write(Port_PinConfigType *PortCnfgTypPtr,uint32_t data);
 
 
#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
