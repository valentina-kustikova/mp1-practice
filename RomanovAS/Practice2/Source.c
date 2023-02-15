#include <stdio.h>
#include<time.h>
int main()
{
	int a;
	printf("Vvedite 1, esli hotite sami ugadivat chislo ili vvedite 0, esli hotite chtob computer ygadival chislo");
	do
	{
		scanf("%d", &a);
	} while ((a != 1) && (a != 0));
	if (a == 1)
	{
		int n, x, k = 0;
		srand((unsigned int)time(NULL));
		n = rand() % 1000;
		printf("vvedite pervuyu popitku");
		do
		{
			k++;
			scanf("%d", &x);
			if (x == n)
			{
				printf("vi otgadali");
				printf("kolichestvo popitok = %d", k);
				return 0;
			}
			if (x < n)
			{
				printf("bolshe");
			}
			if (x > n)
			{
				printf("menshe");
			}
		} while ((x >= 0) && (x <= 1000));
	}
	else
	{
		int x, y = 0, zmax = 1000, zmin = 0, o = 0;
		srand((unsigned int)time(NULL));
		printf("Mehshe = 0, Ravno = 1, Bolshe = 2  ");
		do
		{
			o++;
			x = zmin + rand() % (zmax - zmin + 1);
			printf("\n%d", x);
			scanf("%d", &y);
			switch (y)
			{

			case 0:
			{
				zmax = x;
				break;
			}
			case 1:
			{
				printf("Zagannoe chislo = %d  ", x);
				printf("\nKolichestvo popitok = %d", o);
				return 0;
			}
			case 2:
			{
				zmin = x;
				break;
			}
			}
		} while (y != 1);
	}
}

