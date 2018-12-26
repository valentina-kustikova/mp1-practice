#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	float Xa = 0, Xb = 0, Ya = 0, Yb = 0, Ra = 0, Rb = 0, X, Y, A;
	setlocale(LC_ALL, "Rus");
	printf("input 1: ");
	scanf("%d %d %d", &Xa, &Ya, &Ra);
	printf("\n");
	printf("input 2: ");
	scanf("%d %d %d", &Xb, &Yb, &Rb);
	if (Ra <= 0 || Rb <= 0) /*Защита от дурака*/
	{
		printf("Неверны ввод");
		return;
	}
	if ((Xa == Xb) && (Ya == Yb)) /*Есди центр одинаковый*/
	{
		if (Ra == Rb)
		{
			printf("Круги совподают");
			return;
		}
		if (Ra > Rb)
		{
			printf("Круг 2 внутри круга 1");
			return;
		}
		else
		{
			printf("Круг 1 внутри круга 2");
			return;
		}
	}
	X = fabs((Xa - Xb)*(Xa - Xb)); /*Вспомогательные расчёты*/
	Y = fabs((Ya - Ya)*(Ya - Ya));
	if ((X + Y) < (Ra + Rb)*(Ra + Rb)) /*Когда центр не в одной точке*/
	{
		printf("Круги переекаються в 2 точках");
		return;
	}
	else if ((X + Y) == (Ra + Rb)*(Ra + Rb))
	{
		printf("Круги пересекаються в 1 точке");
		return;
	}
	A = sqrt(X + Y);
	if (A < Ra)
	{
		if ((A + Rb) < Ra)
		{
			printf("Круг 2 находится внутри круга 1");
			return;
		}
		if ((A + Rb) == Ra)
		{
			printf("Круг 2 находится внутри круга 1 и имеет 1 точку касания");
			return;
		}
	}
	if (A < Rb)
	{
		if ((A + Ra) < Rb)
		{
			printf("Круг 1 находится внутри круга 2");
			return;
		}
		if ((A + Ra) < Rb)
		{
			printf("Круг 1 нахожится внутри круга 2 и имеет 1 точку касания");
			return;
		}
	}
}