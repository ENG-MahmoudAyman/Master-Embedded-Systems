/*
 ============================================================================
 Name        : Second_C_Assignment.c
 Author      : Mahmoud_Ayman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	//HW Arrays:

	//*** EX1 (Write C Program to sum two matrices 2x2) ***

//	float sum[2][2], M1[2][2], M2[2][2];
//	int i, j;
//	printf("Enter the elements of the 1st matrix\n");
//	fflush(stdout);
//	for (i = 0; i < 2; i++) {
//		for (j = 0; j < 2; j++) {
//			printf("Enter a%d%d:\t", i + 1, j + 1);
//			fflush(stdout);
//			scanf("%f", &M1[i][j]);
//		}
//	}
//	printf("Enter the elements of the 2nd matrix\n");
//	fflush(stdout);
//	for (i = 0; i < 2; i++) {
//		for (j = 0; j < 2; j++) {
//			printf("Enter b%d%d:\t", i + 1, j + 1);
//			fflush(stdout);
//			scanf("%f", &M2[i][j]);
//		}
//	}
//	printf("Sum of Matrix:\n");
//	fflush(stdout);
//	for (i = 0; i < 2; i++) {
//		for (j = 0; j < 2; j++) {
//			sum[i][j] = M1[i][j] + M2[i][j];
//			printf("%.2f\t", sum[i][j]);
//			fflush(stdout);
//		}
//		printf("\n");
//		fflush(stdout);
//	}

	//*** EX2 (Write C Program to get Average) ***

//	float Numbers[50], Average = 0;
//	unsigned int c;
//	int i;
//	printf("Enter the numbers of data:\t");
//	fflush(stdout);
//	scanf("%d", &c);
//	for (i = 0; i < c; i++) {
//		printf("%d. Enter number:\t", i + 1);
//		fflush(stdout);
//		scanf("%f", &Numbers[i]);
//		Average += Numbers[i];
//	}
//	Average /= c;
//	printf("Average = %.2f", Average);

	//*** EX3 (Write C Program to find transpose of matrix) ***

//	float M[10][10], T[10][10];
//	int i, j, r, c;
//	printf("Enter rows and column of matrix: ");
//	fflush(stdout);
//	scanf("%d%d", &r, &c);
//	printf("Enter the elements of the matrix\n");
//	fflush(stdout);
//	for (i = 0; i < r; i++) {
//		for (j = 0; j < c; j++) {
//			printf("Enter a%d%d:\t", i + 1, j + 1);
//			fflush(stdout);
//			scanf("%f", &M[i][j]);
//		}
//	}
//	printf("Entered Matrix:\n");
//	fflush(stdout);
//	for (i = 0; i < r; i++) {
//		for (j = 0; j < c; j++) {
//			printf("%.2f\t", M[i][j]);
//			fflush(stdout);
//		}
//		printf("\n");
//		fflush(stdout);
//	}
//	printf("Transpose of Matrix:\n");
//	fflush(stdout);
//	for (i = 0; i < c; i++) {
//		for (j = 0; j < r; j++) {
//			T[i][j] = M[j][i];
//			printf("%.2f\t", T[i][j]);
//			fflush(stdout);
//		}
//		printf("\n");
//		fflush(stdout);
//	}

	//*** EX4 (Write C Program to insert an element in array) ***

//	int Array [50],N,i,insert_n,location;
//	printf("Enter no of elements : ");
//	fflush(stdout);
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		Array [i] = i+1;
//		printf("%d\t", Array [i]);
//		fflush(stdout);
//	}
//	printf("\nEnter element to be inserted : ");
//	fflush(stdout);
//	scanf("%d", &insert_n);
//	printf("Enter the location : ");
//	fflush(stdout);
//	scanf("%d", &location);
//	for (i = N+1; i >= location; i--) {
//		Array [i] = Array [i-1];
//	}
//	Array [location-1] = insert_n;
//	for (i = 0; i < N+1; i++) {
//		printf("%d\t", Array [i]);
//		fflush(stdout);
//	}

	//*** EX5 (Write C Program to search an element in array) ***

//	int Array[50], N, i, searched_n, location = 0;
//	printf("Enter no of elements : ");
//	fflush(stdout);
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		Array[i] = i + 1 + (i + 1) * 10;
//		printf("%d\t", Array[i]);
//		fflush(stdout);
//	}
//	printf("\nEnter element to be searched : ");
//	fflush(stdout);
//	scanf("%d", &searched_n);
//
//	for (i = 0; i < N; i++) {
//		if (Array[i] == searched_n) {
//			location = i + 1;
//			break;
//		}
//	}
//	if (location)
//		printf("Number found at the location = %d ", location);
//	else
//		printf("Not found");

	//HW Strings:

	//*** EX1 (Write C Program to find frequency of characters in string) ***

//	char string[50], Character, counter = 0;
//	unsigned char i;
//	printf("Enter a string:  ");
//	fflush(stdout);
//	gets(string);
//	printf("Enter a character to find frequency:  ");
//	fflush(stdout);
//	scanf("%c", &Character);
//	for (i = 0; string[i]; i++) {
//		if (string[i] == Character) {
//			counter++;
//		}
//	}
//	printf("Frequency of %c = %d", Character, counter);

	//*** EX2 (Write C Program to find the length of a string) ***

//	char string[50];
//	unsigned char i;
//	printf("Enter a string:  ");
//	fflush(stdout);
//	gets(string);
//	for (i = 0; string[i]; i++) ;
//	printf("Length of string: %d", i);

	//*** EX3 (Write C Program to reverse a string) ***

	char string[50],buffer;
	unsigned char i,N;
	printf("Enter the string:  ");
	fflush(stdout);
	gets(string);
	N = strlen(string)-1;
	for (i = 0; i < (N+1)/2 ; i++){
		buffer = string [i];
		string [i] = string [N-i];
		string [N-i] = buffer;
	}
	printf("Reverse string is : %s", string);

	return EXIT_SUCCESS;
}
