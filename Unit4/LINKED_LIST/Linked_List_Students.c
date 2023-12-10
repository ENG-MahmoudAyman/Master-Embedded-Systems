/*
 * Linked_List_Students.c
 *
 *  Created on: Dec 9, 2023
 *      Author: engma
 */

#include "Linked_List_Students.h"

struct SStudent* gpFirstStudent;

void AddStudent(){
	struct SStudent* PLastStudent;
	struct SStudent* PNewStudent;

	//check if the linked list is Empty
	if(gpFirstStudent == NULL){
		PNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		if(PNewStudent)
			gpFirstStudent = PNewStudent;
		else{
			printf("No Available Memory\n");
			fflush(stdout);
		}
	}
	else{
		PLastStudent = gpFirstStudent;
		while(PLastStudent->PNextStudent)//Jump to last student in the list
			PLastStudent = PLastStudent->PNextStudent;
		PNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		if(PNewStudent)
			PLastStudent->PNextStudent = PNewStudent;
		else{
			printf("No Available Memory\n");
			fflush(stdout);
		}
	}
	//store data
	printf("Enter the ID : ");
	fflush(stdout);
	scanf("%d",&(PNewStudent->Student.id));
	printf("Enter Student Full Name : ");
	fflush(stdout);
	scanf("%s",PNewStudent->Student.name);
	fflush(stdin);
	printf("Enter height : ");
	fflush(stdout);
	scanf("%f",&(PNewStudent->Student.height));
	printf("-----------------------\n");
	fflush(stdout);
	PNewStudent->PNextStudent = NULL;
}

void DeleteStudent(){
	uint32 Id;
	//check that the list is no Empty
	if(gpFirstStudent){
		printf("Enter Student ID to be Deleted : \n");
		fflush(stdout);
		scanf("%d",&Id);
		fflush(stdin);
		struct SStudent* PSelectedStudent = gpFirstStudent;
		struct SStudent* PPreviousStudent = NULL;
		while(PSelectedStudent){//Jump to selected student to be deleted
			if(PSelectedStudent->Student.id == Id){
				if(PPreviousStudent)
					PPreviousStudent->PNextStudent = PSelectedStudent->PNextStudent;
				else
					gpFirstStudent = PSelectedStudent->PNextStudent;
				free(PSelectedStudent);
				return;
			}
			PPreviousStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->PNextStudent;
		}
	}
	else{
		printf("Empty List\n");
		return;
	}
	printf("Cannot find the student\n");
	return;
}

void PrintList(){
	struct SStudent* PPrintedStudent = gpFirstStudent;
	uint16 count = 0;
	if(PPrintedStudent == NULL)
		printf("Empty List\n");
	while(PPrintedStudent){
		printf("----Record No.%hd----\n ID : %d\n Name : %s\n Height : %f\n",count+1,PPrintedStudent->Student.id,PPrintedStudent->Student.name,PPrintedStudent->Student.height);
		PPrintedStudent = PPrintedStudent->PNextStudent;
		count++;
		printf("-------------------------\n");
	}
}

void DeleteAll(){
	struct SStudent* PDeleteStudent = gpFirstStudent;
		if(PDeleteStudent == NULL)
			printf("Empty List\n");
		else{
			while (PDeleteStudent) {
				struct SStudent* PTempStudent = PDeleteStudent;
				PDeleteStudent = PDeleteStudent->PNextStudent;
				free(PTempStudent);
			}
			gpFirstStudent = NULL;
			printf("------Deleted All Students------\n");
		}
}
void PrintNth(uint16 N){
	struct SStudent* PPrintedStudent = gpFirstStudent;
	uint16 count = 0;
	if(PPrintedStudent == NULL)
		printf("Empty List\n");
	while(PPrintedStudent){
		if(count == N){
		printf("----Index No.%hd----\n ID : %d\n Name : %s\n Height : %f\n",count,PPrintedStudent->Student.id,PPrintedStudent->Student.name,PPrintedStudent->Student.height);
		printf("-------------------------\n");
		break;
		}
		PPrintedStudent = PPrintedStudent->PNextStudent;
		count++;
	}
	if(count < N)
		printf("List Max Index is %hd\n",count);
}

int GetListLength(struct SStudent* PTempStudent){
	if(PTempStudent == NULL){
		return 0;
	}
	return 1 + GetListLength(PTempStudent->PNextStudent);

}
void PrintNthFromEnd(uint16 N){
	struct SStudent *PFastStudent = gpFirstStudent;
	struct SStudent *PSlowStudent = gpFirstStudent;
	uint16 count = 0;
	if (gpFirstStudent == NULL)
		printf("Empty List\n");
	while (1) {
		if (!PFastStudent) {
			if (count <= N)
				printf("List Max Index is %hd\n", count-1);
			else{
				printf("----Index No.%hd From End----\n ID : %d\n Name : %s\n Height : %f\n",N, PSlowStudent->Student.id,PSlowStudent->Student.name,PSlowStudent->Student.height);
				printf("-------------------------\n");
			}
			break;
		}
		if(count > N)
			PSlowStudent = PSlowStudent->PNextStudent;
		PFastStudent = PFastStudent->PNextStudent;
		count++;
	}
}
void PrintMiddleList(){
	struct SStudent *PTempStudent = gpFirstStudent;
	struct SStudent *PDoubleTempStudent = gpFirstStudent;
	uint16 count;
	if(gpFirstStudent == NULL)
		printf("Empty List\n");
	while(1){
		if(!PDoubleTempStudent){
		printf("----Index No.%hd----\n ID : %d\n Name : %s\n Height : %f\n",count,PTempStudent->Student.id,PTempStudent->Student.name,PTempStudent->Student.height);
		printf("-------------------------\n");
		break;
		}
		if(PDoubleTempStudent->PNextStudent){
			PTempStudent = PTempStudent->PNextStudent;
			PDoubleTempStudent = PDoubleTempStudent->PNextStudent->PNextStudent;
			count++;
		}
		else
			PDoubleTempStudent = PDoubleTempStudent->PNextStudent;
	}
}

