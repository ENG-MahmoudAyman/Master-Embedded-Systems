/*
 * Stm32F103x8.h
 *
 *  Created on: Jan 4, 2024
 *      Author: engma
 */

#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdlib.h>

#include "platform_Types.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_Memory_BASE            0x08000000UL
#define System_Memory_BASE           0x1FFFF000UL
#define SRAM_Memory_BASE             0x20000000UL

//NVIC base Address:
#define NVIC_Base                    0xE000E100UL

//IVT Registers Addresses:
#define NVIC_ISER0      *(vuint32*)(NVIC_Base + 0x00)//Irq0to31_Set_Enable_Register
#define NVIC_ISER1      *(vuint32*)(NVIC_Base + 0x04)//Irq32to63_Set_Enable_Register
#define NVIC_ISER2      *(vuint32*)(NVIC_Base + 0x08)//Irq64to80_Set_Enable_Register

#define NVIC_ICER0      *(vuint32*)(NVIC_Base + 0x80)//Irq0to31_Clear_Enable_Register
#define NVIC_ICER1      *(vuint32*)(NVIC_Base + 0x84)//Irq32to63_Clear_Enable_Register
#define NVIC_ICER2      *(vuint32*)(NVIC_Base + 0x88)//Irq64to80_Clear_Enable_Register

#define NVIC_ISPR0      *(vuint32*)(NVIC_Base + 0x100)//Irq0to31_Set_Pending_Register
#define NVIC_ISPR1      *(vuint32*)(NVIC_Base + 0x104)//Irq32to63_Set_Pending_Register
#define NVIC_ISPR2      *(vuint32*)(NVIC_Base + 0x108)//Irq64to80_Set_Pending_Register

#define NVIC_ICPR0      *(vuint32*)(NVIC_Base + 0x180)//Irq0to31_Clear_Pending_Register
#define NVIC_ICPR1      *(vuint32*)(NVIC_Base + 0x184)//Irq32to63_Clear_Pending_Register
#define NVIC_ICPR2      *(vuint32*)(NVIC_Base + 0x188)//Irq64to80_Clear_Pending_Register


//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

#define Peripherals_BASE             0x40000000UL
#define CortexM3_Peripherals_BASE    0xE0000000UL

//Base addresses AHB BUS Peripherals
//-----------------------------
#define RCC_BASE                     0x40021000UL
//Base addresses APB1 BUS Peripherals
//-----------------------------

//USART:
#define USART2_BASE                  0x40004400UL
#define USART3_BASE                  0x40004800UL

//Base addresses APB2 BUS Peripherals
//-----------------------------

//AFIO:
#define AFIO_BASE                    0x40010000UL
//EXTI:
#define EXTI_BASE                    0x40010400UL
//GPIO: (LQFP48 --> Port A & B Fully included -- Port C & D Partially included)
#define GPIOA_BASE                   0x40010800UL
#define GPIOB_BASE                   0x40010C00UL
#define GPIOC_BASE                   0x40011000UL
#define GPIOD_BASE                   0x40011400UL
//C8
#define GPIOE_BASE                   0x40011800UL
//USART:
#define USART1_BASE                  0x40013800UL


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*
//RCC Peripheral register:
typedef struct{
	vuint32 CR;
	vuint32 CFGR;
	vuint32 CIR;
	vuint32 APB2RSTR;
	vuint32 APB1RSTR;
	vuint32 AHBENR;
	vuint32 APB2ENR;
	vuint32 APB1ENR;
	vuint32 BDCR;
	vuint32 CSR;
}RCC_TypeDef;
//AFIO Peripheral register:
typedef struct{
	vuint32 EVCR;
	vuint32 MAPR;
	vuint32 EXTICR[4];
	vuint32 Reserved;
	vuint32 MAPR2;
}AFIO_TypeDef;
//EXTI Peripheral register:
typedef struct{
	vuint32 IMR;
	vuint32 EMR;
	vuint32 RTSR;
	vuint32 FTSR;
	vuint32 SWIER;
	vuint32 PR;
}EXTI_TypeDef;
//GPIO Peripheral register:
typedef struct{
	vuint32 CRL;
	vuint32 CRH;
	vuint32 IDR;
	vuint32 ODR;
	vuint32 BSRR;
	vuint32 BRR;
	vuint32 LCKR;
}GPIO_TypeDef;
//USART Peripheral register:
typedef struct{
	vuint32 SR;
	vuint32 DR;
	vuint32 BRR;
	vuint32 CR1;
	vuint32 CR2;
	vuint32 CR3;
	vuint32 GTPR;
}USART_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

//GPIO
#define GPIOA                       ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                       ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                       ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                       ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                       ((GPIO_TypeDef *)GPIOE_BASE)

//RCC
#define RCC                         ((RCC_TypeDef *)RCC_BASE)

//AFIO
#define AFIO                        ((AFIO_TypeDef *)AFIO_BASE)

//EXTI
#define EXTI                        ((EXTI_TypeDef *)EXTI_BASE)

