#include <stdio.h>
#include <locale.h>
#include <math.h>
void main ()
{
	float w, d, h, m1, m2, m3, m4, m5, m, n;
    float tdvp, tdsp, twood, dvp, dsp, wood; //Толщина
	

	dvp=820;
	dsp=650;
	wood=700;
	tdvp=0.5;
	tdsp=1.5;
	twood=1;
	setlocale (LC_CTYPE,"rus");
	printf("Высота шкафа (от 180 до 220)");
	scanf("%f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Введена неверная высота");
		return;
	}
	printf("Ширина шкафа (от 80 до 120)");
	scanf("%f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Введена неверная ширина");
	    return;
	}
	printf("Глубина шкафа (от 50 до 90)");
	scanf("%f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Введена неверная глубина");
		return;
	}

	//Количество полок
	n=(h/40);
	//Расчет массы
	m1 = (h * w * tdvp * dvp) / 1000000;     //Задняя стенка     
	m2 = (2 * h * d * tdsp * dsp) / 1000000; //Боковины   
	m3 = (2 * w * d * tdsp * dsp) / 1000000; //Верхняя и нижняя крышки   
	m4 = (h * w * twood * wood) / 1000000;   //Двери
	m5 = (n * (d * w * tdsp) / 1000000);     //Полки
	//Общая масса
    printf("Масса шкафа (кг)");
	scanf("%f", &m);
	m = m1 + m2 + m3 + m4 + m5;
	return;
}

