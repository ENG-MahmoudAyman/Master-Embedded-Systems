/*
 ============================================================================
 Name        : Third_c_Assignment.c
 Author      : Mahmoud_Ayman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void prime_numbers(int a, int z) {
	int i = a, j;
	printf("Prime numbers between %d and %d are:", a, z);
	fflush(stdout);
	for (; i <= z; i++) {
		if (i == 2 || i == 3) {
			printf(" %d", i);
			fflush(stdout);
			continue;
		}
		for (j = 2; j < (i / 2 + 1); j++) {
			if ((i % j) == 0) {
				break;
			} else if (j == (i / 2)) {
				printf(" %d", i);
				fflush(stdout);
			}
		}
	}
}

int Factorial(int number) {
	if (number < 0) {
		return -1;
	}
	if (number == 1 || number == 0) {
		return 1;
	}
	return number * Factorial(number - 1);
}
char reverse_sentence(char *string) {
	if (*string != '\0') {
		printf("%c", reverse_sentence(string + 1));
		fflush(stdout);
	}
	return *(string - 1);
}
int Get_power(int base, int power) {
	if(base==0&&power == 0)
		return -1;
	if (power == 0) {
		return 1;
	}
	power--;
	return Get_power(base, power) * base;
}

int main(void) {
	//*** EX1 (Write C Program to Print prime numbers between two intervals) ***
//	int a,z;
//	printf("Enter two numbers(intervals):");
//	fflush(stdout);
//	scanf("%d%d",&a,&z);
//	prime_numbers(a,z);

//	//*** EX2 (Write C Program to calculate factorial using recursion) ***
//	int n;
//	printf("Enter a positive integer: ");
//	fflush(stdout);
//	scanf("%d",&n);
//	printf("Factorial of %d = %d",n,Factorial (n));
//	fflush(stdout);

	//*** EX3 (Write C Program to reverse a sentence using recursion) ***
//	char string[50];
//	printf("Enter a sentence:");
//	fflush(stdout);
//	gets(string);
//	reverse_sentence(string);
//	fflush(stdout);

	//*** EX4 (Write C Program to calculate power using recursion) ***
	int base ,power;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d", &base);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d", &power);
	printf("%d^%d = %d", base,power,Get_power(base ,power));
	fflush(stdout);

	return EXIT_SUCCESS;
}
