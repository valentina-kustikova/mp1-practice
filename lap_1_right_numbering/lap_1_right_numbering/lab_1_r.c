// плотность ДВП = 400, ДСП = 675, дерево =750
#include <stdio.h>
#include <locale.h>

int main() {
	float h, w, d, S;
	int k;
	setlocale(LC_ALL, "Rus");
	do {
		scanf_s("%f", &h);
	} while (h < 180 || h >220);

	do {
		scanf_s("%f", &w);
	} while (w < 80 || w >120);

	do {
		scanf_s("%f", &d);
	} while (d < 50 || d >90);

	h /= 100;
	w /= 100;
	d /= 100;
	k = h / 40;
	S = 400*(h*w*0.005) + 2*675*(d*h*0.015) + 2*675*(w*d*0.015) + 2*750*(h*w*0.01) + k*400*(d*w*0.015);
	printf("Общая масся равна %f килограмм", S);
	return 0;

}