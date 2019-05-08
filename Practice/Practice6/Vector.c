#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

#define PI 3.14159265  

void Create(int *d, Vector **v)
{
    *v = (Vector*)malloc(sizeof(Vector));
    (*v)->dim = *d;
    (*v)->x = (double*)malloc(sizeof(double) * ((*v)->dim));
}

void Fill(Vector **v)
{
    int i = 0;
    printf("Введите координаты вектора:\n");
    for (i = 0; i < (*v)->dim; i++)
        scanf("%lf", &((*v)->x)[i]);
}

void Print(Vector *v)
{
    int i = 0;
    printf("Координаты полученного вектора:\n");
    for (; i < (v)->dim; i++)
        printf("%.3lf ", (v)->x[i]);
}

void Delete(Vector *v)
{
    if (v != NULL)
    {
        free(v->x);
        v->dim = 0;
    }
}

Vector* Add(Vector *v1, Vector *v2) 
{
    int i = 0;
    Vector *v = NULL;
    Create(&v1->dim, &v);
    for (; i < v1->dim; i++)
        ((v)->x)[i] = (v1->x)[i] + (v2->x)[i];
    return v;
}

Vector* Difference(Vector *v1, Vector *v2)
{
    int i = 0;
    Vector *v = NULL;
    Create(&v1->dim, &v);
    for (; i < v1->dim; i++)
        ((v)->x)[i] = (v1->x)[i] - (v2->x)[i];
    return v;
}

double ScalarProduct(Vector *v1, Vector *v2) 
{
    int i = 0;
    double sp = 0;
        for (; i < v1->dim; i++)
            sp += ((v1->x)[i]) * ((v2->x)[i]);
        printf("\n%.3lf", sp);
    return sp;
}

double Lenght(Vector *v) 
{
    int i = 0;
    double len = 0;
    for (; i < v->dim; i++)
        len += (v->x)[i] * (v->x)[i];
    len = sqrt(len);
    return len;
}

double Аngle(Vector *v1, Vector *v2) 
{
    double l1, l2, sp;
    double cos, ang;
    sp = ScalarProduct(v1, v2);
    l1 = Lenght(v1);
    l2 = Lenght(v2);
    cos = sp / (l1 * l2);
    ang = acos(cos) * 180.0 / PI;
    printf("\n угол %.3lf", ang);
    return ang;
}

int Check(Vector *v1, Vector *v2)
{
    int n;
    if ((v1->dim) == (v2->dim))
        n = 1;
    else
        n = 0;
    return n;
}