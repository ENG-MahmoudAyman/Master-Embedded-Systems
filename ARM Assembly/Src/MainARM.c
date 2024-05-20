/*
 * MainARM.c
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */





#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#if 0

#include "Stm32F103x8.h"
#include "GPIO_Stm32F103x8.h"
#include "EXTI_Stm32F103x8.h"
#include "UART_Stm32F103x8.h"
#include "SPI_Stm32F103x8.h"
#include "core_cm3.h"

#define frequency 8000000UL
#define Last

uint8 TaskA_flag = 0,TaskB_flag = 0, IRQ_flag = 0;

#define TaskA_Stack_Size  100
#define TaskB_Stack_Size  100

extern _estack;

//Main Stack
unsigned int _S_MSP = &_estack;
unsigned int _E_MSP;

//process stack Task A
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;

//process stack Task B
unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;

#define OS_SET_PSP(add)              __asm volatile ("MOV R0,%[in] \n\t""MSR PSP,R0" : :[in]"r"(add))
#define OS_SWITCH_SP_to_PSP          __asm volatile ("MRS R0,CONTROL \n\t""ORR R0,R0, #0x02 \n\t""MSR CONTROL,R0")
#define OS_SWITCH_SP_to_MSP          __asm volatile ("MRS R0,CONTROL \n\t""AND R0,R0, #0x05 \n\t""MSR CONTROL,R0")
#define OS_Generate_Exception        __asm volatile ("SVC #0x03")
#define Change_CPU_access_level_to(CPU_access)  switch (CPU_access) {\
	case privileged:\
		__asm(" MRS R0, CONTROL \n\t"" LSR R0,R0, #0x1 \n\t"" LSL R0,R0, #0x1 \n\t"" MSR CONTROL, R0 " );\
		break;\
	case unprivileged:\
		__asm(" MRS R0, CONTROL \n\t"" ORR R0,R0, #0x1 \n\t"" MSR CONTROL, R0" );\
		break;\
}

void delay_ms(uint32 Tms){
	uint32 i,j=Tms*(frequency/1000);
	for(i=0;i<j;i++);
}


enum CPU_access_level{
	privileged,
	unprivileged
};


#ifdef First

void SVC_Handler(){
	Change_CPU_access_level_to(privileged);

}
#endif /*First*/

#ifdef Last

void PendSV_Handler(){
	//clear PendSV
	//CB->ICSR|=SCB_ICSR_PENDSVSET_Msk;

}

void OS_SVC_Services(int* StackFramePointer){

	uint8 SVC_number;
	uint32 Val1,Val2;

	SVC_number = (*(uint8*)(((uint8*)StackFramePointer[6])-2));
	Val1 = StackFramePointer[0];
	Val2 = StackFramePointer[1];

	switch(SVC_number){
	case 0:
		StackFramePointer[0] = Val1+Val2;//add
		break;
	case 1:
		StackFramePointer[0] = Val1-Val2;//sub
		break;
	case 2:
		StackFramePointer[0] = Val1*Val2;//mult
		break;
	case 3:
		SCB->ICSR|=SCB_ICSR_PENDSVSET_Msk;//OS PendSV
		break;
	}

}

__attribute ((naked)) void SVC_Handler(){
	__asm("TST LR, #4 \n\t"
			"ITE EQ \n\t"
			"MRSEQ R0,MSP \n\t"
			"MRSNE R0,PSP \n\t"
			"B OS_SVC_Services \n\t");
}

uint32 TaskA (uint16 a ,uint16 b){
	return a+b;
}

uint32 TaskB (uint16 a ,uint16 b ,uint16 c){
	return a+b+c;
}

int OS_SVC_Set(int a, int b, int SVC_ID){

	int result;
	switch(SVC_ID){
	case 0:
		__asm("SVC #0x0");//add
		break;
	case 1:
		__asm("SVC #0x1");//sub
		break;
	case 2:
		__asm("SVC #0x2");//mult
		break;
	case 3:
		__asm("SVC #0x3");//OS PendSV
		break;
	}
	__asm("MOV %[ret], R0" :[ret]"=r"(result));
	return result;
}

#endif /*Last*/

void MainOs(){
	//Main Stack
	_E_MSP = (_S_MSP - 512);

	//Task A
	_S_PSP_TA = (_E_MSP - 8);
	_E_PSP_TA = (_S_PSP_TA - TaskA_Stack_Size);

	//Task B
	_S_PSP_TB = (_E_PSP_TA - 8);
	_E_PSP_TB = (_S_PSP_TB - TaskB_Stack_Size);
}

void MyIRQHandler(void);

GPIO_PinConfig_t PB1 = {GPIO_PIN_1,GPIO_MODE_OUTPUT_PP,GPIO_Output_Speed_10M};
EXTI_PinConfig_t PB0 = {EXTI0_PB0, EXTI_Trigger_RISING, EXTI_IRQ_Enable,MyIRQHandler};
void init_GPIO(){
	//PB1 OUTPUT PUSH_PULL
	MCAL_GPIO_Init(GPIOB,&PB1);
}



int main(void)
{
	#ifdef First
	//init_RCC();
	init_GPIO();
	MCAL_EXTI_Init(&PB0);

	MainOs();
	#endif /*First*/

	#ifdef Last
	IRQ_flag = 1;
	IRQ_flag = OS_SVC_Set(2, 1, 0);
	IRQ_flag = OS_SVC_Set(2, 1, 1);
	IRQ_flag = OS_SVC_Set(2, 1, 2);
	#endif /*Last*/

	while(1){
	#ifdef First
			__asm("NOP");
			if(TaskA_flag == 1){
				OS_SET_PSP(_S_PSP_TA);//PSP = TA Stack
				OS_SWITCH_SP_to_PSP; //switch from MSP to PSP
				Change_CPU_access_level_to(unprivileged);//switch from privileged to unprivileged
				TaskA_flag = TaskA(1,2);
				OS_Generate_Exception;
				OS_SWITCH_SP_to_MSP; //switch from PSP to MSP

			}
			else if(TaskB_flag == 1){
				OS_SET_PSP(_S_PSP_TB);//PSP = TB Stack
				OS_SWITCH_SP_to_PSP; //switch from MSP to PSP
				Change_CPU_access_level_to(unprivileged);//switch from privileged to unprivileged
				TaskB_flag = TaskB(1,2,3);
				OS_Generate_Exception;
				OS_SWITCH_SP_to_MSP; //switch from PSP to MSP
			}
	#endif /*First*/

	#ifdef Last

	#endif /*Last*/
	}
}



void MyIRQHandler(void){

#ifdef First
	if(IRQ_flag == 0){
		TaskA_flag = 1;
		IRQ_flag = 1;

	}
	else if(IRQ_flag == 1){
		TaskB_flag = 1;
		IRQ_flag = 0;
	}
#endif /*First*/

}

#endif
