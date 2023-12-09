/*
 * Lifo.h
 *
 *  Created on: Dec 5, 2023
 *      Author: engma
 */
#include "platform_Types.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LIFO_H_
#define LIFO_H_

//type definitions
typedef struct{
	uint16 length;
	uint16 count;
	uint32* base;
	uint32* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null
}LIFO_Status;

//APIs
LIFO_Status LIFO_Add_Item(LIFO_Buf_t* LBuf, uint32 Item);
LIFO_Status LIFO_Get_Item(LIFO_Buf_t* LBuf, uint32* Item);
LIFO_Status LIFO_Init(LIFO_Buf_t* LBuf, uint32* Buf ,uint16 Length);



#endif /* LIFO_H_ */
