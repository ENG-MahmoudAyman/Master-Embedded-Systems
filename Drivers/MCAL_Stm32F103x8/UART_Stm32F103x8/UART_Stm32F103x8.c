/*
 * UART_Stm32F103x8.c
 *
 *  Created on: Jan 10, 2024
 *      Author: engma
 */
//-----------------------------
//Includes
//-----------------------------

#include "UART_Stm32F103x8.h"

uint16 USARTx_Word_Length_Parity[3];
/*
 * ==================================================================================================
 *                               APIs Supported by "MCAL UART DRIVER"
 * ==================================================================================================
 */
void MCAL_UART_Init(USART_TypeDef* USARTx, USART_PinConfig_t* USART_Config){
	uint32 PCLK;
	GPIO_PinConfig_t PinConfig;
	AFIO_CLK_EN();//AFIO Clock Enable
	GPIOA_CLK_EN();//GPIOA Clock Enable
	if(USARTx == USART1){USART1_CLK_EN();PCLK = MCAL_RCC_GetPCLK1_Freq(); USARTx_Word_Length_Parity[0] = USART_Config->USART_Word_Length | USART_Config->USART_Parity;
		GP_IRQ_UART_CallBack[0] = USART_Config->P_IRQ_CallBack;
		if (USART_Config->USART_Mode & USART_Mode_TX) {
			//PA9 TX;
			PinConfig.GPIO_PinNumber = GPIO_PIN_9;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_Mode_RX) {
			//PA10 RX;
			PinConfig.GPIO_PinNumber = GPIO_PIN_10;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_FlowCTL_RTS) {
			//PA12 RTS;
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_FlowCTL_CTS) {
			//PA1 CTS;
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
	}

	}
	else if(USARTx == USART2){USART2_CLK_EN();PCLK = MCAL_RCC_GetPCLK2_Freq(); USARTx_Word_Length_Parity[1] = USART_Config->USART_Word_Length | USART_Config->USART_Parity;
		GP_IRQ_UART_CallBack[1] = USART_Config->P_IRQ_CallBack;
		if (USART_Config->USART_Mode & USART_Mode_TX) {
			//PA2 TX;
			PinConfig.GPIO_PinNumber = GPIO_PIN_2;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_Mode_RX) {
			//PA3 RX;
			PinConfig.GPIO_PinNumber = GPIO_PIN_3;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_FlowCTL_RTS) {
			//PA1 RTS;
			PinConfig.GPIO_PinNumber = GPIO_PIN_1;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_FlowCTL_CTS) {
			//PA0 CTS;
			PinConfig.GPIO_PinNumber = GPIO_PIN_0;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}

	}
	else if(USARTx == USART3){USART3_CLK_EN();PCLK = MCAL_RCC_GetPCLK2_Freq(); USARTx_Word_Length_Parity[2] = USART_Config->USART_Word_Length | USART_Config->USART_Parity;
		GP_IRQ_UART_CallBack[2] = USART_Config->P_IRQ_CallBack;
		GPIOB_CLK_EN();//GPIOB Clock Enable
		if (USART_Config->USART_Mode & USART_Mode_TX) {
			//PB10 TX;
			PinConfig.GPIO_PinNumber = GPIO_PIN_10;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_Mode_RX) {
			//PB11 RX;
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_FlowCTL_RTS) {
			//PA14 RTS;
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (USART_Config->USART_Mode & USART_FlowCTL_CTS) {
			//PB13 CTS;
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}

	}

	USARTx->CR1|= (1<<13)|(USART_Config->USART_Mode)|(USART_Config->USART_Parity);
	USARTx->CR2|= (USART_Config->USART_StopBits);
	USARTx->CR3|= (USART_Config->USART_FlowCTL);
	USARTx->BRR = USART_BRR_Register( PCLK , USART_Config->USART_BaudRate );
	if(USART_Config->USART_IRQ_Enable != USART_IRQ_Enable_None){
		USARTx->CR1|= (USART_Config->USART_IRQ_Enable & 0x1FF);
		USARTx->CR2|= ((USART_Config->USART_IRQ_Enable >> 10) & 0x7F);
		USARTx->CR3|= ((USART_Config->USART_IRQ_Enable >> 20) & 0x7FF);

		if(USARTx == USART1){NVIC_IRQ37_USART1_Enable;}
		else if(USARTx == USART2){NVIC_IRQ38_USART2_Enable;}
		else if(USARTx == USART3){NVIC_IRQ39_USART3_Enable;}
	}
}
void MCAL_UART_DeInit(USART_TypeDef* USARTx){
	if(USARTx == USART1){USART1_RESET();NVIC_IRQ37_USART1_Disable;}
	else if(USARTx == USART2){USART2_RESET();NVIC_IRQ38_USART2_Disable;}
	else if(USARTx == USART3){USART3_RESET();NVIC_IRQ39_USART3_Disable;}
}
void MCAL_UART_Send(USART_TypeDef* USARTx, uint16* Data, enum Polling_Mechanism PollingEN){
	if(PollingEN == Enable){
		while(!( USARTx->SR & (1<<7)));
	}
	uint16* Word_Length_Parity;
	if(USARTx == USART1){Word_Length_Parity = &USARTx_Word_Length_Parity[0];}
	else if(USARTx == USART2){Word_Length_Parity = &USARTx_Word_Length_Parity[1];}
	else if(USARTx == USART3){Word_Length_Parity = &USARTx_Word_Length_Parity[2];}

	if(*Word_Length_Parity & USART_Word_Length_9B){
		USARTx->DR = (*Data & (uint16)0x1FF);
	}
	else{
		USARTx->DR = (*Data & (uint16)0xFF);
	}
}
void MCAL_USART_Read(USART_TypeDef* USARTx, uint16* Data, enum Polling_Mechanism PollingEN){
	if(PollingEN == Enable){
		while(!( USARTx->SR & (1<<5)));
	}
	uint16* Word_Length_Parity;
	if(USARTx == USART1){Word_Length_Parity = &USARTx_Word_Length_Parity[0];}
	else if(USARTx == USART2){Word_Length_Parity = &USARTx_Word_Length_Parity[1];}
	else if(USARTx == USART3){Word_Length_Parity = &USARTx_Word_Length_Parity[2];}

	if(*Word_Length_Parity & USART_Word_Length_9B){
		if(*Word_Length_Parity & USART_Parity_Even){
			*((uint16*) Data) = USARTx->DR & 0xFF;
		}
		else{
			*((uint16*) Data) = USARTx->DR;
		}
	}
	else{
		if(*Word_Length_Parity & USART_Parity_Even){
			*((uint16*) Data) = USARTx->DR & 0x7F;
		}
		else{
			*((uint16*) Data) = USARTx->DR & 0xFF;
		}
	}
}

void MCAL_UART_Wait_TC(USART_TypeDef* USARTx){
	while(!(USARTx->SR & (1<<6)));
}

void USART1_IRQHandler(void){
	GP_IRQ_UART_CallBack[0]();
}
void USART2_IRQHandler(void){
	GP_IRQ_UART_CallBack[1]();
}
void USART3_IRQHandler(void){
	GP_IRQ_UART_CallBack[2]();
}
