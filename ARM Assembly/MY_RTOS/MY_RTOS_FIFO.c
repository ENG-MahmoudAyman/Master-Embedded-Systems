/*
 * MY_RTOS_FIFO.c
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */

#include "MY_RTOS_FIFO.h"


//APIs
FIFO_Status FIFO_Enqueue(FIFO_Buf_t* FBuf, Element_Type Item){
	// check FIFO is valid
	if(!FBuf->base || !FBuf->head || !FBuf->tail)
		return FIFO_Null;
	// check FIFO not Full
	if(FIFO_Is_Full(FBuf) == FIFO_Full)
		return FIFO_Full;
	// Enqueue item to FIFO
	*(FBuf->head) = Item;
	FBuf->count++;
	if((uint32)FBuf->head == ((uint32)FBuf->base +(4*FBuf->length) -4))
		FBuf->head = FBuf->base;
	else
		FBuf->head++;

	return FIFO_No_Error;


}
FIFO_Status FIFO_Dequeue(FIFO_Buf_t* FBuf, Element_Type* Item){
	// check FIFO is valid
	if(!FBuf->base || !FBuf->head || !FBuf->tail)
		return FIFO_Null;
	// check FIFO not Empty
	if(FBuf->count == (uint16)0)
		return FIFO_Empty;
	// Dequeue item to FIFO
	*Item = *(FBuf->tail);
	FBuf->count--;
	if((uint32)FBuf->tail == ((uint32)FBuf->base +(4*FBuf->length) - 4))
		FBuf->tail = FBuf->base;
	else
		FBuf->tail++;

	return FIFO_No_Error;

}
FIFO_Status FIFO_Init(FIFO_Buf_t* FBuf, Element_Type* Buf ,uint16 Length){
	// check FIFO is valid
		if(Buf == NULL )
			return FIFO_Null;
		// Initialize FIFO
		FBuf->base = Buf;
		FBuf->head = Buf;
		FBuf->tail = Buf;
		FBuf->length = Length;
		FBuf->count = (uint16) 0 ;
		return FIFO_No_Error;

}
FIFO_Status FIFO_Is_Full(FIFO_Buf_t* FBuf){
	// check FIFO is valid
	if(!FBuf->base || !FBuf->head)
		return FIFO_Null;
	// check FIFO not Full
	if(FBuf->count == FBuf->length)
		return FIFO_Full;

	return FIFO_No_Error;
}
/*void FIFO_Print(FIFO_Buf_t* FBuf){
	Element_Type* Temp;
	uint16 i;
	if(FBuf->count == (uint16)0)
		printf("FIFO is Empty\n");
	else{
		Temp = FBuf->tail;
		printf("------FIFO Print------\n");
		for(i = 0;i < FBuf->count;i++){
			printf("FIFO(%d):  %x\n",i,*Temp);
			Temp++;
		}
		printf("------------\n");
	}

}*/


