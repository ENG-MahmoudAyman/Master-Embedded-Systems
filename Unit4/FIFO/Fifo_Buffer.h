/*
 * Fifo.h
 *
 *  Created on: Dec 6, 2023
 *      Author: engma
 */

#ifndef FIFO_BUFFER_H_
#define FIFO_BUFFER_H_
#include <stdio.h>
#include <stdlib.h>
#include "platform_Types.h"
//User Configuration
//select Element type(uint8 , uint16 , uint32 , uint64)
#define Element_Type uint8
//create buffer 1
#define Width1 5
extern Element_Type UART_Buffer[Width1];
//type definitions
typedef struct{
	uint16 length;
	uint16 count;
	Element_Type* base;
	Element_Type* tail;
	Element_Type* head;
}FIFO_Buf_t;
typedef enum{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null
}FIFO_Status;
//APIs
FIFO_Status FIFO_Enqueue(FIFO_Buf_t* FBuf, Element_Type Item);
FIFO_Status FIFO_Dequeue(FIFO_Buf_t* FBuf, Element_Type* Item);
FIFO_Status FIFO_Init(FIFO_Buf_t* FBuf, Element_Type* Buf ,uint16 Length);
FIFO_Status FIFO_Is_Full(FIFO_Buf_t* FBuf);
void FIFO_Print(FIFO_Buf_t* FBuf);
#endif /* FIFO_BUFFER_H_ */
