#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	float h, w, d;
	int count;
	double shelves, mass_backdoor, mass_sidewalk, mass_roof, mass_door, mass_shelves, mass;
	float density_wood = 640;
	float density_DSP = 800;
	float density_DVP = 750;

	printf("Enter cabinet height h");
	scanf(" %f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Incorrect data, valid values 180 cm < h < 220 cm");
		return 0;
	}
	printf("Enter cabinet width w");
	scanf(" %f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Incorrect data, valid values 80 cm < w < 120 cm");
		return 0;
	}
	printf("Enter cabinet depth d");
	scanf(" %f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Incorrect data, valid values 50 cm < d < 90 cm");
		return 0;
	}
	h = h / 100;
	w = w / 100;
	d = d / 100;
	shelves = (h / 0.415) - 1.015;
	count = (int)shelves;
	mass_backdoor = h * w * 0.005 * density_DVP;
	mass_sidewalk = 2 * h * d * 0.015 * density_DSP;
	mass_roof = 2 * (w - 0.03) * d * 0.015 * density_DSP;
	mass_door = w * h * 0.01 * density_wood;
	mass_shelves = count * d * (w - 0.03) * density_DSP * 0.015;
	mass = mass_backdoor + mass_sidewalk + mass_roof + mass_door + mass_shelves;
	printf("Cabinet weight = %f kg\n", mass);
	return 0;
}