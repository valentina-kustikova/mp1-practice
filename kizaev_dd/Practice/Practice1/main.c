#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	double p_dvp = 0.0, p_dsp = 0.0, p_wood = 0.0; //density
	printf("enter density in kg/(m^3) \n");
	printf("\n");

	do
	{
		printf("enter DVP density: \n");
		scanf("%lf", &p_dvp);
	} while (p_dvp <= 0.0);

	do
	{
		printf("enter DSP density: \n");
		scanf("%lf", &p_dsp);
	} while (p_dsp <= 0.0);

	do
	{
		printf("enter wood density: \n");
		scanf("%lf", &p_wood);
	} while (p_wood <= 0.0);

	double h = 0.0, w = 0.0; // back part
	do
	{
		printf("enter height (1.80 to 2.20) \n");
		scanf("%lf", &h);
	} while ((h < 1.80) || (h > 2.20));

	do
	{
		printf("enter width (0.80 to 1.20) \n");
		scanf("%lf", &w);
	} while ((w < 0.80) || (w > 1.20));

	double d = 0.0; // side parts
	do
	{
		printf("enter depth (0.50 to 0.90) \n");
		scanf("%lf", &d);
	} while ((d < 0.50) || (d > 0.90));

	double roof_t = 0.015;
	int num = (int)((h - 2 * roof_t) / 0.40); // number of shelves

	/* for tests
	printf ("number of shelves: %lf \n", num);
	*/

	double back_t = 0.005, side_t = 0.015, door_t = 0.01;
	//no info about thickness of shelves, let it be 1 cm
	double shelf_t = 0.01;

	double mass =
		p_dvp * (h * w * back_t) + //back part
		p_dsp * (2 * ((h * d * side_t) + (w * d * roof_t)) + //sides, roof & bottom
			num * (w * d * shelf_t)) +  // shelves
		p_wood * (h * w * door_t); //doors

	printf("weight in kg: %.2lf \n", mass);
	system("pause");
}