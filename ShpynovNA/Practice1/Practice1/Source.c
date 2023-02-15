//табличные значения для ДСП: 650 кг/м^3, ДВП: 800 кг/м^3, дерева 550 кг/м^3
//входные данные 180 100 80
//выходные данные 90.576000
#include <stdio.h>
int main()
{
	double h, w, d, back_wall, side_wall, upper_n_lower_wall, shelves, doors, a;
	int i = 0;
	printf("enter wardrobe dimensions in santimeters: height, width, depth: "); 
	do {
		scanf("%lf %lf %lf", &h, &w, &d); //habarytes
	} while ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)); //checking 
	a = h - 3;
	h *= 0.01;
	w *= 0.01;
	d *= 0.01;
	back_wall = h * w * 0.005 * 800;
	side_wall = (h-0.03) * d * 0.015 * 650 * 2;
	upper_n_lower_wall = w * d * 0.015 * 650 * 2;
	while (a >= 40) //shelves amount
	{
		a -= 40;
		i++;
	}
	shelves = d * (w - 0.03) * 0.015 * 650 * i;
	doors = h * w * 0.01 * 550;
	//each part's weight
	/*
	printf("back wall weight: %lf\n", back_wall);
	printf("side wall weight: %lf\n", side_wall);
	printf("upper and lower walls weight: %lf\n", upper_n_lower_wall);
	printf("shelves weight: %lf\n", shelves);
	printf("doors weight: %lf\n", doors);
	*/
	printf("overall wardrobe weight is %lf", back_wall + side_wall + upper_n_lower_wall + shelves + doors, "kg\n");
	return 0;
}