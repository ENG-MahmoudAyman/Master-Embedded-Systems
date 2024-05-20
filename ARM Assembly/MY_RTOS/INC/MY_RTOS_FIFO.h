/*
 * MY_RTOS_FIFO.h
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */

#ifndef INC_MY_RTOS_FIFO_H_
#define INC_MY_RTOS_FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include "Scheduler.h"

#include "platform_Types.h"

//User Configuration
//select Element type
#define Element_Type Task_Ref*

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


#endif /* INC_MY_RTOS_FIFO_H_ */
