#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	int n;
	float m; //Масса
	float hz, wz; //Задняя стенка
	float db; //Боковина
	float dsp, dvp, wood, tdsp, tdvp, twood; //Плотности и толщина
	float Vz, Vd, Vb, Vtop, Vn; //Объемы

	dsp=650;
	dvp=820;
	wood=700;
	tdsp=1.5;
	tdvp=0.5;
	twood=1;
	setlocale (LC_CTYPE,"rus");
	printf("Высота шкафа (от 180см до 220см) =");
	scanf("%f", &hz);
	printf("Ширина шкафа (от 80см до 120см) =");
	scanf("%f", &wz);
	printf("Глубина боковины (от 50см до 90см) =");
	scanf("%f", &db);
	if ((hz<180)||(hz>220)||(db<50)||(db>90)||(wz<80)||(wz>120))
	{
		printf("Значение высоты (ширины, глубины) находится вне диапазона");
		return;
	}
	//Расчет количества и толщины полок
	n=(hz/40);
	//Расчет объемов
	Vz=(hz*wz*tdvp)/1000000;
	Vd=(hz*wz*twood)/1000000;
	Vb=(hz*db*tdsp)/1000000;
	Vtop=(wz*db*tdsp)/1000000;
	Vn=(n*(db*wz*tdsp)/1000000);
	//Расчет массы
	m=(dsp*(Vb+Vtop+Vn)+(dvp*Vz)+(wood*Vd));
	printf("Масса шкафа (кг) = %f ", m);
	return;
}