//табличные значения для ДСП: 650 кг/м^3, ДВП: 800 кг/м^3, дерева 550 кг/м^3//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double h, w, d, back_wall, side_walls, lids, shelves, doors, a;
	int i = 0;
	printf("Enter cabinet dimensions in centimeters: height, width, depth: "); //запрос габаритов
	scanf("%lf %lf %lf", &h, &w, &d); //ввод габаритов
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) //проверка
	{
		printf("Data entered incorrectly");
		return 1;
	}
	a = h;
	h = h * 0.01;
	w = w * 0.01;
	d = d * 0.01;
	back_wall = h * w * 0.005 * 800;
	side_walls = h * d * 0.015 * 650 * 2;
	lids = (w - 0.03) * d * 0.015 * 650 * 2;
	while (a >= 40) //количество полок
	{
		a = a - 40;
		i++;
	}
	shelves = d * (w - 0.03) * 0.015 * 650 * i;
	doors = h * w * 0.01 * 550;
	printf("Total cabinet weight is %lf", back_wall + side_walls + lids + shelves + doors, "kg\n");
	return 0;
}