#include "Vector.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void main()
{
    int num1, num2;
    int f = 0;//flazhok na oshibku v odnoi iz funkcii
    int i;
    Vector x, y, sum, diff;
    double scal, ang, lenX, lenY;
    printf("Enter the first vector's dimension:\n");
    scanf("%d", &num1);
    x = create(num1);
    printf("Please enter values of first vector's components:\n");
    for (i = 0; i < x.n; i++)
    {
        scanf("%lf", &x.mas[i]);
    }
    printf("Enter the second vector's dimension:\n");
    scanf("%d", &num2);
    y = create(num2);
    printf("Please enter values of second vector's components:\n");
    for (i = 0; i < y.n; i++)
    {
        scanf("%lf", &y.mas[i]);
    }
    sum = addition(x, y, &f);
    if (f == 1) return;
    diff = subtraction(x, y, &f);
    if (f == 1) return;
    scal = scalar(x, y, &f);
    if (f == 1) return;
    ang = angle(x, y, &f);
    if (f == 1) return;
    lenX = length(x, &f);
    lenY = length(y, &f);
    printf("A sum of vector x and vector y is vector:\n");
    for (i = 0; i < sum.n; i++)
    {
        printf("%lf \n", sum.mas[i]);
    }
    printf("A difference of vector x and vector y is vector:\n");
    for (i = 0; i < diff.n; i++)
    {
        printf("%lf \n", diff.mas[i]);
    }
    printf("A scalar product of vector x and vector y is %lf \n", scal);
    printf("An angle between vector x and vector y is %lf degrees.\n", ang);
    printf("A length of vector x is %lf \n", lenX);
    printf("A length of vector y is %lf \n", lenY);
    deleteV(x);
    deleteV(y);
    deleteV(sum);
    deleteV(diff);
}