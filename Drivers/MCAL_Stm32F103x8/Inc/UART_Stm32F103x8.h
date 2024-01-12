/*
 * UART_Stm32F103x8.h
 *
 *  Created on: Jan 10, 2024
 *      Author: engma
 */

#ifndef INC_UART_STM32F103X8_H_
#define INC_UART_STM32F103X8_H_

//-----------------------------
//Includes
//-----------------------------

#include "Stm32F103x8.h"
#include "RCC_Stm32F103x8.h"
#include "GPIO_Stm32F103x8.h"

//-----------------------------
//Config. Structures
//-----------------------------

typedef struct{
	uint8 USART_Mode;          //specifies TX/RX Enable/Disable.
                               //This Parameter must be set based on @ref USART_Mode_Define.
	uint32 USART_BaudRate;     //specifies Baud Rate.
                               //This Parameter must be set based on @ref USART_BaudRate_Define.
	uint16 USART_Word_Length;  //specifies Payload Length.
                               //This Parameter must be set based on @ref USART_Word_Length_Define.
	uint16 USART_Parity;       //specifies Parity.
                               //This Parameter must be set based on @ref USART_Parity_Define.
	uint16 USART_StopBits;     //specifies Parity.
                               //This Parameter must be set based on @ref USART_StopBits_Define.
	uint16 USART_FlowCTL;      //specifies Flow control.
	                           //This Parameter must be set based on @ref USART_FlowCTL_Define.
	uint32 USART_IRQ_Enable;   //specifies Interrupt Enable/Disable.
	                           //This Parameter must be set based on @ref USART_IRQ_Enable_Define.
	void (* P_IRQ_CallBack) (void); //specifies USART IRQ Function to be called once the IRQ happened

}USART_PinConfig_t;

//==============================
//Macros Configuration Reference
//==============================

//@ref USART_Mode_Define

#define USART_Mode_RX                  (uint32)(1<<2)
#define USART_Mode_TX                  (uint32)(1<<3)
#define USART_Mode_RX_TX               (uint32)(0b11<<2)

//@ref USART_BaudRate_Define

#define USART_BaudRate_2400            2400
#define USART_BaudRate_9600            9600
#define USART_BaudRate_19200           19200
#define USART_BaudRate_57600           57600
#define USART_BaudRate_115200          115200
#define USART_BaudRate_230400          230400
#define USART_BaudRate_460800          460800
#define USART_BaudRate_921600          921600
#define USART_BaudRate_2250000         2250000
#define USART_BaudRate_4500000         4500000

//@ref USART_Payload_Length_Define

#define USART_Word_Length_8B           (uint32)0
#define USART_Word_Length_9B           (uint32)(1<<12)

//@ref USART_Parity_Define
#define USART_Parity_Disabled          (uint32)0
#define USART_Parity_Even              (uint32)(1<<10)
#define USART_Parity_Odd               (uint32)(0b11<<9)

//@ref USART_StopBits_Define

#define USART_StopBits_Half            (uint32)(1<<12)
#define USART_StopBits_1               (uint32)0
#define USART_StopBits_1_Half          (uint32)(0b11<<12)
#define USART_StopBits_2               (uint32)(1<<13)

//@ref USART_FlowCTL_Define

#define USART_FlowCTL_None              (uint32)0
#define USART_FlowCTL_CTS               (uint32)(1<<9)
#define USART_FlowCTL_RTS               (uint32)(1<<8)
#define USART_FlowCTL_CTS_RTS           (uint32)(0b11<<8)

//@ref USART_IRQ_Enable_Define

#define USART_IRQ_Enable_None           (uint32)0//Interrupt Disabled
#define USART_IRQ_Enable_TXE            (uint32)(1<<7)//Transmit data register empty(TXEIE)->(USART_CR1)
#define USART_IRQ_Enable_TC             (uint32)(1<<6)//Transmission complete(TCIE)->(USART_CR1)
#define USART_IRQ_Enable_RXNE           (uint32)(1<<5)//Received data ready to be read(RXNEIE)->(USART_CR1)
#define USART_IRQ_Enable_ORE            (uint32)(1<<5)//Overrun error detected(RXNEIE)->(USART_CR1)
#define USART_IRQ_Enable_IDLE           (uint32)(1<<4)//Idle line detected(IDLEIE)->(USART_CR1)
#define USART_IRQ_Enable_PE             (uint32)(1<<8)//Parity error(PEIE)->(USART_CR1)
#define USART_IRQ_Enable_LBD            (uint32)(1<<16)(//Break flag(LBDIE)>(USART_CR2)##Second 10 bit (1<<6+10)
#define USART_IRQ_Enable_CTS            (uint32)(1<<30)//CTS flag(CTSIE)->(USART_CR3)##Third 11 bit (1<<10+10+10)
#define USART_IRQ_Enable_NE             (uint32)(1<<20)//Noise flag(EIE)->(USART_CR3)##Third 11 bit (1<<10+10+0)
#define USART_IRQ_Enable_FE             (uint32)(1<<20)//Framing error(EIE)(USART_CR3)##Third 11 bit (1<<10+10+0)

