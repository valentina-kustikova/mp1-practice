#include <stdio.h>
#include <math.h>

int main() {
	float x_1, x_2, y_1, y_2, r_1, r_2, d, x, y;
	scanf_s("%f %f %f %f %f %f", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
	x = fabsf(x_1 - x_2);
	y = fabsf(y_1 - y_2);
	d = sqrtf(x * x + y * y);
	if (r_1 <= 0 || r_2 <= 0) {
		printf("Error");
		return 1;
	}
	if (d == 0) {
		//���������� ���� � ������, ������ �������
		printf("1");
		return 0;
	}
	if (d < fabsf(r_1 - r_2)) {
		//���������� ���� � ������, ������ �� �������
		printf("2");
		return 0;
	}
	if (d == fabsf(r_1 - r_2)) {
		//���������� ���� � ������, �������� �������
		printf("3");
		return 0;
	}
	if (fabsf(r_1 - r_2) < d && d < r_1 + r_2) {
		//���������� ������������
		printf("4");
		return 0;
	}
	if (d == r_1 + r_2) {
		//���������� �������� �������
		printf("5");
		return 0;
	}
	if (d > r_1 + r_2) {
		//printf("���������� �� ������������");
		printf("6");
		return 0;
	}

}
