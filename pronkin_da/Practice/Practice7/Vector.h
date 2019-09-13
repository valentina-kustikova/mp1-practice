#pragma once
#include <math.h>

typedef struct TVector {
	int n;
	double *x;
}Vector;

Vector create(int n);
void filling(Vector, double*);
void deleted(Vector);
Vector addition(Vector, Vector);
Vector substraction(Vector, Vector);
double scalarproduct(Vector, Vector);
double angle(Vector, Vector);
double vectorlength(Vector);
void out(Vector);