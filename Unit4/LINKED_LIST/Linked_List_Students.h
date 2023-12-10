/*
 * Linked_List_Students.h
 *
 *  Created on: Dec 9, 2023
 *      Author: engma
 */


#ifndef LINKED_LIST_STUDENTS_H_
#define LINKED_LIST_STUDENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "platform_Types.h"

struct SData{
	uint8 name[50];
	uint32 id;
	float32 height;
};

struct SStudent{
	struct SData Student;
	struct SStudent* PNextStudent;
};

extern struct SStudent* gpFirstStudent;

void AddStudent();
void DeleteStudent();
void PrintList();
void DeleteAll();
void PrintNth(uint16 N);
void PrintNthFromEnd(uint16 N);
void PrintMiddleList();
int GetListLength(struct SStudent* PTempStudent);


#endif /* LINKED_LIST_STUDENTS_H_ */
