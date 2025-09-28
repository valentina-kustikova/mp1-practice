#include <stdio.h>
#include <math.h>

int inside(float xcentre, float ycentre, float radius, float x, float y) {
	float distance = (xcentre - x) * (xcentre - x) + (ycentre - y) * (ycentre - y);
	return distance <= radius * radius;
}

int main() {
	float x1, y1, x2, y2, radius1, radius2;
	scanf_s("%f %f %f", &x1, &y1, &radius1);
	scanf_s("%f %f %f", &x2, &y2, &radius2);
	// Корректность ввода
	if (radius1 <= 0 || radius2 <= 0) {
		printf("Okruzhnost' ne mozhet imet otrizatel'nyi ili nulevoi radius");
		return 1;
	}
	float distance = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (x1 == x2 && y1 == y2 && radius1 == radius2) {
		printf("Okruzhnosti sovpadayut");
		return 0;
	}
	// Проверяю лежит ли центр одной окружности в другой
	if (inside(x1, y1, radius1, x2, y2) || inside(x2, y2, radius2, x1, y1)) {
		if (radius2 > radius1) {
			float temp = radius1;
			radius1 = radius2;
			radius2 = radius1;
		}

		if (distance + radius2 < radius1) {
			printf("Okruzhnost polnost'yu lezhit v drugoi");
			return 0;
			//0 0 5 and 1 0 1
		}

		if (distance == radius1 - radius2) {
			printf("Okruzhnosti vnutrenne kasayutsya");
			return 0;
			// 0 0 5 and 2 0 3
		}

		if (distance + radius2 > radius1) {
			printf("Okruzhnosti peresekaytsya");
			return 0;
			// 0 0 5 and 3 0 4
		}
	} // Центр одной окружности находится вне второй
	else {
		if (distance < radius1 + radius2) {
			printf("Okruzhnosti peresekaytsya");
			return 0;
			// 0 0 5 and 4 4 5
		}
		if (distance == radius1 + radius2) {
			printf("Okruzhnosti kasayutsya vneshne");
			return 0;
			// 0 0 5 and 8 0 3
		}
		if (distance > radius1 + radius2) {
			printf("Okruzhnosti ne peresekayutsya");
			return 0;
			// 0 0 5 and 6 0 3
		}
	}
	return 0;
}