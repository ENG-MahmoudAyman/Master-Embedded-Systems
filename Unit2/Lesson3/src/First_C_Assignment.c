/*
 ============================================================================
 Name        : First_C_Assignment.c
 Author      : Mahmoud_Ayman
 Version     :
 Copyright   : Your copyright notice
 Description : First_C_Assignment
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//*** EX1 (Write C Program to Print a Sentence) ***

	//  printf("C Programming");

	//*** EX2 (Write C Program to Print a Integer Entered by a User) ***

	//	int number;
	//	printf("Enter a integer:\t");
	//	fflush(stdout);
	//	scanf("%d",&number);
	//	printf("You entered:\t%d",number);

	//*** EX3 (Write C Program to Add Two Integers) ***

	//	int number1,number2;
	//	printf("Enter two integers:\t");
	//	fflush(stdout);
	//	scanf("%d%d",&number1,&number2);
	//	printf("Sum:\t%d",number1+number2);

	//*** EX4 (Write C Program to Multiply two Floating Point Numbers) ***

	//	float number1,number2;
	//	printf("Enter two integers:\t");
	//	fflush(stdout);
	//	scanf("%f%f",&number1,&number2);
	//	printf("Product:\t%f",number1*number2);

	//*** EX5 (Write C Program to Find ASCII Value of a Character) ***

	//	char character;
	//  printf("Enter a character:\t");
	//	fflush(stdout);
	//	scanf("%c",&character);
	//	printf("ASCII value of: %c = %d",character,character);

	//*** EX6 (Write Source Code to Swap Two Numbers) ***

	//	float a,b,swap;
	//	printf("Enter value of a:\t");
	//	fflush(stdout);
	//	scanf("%f",&a);
	//	printf("Enter value of b:\t");
	//	fflush(stdout);
	//	scanf("%f",&b);
	//	swap=a;
	//	a=b;
	//	b=swap;
	//	printf("After swapping, value of a = %.2f\nAfter swapping, value of b = %.2f",a,b);

	//*** EX6 (Write Source Code to Swap Two Numbers without temp variable) ***

	float a,b;
	printf("Enter value of a:\t");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:\t");
	fflush(stdout);
	scanf("%f",&b);
	a+=b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %.2f\nAfter swapping, value of b = %.2f",a,b);

	return EXIT_SUCCESS;
}
