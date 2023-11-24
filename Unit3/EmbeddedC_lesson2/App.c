#include "Uart.h"
#include "platform_Types.h"
uint8 string_buffer[100] = "learn-in-depth:Mahmoud";
void main(void)
{
	Uart_Send_String(string_buffer);
}
