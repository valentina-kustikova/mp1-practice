#include <stdio.h>

int main() {
	float a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	if (a < 0 || b < 0 || c < 0) {
		printf("Incorrect input values!");
		return 1;
	}
	if (a >= b + c || b >= a + c || c >= a + b) {
		printf("Triangle doesn't exist");
		return 1;
	}
	if (a == b && b == c) {
		printf("Equilateral triangle");
		return 0;
	}
	if (a == b || b == c || c == a) {
		printf("Isosceles triangle");
		return 0;
	}
	printf("Regular triangle");
	return 0;
}