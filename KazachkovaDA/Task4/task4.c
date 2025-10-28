#include <stdio.h>
#include <locale.h>
#define N 10000
int main()
{
	setlocale(LC_ALL, "Rus");
	int code[N] = { 0 }, name[N] = { 0 }, price[N] = { 0 }, discount[N] = { 0 }, c, p, d, i, k;
	char str[100];
	char* n;
	printf_s("¬ведите количество товаров:");
	scanf_s("%d", &k);
	for (i = 0; i < k; i++)
	{
		printf_s("¬ведите штрих-код:\n");
		scanf_s("%d", &c);
		code[c] = c;

		printf_s("¬ведите наименование товара:\n");
		n = gets(str);
		name[c] = n;
		
		printf_s("¬ведите цену за товар:\n");
		scanf_s("%d", &p);
		price[c] = p;

		printf_s("¬ведите  cкидку на товар:\n");
		scanf_s("%d", &d);
		code[c] = d;
	}
	return 0;
}