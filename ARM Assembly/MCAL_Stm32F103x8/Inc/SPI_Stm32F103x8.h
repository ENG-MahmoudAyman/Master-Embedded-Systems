/*
 * SPI_Stm32F103x8.h
 *
 *  Created on: Jan 13, 2024
 *      Author: engma
 */

#ifndef INC_SPI_STM32F103X8_H_
#define INC_SPI_STM32F103X8_H_

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
	uint8 SPI_DeviceMode;           //specifies SPI is Master/Slave.
                                    //This Parameter must be set based on @ref SPI_DeviceMode_Define.
	uint16 SPI_CommunicationMode;   //specifies Communication Full duplex/Half duplex/Simplex.
                                    //This Parameter must be set based on @ref SPI_CommunicationMode_Define.
	uint8 SPI_ConnectionMode;       //specifies Connection is point to point/multi-slave.
                                    //This Parameter must be set based on @ref SPI_ConnectionMode_Define.
	uint8 SPI_FrameFormat;          //specifies Frame Format LSBFirst/MSBFirst.
                                    //This Parameter must be set based on @ref SPI_FrameFormat_Define.
	uint16 SPI_DataSize;            //specifies Data Size 8bit/16bit.
                                    //This Parameter must be set based on @ref SPI_DataSize_Define.
	uint8 SPI_CLKPolarity;          //specifies Clock Polarity Idle LOW/HIGH.
                                    //This Parameter must be set based on @ref SPI_CLKPolarity_Define.
	uint8 SPI_CLKPhase;             //specifies Clock Phase sampling when first/second clock transition .
	                                //This Parameter must be set based on @ref SPI_CLKPhase_Define.
	uint16 SPI_NSS;                 //specifies NSS is by Hardware/Software.
	                                //This Parameter must be set based on @ref SPI_NSS_Define.
	uint8 SPI_Prescaler;            //specifies SPI Frequency ratio from the BUS (SPI1 --> ABP2)(SPI2 --> ABP1).
	                                //This Parameter must be set based on @ref SPI_Prescaler_Define.
	uint8 SPI_IRQ_ENABLE;           //specifies Interrupt Source.
	                                //This Parameter must be set based on @ref SPI_IRQ_Enable_Define.
	void (* P_IRQ_CallBack) (void); //specifies SPI IRQ Function to be called once the IRQ happened

}SPI_PinConfig_t;

//==============================
//Macros Configuration Reference
//==============================

//@ref SPI_DeviceMode_Define

#define SPI_DeviceMode_MASTER                  (uint32)(1<<2)
#define SPI_DeviceMode_SLAVE                   (uint32)0

//@ref SPI_CommunicationMode_Define

#define SPI_CommunicationMode_FD               (uint32)0//(BIDIMODE=0 and RXONLY=0)-->CR1
#define SPI_CommunicationMode_1Direction_R     (uint32)(1<<10)//(BIDIMODE=0 and RXONLY=1)-->CR1
#define SPI_CommunicationMode_2Direction_R     (uint32)(1<<15)//(BIDIMODE=1 and BIDIOE=0)-->CR1
#define SPI_CommunicationMode_2Direction_T     (uint32)(1<<15)(1<<14)//(BIDIMODE=1 and BIDIOE=1)-->CR1

//@ref SPI_ConnectionMode_Define
#define SPI_ConnectionMode_PtoP                (uint32)0//point to point
#define SPI_ConnectionMode_MultiSlaves         (uint32)1//multi-slave


//@ref SPI_FrameFormat_Define

#define SPI_FrameFormat_MSBFirst               (uint32)0//(LSBFIRST=0)-->CR1
#define SPI_Word_Length_LSBFirst               (uint32)(1<<7)//(LSBFIRST=1)-->CR1

//@ref SPI_DataSize_Define

#define SPI_DataSize_8bit                      (uint32)0//(DFF=0)-->CR1
#define SPI_DataSize_16bit                     (uint32)(1<<11)//(DFF=1)-->CR1


//@ref SPI_CLKPolarity_Define
#define SPI_CLKPolarity_IDLE_LOW               (uint32)0//(CPOL=0)-->CR1
#define SPI_CLKPolarity_IDLE_HIGH              (uint32)(1<<1)//(CPOL=1)-->CR1

//@ref SPI_CLKPhase_Define
#define SPI_CLKPhase_1st_CLKtran               (uint32)0//(CPHA=0)-->CR1
#define SPI_CLKPhase_2nd_CLKtran               (uint32)(1)//(CPHA=1)-->CR1

