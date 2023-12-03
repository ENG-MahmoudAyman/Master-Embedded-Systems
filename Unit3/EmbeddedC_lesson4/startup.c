//startup.c Cortex M4
//Mahmoud Ayman

#include "platform_Types.h"


void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));;
void HardFault_Handler() __attribute__((weak, alias("Default_Handler")));;
void MemManage_Handler() __attribute__((weak, alias("Default_Handler")));;
void BusFault_Handler() __attribute__((weak, alias("Default_Handler")));;
void UsageFault_Handler() __attribute__((weak, alias("Default_Handler")));;
void Default_Handler(){
	Reset_Handler();
}
//booking 1024 B located by .bss through uninitialized array of long 256 Elements (256*4=1024)
static uint32 Stack_top[256];
extern int main();
extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;
extern uint32 _Stack_top;

void (* const vectors[])() __attribute__((section(".vectors"))) = {

    (void (*)()) ((uint32)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&HardFault_Handler,
	&MemManage_Handler,
	&BusFault_Handler,
	&UsageFault_Handler
};

void Reset_Handler(){
	//copy data section form flash to sram
	uint32 Data_Size = (uint8 *)&_E_data - (uint8 *)&_S_data;
	uint8* P_src = (uint8 *)&_E_text;
	uint8* P_dst = (uint8 *)&_S_data;
	for(uint32 i = 0 ; i < Data_Size ; i++){
		*((uint8 *)P_dst++) = *((uint8 *)P_src++) ;
	}
    //init bss section in sram by zeros
    uint32 Bss_Size = (uint8 *)&_E_bss - (uint8 *)&_S_bss;
    P_dst = (uint8 *)&_S_bss;
    for(uint32 i = 0 ; i < Bss_Size ; i++){
    	*((uint8 *)P_dst++) = (uint8) 0 ;
    }
    //jump to main
	main();
}
