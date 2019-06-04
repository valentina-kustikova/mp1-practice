#pragma once
#include "funcs.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	int raz;
    double test;
	printf("¬ведите размерность");
	scanf("%d", &raz);
    Vector* v1;
    v1 = create(raz);
    vvod(v1);
    Vector* v2;
    v2 = create(raz);
    vvod(v2);
    Vector* v3;
    v3 = create(raz - 1);
    vvod(v3);
    Vector* v4;

    v4 = sum(v1, v2);
    vivod(v4);
    v4 = sum(v1, v3);
    vivod(v4);

    v4 = sub(v1, v2);
    vivod(v4);

    test = length(v1);
    printf("%lf \n", test);
    test = multi(v1, v2);
    printf("%lf \n", test);
    test = corner(v1, v2);
    printf("%lf \n", test);
}