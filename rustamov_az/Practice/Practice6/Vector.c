
#include "Vector.h"

void Print(Vector *v)
{
    int i;
    for (i = 0; i < v->deg; i++)
        printf("%lf ", v->x[i]);
    printf("\n");
}
Vector* CreateV(int _deg)
{
	Vector* res = (Vector*)malloc(sizeof(Vector));
    res->deg = _deg;
    res->x = (double*)malloc(sizeof(double) * _deg);
	return res;
}

void DestroyV(Vector *a)
{
    if (a->deg && a->x) free(a->x);
    a->deg = 0;
    a->x = NULL;
}

Vector Sum(Vector *a, Vector *b)
{
    int i = 0;
	if ((a->deg) != (b->deg))
	{
		printf("Размерности векторов не совпадают");
		return *a;
	}
    Vector* tmp;
    tmp = CreateV(a->deg);
	for (i; i < a->deg; i++)
	{
		tmp->x[i] = a->x[i] + b->x[i];
	}
	return *tmp;
}

Vector Diff(Vector *a, Vector *b)
{
	int i = 0;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return *a;
	}
    Vector* tmp;
    tmp = CreateV(a->deg);
	for (i; i < a->deg; i++)
	{
		tmp->x[i] = a->x[i] - b->x[i];
	}
	return *tmp;
	
}

double Length(Vector *a)
{
	double l = 0.0;
	int i = 0;
	for (i; i < a->deg; i++)
	{
		l += a->x[i] * a->x[i];
	}
	return sqrt(l);
}

double Skal(Vector *a, Vector *b)
{
	double skal = 0.0;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return 0.0;
	}
	int i = 0;
	for (i; i < a->deg; i++)
	{
		skal += a->x[i] * b->x[i];
	}
	return skal;
}
double Angle(Vector *a, Vector *b)
{
	double ang, la, lb, skal;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return 0.0;
	}
	la = Length(a);
	lb = Length(b);
	skal = Skal(a, b);
	ang = acos((skal / (la*lb))) * PI;
	return ang;
}
