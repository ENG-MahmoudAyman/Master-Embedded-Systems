/*
 * RCC_Stm32F103x8.c
 *
 *  Created on: Jan 11, 2024
 *      Author: engma
 */

//-----------------------------
//Includes
//-----------------------------
#include "RCC_Stm32F103x8.h"

const uint8 PLLmulfactor[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16};
const uint8 AHBprescaler[] = {0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};
const uint8 PCLKprescaler[] = {0,0,0,0,1,2,3,4};

uint32 MCAL_RCC_GetSYSCLK_Freq(void){
	switch((RCC->CFGR >> 2) & 0b11){
		case 0 :  //00: HSI oscillator used as system clock.
			return (uint32) HSI_CLK;
			break;
		case 1 :  //01: HSE oscillator used as system clock.
			return (uint32) HSE_CLK;
			break;
		case 2:   //10: PLL used as system clock.
			if((RCC->CFGR >> 16)& 1){
				if((RCC->CFGR >> 17)& 1){
					return (uint32) (HSE_CLK<<1)*PLLmulfactor[(RCC->CFGR >> 18) & 0b1111];
				}
				else{
					return (uint32) (HSE_CLK)*PLLmulfactor[(RCC->CFGR >> 18) & 0b1111];
				}
			}
			else{
				return (uint32) (HSI_CLK<<1)*PLLmulfactor[(RCC->CFGR >> 18) & 0b1111];
			}
			break;
		default:
			return (uint32) HSI_CLK;
			break;
	}
}
uint32 MCAL_RCC_GetHCLK_Freq(void){
//	Bits 7:4 HPRE: AHB prescaler
//	Set and cleared by software to control the division factor of the AHB clock.
	return MCAL_RCC_GetSYSCLK_Freq() >> AHBprescaler[((RCC->CFGR >> 4) & 0b1111)];
}
uint32 MCAL_RCC_GetPCLK1_Freq(void){
//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//	Set and cleared by software to control the division factor of the APB low-speed clock (PCLK1).
	return MCAL_RCC_GetHCLK_Freq() >> PCLKprescaler[((RCC->CFGR >> 8) & 0b111)];
}
uint32 MCAL_RCC_GetPCLK2_Freq(void){
//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//	Set and cleared by software to control the division factor of the APB high-speed clock (PCLK2).
	return MCAL_RCC_GetHCLK_Freq() >> PCLKprescaler[((RCC->CFGR >> 11) & 0b111)];
}
