#include <stdio.h>

int main() {

	const double WOOD_DENSITY = 0.00055; //kg*cm^3
	const double DSP_DENSITY = 0.00065;
	const double DVP_DENSITY = 0.0008;

	double h, w, d;
	double shelves_mass, back_wall_mass, door_mass, upper_and_lower_cover_mass, sidewalls_mass, wardrobe_mass;
	int shelf_count = 4; //The minimum possible number of shelves (follows from the minimum height of the wardrobe)

	printf("Enter the height, width and depth of the wardrobe in centimeters... \n");
	scanf("%lf%lf%lf", &h, &w, &d);

	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) {
		printf("The entered data is invalid!");
		return 1;
	}

	if (h > 200)
		shelf_count = 5; //The maximum possible number of shelves (follows from the maximum height of the wardrobe)

	back_wall_mass = DVP_DENSITY * (h * w * 0.5);
	door_mass = WOOD_DENSITY * (h * w * 1);
	sidewalls_mass = 2 * DSP_DENSITY * h * d * 1.5; //Subtract the thickness of the overhead doors and the back wall
	upper_and_lower_cover_mass = 2 * DSP_DENSITY * d * (w - 3) * 1.5;
	shelves_mass = DSP_DENSITY * shelf_count * (w - 3) * d * 1.5;

	wardrobe_mass = back_wall_mass + door_mass + sidewalls_mass + upper_and_lower_cover_mass + shelves_mass;

	printf("Wardrobe mass is: %lf", wardrobe_mass);

	return 0;
}