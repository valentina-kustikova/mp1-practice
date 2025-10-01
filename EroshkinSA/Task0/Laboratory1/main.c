#include <stdio.h>

int main() {
	float h, w, d, dvp = 0.5f, dsp = 1.5f, tree = 1.0f, v1, v2, v3, v4, v5;
	// constant Rdvp Rdsp Rtree
	do {
		scanf_s("%f %f %f", &h, &w, &d);
	} while (h < 180 || h > 210 || w < 80 || w > 120 || d < 50 || d > 90);
	v1 = h * w * dvp;
	return 0;
}