/*
 * GPIO_Stm32F103x8.c
 *
 *  Created on: Jan 4, 2024
 *      Author: engma
 */

//-----------------------------
//Includes
//-----------------------------
#include "GPIO_Stm32F103x8.h"

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Functions:
//-*-*-*-*-*-*-*-*-*-*-*
uint8 Get_CRLH_Position(uint16 PinNumber){
	switch(PinNumber){
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break;
	default:
		return 0;
		break;
	}
}

/**================================================================
* @Fn               - MCAL_GPIO_Init
* @brief            - Initialize GPIOx PINy According to the specified parameters in the Pinconfig
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @param [in]       - PinConfig: pointer to GPIO_PinConfig_t structure that contains the config parameters
* @retval           - None
* Note              - (LQFP48 --> Port A & B Fully included -- Port C & D Partially included)
*/
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_PinConfig_t *PinConfig){
	if(GPIOx == GPIOA){GPIOA_CLK_EN();}
	else if(GPIOx == GPIOB){GPIOB_CLK_EN();}
	else if(GPIOx == GPIOC){GPIOC_CLK_EN();}
	else if(GPIOx == GPIOD){GPIOD_CLK_EN();}
	else if(GPIOx == GPIOE){GPIOE_CLK_EN();}
	//Port configuration register low (GPIOx_CRL) (x=A..E) Pin 0 >>> 7
	//Port configuration register low (GPIOx_CRH) (x=A..E) Pin 8 >>> 15
	vuint32 *ConfigReg = NULL;
	uint8 PIN_Config;
	uint8 CRLH_Shift = Get_CRLH_Position(PinConfig->GPIO_PinNumber);
	ConfigReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL: &GPIOx->CRH;
	//clear CNFy[1:0] MODEy[1:0]
	(*ConfigReg)&=~(0xF<<CRLH_Shift);
	//PIN is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)){
		PIN_Config = ((((PinConfig->GPIO_MODE -4)<< 2)|(PinConfig->GPIO_Output_Speed)) & 0x0F);
	}
	//PIN is input MODEy[1:0] = 00: Input mode (reset state)
	else{
		if((PinConfig->GPIO_MODE == GPIO_MODE_Analog)||(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO)){
			PIN_Config = (((PinConfig->GPIO_MODE)<< 2) & 0x0C);
		}
		else{//Pull up or down Input mode Is Selected
			PIN_Config = (((GPIO_MODE_INPUT_PU)<< 2) & 0x0C);
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){//Pull up Input mode Is Selected
			//Table 20. Port bit configuration table PINy ODRx register = 1
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);
			}
			else{//Pull down Input mode Is Selected
			//Table 20. Port bit configuration table PINy ODRx register = 0
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	(*ConfigReg)|= PIN_Config<<CRLH_Shift;

}

/**================================================================
* @Fn               - MCAL_GPIO_DeInit
* @brief            - Reset GPIOx All Registers
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @retval           - None
* Note              - None
*/
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx){

	if(GPIOx == GPIOA){
		RCC->APB2RSTR|=(1<<2);
		RCC->APB2RSTR&=~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR|=(1<<3);
		RCC->APB2RSTR&=~(1<<3);
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR|=(1<<4);
		RCC->APB2RSTR&=~(1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR|=(1<<5);
		RCC->APB2RSTR&=~(1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR|=(1<<6);
		RCC->APB2RSTR&=~(1<<6);
	}

}

/**================================================================
* @Fn               - MCAL_GPIO_ReadPin
* @brief            - Read GPIOx PINy
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @param [in]       - PinNumber: Set Pin Number According to @ref GPIO_PINS_Define
* @retval           - Pin value (Two values According to @ref GPIO_PIN_State)
* Note              - None
*/
uint8 MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16 PinNumber){
	uint8 PinStatus;
	if((GPIOx->IDR)&PinNumber){
		PinStatus = GPIO_PIN_HIGH;
	}
	else{
		PinStatus = GPIO_PIN_LOW;
	}
	return PinStatus;
}

/**================================================================
* @Fn               - MCAL_GPIO_ReadPort
* @brief            - Read GPIOx Port
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @retval           - Port value 0x00 to 0xFF
* Note              - None
*/
uint16 MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx){
	return (uint16)(GPIOx->IDR);
}

/**================================================================
* @Fn               - MCAL_GPIO_WritePin
* @brief            - Write a value to GPIOx PINy
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @param [in]       - PinNumber: Set Pin Number According to @ref GPIO_PINS_Define
* @param [in]       - Value: Set Pin Value According to @ref GPIO_PIN_State
* @retval           - None
* Note              - None
*/
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16 PinNumber,uint8 Value){
	if(Value){
		//(GPIOx->ODR)|= PinNumber;
		(GPIOx->BSRR)= (uint32)PinNumber;
	}
	else{
		//(GPIOx->ODR)&= ~PinNumber;
		(GPIOx->BRR)= (uint32)PinNumber;
	}
}

/**================================================================
* @Fn               - MCAL_GPIO_WritePort
* @brief            - Write a value to GPIOx
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @param [in]       - Value: Set Port Value 0x00 to 0xFF
* @retval           - None
* Note              - None
*/
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx,uint16 Value){
	(GPIOx->ODR) = (uint32)Value;
}

/**================================================================
* @Fn               - MCAL_GPIO_TogglePin
* @brief            - Toggle GPIOx PINy value
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @param [in]       - PinNumber: Set Pin Number According to @ref GPIO_PINS_Define
* @retval           - None
* Note              - None
*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16 PinNumber){
	(GPIOx->ODR)^= (uint32)PinNumber;
}

/**================================================================
* @Fn               - MCAL_GPIO_LockPin
* @brief            - Lock GPIOx PINy value
* @param [in]       - GPIOx: where x can be from A to E to select the GPIO Peripheral
* @param [in]       - PinNumber: Set Pin Number According to @ref GPIO_PINS_Define
* @retval           - Acknowledge according to @ref GPIO_PIN_Lock_Ack
* Note              - None
*/
uint8 MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx,uint16 PinNumber){
	vuint32 Temp = (1<<16)|(uint32)PinNumber;
//	Bit 16 LCKK[16]: Lock key
//	LOCK key writing sequence:
//	Write 1
	GPIOx->LCKR = Temp;
//	Write 0
	GPIOx->LCKR = (uint32)PinNumber;
//	Write 1
	GPIOx->LCKR = Temp;
//	Read 0
	Temp = GPIOx->LCKR;
//	Read 1 (this read is optional but confirms that the lock is active)
	if((GPIOx->LCKR)&(1<<16)){
		return GPIO_PIN_Lock_Enabled;
	}
	else{
		return GPIO_PIN_Lock_Error;
	}
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.

}
