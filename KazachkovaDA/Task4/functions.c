#include "functions.h"
#include "global_names.h"

int scan(char* code)
{	//счетчик количества товара увеличивается сразу при добавлении
	int idx = -1;
	printf_s("Input code: ");
	gets_s(code, sizeof(code));
	idx = search(code);
	return (idx >= 0 ? 0 : 1);
}

int search(char code[])
{
	int idx;
	int i;
	for (i = 0; i < sizedb; i++)
	{
		if (strcmp(code, given_codes[i]) == 0)
		{
			return i;

		}
	}
	return -1;
}

void add(char code[])
{
	int idx = search(code);
	cnt[idx] += 1;
}

void print_receipt()
{
	float total = 0;
	int i;
	for (i = 0; i < sizedb; i++) {
		if (cnt[i] > 0)
		{
			printf_s("Code: %s, name: %s, price: %d, count: %d, discount: %.2f = %.2f\n",
				given_codes[i], name[i], price[i], cnt[i],
				cnt[i] * price[i] * discount[i],
				cnt[i] * (price[i] - price[i] * discount[i]));
			total += cnt[i] * (price[i] - price[i] * discount[i]);
		}
	}
	printf_s("TOTAL = %.2f", total);
}