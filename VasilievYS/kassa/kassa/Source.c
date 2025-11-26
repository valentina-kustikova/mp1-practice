#include <stdio.h>
#include <string.h>
#include <locale.h>
#define N 4
struct tovar
{
	char kod[5];
	char name[15];
	float price;
	int sale;
};
struct tovar bd[N] = { {"1000", "Вода 0,5л", 35.f, 10},
		{ "1100", "Шоколад", 120.f, 15 },
		{ "1110", "Молоко", 90.f, 25 },
		{ "1111", "Хлеб", 50.f, 5 } };
int cnt_t[N] = { 0 };
struct tovar scanned;
int scan()
{
	int i, idx = -1;
	char vvod[5];
	printf("Введите код: ");
	scanf_s("%s", vvod, (unsigned)sizeof(vvod));
	for (i = 0; i < N; i++)
	{
		if (strcmp(vvod, bd[i].kod) == 0)
		{
			scanned = bd[i];
			idx = i;
		}
	}
	if (idx == -1)
	{
		printf("\nТакого товара нет.");
	}
	return idx;
}
void print(struct tovar n_t)
{
	printf("\nКод: %s  Название: %s  Цена:  %.2f  Скидка: %d%% ",
		(n_t.kod), (n_t.name), (n_t.price), (n_t.sale));
}
void add(struct tovar n_t)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (strcmp(n_t.kod, bd[i].kod) == 0)
		{
			cnt_t[i]++;
			break;
		}
	}
}
void make_bill()
{
	int i = 0;
	float price = 0.f;
	for (i = 0; i < N; i++)
	{
		if (cnt_t[i] != 0)
		{
			price += bd[i].price * (1 - 0.01 * bd[i].sale);
			printf("\nНазвание: %s  Цена: %.2f  Скидка: %d%%  Цена со скидкой: %.2f  Количество: %d\n",
				(bd[i].name), (bd[i].price), (bd[i].sale), bd[i].price * (1 - 0.01 * bd[i].sale), cnt_t[i]);
		}

	}
	printf("\nЦена: %.2f\n", price);
}
int main()
{
	int ans, ans2, i, res = 0, idx=0;
	setlocale(LC_ALL, "Russian");
  do////
	{
		if (res == 0){ printf("\nСканировать товар - 1, Завершить - 0: "); }
		else { printf("\nСканировать товар - 1, Сформировать чек - 2, Завершить - 0: "); }
		scanf_s("%d", &ans);
		switch (ans)
		{
		case 1:
			do
			{
				idx = scan();
			} while ( idx == -1);
			do
			{
				printf("\nВывести информацию о товаре - 1, добавить товар в чек - 2, Назад - 0: ");
				scanf_s("%d", &ans2);

				switch (ans2)
				{
				case 1:
					print(scanned);

				case 2:
					add(scanned);
					res++;
				}
			} while (ans2 != 0 && ans2 != 2);
		case 2:
			make_bill();
		}
	} while (ans != 0);
	if (res > 0)
	{
		printf("\nИтоговый чек: ");
		make_bill();
	}
	return 0;
}