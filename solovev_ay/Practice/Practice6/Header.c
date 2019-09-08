#include "Header.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
void Output(VECTOR a)
{
	int i;
	printf("Its vector:");
	for (i = 0; i < a.n; i++)
	{
		printf("%d , ", a.elements[i]);
	}
}
VECTOR  input(int _n)
{
	VECTOR a;
	int i;
	a.n = _n;
	a.elements = (int*)malloc(sizeof(int)*_n);
	printf("Enter");
	for (i = 0; i < a.n; i++)
	{
		scanf("%d", &a.elements[i]);
	}
	printf("vash vector");
	for (i = 0; i < a.n; i++)
	{
		printf("%d", a.elements[i]);
	}
	printf("\n");
	return a;
}
VECTOR Sum(VECTOR a, VECTOR b)
{
	int i;
	int q;
	VECTOR c;
	c.n = a.n;
	q = a.n;
	c.elements = (int*)malloc(sizeof(int)*c.n);
	for (i = 0; i < q; i++)
	{
		c.elements[i] = 0;
	}
	if (a.n == b.n)
	{
		for (i = 0; i < a.n; i++)
		{
			c.elements[i] =a.elements[i] + b.elements[i];
		}
		return c;
	}
	else
	{
		printf("dlini ne sovpadayut");
	}
}
VECTOR roflan(VECTOR a, VECTOR b)
{
	VECTOR c;
	int q;
	q = a.n;
	c.n = q;
	c.elements= (int*)malloc(sizeof(int)*q);
	int i;
	for ( i = 0; i < q; i++)
	{
		c.elements[i] = 0;
	}
	if (a.n == b.n)
	{
		for (i = 0; i < a.n; i++)
		{
			c.elements[i] =a.elements[i] - b.elements[i];
		}
		return c;
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
		return sum;
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
	printf("%f", length);
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
		return otv;
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
		free(a.elements);
	return 0;
}
