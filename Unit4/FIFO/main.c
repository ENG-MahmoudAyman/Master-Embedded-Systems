/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: engma
 */

#include <stdio.h>
#include <stdlib.h>

#include "Fifo_Buffer.h"


int main(void) {

	Element_Type i,Temp;
	FIFO_Buf_t FIFO_UART;
	if(FIFO_Init(&FIFO_UART, UART_Buffer, Width1) == FIFO_No_Error)
		printf("FIFO_Init --> Done\n");

	for(i = 0;i < 7;i++){
		printf("FIFO Enqueue (%x)",i);
		if(FIFO_Enqueue(&FIFO_UART, i) == FIFO_No_Error)
			printf("FIFO_Enqueue --> Done\n");
		else
			printf("FIFO_Enqueue --> Failed\n");
	}
	FIFO_Print(&FIFO_UART);
	if(FIFO_Dequeue(&FIFO_UART,&Temp) == FIFO_No_Error)
			printf("FIFO_Dequeue of (%x) --> Done\n",Temp);
	if(FIFO_Dequeue(&FIFO_UART,&Temp) == FIFO_No_Error)
			printf("FIFO_Dequeue of (%x) --> Done\n",Temp);
	FIFO_Print(&FIFO_UART);

	return 0;

}
