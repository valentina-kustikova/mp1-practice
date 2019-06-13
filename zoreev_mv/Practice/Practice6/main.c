#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "vector.h"

void main()
{
    vector a, b, c;
    double result, m;
    int control;
    setlocale(LC_ALL, "Russian");
    vector_input(&a);
    vector_input(&b);
    vector_create(&c, 1);
    printf("Выберите действие: a+b, a-b, a*b, a*m, |a|, exit\n");
    do
    {
        scanf("%d", &control);
        switch (control)
        {
        case 1:
            if (!vector_add(&c, a, b))
            {
                vector_print(c);
            }
            else
            {
                printf("Неподходящий вектор\n");
            }
            break;
        case 2:
            if (!vector_sub(&c, a, b))
            {
                vector_print(c);
            }
            else
            {
                printf("Неподходящий вектор\n");
            }
            break;
        case 3:
            if (!vector_scalar(&result, a, b))
            {
                printf("%lf\n", result);
            }
            else
            {
                printf("Неподходящий вектор\n");
            }
            break;
        case 4:
            printf("Введите m ");
            scanf("%lf", &m);
            if (!vector_multiply(&c, a, m))
            {
                vector_print(c);
            }
            else
            {
                printf("Неподходящий вектор\n");
            }
            break;
        case 5:
            if (!vector_length(&result, a))
            {
                printf("%lf\n", result);
            }
            else
            {
                printf("Неподходящий вектор\n");
            }
            break;
        } 
    } while (control != 6);
}