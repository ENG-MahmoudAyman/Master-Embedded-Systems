//startup.c Cortex M3
//Mahmoud Ayman

#include "platform_Types.h"
#define Stack_Top_address 0x20001000

void Reset_Handler();
void NMI_Handler();
void HardFault_Handler();
void MemManage_Handler();
void BusFault_Handler();
void UsageFault_Handler();
extern int main();

uint32 vectors[] __attribute__((section(".vectors"))) = {

    (uint32)Stack_Top_address,
	(uint32)&Reset_Handler,
	(uint32)&NMI_Handler,
	(uint32)&HardFault_Handler,
	(uint32)&MemManage_Handler,
	(uint32)&BusFault_Handler,
	(uint32)&UsageFault_Handler,


};

void Reset_Handler(){
	main();
}
void NMI_Handler(){
	Reset_Handler();
}
void HardFault_Handler(){
	Reset_Handler();
}
void MemManage_Handler(){
	Reset_Handler ();
}
void BusFault_Handler (){
	Reset_Handler();
}
void UsageFault_Handler(){
	Reset_Handler();
}