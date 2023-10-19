/*
 ============================================================================
 Name        : 4th_C_programming_Assignment.c
 Author      : Mahmoud_Ayman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define pi 3.1416
#define Circle_Area(r) pi*r*r

enum order{
	first,second
};

//*** EX1 (Write C Program to store data of student using structure) ***
struct SStudent {
	char name[50];
	unsigned short roll;
	float mark;
};

struct SStudent Read_Student(){
	struct SStudent Student;
	printf("Enter information of Students:\n");
	printf("Enter name: ");
	fflush(stdout);
	gets(Student.name);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%hu",&Student.roll);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&Student.mark);

	return Student;
}

void Display_Student(struct SStudent Student){
	printf("Displaying Information\n");
	printf("name: %s\n",Student.name);
	printf("Roll: %hu\n",Student.roll);
	printf("Marks: %f\n",Student.mark);
	fflush(stdout);
}

//*** EX2 (Write C Program to add two distances (in inch-feet) using structure) ***

struct SDistance {
	int feet;
	float inch;
};

struct SDistance Read_Distance(enum order order){
	struct SDistance Distance;
	switch (order) {
	case first:
		printf("Enter information of 1st distance:\n");
		break;
	case second:
		printf("Enter information of 2nd distance:\n");
		break;
	}
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&Distance.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f", &Distance.inch);
	return Distance;
}

void Print_2Distances_Sum(struct SDistance Distance1,struct SDistance Distance2) {
	struct SDistance Sum;
	Sum.feet = Distance1.feet + Distance2.feet;
	Sum.inch = Distance1.inch + Distance2.inch;
	while (Sum.inch >= 12.0) {
		Sum.inch -= 12.0;
		Sum.feet++;
	}
	printf("Sum of distances = %d' %.2f\"\n",Sum.feet,Sum.inch);
}

//*** EX3 (Write C Program to add two Complex numbers using structure) ***

struct SComplex {
	float real;
	float imaginary;
};

struct SComplex Read_Complex(enum order order){
	struct SComplex Complex;
	switch (order) {
	case first:
		printf("For 1st complex number:\n");
		break;
	case second:
		printf("For 2nd complex number:\n");
		break;
	}
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f%f",&Complex.real,&Complex.imaginary);
	return Complex;
}

void Print_2Complex_Sum(struct SComplex Complex1,struct SComplex Complex2) {
	struct SComplex Sum_Complex;
	Sum_Complex.real = Complex1.real + Complex2.real;
	Sum_Complex.imaginary = Complex1.imaginary + Complex2.imaginary;

	printf("Sum = %.2f +%.2fi\n",Sum_Complex.real,Sum_Complex.imaginary);
}

//*** EX4 (Write C Program to store data of students using structure) ***
struct SStudent Student[10];
struct SStudent* Read_List_Students(){

	int i;
	printf("Enter information of Students:\n");
	for (i = 0; i < 10; i++) {
		Student[i].roll = i;
		printf("For roll number %hu\n",Student[i].roll+1);
		fflush(stdout);
		printf("Enter name: ");
		fflush(stdout);
		scanf("%s", Student[i].name);
		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f", &Student[i].mark);
	}
	return Student;
}

void Display_List_Students(struct SStudent *Student) {
	int i;
	printf("\nDisplaying information of Students:\n");
	for (i = 0; i < 10; i++) {
		printf("\nInformation for roll number %hu:\n", Student[i].roll+1);
		printf("name: %s\n", Student[i].name);
		printf("Marks: %f\n", Student[i].mark);
		fflush(stdout);
	}
}

int main(void) {

	//*** EX1 (Write C Program to store data of student using structure) ***

//	struct SStudent Student1;
//	Student1 = Read_Student();
//	Display_Student(Student1);

	//*** EX2 (Write C Program to add two distances (in inch-feet) using structure) ***

//	struct SDistance Distance1, Distance2;
//	Distance1 = Read_Distance(first);
//	Distance2 = Read_Distance(second);
//	Print_2Distances_Sum(Distance1, Distance2);

	//*** EX3 (Write C Program to add two Complex numbers using structure) ***

//	struct SComplex Complex1, Complex2;
//	Complex1 = Read_Complex(first);
//	Complex2 = Read_Complex(second);
//	Print_2Complex_Sum(Complex1, Complex2);

	//*** EX4 (Write C Program to store data of students using structure) ***

//	Display_List_Students(Read_List_Students());

	//*** EX5 (Write C Program to fine area of circle using macros) ***

	float r;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&r);
	printf("Area = %.2f",Circle_Area(r));


	return EXIT_SUCCESS;
}
