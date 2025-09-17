#include <stdio.h>
#include <locale.h>

#define LEN 512

int main() {
	float a, b, c;

	setlocale(LC_ALL, "RUS");
	
	char line[LEN];
	fgets(line, LEN, stdin);
	sscanf_s(line, "%f%f%f", &a, &b, &c);
	
	if (a <= 0 || b <= 0 || c <= 0) {
		printf("Стороны должны быть положительными.");
		return 1;
	}

	if (a >= b + c || b >= a + c || c >= a + b) {
		printf("Треугольник не существует.");
		return 2;
	}

	if (a == b && b == c) {
		printf("Равносторонний");
	} else if (a == b || b == c || a == c) {
		printf("Равнобедренный");
	} else {
		printf("Треугольник общего вида");
	}

	return 0;
}