#include <stdio.h>
int main() {
	int dvp = 850, dsp = 700, oakDensity = 700;
	float h, w, d, hm, wm, dm, shelves;

	do {
		printf("Enter correct height h: ");
		scanf_s("%f", &h);
	} while (h < 180 || h > 220);


	do {
		printf("Enter correct width w: ");
		scanf_s("%f", &w);
	} while (w < 80 || w > 120);


	do {
		printf("Enter correct depth d: ");
		scanf_s("%f", &d);
	} while (d < 50 || d > 90);

	// Перевод в СИ
	
	hm = h / 100;
	wm = w / 100;
	dm = d / 100;
	
	shelves = (int)(h) / 40;

	printf("Масса шкафа в килограммах: %f", (dvp * hm * wm * 0.005) + (2 * dsp * hm * dm * 0.015) + (2 * dsp * wm * dm * 0.015) + (oakDensity * hm * wm * 0.01) + (wm * dm * 0.015 * shelves * dsp));




}