//@ref USART_Status_Define

#define USART_Status_TXE                (uint32)(1<<7)//Transmit data register empty
#define USART_Status_TC                 (uint32)(1<<6)//Transmission complete
#define USART_Status_RXNE               (uint32)(1<<5)//Received data ready to be read
#define USART_Status_ORE                (uint32)(1<<3)//Overrun error detected
#define USART_Status_IDLE               (uint32)(1<<4)//Idle line detected
#define USART_Status_PE                 (uint32)(1<<0)//Parity error
#define USART_Status_LBD                (uint32)(1<<8)(//Break flag
#define USART_Status_CTS                (uint32)(1<<9)//CTS flag
#define USART_Status_NE                 (uint32)(1<<2)//Noise flag
#define USART_Status_FE                 (uint32)(1<<1)//Framing error

enum Polling_Mechanism{
	Disable,
	Enable
};

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define USARTDIV(_PCLK_,_BAUD_)             (uint32)(_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_)      (uint32)((_PCLK_*25)/(4*_BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)      (uint32)(USARTDIV(_PCLK_,_BAUD_)*100)
#define Mantissa(_PCLK_,_BAUD_)             (uint32)(USARTDIV(_PCLK_,_BAUD_))
#define DIV_Fraction(_PCLK_,_BAUD_)         (uint32)(((USARTDIV_MUL100(_PCLK_,_BAUD_)-Mantissa_MUL100(_PCLK_,_BAUD_))*16)/100)
#define USART_BRR_Register(_PCLK_,_BAUD_)   (uint32)((Mantissa(_PCLK_,_BAUD_)<<4)|(DIV_Fraction(_PCLK_,_BAUD_)&0xF))

/*
 * ==================================================================================================
 *                               APIs Supported by "MCAL UART DRIVER"
 * ==================================================================================================
 */

void MCAL_UART_Init(USART_TypeDef* USARTx, USART_PinConfig_t* USART_Config);
void MCAL_UART_DeInit(USART_TypeDef* USARTx);
void MCAL_UART_Send(USART_TypeDef* USARTx, uint16* Data, enum Polling_Mechanism PollingEN);
void MCAL_USART_Read(USART_TypeDef* USARTx, uint16* Data, enum Polling_Mechanism PollingEN);

void MCAL_UART_Wait_TC(USART_TypeDef* USARTx);

//to do MCAL_LIN_Init();     //LIN
//to do MCAL_USART_Init();   //Synchronous
//to do MCAL_USART_DMA_Init();   //DMA Controller --> USART

/*
 * ==================================================================================================
 *                               Macros For User "MCAL UART DRIVER"
 * ==================================================================================================
 */

// check on the Interrupt Source For taking Actions:

#define TXREG_Empty(USARTx)       ((USARTx->CR1)&USART_IRQ_Enable_TXE)&&((USARTx->SR)&USART_Status_TXE)
#define Tcomplete(USARTx)         ((USARTx->CR1)&USART_IRQ_Enable_TC)&&((USARTx->SR)&USART_Status_TC)
#define Rcomplete(USARTx)         ((USARTx->CR1)&USART_IRQ_Enable_RXNE)&&((USARTx->SR)&USART_Status_RXNE)
#define Overrun_E(USARTx)         ((USARTx->CR1)&USART_IRQ_Enable_ORE)&&((USARTx->SR)&USART_Status_ORE)
#define IdleL_Detected(USARTx)    ((USARTx->CR1)&USART_IRQ_Enable_IDLE)&&((USARTx->SR)&USART_Status_IDLE)
#define Parity_E(USARTx)          ((USARTx->CR1)&USART_IRQ_Enable_PE)&&((USARTx->SR)&USART_Status_PE)
#define Break_F(USARTx)           ((USARTx->CR2)&(USART_IRQ_Enable_LBD >> 10))&&((USARTx->SR)&USART_Status_LBD)
#define CTS_F(USARTx)             ((USARTx->CR3)&(USART_IRQ_Enable_CTS >> 20))&&((USARTx->SR)&USART_Status_CTS)
#define Noise_F(USARTx)           ((USARTx->CR3)&(USART_IRQ_Enable_NE >> 20))&&((USARTx->SR)&USART_Status_NE)
#define Framing_E(USARTx)         ((USARTx->CR3)&(USART_IRQ_Enable_FE >> 20))&&((USARTx->SR)&USART_Status_FE)


#endif /* INC_UART_STM32F103X8_H_ */
