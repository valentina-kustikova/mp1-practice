#include <stdio.h>
#include <locale.h>
#define t 0.015
#define pd 700  // kg/m3
#define pdsp 800
#define pdvp 735
int main() {
	double mass, h, w, d, m1, m2, m3, m4, m5; // copy;
	int k = 0, hi, wi, di, copy;
	setlocale(LC_ALL, "Rus");

	do {
		printf("Введите высоту, ширину и глубину шкафа через пробел\n");
		//scanf_s("%f %f %f", &h, &w, &d);
		//scanf_s("%f", &h);
		//scanf_s("%f", &w);
		//scanf_s("%f", &d);
		scanf_s("%d %d %d", &hi, &wi, &di);
		//if ((h >= 180) && (h <= 220) && (w >= 80) && (w <= 120) && (d >= 50) && (d <= 90))
		//	break;
		//if (h >= 180 && h <= 220 && w >= 80 && w <= 120 && d >= 50 && d <= 90) break;
		if ((hi < 180) || (hi > 220) || (wi < 80) || (wi > 120) || (di < 50) || (di > 90))
			printf("Данные некоректны");
	} //while (!((h >= 180) && (h <= 220) && (w >= 80) && (w <= 120) && (d >= 50) && (d <= 90)));
	while ((hi < 180) || (hi > 220) || (wi < 80) || (wi > 120) || (di < 50) || (di > 90));
	//h /= 100;
	//w /= 100;
	//d /= 100;
	//h = hi / 100;                                                     printf("h = %f m\n", h);       //m
	//w = wi / 100;                                                     printf("w = %f m\n", w);
	//d = di / 100;                                                     printf("d = %f m\n", d);
	h = hi;
	w = wi;
	d = di;
	h /= 100;                                                     printf("h = %f m\n", h);       //m
	w /= 100;                                                     printf("w = %f m\n", w);
	d /= 100;                                                     printf("d = %f m\n", d);
	m1 = h * w * pdvp * 0.005;                                        printf("m1 = %f kg\n", m1);    //Задняя стенка     ( m*m*m * (kg/m3) = kg)
	m2 = 2 * (h - 2 * t) * (d - 0.01) * t * pdsp;                     printf("m2 = %f kg\n", m2);    //Боковины
	m3 = 2 * w * d * t * pdsp;                                        printf("m3 = %f kg\n", m3);    //Крышки
	m4 = h * w * pd * 0.01;                                           printf("m4 = %f kg\n", m4);    //Дверцы
	//k = int((int(h * 1000)) / 415) - как реализовать без цикла?
	//copy = h * 1000;
	//while (copy >= 415) {  //0.415
	//	copy -= 400;      //0.4
	//	k++;
	//}
	//k--;
	//k += 2;
	k = (hi <= 202) ? 4 : 5;
	m5 = k * (w - t * 2) * (d - 0.01) * t * pdsp;                     printf("m5 = %f kg\n", m5);   //Полки
	printf("\nМасса вашего шкафа = %f\n", m1 + m2 + m3 + m4 + m5);
	printf("Полок в нем %d\n", k);
	return 0;
}