#include <stdio.h>
#define t 0.015
#define pd 750
#define pdsp 650
#define pdvp 600
int main() {
	double mass, h, w, d, m1, m2, m3, m4, m5, copy;
	int k;
	printf("Введите высоту, ширину и глубину шкафа");
	do {
		scanf_s("%d %d %d", &h, &w, &d);
	} while (!(h >= 180 && h <= 220 && w >= 80 && w <= 120 && d >= 50 && d <= 90));
	m1 = h * w * pdvp * 0.005;
	m2 = 2 * h * d * t * pdsp;
	m3 = 2 * w * d * t * pdsp;
	m4 = h * w * pd * 0.01;
	//k = int((int(h * 1000)) / 415)
	copy = h;
	while (copy >= 0.415) {
		copy -= 0.4;
		k++;
	}
	m5 = k * (w - t * 2) * d * t * pdsp;
	printf("Масса вашего шкафа = %f", m1 + m2 + m3 + m4 + m5);
	return 0;
}