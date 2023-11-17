# include <stdio.h> 
# include <locale.h>
# include <math.h>

int main() {
	float x1, y1, R1, x2, y2, R2, D; 
	setlocale(LC_ALL, "Rus");

	printf("Введите координаты центра 1ой окружности и её радиус\n");
	printf("x1 y1 R1 = ");
	scanf("%f %f %f", &x1, &y1, &R1);

	if (R1 <= 0) {
		printf("Т.к радиус 1ой окружности <=0 это не окружность");
		return 0;
	}

	printf("Введите координаты центра 2ой окружности и её радиус\n");
	printf("x2 y2 R2 = ");
	scanf("%f %f %f", &x2, &y2, &R2);

	if (R2 <= 0) {
		printf("Т.к радиус 2ой окружности <= 0 это не окружность"); 
		return 0;
	}
	if (R1 == R2 && x1 == x2 && y1 == y2) {
		printf("Окружности совпадают");
		return 0;
	}

	D = sqrt( (abs(x1 - x2))*(abs(x1 - x2)) + 
		(abs(y1 - y2)) * (abs(y1 - y2)));

	if (D < abs(R1 - R2)) {
		printf("Окружности вложены и не песекаются");
		return 0;
	}
	if (D > R1 + R2) {
		printf("Окружности не пересекаются");
		return 0;
	}
	if (D == R1 + R2) {
		printf("Окружности касаются снаружи");
		return 0;
	}
	if (D == R1 - R2) {
		printf("Окружности соприкасаются внутри");
		return 0;
	}
	printf("Окружности пересекаются в двух точках");
	return 0;
}
