#include "Vector.h" 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define P 3.14F

//Выделение памяти под вектор 
Vector Create(int n)
{
	Vector x;
	int i;
	x.size = n;
	x.V = (float*)malloc(sizeof(float)*x.size);
	for (i = 0; i < n; i++)
		x.V[i] = 0;
	return x;
}

//Заполнение 
Vector fill()
{
	Vector x;
	int i, n;
	printf("Enter size of your vector: ");
	scanf_s("%d", &n);
	x.size = n;
	x.V = (float*)malloc(sizeof(float)*x.size);
	printf("Enter coordinat: \n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &(x.V[i]));
	}
	printf("Vector fill with coordinates : ");
	return x;
}

//Удаление 
void Delete(Vector x)
{
	x.size = 0;
	free(x.V);
}

//Суммирование 
Vector Sum(Vector V1, Vector V2)
{
	Vector s;
	int i;
	s = Create(V1.size);
	if (V1.size == V2.size)
	{
		for (i = 0; i < V1.size; i++)
		{
			s.V[i] = V1.V[i] + V2.V[i];
		}
		printf("Sum: ");
		return s;
	}
	else
	{
		printf("Error. Different sizes");
		return s;
	}
}


//Вычитание 
Vector Sub(Vector V1, Vector V2)
{
	Vector m;
	int i;
	m = Create(V1.size);
	if (V1.size == V2.size)
	{
		for (i = 0; i < V1.size; i++)
		{
			m.V[i] = V1.V[i] - V2.V[i];
		}
		printf("Difference: ");
		return m;
	}
	else
	{
		printf("Error. Different sizes ");
		return m;
	}
}

//Скалярное произведение 
float scalar(Vector V1, Vector V2)
{
	int i;
	float sc = 0;
	if (V1.size == V2.size)
	{
		for (i = 0; i < V1.size; i++)
		{
			sc += V1.V[i] * V2.V[i];
		}
		printf("Scalar: ");
		return sc;
	}
	else
	{
		printf("Error. Different sizes ");
		return 0;
	}
}

//Длина вектора
float Length(Vector V)
{
	float l = 0;
	int i;
	for (i = 0; i < V.size; i++)
		l += (V.V[i] * V.V[i]);
	l = sqrt(l);
	return l;
}

//угол между векторами
float Angle(Vector V1, Vector V2)
{
	float An = 0, A = 0;
	int i;

	if (V1.size == V2.size)
	{

		for (i = 0; i < V1.size; i++)
			A += V1.V[i] * V2.V[i];

		An = A / ((Length(V1) * Length(V2)));
		An = acos(An) * 180 / P;
	}

	else
	{
		printf("Error. Different sizes ");
		return An;
	}

	return An;
}

//Вывод 
Vector Output(Vector x)
{
	int i;
	if (x.size == 0)
		printf("Vector is empty. \n");
	else
	{
		for (i = 0; i < x.size; i++)
			printf("%d ", x.V[i]);
		printf("\n");
	}
}