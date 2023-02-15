#include <stdio.h>
#define Chipboard 0.0008f
#define Fiberboard 0.0008f
#define Wood 0.0009f
#define _CRT_SECURE_NO_WARNINGS


int main()
{
	float h, w, d, weight, weight_back, weight_side, weight_cover, weight_door, weight_shelf;

	//Input data
	printf("Input a height of the wardrope (180 <= h <= 220) : ");
	scanf("%f", &h);
	if (h > 220 || h < 180) {
		printf("You inputed uncorrect height ");
		return 0;
	}


	printf("Input a width of the wardrope(80 <= w <= 120) : ");
	scanf("%f", &w);
	if (w < 80 || w > 120) {
		printf("You inputed uncorrect height");
		return 0;
	}

	printf("Input a deep of the wardrope (50 <= d <= 90) : ");
	scanf("%f", &d);
	if (d > 90 || d < 50) {
		printf("You inputed uncorrect deep");
		return 0;
	}


	//Weight of the back wall
	weight_back = 0.5 * w * h * Fiberboard;

	//Weigh of the side walls
	weight_side = 2 * h * d * 1.5 * Chipboard;

	//Weight of the overhead cover
	weight_cover = 2 * (w-3) * d * 1.5 * Chipboard;

	//Weight of the doors
	weight_door = h * w * Wood;

	//Weight of the shelfs
	int n;
	n = h / 40;
	weight_shelf = (n - 1) * 1.5 * (w - 3) * d * Chipboard;


	weight = weight_back + weight_cover + weight_door + weight_shelf + weight_side;
	printf("The weight of the  wardrobe is (kg) :  ");
	printf("%.2f", weight);


	return 0;

}