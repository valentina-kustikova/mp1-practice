
#include <stdio.h>
int main()
{
	double h, w, d, back_wall, side_wall, upper_wall, shelves, doors, k;
	double density_wood = 550;
	double density_DSP = 650;
	double density_DVP = 800;
	int i = 0;
	printf("Enter wardrobe dimensions: height, width, depth: \n"); 
	scanf_s("%lf %lf %lf", &h, &w, &d); 
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) 
	{
		printf("something went wrong...\n");
		return 1;
	}
	k = h-3;
	h *= 0.01;
	w *= 0.01;
	d *= 0.01;
	back_wall = h * w * 0.005 * density_DVP;
	side_wall = h * d * 0.015 * 2 * density_DSP;
	upper_wall = (w-0.03) * d * 0.015 * 2 * density_DSP;
	doors = h * w * 0.01 * density_wood;
	while (k >= 41.5)
	{
		k -= 41.5;
		i++;
	}
	shelves = d * (w-0.03) * 0.015 * i * density_DSP;
	printf("overall wardrobe weight is %lf", back_wall + side_wall + upper_wall + shelves + doors);
	return 0;
}
