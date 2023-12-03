/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "platform_Types.h"

#define RCC_BASE         0x40021000
#define GPIOA_BASE       0x40010800
#define RCC_APB2ENR     *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH       *(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_ODR       *(volatile uint32_t *) (GPIOA_BASE + 0x0C)

#define RCC_IOPAEN      2
#define GPIOAx          (1UL<<x)
#define SET_BIT(Regiter,bit)     (Regiter|= (1UL<<bit))
#define RESET_HBYTE(Regiter,S_bit)     (Regiter &= ~(0x0F<<S_bit))

typedef union{
	vuint32    PORT;
	struct{
		vuint32	  P_0:1;
		vuint32	  P_1:1;
		vuint32	  P_2:1;
		vuint32	  P_3:1;
		vuint32	  P_4:1;
		vuint32	  P_5:1;
		vuint32	  P_6:1;
		vuint32	  P_7:1;
		vuint32	  P_8:1;
		vuint32	  P_9:1;
		vuint32	  P_10:1;
		vuint32	  P_11:1;
		vuint32	  P_12:1;
		vuint32	  P_13:1;
	}PIN;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*) (GPIOA_BASE + 0x0C);
uint8 g_variables[3] = {1,2,3};
uint8 const Const_variables[3] = {1,2,3};
uint8 bss_var[3];
int main(void)
{
	SET_BIT(RCC_APB2ENR,RCC_IOPAEN);
	//RCC_APB2ENR |=(1<<RCC_IOPAEN);
	RESET_HBYTE(GPIOA_CRH,20);
	//GPIOA_CRH &= 0xFF0FFFFF;
	SET_BIT(GPIOA_CRH,21);
	//GPIOA_CRH |= 0x00200000;

	while(1){
		R_ODR->PIN.P_13 = 1;
		//GPIOA_ODR|=(1<<13);
		for(uint16 i = 0;i<50000;i++);
		R_ODR->PIN.P_13 = 0;
		//GPIOA_ODR&=~(1<<13);
		for(uint16 i = 0;i<50000;i++);
	}

}