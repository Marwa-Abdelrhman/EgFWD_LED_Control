/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  NVIC.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include <stdint.h>

#include "TM4C123GH6PM.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEX_PERI_BASE_ADDRESS				    *((volatile uint32_t *) 0xE000E000 )
	

#define INTCTRL 														*((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0xD04 )
#define APINT       												*((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0xD0C )
	

#define NVIC_PRI4                           *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x410 )
#define NVIC_PRI5                           *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x404 )
#define NVIC_PRI8                           *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x420 )
#define NVIC_PRI9                           *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x424 )
	
	
#define NVIC_EN0                            *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x100 )
#define NVIC_EN1                            *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0x104 )
	

#define SYS_CTRL                            *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0xD10 )
#define SYS_PRI1                            *((volatile uint32_t *) CORTEX_PERI_BASE_ADDRESS + 0xD18 )
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*Bit Field Struct to access bit instead of full reg in case of typecasted as union not uint32_t in macro*/
typedef struct 
{
	uint32_t VECACT			:8;
	uint32_t 						:3;
	uint32_t RETBASE		:1;
	uint32_t VECPEND		:8;
	uint32_t        		:2;
  uint32_t ISRPEND 	  :1;
	uint32_t ISRPRE 		:1;
	uint32_t        	  :1;
	uint32_t         		:1;
  uint32_t PENDSTCLR	:1;
  uint32_t PENDSTSET	:1;
  uint32_t UNPENDSV 	:1;
  uint32_t PENDSV   	:1;
  uint32_t          	:2;
  uint32_t NMISET   	:1; 
}INTCTRL_BF; 


typedef struct 
{
	uint32_t VECTRESET	:1;
	uint32_t VECTCLRACT	:1;
	uint32_t SYSRESREQ	:1;
	uint32_t  		      :5;
	uint32_t PRIGROUP   :3;
  uint32_t   	        :4;
	uint32_t ENDIANESS 	:1;
	uint32_t VECTKEY    :16;

}APINT_BF;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
 void IntCrtl_Init(void) ;
#endif  /* NVIC_H */

/**********************************************************************************************************************
 *  END OF FILE: NVIC.h

 *********************************************************************************************************************/
