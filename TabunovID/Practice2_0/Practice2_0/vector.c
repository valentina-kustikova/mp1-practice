#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <math.h>

void allocate_vector(TVector** vector, int n)
{
    (*vector) = (TVector*)malloc(sizeof(TVector) * 1);
    (*vector)->n = n;
    (*vector)->x = (float*)malloc(sizeof(float) * n);
}

void fill_vector(TVector* vector)
{
    int i = 0;
    for (; i < vector->n; i++)
    {
        scanf_s("%f", &(vector->x[i]));
    }
}

void print_vector(TVector* vector)
{
    int i = 0;
    for (; i < vector->n; i++)
    {
        printf("%.3f ", vector->x[i]);
    }
    printf("\n");
}

void free_vector(TVector** vector)
{
    free((*vector)->x);
    free(*vector);
}

TVector* add_vector(TVector* vector1, TVector* vector2)
{
    TVector* res;
    int i = 0;
    if (vector1->n != vector2->n)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return NULL;
    }
    allocate_vector(&res, vector1->n);
    for (; i < res->n; i++)
    {
        res->x[i] = vector1->x[i] + vector2->x[i];
    }
    return res;
}

TVector* add_const(TVector* vector, float c)
{
    TVector* res;
    int i = 0;
    allocate_vector(&res, vector->n);
    for (; i < res->n; i++)
    {
        res->x[i] = vector->x[i] + c;
    }
    return res;
}

float multi_vector(TVector* vector1, TVector* vector2)
{
    float res = 0.0f;
    int i = 0;
    if (vector1->n != vector2->n)
    {
        printf("ERROR: Matrix should have the same lenght.\n");
        return 0.0f;
    }
    float a = sqrt(vector1->n);
    for (; i < a; i++)
    {
       
    }
    return res;
}

TVector* multi_const(TVector* vector, float c)
{
    TVector* res;
    int i = 0;
    allocate_vector(&res, vector->n);
    for (; i < res->n; i++)
    {
        res->x[i] = vector->x[i] * c;
    }
    return res;
}
