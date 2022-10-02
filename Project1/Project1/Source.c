#define _CRT_NO_WORNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {

	float x1, y1, radius1; // данные первой окружности 
	float  x2, y2, radius2; // данные второй окружности 
	float length_between_centers; // расстояние между центрами окружности
	float sum_of_radiuses; // сумма радиусов
	float larger_radius; // больший радиус

	setlocale(LC_ALL, "");


	// ввод данных первой окружности
	printf("введите координаты центра первой окружности по оси Ох\n");
	scanf_s("%f", &x1);
	printf("введите координаты центра первой окружности по оси Оy\n");
	scanf_s("%f", &y1);
	printf("введите длину радиуса первой окружности\n");
	scanf_s("%f", &radius1);
	

	// ввод данных второй окружности
	printf("введите координаты центра второй окружности по оси Ох\n");
	scanf_s("%f", &x2);
	printf("введите координаты центра второй окружности по оси Оy\n");
	scanf_s("%f", &y2);
	printf("введите длину радиуса второй окружности\n");
	scanf_s("%f", &radius2);




	length_between_centers = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //  расстояние между центрами окружности

	sum_of_radiuses = radius1 + radius2; // сумма радиусов


	// определение большего радиуса
	if (radius1 > radius2)
		larger_radius = radius1;
	else 
		larger_radius = radius2;
	


	if (length_between_centers == sum_of_radiuses) {
		printf("окружности касаются друг друга");
	}
	
	if (length_between_centers > (sum_of_radiuses)) {
		printf("окружности не касаются друг друга");
	}

	if ((length_between_centers < sum_of_radiuses) && (larger_radius < length_between_centers)) {
		printf("окружности пересекаются");
	}

	if ((length_between_centers < sum_of_radiuses) && (larger_radius > length_between_centers)) {
		printf("окружность внутри другой");
	}

	if ((length_between_centers < sum_of_radiuses) && (sum_of_radiuses == larger_radius)) {
		printf("окружность внутри другой и касается ее");
	}

	if ((radius1 == radius2) && (x1 == x2) && (y1 == y2)) {
		printf("окружности совпадают");
	}

	return 0;
}