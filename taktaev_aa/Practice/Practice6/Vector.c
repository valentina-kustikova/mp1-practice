#include "Vector.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

Vector create(int n)
{
	Vector x;
	int i;
	x.n = n;
	x.mas = (double*)malloc(x.n * sizeof(double));
	return x;
}
void deleteV(Vector x)
{
	x.n = 0;
	free(x.mas);
}
Vector addition(Vector a, Vector b, int* f)
{
	Vector rez = create(a.n);
	Vector error = create(0);
	int i;
	if (a.n != b.n)
	{
		printf("Vectors' dimensions are not equal!\n");
		*f = 1;
		return error;
	}
	for (i = 0; i < a.n; i++)
	{
		rez.mas[i] = a.mas[i] + b.mas[i];
	}
	return rez;
}
Vector subtraction(Vector a, Vector b, int* f)
{
	Vector rez = create(a.n);
	Vector error = create(0);
	int i;
	if (a.n != b.n)
	{
		printf("Vectors' dimensions are not equal!\n");
		*f = 1;
		return error;
	}
	for (i = 0; i < a.n; i++)
	{
		rez.mas[i] = a.mas[i] - b.mas[i];
	}
	return rez;
}
double scalar(Vector a, Vector b, int* f)
{
	double rez = 0;
	int i;
	if (a.n != b.n)
	{
		printf("Vectors' dimensions are not equal!\n");
		*f = 1;
		return 0;
	}
	for (i = 0; i < a.n; i++)
	{
		rez += a.mas[i] * b.mas[i];
	}
	return rez;
}
double angle(Vector a, Vector b, int* f)
{
	double cos;
	if ((length(a, f) == 0) || (length(b, f) == 0))
	{
		printf("ERROR/n");
		*f = 1;
		return 0;
	}
	cos = scalar(a, b, f) / (length(a, f) * length(b, f));
	return acos(cos) * 180 / M_PI;
}
double length(Vector x, int* f)
{
	double rez = 0;
	return sqrt(scalar(x, x, f));
}
