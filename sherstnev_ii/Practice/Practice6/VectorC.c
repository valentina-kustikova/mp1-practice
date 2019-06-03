#include "VectorC.h"
#include <stdio.h>
#include <math.h>

#define M_PI       3.14159265358979323846

void Create(int n, Vector *v) 
{
	if (n <= 0) {
		printf("Dimension < 1\n");
		return;
	}
	v->size = n;
	v->elements = (double*)malloc(sizeof(double)*v->size);
}

void Delete(Vector *v) 
{
	int i;
	for (i = 0; i < v->size; i++) 
	{
		free(v->elements[i]);
	}
	v->size = 0;
}

int Sum(Vector *v1, Vector *v2, Vector *vres) 
{
	int i;
	if ((v1->size != v2->size) || (v1->size != vres->size)) {
		printf("Wrong dimensions");
		return -1;
	}
	for (i = 0; i < v1->size; i++) 
	{
		vres->elements[i] = v1->elements[i] + v2->elements[i];
	}
	return 0;
}

int Sub(Vector *v1, Vector *v2, Vector *vres)
{
	int i;
	if ((v1->size != v2->size) || (v1->size != vres->size)) {
		printf("Wrong dimensions");
		return -1;
	}
	for (i = 0; i < v1->size; i++)
	{
		vres->elements[i] = v1->elements[i] - v2->elements[i];
	}
	return 0;
}

int Scalar(Vector *v1, Vector *v2, double *s) 
{
	int i;
	if (v1->size != v2->size) {
		printf("Wrong dimensions");
		return -1;
	}
	*s = 0.0;
	for (i = 0; i < v1->size; i++) 
	{
		*s += v1->elements[i] * v2->elements[i];
	}
	return 0;
}

double Length(Vector *v) 
{
	int i;
	double res = 0.0;
	for (i = 0; i < v->size; i++) 
	{
		res += v->elements[i] * v->elements[i];
	}
	return sqrt(res);
}

int Angle(Vector *v1, Vector *v2, double *s) 
{
	int i;
	double l1, l2, sc;
	if (v1->size != v2->size) {
		printf("Wrong dimensions");
		return -1;
	}
	l1 = Length(v1);
	l2 = Length(v2);
	Scalar(v1, v2, &sc);
	*s = acos(sc / (l1 * l2)) * 180 / M_PI;
	return 0;
}

void Input(Vector *v) 
{
	int i;
	if (v->size <= 0) {
		printf("Dimension < 1\n");
		return;
	}
	for (i = 0; i < v->size; i++) 
	{
		printf("Vvedite coord %d\n", i+1);
		scanf("%lf", &v->elements[i]);
		printf("\n");
	}
	printf("Done\n");
}

void Output(Vector *v) 
{
	int i;
	if (v->size <= 0) {
		printf("Dimension < 1\n");
		return;
	}
	printf("Vector: ");
	for (i = 0; i < v->size; i++)
	{
		printf("%lf ", v->elements[i]);
	}
	printf("\n");
}