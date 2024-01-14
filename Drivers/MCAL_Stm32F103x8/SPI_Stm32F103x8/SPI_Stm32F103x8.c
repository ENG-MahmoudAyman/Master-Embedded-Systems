/*
 * SPI_Stm32F103x8.c
 *
 *  Created on: Jan 13, 2024
 *      Author: engma
 */

//-----------------------------
//Includes
//-----------------------------

#include "SPI_Stm32F103x8.h"

/*
 * ==================================================================================================
 *                               APIs Supported by "MCAL SPI DRIVER"
 * ==================================================================================================
 */

/**================================================================
* @Fn               - MCAL_SPI_Init
* @brief            - Initialize SPI specified parameters & GPIO Pins
* @param [in]       - SPIx: Selected SPI 1/2
* @param [in]       - SPI_Config: pointer to SPI_PinConfig_t structure that contains the config parameters
* @retval           - None
* Note              - None
*/
void MCAL_SPI_Init(SPI_TypeDef* SPIx, SPI_PinConfig_t* SPI_Config){
	GPIO_PinConfig_t PinConfig;
	AFIO_CLK_EN();//AFIO Clock Enable
	if(SPIx == SPI1){
		SPI1_CLK_EN();
		GPIOA_CLK_EN();//GPIOA Clock Enable
		GP_IRQ_SPI_CallBack[0] = SPI_Config->P_IRQ_CallBack;
		//PA4 NSS;
		if (SPI_Config->SPI_NSS == SPI_NSS_HARD_MASTER_INPUT) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_4;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		} else if (SPI_Config->SPI_NSS == SPI_NSS_HARD_MASTER_OUTPUT) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_4;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		//PA5 SCK;
		if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_MASTER) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_5;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		} else {
			PinConfig.GPIO_PinNumber = GPIO_PIN_5;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		//PA6 MISO;
		if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_MASTER
				&& SPI_Config->SPI_CommunicationMode == SPI_CommunicationMode_FD) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_6;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		} else if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_SLAVE
				&& SPI_Config->SPI_ConnectionMode == SPI_ConnectionMode_PtoP) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_6;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		} else if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_SLAVE
				&& SPI_Config->SPI_ConnectionMode
						== SPI_ConnectionMode_MultiSlaves) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_6;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		//PA7 MOSI;
		if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_MASTER) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_7;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		} else if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_SLAVE
				&& SPI_Config->SPI_CommunicationMode == SPI_CommunicationMode_FD) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_7;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
	}
	else if(SPIx == SPI2){
		SPI2_CLK_EN();
		GPIOB_CLK_EN();//GPIOB Clock Enable
		GP_IRQ_SPI_CallBack[1] = SPI_Config->P_IRQ_CallBack;
		//PB12 NSS;
		if (SPI_Config->SPI_NSS == SPI_NSS_HARD_MASTER_INPUT) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		} else if (SPI_Config->SPI_NSS == SPI_NSS_HARD_MASTER_OUTPUT) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		//PB13 SCK;
		if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_MASTER) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		} else {
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		//PB14 MISO;
		if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_MASTER
				&& SPI_Config->SPI_CommunicationMode == SPI_CommunicationMode_FD) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		} else if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_SLAVE
				&& SPI_Config->SPI_ConnectionMode == SPI_ConnectionMode_PtoP) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		} else if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_SLAVE
				&& SPI_Config->SPI_ConnectionMode
						== SPI_ConnectionMode_MultiSlaves) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		//PB15 MOSI;
		if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_MASTER) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_15;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed = GPIO_Output_Speed_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		} else if (SPI_Config->SPI_DeviceMode == SPI_DeviceMode_SLAVE
				&& SPI_Config->SPI_CommunicationMode == SPI_CommunicationMode_FD) {
			PinConfig.GPIO_PinNumber = GPIO_PIN_15;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
	}


	SPIx->CR1|= (1<<6)|(SPI_Config->SPI_DeviceMode)|(SPI_Config->SPI_CommunicationMode)|(SPI_Config->SPI_DataSize)|(SPI_Config->SPI_CLKPolarity)
			|(SPI_Config->SPI_CLKPhase)|(SPI_Config->SPI_FrameFormat)|(SPI_Config->SPI_Prescaler)|(SPI_Config->SPI_NSS & 0xFF0);
	SPIx->CR2|= (SPI_Config->SPI_IRQ_ENABLE)|(SPI_Config->SPI_NSS & 0xF);
	if(SPIx == SPI1){NVIC_IRQ35_SPI1_Enable;}
	else if(SPIx == SPI2){NVIC_IRQ36_SPI2_Enable;}
}

/**================================================================
* @Fn               - MCAL_SPI_DeInit
* @brief            - Reset SPI And NVIC in Cortex M3
* @param [in]       - SPIx: Selected SPI 1/2
* @retval           - None
* Note              - None
*/
void MCAL_SPI_DeInit(SPI_TypeDef* SPIx){
	if(SPIx == SPI1){SPI1_RESET();NVIC_IRQ35_SPI1_Disable;}
	else if(SPIx == SPI2){SPI2_RESET();NVIC_IRQ36_SPI2_Disable;}
}

/**================================================================
* @Fn               - MCAL_SPI_Send
* @brief            - Send Data using SPI
* @param [in]       - SPIx: Selected SPI 1/2
* @param [in]       - Data: Pointer To data to be Sent
* @param [in]       - PollingEN: enum to specify Polling For Data Sending
* @retval           - None
* Note              - None
*/
void MCAL_SPI_Send(SPI_TypeDef* SPIx, uint16* Data, enum Polling_Mechanism PollingEN){
	if(PollingEN == Enable){
		while(!( SPIx->SR & (1<<1)));
	}
	SPIx->DR = *Data ;

}

/**================================================================
* @Fn               - MCAL_SPI_Read
* @brief            - Read Data From SPI
* @param [in]       - SPIx: Selected SPI 1/2
* @param [in]       - Data: Pointer To data to be Sent
* @param [in]       - PollingEN: enum to specify Polling For Data Sending
* @retval           - None
* Note              - None
*/
void MCAL_SPI_Read(SPI_TypeDef* SPIx, uint16* Data, enum Polling_Mechanism PollingEN){
	if(PollingEN == Enable){
		while(!( SPIx->SR & (1<<0)));
	}
	*((uint16*) Data) = SPIx->DR;
}
/**================================================================
* @Fn               - MCAL_SPI_Send_Read
* @brief            - Send Data using SPI then Read
* @param [in]       - SPIx: Selected SPI 1/2
* @param [in]       - Data: Pointer To data to be Sent
* @param [in]       - PollingEN: enum to specify Polling For Data Sending
* @retval           - None
* Note              - None
*/
void MCAL_SPI_Send_Read(SPI_TypeDef* SPIx, uint16* Data, enum Polling_Mechanism PollingEN){
	if(PollingEN == Enable){
		while(!( SPIx->SR & (1<<1)));
	}
	SPIx->DR = (*Data) ;
	if(PollingEN == Enable){
		while(!( SPIx->SR & (1<<0)));
	}
	*((uint16*) Data) = SPIx->DR;
}

void MCAL_SPI_Wait_TC(SPI_TypeDef* SPIx){
	while(!(SPIx->SR & (1<<1)));
}

void SPI1_IRQHandler(void){
	GP_IRQ_SPI_CallBack[0]();
}
void SPI2_IRQHandler(void){
	GP_IRQ_SPI_CallBack[1]();
}


