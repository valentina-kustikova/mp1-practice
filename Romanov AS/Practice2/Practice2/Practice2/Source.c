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
		int n, x, k=0;
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
				printf("kolichestvo popitok =%d", k);
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
		}
		while ((x >= 0) && (x <= 1000));
	}
	else
	{
		int x, y=0, zmax=-1, zmin=-1, o=1, v=1, k=0;
		srand((unsigned int)time(NULL));
		x = rand() % 1000;
		printf("Mehshe = 0, Ravno = 1, Bolshe = 2  ");
		printf("Pervaya popitka %d", x);
		scanf("%d", &y);
		switch (y) {
			case 0:
				zmax = x;
				break;
			case 1:
				printf("Zagannoe chislo = %d  ", x);
				printf("kolichestvo popitok = 1");
				return 0;
				break;
			case 2:
				zmin = x;
				break;
		}
		if (y != 1)
		{
			if (zmax > 0)
			{
				zmin = zmax;
				do
				{
					o++;
					zmin = zmin / 2;
					printf("%d", zmin);
					scanf("%d", &y);
					if (y == 1)
					{
						printf("Zagannoe chislo = %d  ", zmin);
						printf("kolichestvo popitok = %d", o);
						return 0;
					}
				} while (y != 2);
			}
			if (zmin > 0)
			{
				zmax = zmin;
				do
				{
					v++;
					zmax = zmax * 2;
					printf("%d", zmax);
					scanf("%d", &y);
					if (y == 1)
					{
						printf("Zagannoe chislo = %d  ", zmax);
						printf("kolichestvo popitok = %d", v);
						return 0;
					}
				} while (y != 0);
			}
			k = o + v;
			do
			{
				k++;
				x = (zmax + zmin) / 2;
				printf("%d", x);
				scanf("%d", &y);
				if (y == 0)
				{
					zmax = x;
				}
				if (y == 2)
				{
					zmin = x;
				}
			} while (y != 1);
		}
		k = k - 1;
		printf("Zagadonnoe chislo - %d  ", x);
		printf("kolichestvo popitok = %d", k);
		system("pause");
		return 0;
	}
}