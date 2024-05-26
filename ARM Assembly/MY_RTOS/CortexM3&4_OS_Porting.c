/*
 * CortexM3&4_OS_Porting.c
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */

#include "CortexM3&4_OS_Porting.h"

uint32 x = 0;
void DecideNext(void);
void MY_RTOS_Update_TaskingTime(void);

  void HardFault_Handler(void){
	  while(1);
  }
  void	MemManage_Handler(void){
	  while(1);
  }
  void	BusFault_Handler(void){
	  while(1);
  }
  void	UsageFault_Handler(void){
	  while(1);
  }

  __attribute ((naked)) void SVC_Handler(){
  	__asm("TST LR, #4 \n\t"
  			"ITE EQ \n\t"
  			"MRSEQ R0,MSP \n\t"
  			"MRSNE R0,PSP \n\t"
  			"B OS_SVC \n\t");
  }

  void HW_init(){
	  //Initialize clock (RCC->SysTick Timer & CPU) 8MHZ
	  //8MHZ
	  //0.125 us
	  // 1ms -> 8000 Ticks

	  //Decrease PenSV priority = SysTick timer
	  __NVIC_SetPriority(PendSV_IRQn, 15);
	 // __NVIC_SetPriority(EXTI0_IRQn,22);

  }

  void Trigger_OS_PendSV(){
	  SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
  }

  void StartTicker(){
	  //SysTick Config
	  SysTick_Config(8000);
  }

  vuint8 SysTickIndic;
  void SysTick_Handler(){

	  //Decide Next
	  SysTickIndic ^= 1;
	  MY_RTOS_Update_TaskingTime();
	  DecideNext();
	  Trigger_OS_PendSV();
  }



