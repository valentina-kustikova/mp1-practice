#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "Vector.h"

void main()
{
	Vector v1, v2, v3;
	int op;
	size_t dims = 0;
	double op2;
	setlocale(LC_ALL, "Russian");

	v_init(&v1);
	v_init(&v2);
	v_init(&v3);

	/*v_create(3, &v1);
	v1.v[0] = 1;
	v1.v[1] = 2;
	v1.v[2] = 3;
	v_output(v1);

	v_create(3, &v2);
	v2.v[0] = 3;
	v2.v[1] = 2;
	v2.v[2] = 1;
	v_output(v2);

	if (!v_add(v1, v2, &v3))
		v_output(v3);
	else
		printf("Не могу сложить.\n");
	*/

	printf("Введите размер первого вектора: ");
	scanf("%zd", &dims);
	if(v_create(dims, &v1))
		printf("Вы создали вектор длины 0.\n");
	printf("Введите координаты вектора (через пробел): ");
	v_input(v1);
	v_output(v1);
	printf("1. длина  2. ввести v2  3. *(-1)\nВыберите операцию: ");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
		printf("Длина: %lf\n", v_len(v1));
		break;
	case 3:
		printf("Умнож на -1: ");
		if (!v_mul(v1, -1.0F, &v3))
			v_output(v3);
		else
			printf("Не могу инвертировать.\n");
		break;
	case 2:
		printf("Введите размер второго вектора: ");
		scanf("%zd", &dims);
		if(v_create(dims, &v2))
			printf("Вы создали вектор длины 0.\n");;
		printf("Введите координаты вектора (через пробел): ");
		v_input(v2);
		v_output(v2);
		printf("1. +   2. -  3. скп  4. угол(рад)  5. угол(гр)\nВыберите операцию: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if(!v_add(v1, v2, &v3))
				v_output(v3);
			else
				printf("Не могу сложить (возможно, векторы разной длины).\n");
			break;
		case 2:
			if(!v_sub(v1, v2, &v3))
				v_output(v3);
			else
				printf("Не могу вычесть (возможно, векторы разной длины).\n");
			break;
		case 3:
			if (!v_scm(v1, v2, &op2))
				printf("%lf\n", op2);
			else
				printf("Не могу произвести (возможно, векторы разной длины).\n");
			break;
		case 4:
			if (!v_ang(v1, v2, &op2))
				printf("%lf\n", op2);
			else
				printf("Не могу посчитать в угол (возможно, векторы разной длины).\n");
			break;
		case 5:
			if (!v_deg(v1, v2, &op2))
				printf("%lf\n", op2);
			else
				printf("Не могу посчитать угол (возможно, векторы разной длины).\n");
			break;
		}
		break;
	}
}