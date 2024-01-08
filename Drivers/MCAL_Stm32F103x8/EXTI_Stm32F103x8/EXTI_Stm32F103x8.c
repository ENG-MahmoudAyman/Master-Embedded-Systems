/*
 * EXTI_Stm32F103x8.c
 *
 *  Created on: Jan 7, 2024
 *      Author: engma
 */


//-----------------------------
//Includes
//-----------------------------
#include "EXTI_Stm32F103x8.h"

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define AFIO_GPIO_EXTI_Mapping(x)          ((x == GPIOA)? 0 :\
                                            (x == GPIOB)? 1 :\
		                                    (x == GPIOC)? 2 :\
		                                    (x == GPIOD)? 3 :\
		                                    (x == GPIOE)? 4 : 0)
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Functions:
//-*-*-*-*-*-*-*-*-*-*-*
void NVIC_Enable(uint16 IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI9_5_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI15_10_Enable;
		break;
	}
}
void NVIC_Disable(uint16 IRQ){
	switch(IRQ){
		case 0:
			NVIC_IRQ6_EXTI0_Disable;
			break;
		case 1:
			NVIC_IRQ7_EXTI1_Disable;
			break;
		case 2:
			NVIC_IRQ8_EXTI2_Disable;
			break;
		case 3:
			NVIC_IRQ9_EXTI3_Disable;
			break;
		case 4:
			NVIC_IRQ10_EXTI4_Disable;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI9_5_Disable;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI15_10_Disable;
			break;
		}
}

/**================================================================
* @Fn               - MCAL_EXTI_ALL_DeInit
* @brief            - Reset EXTI All Registers And NVIC in Cortex M3
* @param [in]       - None
* @retval           - None
* Note              - None
*/
void MCAL_EXTI_ALL_DeInit(void){
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;
    NVIC_IRQ6_EXTI0_Disable;
    NVIC_IRQ7_EXTI1_Disable;
    NVIC_IRQ8_EXTI2_Disable;
    NVIC_IRQ9_EXTI3_Disable;
    NVIC_IRQ10_EXTI4_Disable;
    NVIC_IRQ23_EXTI9_5_Disable;
    NVIC_IRQ40_EXTI15_10_Disable;

}

/**================================================================
* @Fn               - MCAL_EXTI_Init
* @brief            - Initialize EXTI for GPIOx PINy According to the specified parameters in the EXTI_Config
* @param [in]       - EXTI_Config: pointer to EXTI_PinConfig_t structure that contains the config parameters
* @retval           - None
* Note              - (LQFP48 --> Port A & B Fully included -- Port C & D Partially included)
*/
void MCAL_EXTI_Init(EXTI_PinConfig_t* EXTI_Config){
	//Init Pin to be GPIO Input AFIO
	GPIO_PinConfig_t GPIO_Config = {EXTI_Config->EXTI_PIN.GPIO_PIN,GPIO_MODE_INPUT_AF,};
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIOPort,&GPIO_Config);
	//Select the Pin connect to AFIO
	register uint8 AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_InputLineNumber >>2;
	register uint8 AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber % 4)<<2;
	//clear four bit:
	(AFIO->EXTICR[AFIO_EXTICR_Index])&=~((0xF)<<AFIO_EXTICR_Position);
	//(AFIO->EXTICR[AFIO_EXTICR_Index])|=(( AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIOPort) & 0xF)<<AFIO_EXTICR_Position);
	//OR:
	(AFIO->EXTICR[AFIO_EXTICR_Index])|=(((((vuint32)((vuint8*)EXTI_Config->EXTI_PIN.GPIOPort - (vuint8*)GPIOA))>>10)&0xF)<<AFIO_EXTICR_Position);
	//Trigger Selection
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->RTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->RTSR |= ((EXTI_Config->EXTI_Trigger_Case & 0b01)<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR |= (((EXTI_Config->EXTI_Trigger_Case & 0b010)>>1)<<(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber));
	//update IRQ handling CallBack function
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;
	//Enable/Disable IRQ EXTI & NVIC
	if(EXTI_Config->EXTI_IRQ == EXTI_IRQ_Enable){
		//EXTI Enable
		EXTI->IMR|=(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		//NVIC Enable
		NVIC_Enable(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else{
		//EXTI Disable
		EXTI->IMR&=~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		//NVIC Disable
		NVIC_Disable(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
}
/**================================================================
* @Fn               - MCAL_EXTI_Update
* @brief            - Initialize EXTI for GPIOx PINy According to the specified parameters in the EXTI_Config
* @param [in]       - EXTI_Config: pointer to EXTI_PinConfig_t structure that contains the config parameters
* @retval           - None
* Note              - (LQFP48 --> Port A & B Fully included -- Port C & D Partially included)
*/
void MCAL_EXTI_Update(EXTI_PinConfig_t* EXTI_Config){
	MCAL_EXTI_Init(EXTI_Config);
}

/*
 * ==================================================================================================
 *                                           ISR FUNCTIONS
 * ==================================================================================================
 */

void EXTI0_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	EXTI->PR|=(1<<0);
	//call the IRQ_Call_Function
	GP_IRQ_CallBack[0]();
}
void EXTI1_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	EXTI->PR|=(1<<1);
	//call the IRQ_Call_Function
	GP_IRQ_CallBack[1]();
}
void EXTI2_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	EXTI->PR|=(1<<2);
	//call the IRQ_Call_Function
	GP_IRQ_CallBack[2]();
}
void EXTI3_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	EXTI->PR|=(1<<3);
	//call the IRQ_Call_Function
	GP_IRQ_CallBack[3]();
}
void EXTI4_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	EXTI->PR|=(1<<4);
	//call the IRQ_Call_Function
	GP_IRQ_CallBack[4]();
}
void EXTI9_5_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	if(EXTI->PR &(1<<5)){EXTI->PR|=(1<<5);GP_IRQ_CallBack[5]();}
	if(EXTI->PR &(1<<6)){EXTI->PR|=(1<<6);GP_IRQ_CallBack[6]();}
	if(EXTI->PR &(1<<7)){EXTI->PR|=(1<<7);GP_IRQ_CallBack[7]();}
	if(EXTI->PR &(1<<8)){EXTI->PR|=(1<<8);GP_IRQ_CallBack[8]();}
	if(EXTI->PR &(1<<9)){EXTI->PR|=(1<<9);GP_IRQ_CallBack[9]();}
}
void EXTI15_10_IRQHandler(void){
	//clearing Interrupt by writing a ‘1’ into the PR register
	if(EXTI->PR &(1<<10)){EXTI->PR|=(1<<10);GP_IRQ_CallBack[10]();}
	if(EXTI->PR &(1<<11)){EXTI->PR|=(1<<11);GP_IRQ_CallBack[11]();}
	if(EXTI->PR &(1<<12)){EXTI->PR|=(1<<12);GP_IRQ_CallBack[12]();}
	if(EXTI->PR &(1<<13)){EXTI->PR|=(1<<13);GP_IRQ_CallBack[13]();}
	if(EXTI->PR &(1<<14)){EXTI->PR|=(1<<14);GP_IRQ_CallBack[14]();}
	if(EXTI->PR &(1<<15)){EXTI->PR|=(1<<15);GP_IRQ_CallBack[15]();}
}
