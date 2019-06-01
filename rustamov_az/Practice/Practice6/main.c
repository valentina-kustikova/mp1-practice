#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "Vector.h"

main()
{
    setlocale(LC_ALL, "Russian");
    Vector *a, *b, *c, *d, *e;
	int i = 0;
	double l, s, ang;
	a = CreateV(5);
	b = CreateV(5);
	c = CreateV(7);
    d = CreateV(7);
    e = CreateV(7);
	DestroyV(b);
	b = CreateV(5);
	for ( i; i < a->deg; i++)
	{
		a->x[i] = i;
		b->x[i] = i + 1;
	}
    printf("Вектор а:");
    Print(a);
    printf("Вектор b:");
    Print(b);
	*d = Sum(a, b);
    printf("Вектор d(суммы a и b):");
    Print(d);
	*e = Diff(a, b);
    printf("Вектор e(разности a и b):");
    Print(e);
	printf("Длина а = %lf\n", Length(a));
    printf("Длина b = %lf\n", Length(b));
    printf("Длина d(суммы a и b) = %lf\n", Length(d));
    printf("Длина e(разности a и b) = %lf\n", Length(e));
	s = Skal(a, b);
	printf("Скалярное произведение a и b = %lf\n", s);
	ang = Angle(b, a);
	printf("Угол между a и b = %lf\n", ang);
    scanf_s("%lf",&l);

}