#include <stdio.h>

int main()
{
	const float dens_dvp = 0.0008f, dens_dsp = 0.00065f, dens_derevo = 0.00055f;
	float h, w, d;
	float size_backwall, size_sidewalls, size_updownwalls, size_doors, size_shelves, total_weight;
	short shelves_count;

	// Getting data
	printf("Insert h (180-220 cm), w (80-120 cm), d (50-90 cm) \n");
	scanf("%f%f%f", &h, &w, &d);
	if (h > 220 || h < 180 || w > 120 || w < 80 || d > 90 || d < 50)
	{
		printf("Invalid metrics");
		return 1;
	}

	// Finding number of shelves
	shelves_count = (short) (h / (40 + 1.5f));

	// Finding sizes
	size_backwall = h * w * 0.5f;
	size_sidewalls = 2 * h * d * 1.5f;
	size_updownwalls = 2 * (w - 3) * d * 1.5f;
	size_doors = h * w;
	size_shelves = shelves_count * (w - 3) * d * 1.5f;

	// Total weight
	total_weight = dens_dsp * (size_sidewalls + size_updownwalls + size_shelves)
		         + dens_dvp * size_backwall
		         + dens_derevo * size_doors;

	printf("Closet's total weight: %f kg", total_weight);
	return 0;
}