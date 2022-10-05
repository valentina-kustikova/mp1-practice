#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{	
	setlocale(LC_ALL, "rus");
	float h, w, ;
	printf("Введите высоту шкафа h: ");
	scanf("%f", &h);
	if ((h > 180) && (h < 220))
	{
		printf("Корректные данные")
	}
}