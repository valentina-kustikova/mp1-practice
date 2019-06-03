#pragma once

#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS

typedef struct 
{
	int n;//razmer
	double* mas;
}Vector;

Vector create(int n);
void deleteV(Vector x);
Vector addition(Vector a, Vector b, int* f);
Vector subtraction(Vector a, Vector b, int* f);
double scalar(Vector a, Vector b, int* f);
double angle(Vector a, Vector b, int* f);
double length(Vector x, int* f);
