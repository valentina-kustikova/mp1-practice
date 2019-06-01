#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535

typedef struct
{
	int deg;
	double* x;
}Vector;

void Print(Vector * v);
Vector* CreateV(int _deg);
void DestroyV(Vector *a);
Vector Sum(Vector *a, Vector *b);
Vector Diff(Vector *a, Vector *b);
double Length(Vector *a);
double Skal(Vector *a, Vector *b);
double Angle(Vector *a, Vector *b);

#endif