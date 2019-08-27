#include "stdio.h"
#include "vector.h"
#include "locale.h"

void main() {
	vector a, b, c;
	int f, flag = 1;
	double an, len;
	float s;
	setlocale(LC_ALL, "Rus");
	while (flag) {
		printf("Список комманд:\n0.Создать векторы\n1. Сумма векторов\n2. a-b\n3. b-a\n4. Угол между векторами\n5. Скалярное произведение\n6. Длина первого вектора\n7. Длинна второго вектора\n8. Удалить векторы\n9. Закончить\n");
		scanf("%d", &f);
		switch (f) {
		case 0:
			a = create();
			b = create();
			break;
		case 1:
			c = sum(a, b);
			printf("Сумма вектора a и b:\n");
			output(c);
			del(c);
			break;
		case 2:
			c = dif(a, b);
			printf("Разность a и b:\n");
			output(c);
			del(c);
			break;
		case 3:
			c = dif(b, a);
			printf("Разность b и a:\n");
			output(c);
			del(c);
			break;
		case 4:
			printf("Угол между векторами a и b: ");
			an = angle(a, b);
			printf("%.2f\n", an);
			break;
		case 5:
			s = scalar(a, b);
			printf("Скалярное произведение: %.2f\n", s);
			break;
		case 6:
			len = length(a);
			printf("Длинна вектора a: %lf\n", len);
			break;
		case 7:
			len = length(b);
			printf("Длинна вектора b: %lf\n", len);
			break;
		case 8:
			del(a);
			del(b);
			printf("Векторы успешно удалены\n");
			break;
		case 9:
			flag = 0;
			break;
		}
	}
}