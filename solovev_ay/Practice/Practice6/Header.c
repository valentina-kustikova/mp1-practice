#include "Header.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
void Output(VECTOR a)
{
	int i;
	printf("vot vector:");
	for (i = 0; i < a.n; i++)
	{
		printf("%d, ", a.elements[i]);
	}
}
VECTOR  input(int _n)
{
	VECTOR a;
	int i;
	a.n = _n;
	a.elements = (int*)malloc(sizeof(int)*_n);
	for (i = 0; i < a.n; i++)
	{
		scanf("%d", &a.elements[i]);
	}
	printf("vash vector: ");
	for (i = 0; i < a.n; i++)
	{
		printf("%d", a.elements[i]);
	}
	return a;
}
void sum(VECTOR a, VECTOR b)
{
	int i;
	if (a.n == b.n)
	{
		for (i = 0; i < a.n; i++)
		{
			a.elements[i] += b.elements[i];
		}
	}
	else
	{
		printf("dlini ne sovpadayut");
	}
}
void roflan(VECTOR a, VECTOR b)
{
	int i;
	if (a.n == b.n)
	{
		for (i = 0; i < a.n; i++)
		{
			a.elements[i] -= b.elements[i];
		}
	}
	else
	{
		printf("dlini ne sovpadayut");
	}
}
void skalyar(VECTOR a, VECTOR b)
{
	int i;
	int sum = 0;
	if (a.n == b.n)
	{
		for (i = 0; i < a.n; i++)
		{
			sum += (a.elements[i] * b.elements[i]);
		}
		printf("/n %d", sum);
	}
	else
	{
		printf("dlini ne sovpadayut");
	}
}
void length(VECTOR a)
{
	int i;
	float length = 0;
	for (i = 0; i < a.n; i++)
	{
		length += (a.elements[i] * a.elements[i]);
	}
	length = sqrt(length);
}
void corner(VECTOR a, VECTOR b)
{
	int skalur = 0;
	float lengtha = 0, lengthb = 0, znam = 0, cosinius = 0, otv = 0;
	int i;
	if (a.n == b.n)
	{
		{
			for (i = 0; i < a.n; i++)
			{
				skalur += (a.elements[i] * b.elements[i]);
			}
		}
		for (i = 0; i < a.n; i++)
		{
			lengtha += (a.elements[i] * a.elements[i]);
			lengthb += (b.elements[i] * b.elements[i]);
		}
		lengtha = sqrt(lengtha);
		lengthb = sqrt(lengthb);
		znam = lengthb * lengtha;
		cosinius = skalur / znam;
		otv = acos(cosinius);
		printf("ugol %f rad, %f gradusov, cos = %f", otv, otv*(180 / 3.14), cosinius);
	}
	else
	{
		printf("dlini ne sovpadayut");
	}
}
int Delete(VECTOR a)
{
	a.n = 0;
	if (a.elements)
	{
		free(a.elements);
	}
	return 0;
}
