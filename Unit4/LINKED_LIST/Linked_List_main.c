/*
 * Linked_List_main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: engma
 */
#include "Linked_List_Students.h"

int main(void){
	uint8 choice;
	uint16 Index;
	while (1) {
		printf("Choose one of the Following Options\n");
		printf(" 1 : Add Student\n 2 : Delete Student\n 3 : Print Students List\n 4 : Delete All Students\n");
		printf(" 5 : Print Student of Index : \n 6 : Get List Length\n 7 : Print Student of Index From End : \n 8 : Print Student in The Middle of List\n");
		printf("-------------------\n");
		fflush(stdout);
		scanf("%hhu",&choice);
		switch(choice){
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			PrintList();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			printf("Enter Index : ");
			fflush(stdout);
			scanf("%hu",&Index);
			PrintNth(Index);
			break;
		case 6:
			printf("List Length = %d\n",GetListLength(gpFirstStudent));
			break;
		case 7:
			printf("Enter Index From End : ");
			fflush(stdout);
			scanf("%hu",&Index);
			PrintNthFromEnd(Index);
			break;
		case 8:
			PrintMiddleList();
			break;
		default:
			printf("Wrong Selection\n");
		}
	}
	return 0;
}
