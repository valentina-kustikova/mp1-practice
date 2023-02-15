#include <stdio.h>

int main() {

	float h, d, w; // height, deep, width of wardrobe
	float density_of_tree = 900;
	float density_of_dsp = 800;
	float density_of_dvf = 800;
	float mass_of_backdoor;
	float mass_of_side_walls;
	float mass_of_overhead_lids;
	float mass_of_frontdoors;
	float mass_of_shelves;
	float control_mass;
	int counting_shelves;
	

	// input of data
	printf("enter the heigth of the wardrobe in cm\n");
	scanf_s("%f", &h);
	printf("enter the deep of the wardrobe in cm\n");
	scanf_s("%f", &d);
	printf("enter the width of the wardrobe in cm\n");
	scanf_s("%f", &w);

	// validation of entered data
	if ((180 > h) || (h > 220)) {
		printf("input correct data");
		return 0;
	}

	if ((50 > d) || (d > 90)) {
		printf("input correct data");
		return 0;
	}

	if ((80 > w) || (w > 120)) {
		printf("input correct data");
		return 0;
	}

	// converting data 
	h = h / 100;
	w = w / 100;
	d = d / 100;

	counting_shelves = (h / 0.4) - 1;	 // counting shelves

	// calculation
	mass_of_backdoor = (0.005 * h * w) * density_of_dvf;
	mass_of_side_walls = 2 * (0.015 * d * (h-0.03)) * density_of_dsp;
	mass_of_overhead_lids = 2 * (0.015 * d * w) * density_of_tree;
	mass_of_frontdoors = (0.01 * h * w) * density_of_tree;
	mass_of_shelves = counting_shelves * (0.0015 * d * (w-0.03)) * density_of_dsp;


	control_mass = mass_of_backdoor + mass_of_overhead_lids + mass_of_side_walls + mass_of_frontdoors + mass_of_shelves;

	printf("mass of the cupboard\n");
	printf("%f", control_mass);


	return 0;
}
