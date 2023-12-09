/*
 * Lifo.c
 *
 *  Created on: Dec 5, 2023
 *      Author: engma
 */
#include "Lifo.h"


//APIs
LIFO_Status LIFO_Add_Item(LIFO_Buf_t* LBuf, uint32 Item){
	 // check LIFO is valid
	if(!LBuf->base || !LBuf->head)
		return LIFO_Null;
	// check LIFO not Full
	if(LBuf->count == LBuf->length)
		return LIFO_Full;
	// Add item to LIFO
	*(LBuf->head) = Item;
	LBuf->head++;
	LBuf->count++;
	return LIFO_No_Error;
}
LIFO_Status LIFO_Get_Item(LIFO_Buf_t* LBuf, uint32* Item){
	if(!LBuf->base || !LBuf->head)
		return LIFO_Null;
	// check LIFO not Empty
	if(LBuf->count == (uint16)0)
		return LIFO_Empty;
	// Get item from LIFO
	LBuf->head--;
	*(Item) = *(LBuf->head) ;
	LBuf->count--;
	return LIFO_No_Error;
}
LIFO_Status LIFO_Init(LIFO_Buf_t* LBuf, uint32* Buf,uint16 Length){
	if(Buf == NULL)  // check buffer is valid
		return LIFO_Null;
	LBuf->base = Buf;
	LBuf->head = Buf;
	LBuf->length = Length;
	LBuf->count = 0;
	return LIFO_No_Error;
}
