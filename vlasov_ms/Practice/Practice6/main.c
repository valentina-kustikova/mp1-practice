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
	printf("Введите размер первого вектора: ");
	scanf("%zd", &dims);
	v_create(dims, &v1);
	printf("Введите координаты вектора (через пробел): ");
	v_input(v1);
	v_output(v1);
	printf("1. длина  2. ввести v2\nВыберите операцию: ");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
		printf("Длина: %lf\n", v_len(v1));
		break;
	case 3:
		printf("Инверт: ");
		if (!v_inv(v1, &v3))
			v_output(v3);
		else
			printf("Не могу инвертировать.\n");
		break;
	case 2:
		printf("Введите размер второго вектора: ");
		scanf("%zd", &dims);
		v_create(dims, &v2);
		printf("Введите координаты вектора (через пробел): ");
		v_input(v2);
		v_output(v2);
		printf("1. +   2. -  3. скп  4. угол(рад)  5. угол(гр)\nВыберите операцию: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			v_add(v1, v2, &v3);
			break;
		case 2:
			v_sub(v1, v2, &v3);
			break;
		case 3:
			v_scm(v1, v2, &op2);
			printf("СкП: %lf\n", op2);
			break;
		case 4:
			v_ang(v1, v2, &op2);
			printf("Угол(рад): %lf\n", op2);
			break;
		case 5:
			v_deg(v1, v2, &op2);
			printf("Угол(гр): %lf\n", op2);
			break;
		}
		break;
	}
}