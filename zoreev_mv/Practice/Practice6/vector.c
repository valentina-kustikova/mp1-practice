#include "vector.h"

void vector_create(vector* temp, int size)
{
    int i;
    temp->size = size;
    temp->array = (double*)malloc(sizeof(double) * size);
    for (i = 0; i < size; i++)
    {
        temp->array[i] = 0;
    }
}

void vector_input(vector* temp)
{
    int i, size = 0;
    printf("Введите размерность вектора\n");
    do
    {
        scanf("%d", &size);
    } while (size <= 0);
    temp->size = size;
    temp->array = (double*)malloc(sizeof(double) * size);
    printf("Введите координаты вектора\n");
    for (i = 0; i < size; i++)
    {
        scanf("%lf", &(temp->array[i]));
    }
}

int vector_add(vector* result, vector a, vector b)
{
    int i;
    if (a.size != b.size)
    {
        return 1;
    }
    free(result->array);
    result->size = a.size;
    result->array = (double*) malloc(sizeof(double) * a.size);
    for (i = 0; i < a.size; i++)
    {
        result->array[i] = a.array[i] + b.array[i];
    }
    return 0;
}

int vector_sub(vector* result, vector a, vector b)
{
    int i;
    if (a.size != b.size)
    {
        return 1;
    }
    free(result->array);
    result->size = a.size;
    result->array = (double*)malloc(sizeof(double) * a.size);
    for (i = 0; i < a.size; i++)
    {
        result->array[i] = a.array[i] - b.array[i];
    }
    return 0;
}

int vector_scalar(double* result, vector a, vector b)
{
    *result = 0;
    int i;
    if (a.size != b.size)
    {
        return 1;
    }
    for (i = 0; i < a.size; i++) {
        *result += a.array[i] * b.array[i];
    }
    return 0;
}

int vector_multiply(vector* result, vector a, double m)
{
    int i;
    free(result->array);
    result->size = a.size;
    result->array = (double*)malloc(sizeof(double) * a.size);
    for (i = 0; i < a.size; i++)
    {
        result->array[i] = a.array[i] * m;
    }
    return 0;
}

int vector_length(double* result, vector temp)
{
    *result = 0;
    int i = 0;
    for (i = 0; i < temp.size; i++)
    {
        *result += temp.array[i] * temp.array[i];
    }
    *result = sqrt(*result);
    return 0;
}


int vector_angle(double* result, vector a, vector b)
{
    double length_a, length_b, scalar;
    if (vector_length(&length_a, a) || vector_length(&length_b, b))
    {
        return 1;
    }
    if (vector_scalar(&scalar, a, b))
    {
        return 1;
    }
    *result = acos(scalar / (length_a * length_b));
    return 0;
}

void vector_print(vector a) {
    int i;
    for (i = 0; i < a.size; i++) {
        printf("%lf\n", a.array[i]);
    }
}