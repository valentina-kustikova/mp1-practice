#include <stdio.h>

int main()
{
	const float density_dvp = 0.6, density_dsp = 0.65, density_wood = 0.5;
	float h, w, d;
	printf("Input height, width, depth:\n");
	scanf_s("%f%f%f", &h, &w, &d);
	while (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90)
	{
		printf("Incorrect values, try again:\n");
		scanf_s("%f%f%f", &h, &w, &d);
	}
	float weight_back = h * w * 0.5 * density_dvp,
		weight_side = h * d * 1.5 * density_dsp,
		weight_doors = h * w * 1.0 * density_wood,
		weight_top = w * d * 1.5 * density_dsp,
		weight_shelf = (w - 2 * 1.5) * (d - 0.5 - 1) * 1.5 * density_dsp;

	printf("The weight of the closet is %.2f kg", (weight_back + 2*weight_side + weight_doors + 2*weight_top + ((int)(h/40)-1)*weight_shelf)/1000.0);
	return 0;
}

/*
* 180 80 50 - 47.79
* 190 100 80 - 82.71
* 210 120 90 - 118.46
*/