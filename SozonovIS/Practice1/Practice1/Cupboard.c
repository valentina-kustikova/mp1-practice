#include <stdio.h>
int main()
{
	double h, w, d, backwall, sidewall, lids, doors, shelves_height, shelves = 0, m;
	printf("Enter the back wall height h(sm.)=");
	scanf("%lf", &h);
	printf("Enter back wall width w(sm.)=");
	scanf("%lf", &w);
	printf("Enter sidewall depth d(sm.)=");
	scanf("%lf", &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
	{
		printf("Invalid data entered");
		return 1;
	}
	backwall = h * w * 0.5 * 0.8;
	sidewall = 2 * h * d * 1.5 * 0.65;
	lids = 2 * (w-3) * d * 1.5 * 0.65;
	doors = h * w * 0.55;
	shelves_height = 41.5;
	while (shelves_height < h)
	{
		shelves += d * (w - 3) * 1.5 * 0.65;
		shelves_height += 41.5;
	}
	printf("Total cabinet weight(kg.)=%lf", (backwall + sidewall + lids + doors + shelves) / 1000);
	return 0;
}
