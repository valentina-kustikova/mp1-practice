#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, x1, x2, d;
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == 0.0f) {
		if (b == 0.0f) {
			if (c == 0.0f) {
				printf("Beskonechno mnogo korney.");
				return 0;
			}
			printf("Korney net.");
			return 0;
		}
		x1 = -c / b;
		printf("Uravnenie lineynoe. Koren' edinstvennyi x = %f", x1);
		return 0;
	}
	d = b * b - 4 * a * c;
	if (d < 0) {
		printf("Deystvitelnyh korney net.");
		return 0;
	}
	if (d == 0) {
		x1 = -b / (2 * a);
		printf("Dva kornya sovpadaut x1 = x2 = %f", x1);
		return 0;
	}
	x1 = (-b + sqrt(d)) / (2 * a);
	x2 = (-b - sqrt(d)) / (2 * a);
	printf("Korni ravny: x1 = %f; x2 = %f", x1, x2);
	return 0;
}