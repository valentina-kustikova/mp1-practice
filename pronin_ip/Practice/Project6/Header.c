#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
Vector Input(int n)
{
	Vector a;
	int i;
	a.n = n;
	a.elements = (int*)malloc(sizeof(int)*n);
	printf("Vvedite koordinat");
	for (i = 0; i < a.n; i++)
	{
		scanf_s("%d", &a.elements[i]);
	}
	return a;
}
void Delete(Vector a)
{
	if (a.elements)
	{
		free(a.elements);
	}
	a.n = 0;
}
Vector Sum(Vector a, Vector b)
{
	if (a.n = b.n)
	{
		int i;
		Vector c;
		c.n = a.n;
		c.elements = (int*)malloc(sizeof(int)*a.n);
		for (i = 0; i < a.n; i++)
			c.elements[i] = a.elements[i] + b.elements[i];
		return c;
	}
	else
	{
		printf("mistake!");
		return;
	}
}
void Output(Vector a)
{
	int i;
	for (i = 0; i < a.n; i++)
	{
		printf("%d", a.elements[i]);
	}
}
Vector Raz(Vector a, Vector b)
{
	if (a.n = b.n)
	{
		int i;
		Vector d;
		d.n = a.n;
		d.elements = (int*)malloc(sizeof(int)*a.n);
		for (i = 0; i < a.n; i++)
			d.elements[i] = a.elements[i] - b.elements[i];
		return d;
	}
	else
	{
		printf("mistake!");
		return;
	}
}
int Scayler(Vector a, Vector b)
{
	int i, x = 0;
	for (i = 0; i < a.n; i++)
		x += a.elements[i] * b.elements[i];
	return x;
}
double Length(Vector a)
{
	int i, y = 0;
	double z;
	for (i = 0; i < a.n; i++)
		y += (a.elements[i])*(a.elements[i]);
	z = sqrt(y);
	return z;
}
double Corner(Vector a, Vector b)
{
	int q;
	double w, e, r, t;
	q = Scayler(a, b);
	w = Length(a);
	e = Length(b);
	r = q / (w*e);
	t = acos(r);
	return t;
}