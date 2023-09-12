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

	//First Part:

	//*** EX1 (Write C Program to Print a Sentence) ***

	//  printf("C Programming");

	//*** EX2 (Write C Program to Print a Integer Entered by a User) ***

	//	int number;
	//	printf("Enter an integer:\t");
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

	//	float a,b;
	//	printf("Enter value of a:\t");
	//	fflush(stdout);
	//	scanf("%f",&a);
	//	printf("Enter value of b:\t");
	//	fflush(stdout);
	//	scanf("%f",&b);
	//	a+=b;
	//	b=a-b;
	//	a=a-b;
	//	printf("After swapping, value of a = %.2f\nAfter swapping, value of b = %.2f",a,b);

	//Second Part:

	//*** EX1 (Write C Program to Check odd & even) ***

	//	int number;
	//	printf("Enter a integer you want to check:\t");
	//	fflush(stdout);
	//	scanf("%d",&number);
	//	if (number%2)
	//  printf("%d is odd.",number);
	//	else
	//	printf("%d is even.",number);

	//*** EX2 (Write C Program to Check odd & even) ***

	//	char character;
	//	printf("Enter an alphabet:\t");
	//	fflush(stdout);
	//	scanf("%c",&character);
	//	switch(character)
	//	{
	//	case 'a':
	//	case 'A':
	//	case 'u':
	//	case 'U':
	//	case 'i':
	//	case 'I':
	//	case 'e':
	//	case 'E':
	//	case 'o':
	//	case 'O':
	//	{
	//		printf("%c is vowel.",character);
	//	}
	//	break;
	//	default:
	//	{
	//		printf("%c is consonant.",character);
	//	}
	//	break;
	//	}

	//*** EX3 (Write C Program to find the largest of three) ***

	//	float N1,N2,N3;
	//	printf("Enter three numbers:\t");
	//	fflush(stdout);
	//	scanf("%f%f%f",&N1,&N2,&N3);
	//
	//	if (N1>=N2)
	//	{
	//		if (N1>=N3)
	//			printf("Largest number = %.2f",N1);
	//		else
	//			printf("Largest number = %.2f",N3);
	//	}
	//	else
	//	{
	//		if (N2>=N3)
	//			printf("Largest number = %.2f",N2);
	//		else
	//			printf("Largest number = %.2f",N3);
	//	}

	//*** EX4 (Write C Program to check whether the number is positive or negative) ***

	//	float number;
	//	printf("Enter a number:\t");
	//	fflush(stdout);
	//	scanf("%f",&number);
	//	if(number>0)
	//	printf("%.2f is positive.",number);
	//	else if(number<0)
	//	printf("%.2f is Negative.",number);
	//	else
	//	printf("You entered zero.");

	//*** EX5 (Write C Program to check whether the char is alphabet or not) ***

	//	char character;
	//	printf("Enter an character:\t");
	//	fflush(stdout);
	//	scanf("%c",&character);
	//	if ((character>='a'&&character<='z')||(character>='A'&&character<='Z'))
	//		printf("%c is an alphabet",character);
	//	else
	//		printf("%c is not an alphabet",character);

	//*** EX6 (Write C Program to calculate sum of natural numbers) ***


	//	int number,i,sum=0;
	//	printf("Enter an integer:\t");
	//	fflush(stdout);
	//	scanf("%d",&number);
	//	for(i=1;i<=number;i++)
	//		sum+=i;
	//	printf("Sum = %d",sum);

	//*** EX7 (Write C Program to find factorial of a number) ***

	//	int number,i,factorial=1;
	//	printf("Enter an integer:\t");
	//	fflush(stdout);
	//	scanf("%d",&number);
	//	if(number<0)
	//		printf("Error!!! Factorial of negative number doesn't exist.");
	//	else if(number==0)
	//		printf("Factorial = 1");
	//	else
	//	{
	//		for(i=1;i<=number;i++)
	//			factorial*=i;
	//		printf("Factorial = %d",factorial);
	//	}

	//*** EX8 (Write C Program of simple calculator) ***

	char operator;
	float number1,number2;
	printf("Enter operator either + or - or * or /:\t");
	fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two operands:\t");
	fflush(stdout);
	scanf("%f%f",&number1,&number2);
	switch(operator)
	{
	case '+':
	{
		printf("%.2f %c %.2f = %.2f",number1,operator,number2,number1+number2);
	}
	break;
	case '-':
	{
		printf("%.2f %c %.2f = %.2f",number1,operator,number2,number1-number2);
	}
	break;
	case '*':
	{
		printf("%.2f %c %.2f = %.2f",number1,operator,number2,number1*number2);
	}
	break;
	case '/':
	{
		printf("%.2f %c %.2f = %.2f",number1,operator,number2,number1/number2);
	}
	break;
	default:
	{
		printf("Error");
	}
	}


	return EXIT_SUCCESS;
}
