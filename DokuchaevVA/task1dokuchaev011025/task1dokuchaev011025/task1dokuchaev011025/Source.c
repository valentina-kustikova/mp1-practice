#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Rus");

	float h, w, d, massa1, massa2, massa3, massa4, massa5, massa, n;
	int der = 700, dsp = 800, dvp = 735, tder = 10, tdsp = 15, tdvp = 5;

	do
	{
		printf_s("Введите значение высота шкафа H (в см, 180-220)\n");
		scanf_s("%f", &h);
	} while ((h < 180) || (h > 220));
	h = h * 10;

	do
	{
		printf_s("Введите значение ширины шкафа W (в см, 80-120)\n");
		scanf_s("%f", &w);
	} while ((w < 80) || (w > 120));
	w = w * 10;	

	do
	{
		printf_s("Введите значение глубины шкафа D (в см, 50-90)\n");
		scanf_s("%f", &d);
	} while ((w < 80) || (d > 90));
	d = d * 10;

	n = ((h / 10)/40)-1;
	n=(int)n;

	massa1 = (h+30) * tdvp * w * dvp / 1000000000.0; //масса задней стенки
	massa2 = h * tdsp * d * dsp / 1000000000.0 *2;//боковые стенки
	massa3 = w * d * dsp * tdsp / 1000000000.0 * 2;// дно и потолок
	massa4 = w * (h+30) * tder * der / 1000000000.0;// двери
	massa5 = (w - 2*tdsp) * d * dsp * tdsp * n / 1000000000.0;
	massa = massa1 + massa2 + massa3 + massa4 + massa5;
	printf("Общая масса = %.1f кг\n\n\n", massa);
	printf("Масска задней стенки = %.1f кг\n", massa1);
	printf("Масса боковых стенок = %.1f кг\n", massa2);
	printf("Масса дна и потолка = %.1f кг\n", massa3);
	printf("Масса дверей = %.1f кг\n", massa4);
	printf("Масса полок и их количество= %.1f кг, %.0f\n", massa5, n);
	return 0;
}