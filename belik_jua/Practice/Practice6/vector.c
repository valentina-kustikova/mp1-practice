#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define pi 3.1415F

void Print(Vector *v)
{
    int i;
    for (i = 0; i < (*v).n; i++)
        printf("%lf ", (*v).x[i]);
    printf("\n");
}

Vector* Fill(Vector *v)
{
    int i;
    printf("Enter coordinates \n");
    for (i = 0; i < (*v).n; i++)
    {
        scanf("%lf", &((*v).x[i]));
    }
    return v;
}

Vector* Cre(int _n)
{
    Vector *A = (Vector*)malloc(sizeof(Vector));
    (A)->n = _n;
    (A)->x = (float*)malloc(sizeof(float) * _n);
    return A;
}

void DeleteAll(Vector *v)
{
    free((*v).x);
    (*v).n = 0;
}

Vector* Sum(Vector *v1, Vector *v2)
{
    if ((v1->n) != (v2->n)) 
        return;
    Vector *A;
    A = Cre(v1->n);
    int i;
    for (i = 0; i < (*A).n; i++)
        (*A).x[i] = (*v1).x[i] + (*v2).x[i];
    return A;
}

Vector* Diff(Vector *v1, Vector *v2)
{
    if ((*v1).n != (*v2).n)
        return;
    Vector *A;
    A = Cre(v1->n);
    int i;
    for (i = 0; i < (*A).n; i++)
        (*A).x[i] = (*v1).x[i] - (*v2).x[i];
    return A;
}

double Len(Vector *v)
{
    double s = 0;
    int i;
    for (i = 0; i < (*v).n; i++)
        s += ((*v).x[i] * (*v).x[i]);
    s = sqrt(s);
    return s;
}

double Skal(Vector *v1, Vector *v2)
{
    if ((*v1).n != (*v2).n)
        return 0;
    double S = 0;
    int i;
    for (i = 0; i < (v1)->n; i++)
        S += ((v1)->x[i] * (v2)->x[i]);
    return S;
}

double Angle(Vector *v1, Vector *v2)
{
    double S, c, l1, l2;
    c = Skal(v1, v2);
    l1 = Len(v1);
    l2 = Len(v2);
    if ((l1 == 0) || (l2 == 0))
        return 0;
    S = acos(c / (l1 * l2)); 
    S = S / pi * 180;
    return S;
}