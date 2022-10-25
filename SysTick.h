/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef  SYSTICK_H
#define  SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include "TM4C123GH6PM.h"
#include "NVIC.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SYSCTL_RCC_XTAL_16MHZ                 0x00000540  
#define NUMBER_OF_OVERFLOWS_PER_SECOND 


#define STCTRL                              *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x010)
#define STRELOAD                            *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x014)
#define STCURRENT                           *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x018)	

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern void (*SysTick_Cbk_ptr)(void);
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : 
* \Description     :  
*                                                       
*                                                                             
* \Sync\Async      :                                                
* \Reentrancy      :                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Init(void);
 
/******************************************************************************
* \Syntax          : 
* \Description     :  
*                                                       
*                                                                             
* \Sync\Async      :                                                
* \Reentrancy      :                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 void SysTick_Handler(void);
 
 
#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick.h
 *********************************************************************************************************************/