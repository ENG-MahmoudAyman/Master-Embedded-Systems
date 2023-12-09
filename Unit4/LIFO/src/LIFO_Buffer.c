/*
 ============================================================================
 Name        : LIFO_Buffer.c
 Author      : Mahmoud_Ayman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform_Types.h"
#include "Lifo.h"

uint32 Buffer1[5];

int main(void) {
	uint32 i , Temp;
	LIFO_Buf_t Uart_Lifo,I2c_Lifo;
	//static allocation
	LIFO_Init(&Uart_Lifo, Buffer1 , 5);
	//dynamic allocation
	uint32* Buffer2 = (uint32*)malloc(5*sizeof(uint32));
	LIFO_Init(&I2c_Lifo, Buffer2 , 5);

	for(i = 0;i < 5;i++){
		if(LIFO_Add_Item(&Uart_Lifo, i) == LIFO_No_Error)
			printf("Uart_LIFO Add: %d\n",i);
	}

	while(LIFO_Get_Item(&Uart_Lifo, &Temp) == LIFO_No_Error)
		printf("Uart_LIFO Get: %d\n",Temp);


	return EXIT_SUCCESS;
}
