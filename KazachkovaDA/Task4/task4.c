#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define N 1000
#define sizedb 5
const int code[sizedb] = { 1001, 1002, 1003, 1004, 1005 };
const char* name[5] = { "apples", "milk", "bananas", "bread", "juice" };
const int price[5] = {100, 90, 75, 30, 300 };
const int discount[5] = {15, 10, 25, 35, 5};


int main()
{
	int codes[N]; //все считанные штрихкоды
	int amount;//количество считанных штрихкодов
	amount = scan(codes);//считали штрихкоды
	int goods_amount[N];//количество штук для штрихкода
	int unic_codes[N];//массив уникальных штрихкодов
	int num_unic_codes = amount_calc(codes, unic_codes, goods_amount, amount);

	for (int i = 0; i <= num_unic_codes; i++) {
		printf_s("ID: %d  Amount: %d\n", unic_codes[i], goods_amount[i]);
	}

	create_receipt(unic_codes, goods_amount, num_unic_codes); //вызываем создание чека

	return 0;
}

int scan(int *codes)
{
	int i = 0;
	// j - счетчик принятых штрихкодов
	int j = 0;
	int flag = 0;
	int value = 0;
	do
	{
		//scanf_s("%d", &(codes[i]));
		scanf_s("%d", &value);
		//printf_s("Value: %d\n", value);
		for (int i = 0; i < sizedb; i++)
		{
			//printf_s("code[i] = %d", code[i]);
			if (code[i] == value)
			{
				codes[j] = value;
				flag = 1;
				j++;
			}
		}
		if (flag == 0) {
			printf_s(" \nPoprobui esche raz\n");
		}
		
	} while (value > 0);
	return j;

}

int amount_calc(int *codes, int *unic_codes, int *goods_amount, int amount)
{
	int k = 0;
	for (int i = 0; i <= amount; i++) 
	{
		if (codes[i] == 0)
		{
			continue; //берем следующий код
		}
		int flag = 0;
		goods_amount[k] = 1; //считаем количество встретившегося штрихкода
		if ((i == amount - 1) && (codes[i] > 0))
		{
			unic_codes[k] = codes[i];
			break;
		}
		for (int j = i+1; j < amount; j++)
		{
			if (codes[i] == codes[j] && codes[i] != 0)
			{
				goods_amount[k] += 1;//считаем количество встретившегося штрихкода
				unic_codes[k] = codes[i];//записываем штрихкод в новый массив уникальных штрихкодов
				codes[j] = 0;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			unic_codes[k] = codes[i];

		}
		k++;
	}
	return k;//индекс последнего уникального штрихкода (количество уникальных - 1)
}

create_receipt(int *unic_codes, int *goods_amount, int num_unic_codes)
{
	float total = 0; //полная сумма
	for (int i = 0; i <= num_unic_codes; i++)
	{
		//ищем штрихкод в базе данных
		for (int j = 0; j < 5; j++)
		{
			//printf_s("%d ", code[j]);
			if (unic_codes[i] == code[j])
			{
				float total0 = goods_amount[i]*(price[j] * (1 - (discount[j] * 0.01)));
				printf_s("code: %d name: %s price: %d amount: %d discount: %d = %.2f\n", unic_codes[i], name[j], price[j], goods_amount[i], discount[j], total0);
				total += total0;
			}
		}
	}
	printf_s("TOTAL:	%.2f", total);
}

