#include "Uart.h"
#define UART0DR  *((vuint32 * const)((uint32 *)0x101f1000))
void Uart_Send_String(uint8 * P_T_String){
	while(*P_T_String != '\0'){
         UART0DR = (uint32)(*P_T_String);
         P_T_String++;
	}
}