//USART:
#define USART1                      ((USART_TypeDef *)USART1_BASE)
#define USART2                      ((USART_TypeDef *)USART2_BASE)
#define USART3                      ((USART_TypeDef *)USART3_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define AFIO_CLK_EN()               (RCC->APB2ENR|=(1<<0))
#define GPIOA_CLK_EN()              (RCC->APB2ENR|=(1<<2))
#define GPIOB_CLK_EN()              (RCC->APB2ENR|=(1<<3))
#define GPIOC_CLK_EN()              (RCC->APB2ENR|=(1<<4))
#define GPIOD_CLK_EN()              (RCC->APB2ENR|=(1<<5))
#define GPIOE_CLK_EN()              (RCC->APB2ENR|=(1<<6))
#define USART1_CLK_EN()             (RCC->APB2ENR|=(1<<14))

#define USART2_CLK_EN()             (RCC->APB1ENR|=(1<<17))
#define USART3_CLK_EN()             (RCC->APB1ENR|=(1<<18))

//RCC Reset:

#define AFIO_RESET()                (RCC->APB2RSTR|=(1<<0))
#define GPIOA_RESET()               (RCC->APB2RSTR|=(1<<2))
#define GPIOB_RESET()               (RCC->APB2RSTR|=(1<<3))
#define GPIOC_RESET()               (RCC->APB2RSTR|=(1<<4))
#define GPIOD_RESET()               (RCC->APB2RSTR|=(1<<5))
#define GPIOE_RESET()               (RCC->APB2RSTR|=(1<<6))
#define USART1_RESET()              (RCC->APB2RSTR|=(1<<14))

#define USART2_RESET()              (RCC->APB1RSTR|=(1<<17))
#define USART3_RESET()              (RCC->APB1RSTR|=(1<<18))

//-*-*-*-*-*-*-*-*-*-*-*-
//IVT:
//-*-*-*-*-*-*-*-*-*-*-*

//EXTI
#define EXTI0_IRQ                     6
#define EXTI1_IRQ                     7
#define EXTI2_IRQ                     8
#define EXTI3_IRQ                     9
#define EXTI4_IRQ                     10
#define EXTI5_IRQ                     23
#define EXTI6_IRQ                     23
#define EXTI7_IRQ                     23
#define EXTI8_IRQ                     23
#define EXTI9_IRQ                     23
#define EXTI10_IRQ                    40
#define EXTI11_IRQ                    40
#define EXTI12_IRQ                    40
#define EXTI13_IRQ                    40
#define EXTI14_IRQ                    40
#define EXTI15_IRQ                    40

#define USART1_IRQ                    37
#define USART2_IRQ                    38
#define USART3_IRQ                    39

//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable/Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IRQ6_EXTI0_Enable        (NVIC_ISER0|=(1<<EXTI0_IRQ))
#define NVIC_IRQ7_EXTI1_Enable        (NVIC_ISER0|=(1<<EXTI1_IRQ))
#define NVIC_IRQ8_EXTI2_Enable        (NVIC_ISER0|=(1<<EXTI2_IRQ))
#define NVIC_IRQ9_EXTI3_Enable        (NVIC_ISER0|=(1<<EXTI3_IRQ))
#define NVIC_IRQ10_EXTI4_Enable       (NVIC_ISER0|=(1<<EXTI4_IRQ))
#define NVIC_IRQ23_EXTI9_5_Enable     (NVIC_ISER0|=(1<<23))
#define NVIC_IRQ40_EXTI15_10_Enable   (NVIC_ISER1|=(1<<8))

#define NVIC_IRQ37_USART1_Enable      (NVIC_ISER1|=(1<<5))
#define NVIC_IRQ38_USART2_Enable      (NVIC_ISER1|=(1<<6))
#define NVIC_IRQ39_USART3_Enable      (NVIC_ISER1|=(1<<7))

#define NVIC_IRQ6_EXTI0_Disable       (NVIC_ICER0|=(1<<EXTI0_IRQ))
#define NVIC_IRQ7_EXTI1_Disable       (NVIC_ICER0|=(1<<EXTI1_IRQ))
#define NVIC_IRQ8_EXTI2_Disable       (NVIC_ICER0|=(1<<EXTI2_IRQ))
#define NVIC_IRQ9_EXTI3_Disable       (NVIC_ICER0|=(1<<EXTI3_IRQ))
#define NVIC_IRQ10_EXTI4_Disable      (NVIC_ICER0|=(1<<EXTI4_IRQ))
#define NVIC_IRQ23_EXTI9_5_Disable    (NVIC_ICER0|=(1<<23))
#define NVIC_IRQ40_EXTI15_10_Disable  (NVIC_ICER1|=(1<<8))

#define NVIC_IRQ37_USART1_Disable     (NVIC_ICER1|=(1<<5))
#define NVIC_IRQ38_USART2_Disable     (NVIC_ICER1|=(1<<6))
#define NVIC_IRQ39_USART3_Disable     (NVIC_ICER1|=(1<<7))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Variables:
//-*-*-*-*-*-*-*-*-*-*-*

void (* GP_IRQ_EXTI_CallBack[16]) (void);
void (* GP_IRQ_UART_CallBack[3]) (void);



#endif /* INC_STM32F103X8_H_ */
