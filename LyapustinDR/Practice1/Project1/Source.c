#include <stdio.h>

int main() {
	int shelves;
	float w, h, d, mass;
	float wood = 1.54f, dsp = 1.0f, dvp = 0.95f;
	printf("Enter w, h, d ");
	scanf_s("%f %f %f", &w, &h, &d);
	if (h < 180 || h > 220) {
		printf("h out of [180-220]");
		return 1;
	}
	if (w < 80 || w > 120) {
		printf("w out of [80-120]");
		return 1;
	}
	if (d < 50 || d > 90) {
		printf("d out of [50-90]");
		return 1;
	}
	shelves = (int)h / 40;
	mass = (dvp * h * w * 0.5f) + (dsp * 2 * h * d * 1.5f) + (dsp * 2 * w * d * 1.5f) + (wood * h * w) + (dsp * shelves * d * w * 1.5);
	printf("%f", mass);

	return 0;
}
