#include <stdio.h>
int main() {
	float a, b, c;
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == 0) {
		printf("x = %f", -b / c);
		return 1;
	}
	printf("d = %f", b * b - 4 * a * c);
	return 0;
}
