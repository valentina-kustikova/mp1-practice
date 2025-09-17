#include <stdio.h>
int main() {
	float a, b, c;
	scanf_s("%f %f %f", &a, &b, &c);
	printf("s = %.0f", a * b * c);
	return 0;
}