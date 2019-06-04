#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Header.h"
#define P 3.14

Vector* Add(int nn)
{
	Vector *el = (Vector*)malloc(sizeof(Vector)); 
	el->n = nn;
	el->a = (double*)malloc(sizeof(double) * nn);
	return el;
}
Vector* Fill(Vector *v)
{
	int i;
	printf("Enter coordinates\n");
	for(i = 0; i < v->n; i++)
		scanf ("%lf", &v->a[i]);
	return v;
}
void Print(Vector *v)
{
	int i;
	printf("Coordinates ");
	for(i = 0; i < v->n; i++)
		printf ("%lf  ", v->a[i]);
	printf ("\n");
}
void Sum(Vector *v, Vector *vv, Vector *s)
{
	int i;
	for(i = 0; i < (v)->n; i++)
		s->a[i] = v->a[i] + vv->a[i];
}
void Sub(Vector *v, Vector *vv, Vector *ss)
{
	int i;
	for(i = 0; i < (v)->n; i++)
		ss->a[i] = v->a[i] - vv->a[i];
}
double Com(Vector *v, Vector *vv)
{
	int i;
	double c = 0;
	for(i = 0; i < (v)->n; i++)
		c += v->a[i] * vv->a[i];
	return c;
}
double Length(Vector *a)
{
	int i;
	double sum = 0.0, len;
	for(i = 0; i < a->n; i++)
		sum += (a->a[i]) * (a->a[i]);
	len = sqrt(sum);
	return len;
}
double Angle(Vector *v, Vector *vv)
{
	double l1, l2, c, u;
	l1 = Length(v);
	l2 = Length(vv);
	c = Com(v, vv);
	u = acos(c / (l1 * l2)); 
	u = u / P * 180; 
	return u;
}
 void Delete (Vector *а)
{
	free(а->a);
	а->n = 0;  
}
