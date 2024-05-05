/*
 * RCC_Stm32F103x8.h
 *
 *  Created on: Jan 11, 2024
 *      Author: engma
 */

#ifndef INC_RCC_STM32F103X8_H_
#define INC_RCC_STM32F103X8_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32F103x8.h"

#define HSI_CLK    (uint32)8000000UL
#ifndef HSE_CLK
#define HSE_CLK    (uint32)8000000UL
#endif

/*
 * ==================================================================================================
 *                               APIs Supported by "MCAL RCC DRIVER"
 * ==================================================================================================
 */

uint32 MCAL_RCC_GetSYSCLK_Freq(void);
uint32 MCAL_RCC_GetHCLK_Freq(void);
uint32 MCAL_RCC_GetPCLK1_Freq(void);
uint32 MCAL_RCC_GetPCLK2_Freq(void);

#endif /* INC_RCC_STM32F103X8_H_ */
