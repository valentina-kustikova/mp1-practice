#include <stdio.h>
int main() {
	float v, u, t1, t2;
	scanf_s("%f %f %f %f", &v, &u, &t1, &t2);
	printf("%f", v * t1 + (v - u) * t2);
	return 0;
}