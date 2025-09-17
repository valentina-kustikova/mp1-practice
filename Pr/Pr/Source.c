#include<stdio.h>

int main() {
	float v1, v2, s, t;
	scanf_s("%f%f%f%f", &v1, &v2, &s, &t);
	printf("s=%f", s+(v1+v2)*t);
	return 0;
}
