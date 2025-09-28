#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, r1, x2, y2, r2, dist;
	printf("Введите координаты и радиус 1 окружности:\n");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Введите координаты и радиус 2 окружности:\n");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	if ((r1 < 0) || (r2 < 0)) {
		printf("Радиусы не могут быть отрицательными");
		return 1;
	}


	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
		printf("Окружности совпадают");
		return 0;
	}


	dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));


	if ((abs(r1 - r2) > dist) || ((r1 + r2) < dist)) {
		printf("Окружности не пересекаются");
		return 0;
	}


	if (abs(r1 - r2) == dist) {
		printf("Внутреннее касание окружностей");
		return 0;
	}


	if ((r1 + r2) == dist) {
		printf("Внешнее касание окружностей");
		return 0;
	}


	printf("Окружности пересекаются");
	return 0;
}