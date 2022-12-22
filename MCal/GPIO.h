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

#include "bit_maths.h"

  /**********************************************************************************************************************
   *  GLOBAL CONSTANT MACROS
   *********************************************************************************************************************/
#define RCGPortA					0
#define RCGPortB					1
#define RCGPortC					2
#define RCGPortD					3
#define RCGPortE					4
#define RCGPortF					5



#define GPIOA				 ((GPIOA_Type_*)0x40004000)
#define GPIOB				 ((GPIOA_Type_*)0x40005000)
#define GPIOC				 ((GPIOA_Type_*)0x40006000)
#define GPIOD				 ((GPIOA_Type_*)0x40007000)
#define GPIOE				 ((GPIOA_Type_*)0x40024000)
#define GPIOF				 ((GPIOA_Type_*)0x40025000)



   // the register to enable gpio ports
#define RCGCGPIO								*((volatile uint32_t *)(0x400FE000 + 0x608))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


 /**********************************************************************************************************************
  *  GLOBAL DATA TYPES AND STRUCTURES
  *********************************************************************************************************************/
typedef enum
{
	GPIO_PortA,
	GPIO_PortB,
	GPIO_PortC,
	GPIO_PortD,
	GPIO_PortE,
	GPIO_PortF
}GPIO_PortType;


typedef enum
{
	GPIO_Pin0,
	GPIO_Pin1,
	GPIO_Pin2,
	GPIO_Pin3,
	GPIO_Pin4,
	GPIO_Pin5,
	GPIO_Pin6,
	GPIO_Pin7
}GPIO_PinNo;

typedef enum
{
	GPIO_LevelLow = 0,
	GPIO_LevelHigh = 1
}GPIO_LevelType;


typedef enum
{
	GPIO_PinIn = 0,
	GPIO_PinOut = 1
}GPIO_PinType;



typedef struct {                           /* GPIOA Structure                                                       */
	uint32_t RESERVED[255];
	volatile uint32_t DATA;                              /* GPIO Data      ***********                                                       */
	volatile uint32_t DIR;                               /* GPIO Direction          *********                                              */
	volatile uint32_t IS;                                /* GPIO Interrupt Sense                                                  */
	volatile uint32_t IBE;                               /* GPIO Interrupt Both Edges                                             */
	volatile uint32_t IEV;                               /* GPIO Interrupt Event                                                  */
	volatile uint32_t IM;                                /* GPIO Interrupt Mask                                                   */
	volatile uint32_t RIS;                               /* GPIO Raw Interrupt Status                                             */
	volatile uint32_t MIS;                               /* GPIO Masked Interrupt Status                                          */
	volatile uint32_t ICR;                               /* GPIO Interrupt Clear                                                  */
	volatile uint32_t AFSEL;                             /* GPIO Alternate Function Select                                        */
	uint32_t RESERVED1[55];
	volatile uint32_t DR2R;                              /* GPIO 2-mA Drive Select                                                */
	volatile uint32_t DR4R;                              /* GPIO 4-mA Drive Select                                                */
	volatile uint32_t DR8R;                              /* GPIO 8-mA Drive Select                                                */
	volatile uint32_t ODR;                               /* GPIO Open Drain Select                                                */
	volatile uint32_t PUR;                               /* GPIO Pull-Up Select                                                   */
	volatile uint32_t PDR;                               /* GPIO Pull-Down Select                                                 */
	volatile uint32_t SLR;                               /* GPIO Slew Rate Control Select                                         */
	volatile uint32_t DEN;                               /* GPIO Digital Enable              ***********                                     */
	volatile uint32_t LOCK;                              /* GPIO Lock                                                             */
	volatile uint32_t CR;                                /* GPIO Commit                                                           */
	volatile uint32_t AMSEL;                             /* GPIO Analog Mode Select                                               */
	volatile uint32_t PCTL;                              /* GPIO Port Control                                                     */
	volatile uint32_t ADCCTL;                            /* GPIO ADC Control                                                      */
	volatile uint32_t DMACTL;                            /* GPIO DMA Control                                                      */
} GPIOA_Type_;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


void GPIO_RCGEnablePorts(void);
void GPIO_SetPin(GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_PinType PinDi);
void GPIO_WriteChannel(GPIO_PortType PortId, GPIO_PinNo PinId, GPIO_LevelType Level);
GPIO_LevelType GPIO_ReadChannel(GPIO_PortType PortId, GPIO_PinNo PinId);
uint8_t GPIO_ReadPort(GPIO_PortType PortId);
void GPIO_WritePort(GPIO_PortType PortId, uint8_t Value);
void GPIO_FlipChannel(GPIO_PortType PortId, GPIO_PinNo PinId);


#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
