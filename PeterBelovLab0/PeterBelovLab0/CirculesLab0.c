#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "RU");
	double x1, y1, r1;
	double x2, y2, r2;
	double distance;

	printf("Введите координаты x1 и y1 и радиус r1: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &r1);

	printf("Введите координаты x2 и y2 и радиус r2: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &r2);

	if (r1 < 0 || r2 < 0) {
		printf("Радиус должен быть положительным");
		return 1;
	}

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (distance > r1 + r2) {
		printf("Окружности не пересекаются\n");
	}
	else if (distance < fabs(r1 - r2)) {
		printf("Одна окружность внутри другой\n");
	}
	else if (distance == 0 && r1 == r2) {
		printf("Окружности совпадают\n");
	}

	else if (distance == r1 + r2 || distance == fabs(r1 - r2)) {
		printf("Окружности имеют одну точку касания\n");
	}

	else {
		printf("Окружности пересекаются\n");
	}
	return 0;
}