#include <stdio.h>

int main() {
	float h, d, w;
	float dvp = 0.5, dsp = 1.5;

	printf("Enter the height, width and depth of the cabinet ");
	scanf_s("%f %f %f", &h, &w, &d);

	if (h < 180 || h > 220 || d < 50 || d > 90 || w < 80 || w > 120) {
		printf("Incorrect data entered\n");
		printf("h in [180, 220], w in [80, 120], d in [50, 90]");
		return 0;
	}

	int k = h / 40;
	float m1 = k * d * (w - 2 * dsp) * dsp * 0.55;

	float m2 = h * w * dvp * 0.8;

	float m3 = 2 * h * d * dsp * 0.55;

	float m4 = 2 * (w - 2 * dsp) * d * dsp * 0.55;

	float m5 = w * h * 1.5;

	float m = (m1 + m2 + m3 + m4 + m5) / 1000;

	printf("%f", m);
	printf(" kg ");

	return 0;
}
