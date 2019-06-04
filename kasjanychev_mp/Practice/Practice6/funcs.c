#pragma once
#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

Vector* create(int n)
{
    Vector *res = (Vector*)malloc(sizeof(Vector));
    res->a = n;
    res->vec = (double*)malloc(sizeof(double) * n);
    return res;
}
void del(Vector* v)
{
    free(v->vec);
    v->a = 0;
}
Vector* sum(Vector* v1, Vector* v2)
{
    int i;
    if (v1->a != v2->a)
    {
        printf("Ошибка");
        return;
    }
    Vector *res = (Vector*)malloc(sizeof(Vector));
    res->a = v1->a;
    res->vec = (double*)malloc(sizeof(double) * v1->a);
    for (i = 0; i < v1->a; i++)
    {
        res->vec[i] = v1->vec[i] + v2->vec[i];
    }
    return res;
}
Vector* sub(Vector* v1, Vector* v2)
{
    int i;
    if (v1->a != v2->a)
    {
        printf("Ошибка");
        return;
    }
    Vector *res = (Vector*)malloc(sizeof(Vector));
    res->a = v1->a;
    res->vec = (double*)malloc(sizeof(double) * v1->a);
    for (i = 0; i < v1->a; i++)
    {
        res->vec[i] = v1->vec[i] - v2->vec[i];
    }
    return res;
}
double length(Vector* v)
{
    int i;
    double len = 0;
    for (i = 0; i < v->a; i++)
        len += v->vec[i] * v->vec[i];
    len = sqrt(len);
    return len;
}
double multi(Vector* v1, Vector* v2)
{
    if (v1->a != v2->a)
    {
        printf("Ошибка");
        return;
    }
    int i;
    double al = 0;
    for (i = 0; i < v1->a; i++)
        al += v1->vec[i] * v2->vec[i];
    return al;
}
double corner(Vector* v1, Vector* v2)
{
    if (v1->a != v2->a)
    {
        printf("Ошибка");
        return;
    }
    int i;
    double ug = acos((multi(v1, v2)) / ((length(v1)) * (length(v2))));
    ug = ug * 180 / 3.1415;
    return ug;
}

void vivod(Vector* v)
{
    int i;
    for (i = 0; i < v->a; i++)
    {
        printf("%lf ", v->vec[i]);
    }
}
void vvod(Vector* v)
{
    int i;
    for (i = 0; i < v->a; i++)
    {
        scanf("%lf", &v->vec[i]);
    }
}