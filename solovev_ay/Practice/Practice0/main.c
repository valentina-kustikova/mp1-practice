#include <stdio.h>
#include <math.h>
#include <locale.h>
    	void main()
    	{
	float x, x1, y, y1, r, r1, s = 0.0f;
	setlocale(LC_ALL, "Russian");
 	printf("Введите координаты вида (х:у) первой окружности.\n");
	printf("Введите х: ");
	scanf("%f",&x);
	printf("Введите y: ");
	scanf("%f",&y);
	printf("Введите радиус первой окружности: ");
	scanf("%f", &r);
	if (r <= 0)
	{
	printf("Вы ввели неверные данные!\nТакого радиуса не может быть! \n");
	return;
	}
	printf("Координаты первой окружности (%.4f:%.4f) радиус=%.4f\n", x, y, r);
	printf("Введите координаты вида (х:у) второй  окружности.\n");
	printf("Введите х: ");
	scanf("%f",&x1);
	printf("Введите y: ");
	scanf("%f",&y1);
	printf("Введите радиус второй окружности: ");
	scanf("%f", &r1);
	if (r1 <= 0)
	{
	printf("Вы ввели неверные данные!\nТакого радиуса не может быть!\n");
	return;
	}
	printf("Координаты второй окружности (%.4f:%.4f) радиус=%.4f\n", x1, y1, r1);
	s=sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	if(s > (r + r1)) 
	{
	printf("Окружности не пересекаются!\n");
	return;
	}
	if((x == x1) && (y == y1) && (r == r1))
	{
	printf("Окружности совпадают!\n");
	return;
	}
	if (s == (r + r1))
	{
	printf("Окружности касаются внешним образом один раз!\n");
	return;
	}
	if ((s + r == r1) || (s + r1 == r))
	{
	printf("Окружности касаются внутренним образом!\n");
	return;
	}
	if (((s + r) < r1)||((s + r1) < r))
	{
	printf("Одна окружность находится внутри другой!\n");
	return;
	}
 	printf("Окружности пересекаются два раза!\n");
	return;
    } 