//@ref SPI_NSS_Define
#define SPI_NSS_SOFT_MASTER                    (uint32)(1<<9)|(1<<8)//(SSM=1)(SSI=1)-->CR1
#define SPI_NSS_SOFT_SLAVE                     (uint32)(1<<9)//(SSM=1)(SSI=0)-->CR1
#define SPI_NSS_HARD_MASTER_INPUT              (uint32)0//(SSOE=0)-->CR2
#define SPI_NSS_HARD_MASTER_OUTPUT             (uint32)(1<<2)//(SSOE=1)-->CR2
#define SPI_NSS_HARD_SLAVE                     (uint32)0//(SSOE=0)-->CR2

//@ref SPI_Prescaler_Define
#define SPI_Prescaler_fPCLK_2                  (uint32)0//(BR=0)-->CR1
#define SPI_Prescaler_fPCLK_4                  (uint32)(1<<3)//(BR=1)-->CR1
#define SPI_Prescaler_fPCLK_8                  (uint32)(2<<3)//(BR=2)-->CR1
#define SPI_Prescaler_fPCLK_16                 (uint32)(3<<3)//(BR=3)-->CR1
#define SPI_Prescaler_fPCLK_32                 (uint32)(4<<3)//(BR=4)-->CR1
#define SPI_Prescaler_fPCLK_64                 (uint32)(5<<3)//(BR=5)-->CR1
#define SPI_Prescaler_fPCLK_128                (uint32)(6<<3)//(BR=6)-->CR1
#define SPI_Prescaler_fPCLK_256                (uint32)(0<<3)//(BR=7)-->CR1

//@ref SPI_IRQ_ENABLE_Define
#define SPI_IRQ_ENABLE_None                    (uint32)0//Interrupt Disabled
#define SPI_IRQ_ENABLE_TXE                     (uint32)(1<<7)//Transmit buffer empty flag(TXEIE=1)-->CR2
#define SPI_IRQ_ENABLE_RXNE                    (uint32)(1<<6)//Receive buffer not empty flag(RXNEIE=1)-->CR2
#define SPI_IRQ_ENABLE_OVR                     (uint32)(1<<5)//Overrun error(ERRIE=1)-->CR2
#define SPI_IRQ_ENABLE_UDR                     (uint32)(1<<5)//Underrun error(ERRIE=1)-->CR2

//@ref USART_Status_Define

#define SPI_Status_TXE                         (uint32)(1<<1)//Transmit  buffer empty
#define SPI_Status_RXNE                        (uint32)(1<<0)//Received buffer not empty
#define SPI_Status_OVR                         (uint32)(1<<6)//Overrun error detected
#define SPI_Status_UDR                         (uint32)(1<<7)//Under run line detected


/*
 * ==================================================================================================
 *                               APIs Supported by "MCAL SPI DRIVER"
 * ==================================================================================================
 */

void MCAL_SPI_Init(SPI_TypeDef* SPIx, SPI_PinConfig_t* SPI_Config);
void MCAL_SPI_DeInit(SPI_TypeDef* SPIx);
void MCAL_SPI_Send(SPI_TypeDef* SPIx, uint16* Data, enum Polling_Mechanism PollingEN);//for Multi slaves Use GPIO pens to drive the connection
void MCAL_SPI_Read(SPI_TypeDef* SPIx, uint16* Data, enum Polling_Mechanism PollingEN);
void MCAL_SPI_Send_Read(SPI_TypeDef* SPIx, uint16* Data, enum Polling_Mechanism PollingEN);

void MCAL_SPI_Wait_TC(SPI_TypeDef* SPIx);

//to do MCAL_T2S_Init();     //I2S
//to do MCAL_SPI_DMA_Init();   //DMA Controller --> SPI

/*
 * ==================================================================================================
 *                               Macros For User "MCAL SPI DRIVER"
 * ==================================================================================================
 */

// check on the Interrupt Source For taking Actions:

#define SPI_TB_Empty(SPIx)          ((SPIx->CR2)&SPI_IRQ_ENABLE_TXE)&&((SPIx->SR)&SPI_Status_TXE)//Transmit  buffer empty
#define SPI_RB_NEmpty(SPIx)         ((SPIx->CR2)&SPI_IRQ_ENABLE_RXNE)&&((SPIx->SR)&SPI_Status_RXNE)//Received buffer not empty
#define SPI_Overrun_E(SPIx)         ((SPIx->CR2)&SPI_IRQ_ENABLE_OVR)&&((SPIx->SR)&SPI_Status_OVR)//Overrun error detected
#define SPI_Underrun_E(SPIx)        ((SPIx->CR2)&SPI_IRQ_ENABLE_UDR)&&((SPIx->SR)&SPI_Status_UDR)//Under run line detected

#endif /* INC_SPI_STM32F103X8_H_ */
