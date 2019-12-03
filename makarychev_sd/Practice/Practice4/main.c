#include <stdio.h>
#include <locale.h>

int vvod_sravn(int e, int t)
{
	int i, l, k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;
	int q1[4] = { 0, 0, 1, 0 };
	int q2[4] = { 0, 2, 3, 4 };
	int q3[4] = { 9, 3, 4, 3 };
	int q4[4] = { 7, 4, 0, 2 };
	int q5[4] = { 1, 1, 5, 5 };
	int a[5];
	printf("\n введите 0 для печати чека или введите любую другую цифру для дальнейшего сканирования \n");
	printf("или введите любую другую цифру дл дальнейшего сканирования \n");
	scanf("%d", &l);
	if (l == 0)
		return t = 0;
	printf("\n\n введите штрих-код \n");
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &(a[i]));
	}
	for (i = 0; i < 4; i++)
	{

		if (a[i] == q1[i])
			k1++;
		if (a[i] == q2[i])
			k2++;
		if (a[i] == q3[i])
			k3++;
		if (a[i] == q4[i])
			k4++;
		if (a[i] == q5[i])
			k5++;
	}
	if (k1 == 4)
		return e = 1;
	else if (k2 == 4)
		return e = 2;
	else if (k3 == 4)
		return e = 3;
	else if (k4 == 4)
		return e = 4;
	else if (k5 == 4)
		return e = 5;
	else
		printf("товара с таким штрих-кодом не существует \n");
}
int vivod_information(int e)
{
	printf("\n\t информация о товаре: \n");
	switch (e)
	{
	case 1:
		printf("стиральный порошок Дося - 136 рублей \n");
		printf("штрих-код товара: 0010 \n");
		printf("действующая скидка на товар - 10 процентов \n");
		return 1;
		break;
	case 2:
		printf("сухарики 3 корочки - 15 рублей \n");
		printf("штрих-код товара: 0234 \n");
		return 2;
		break;
	case 3:
		printf("соль - 50 рублей \n");
		printf("штрих-код товара: 9343 \n");
		printf("действующая скидка на товар - 7 процентов \n");
		return 3;
		break;
	case 4:
		printf("лимонад - 120 рублей \n");
		printf("штрих-код товара: 7402 \n");
		return 4;
		break;
	case 5:
		printf("пельмени - 100 рублей \n");
		printf("штрих-код товара: 1155 \n");
		printf("действующая скидка на товар - 11 процентов \n");
		return 5;
		break;
	}
}
void chek(int k1, int k2, int k3, int k4, int k5)
{
	int x = 0;
	printf("\n\n\t чек на покупку \n");
	if (k1 != 0)
	{
		printf("стиральный порошок Дося - 136 рублей \n");
		printf("количество %d \n", k1);
	}
	if (k2 != 0)
	{
		printf("сухарики 3 корочки - 15 рублей \n");
		printf("количество %d \n", k2);
	}
	if (k3 != 0)
	{
		printf("соль - 50 рублей \n");
		printf("количество %d \n", k3);
	}
	if (k4 != 0)
	{
		printf("лимонад - 120 рублей \n");
		printf("количество %d \n", k4);
	}
	if (k5 != 0)
	{
		printf("пельмени - 100 рублей \n");
		printf("количество %d \n", k5);
	}
	x = 136 * k1 + 15 * k2 + 50 * k3 + 120 * k4 + 100 * k5;
	printf("итоговая сумма: %d \n", x);
}
void main()
{
	int t = 1, b = 1, c, e = 0, k = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0;
	setlocale(LC_ALL, "Rus");
	while (b != 0)
	{
		b = vvod_sravn(e, t);
		k = vivod_information(b);
		if (k == 1)
			k1++;
		else if (k == 2)
			k2++;
		else if (k == 3)
			k3++;
		else if (k == 4)
			k4++;
		else if (k == 5)
			k5++;
	}
	chek(k1, k2, k3, k4, k5);
}