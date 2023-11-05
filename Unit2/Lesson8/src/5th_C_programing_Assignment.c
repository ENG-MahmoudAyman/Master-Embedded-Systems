/*
 ============================================================================
 Name        : 5th_C_programing_Assignment.c
 Author      : Mahmoud_Ayman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
	char name[20];
	int id;
};

int main(void) {

	//*** EX1 (Write a program in C to demonstrate how to handle the pointers in the program) ***
//	int m = 29;
//	printf("Address of m : 0x%9p\nValue of m : %d\n\n",&m, m);
//	int *ab = &m;
//	printf("Now ab is assigned with the address of m.\n");
//	printf("Address of pointer ab : 0x%9p\nContent of pointer ab : %d\n\n",ab,*ab);
//	m = 34;
//	printf("The value of m is assigned to %d now.\n", m);
//	printf("Address of pointer ab : 0x%9p\nContent of pointer ab : %d\n\n",ab,*ab);
//	*ab = 7;
//	printf("The pointer variable ab is assigned with the value %d now.\n\n",*ab);
//	printf("Address of m : 0x%9p\nValue of m : %d\n",&m, m);

	//*** EX2 (Write a program in C to print all the alphabets using a pointer) ***
//	char alph[26];
//	char *p = alph;
//	char i;
//	for (i = 0; i < 26; i++) {
//		*p = i + 'A';
//		p++;
//	}
//	p = alph;
//	printf("The Alphabets are :\n");
//	for (i = 0; i < 26; i++) {
//		printf("%c   ", *p);
//		p++;
//	}

	//*** EX3 (Write a program in C to print a string in reverse using a pointer) ***
//	char a[40], i;
//	char *p = a;
//	printf("Input a string : ");
//	fflush(stdout);
//	scanf("%s", p);
//	for (; (*p) != '\0'; i++) {
//		p++;
//	}
//	p--, i--;
//	printf("Reverse of the string is : ");
//	for (; i >= 0; i--) {
//		printf("%c", *p);
//		p--;
//	}

	//*** EX4 (Write a program in C to print the elements of an array in reverse order) ***
//	int element[15], *p;
//	p = element;
//	char i, N;
//	printf("Input the number of elements to store in the array (max 15):");
//	fflush(stdout);
//	scanf("%hhd", &N);
//	printf("Input 5 number of elements in the array :\n");
//	for (i = 0; i < N; i++) {
//		printf("element - %d :", i + 1);
//		fflush(stdout);
//		scanf("%d", p);
//		p++;
//	}
//	p--, i--;
//	printf("\nThe elements of array in reverse order are :\n");
//	for (; i >= 0; i--) {
//		printf("element - %d :%d\n", i + 1, *p);
//		p--;
//	}

	//*** EX5 (Write a program in C to show a pointer to an array which contents are pointer to structure) ***
	struct employee employee1;
	struct employee* ps = &employee1;
	strcpy(ps->name,"Alex");
	ps->id = 1002;
	printf("Employee Name :%s\nEmployee ID :%d",ps->name,ps->id);

	return EXIT_SUCCESS;
}
