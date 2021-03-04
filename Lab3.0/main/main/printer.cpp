#define _CRT_SECURE_NO_WARNINGS
#include "printer.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <stdlib.h>

void Printer::print_add(int a, int b)
{
	printf("%d\n", a+b);
}

void Printer::print_add(int a, int b, int c)
{
	printf("%d\n", a + b+c);
}

void Printer::print_add(double a, double b)
{ 
	printf("%f\n", a + b);
}

void Printer::print_add(double a, double b, double c)
{
	printf("%f\n", a + b + c);
}

void Printer::print_add(int count, ...)
{
	int sum = 0;
	va_list v1;
	va_start(v1, count);
	for (int i = 0; i < count; i++)
	{ 
		sum += va_arg(v1, int);
	}
	va_end(v1);
	printf("%d\n", sum);

}

void Printer::print_add(const char* s1, const char* s2)
{
	char* result = (char* )(malloc(strlen(s1) + strlen(s2) + 1));
	strcpy(result, s1);
	strcat(result, s2);
	printf("%s\n", result);
	free(result);

}

