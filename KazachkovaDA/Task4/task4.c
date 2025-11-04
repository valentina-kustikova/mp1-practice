#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define N 1000
#define sizedb 15
const int code[sizedb] = { 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015};
const char* name[15] = { "apples", "milk", "bananas", "bread", "juice", "ketchup", "mayonaise", "eggs", "cheese", "tomatoes", "sausages", "salad", "meat", "butter", "fish"};
const int price[15] = {100, 90, 75, 30, 300, 80, 75, 60, 140, 200, 300, 250, 400, 170, 270};
const int discount[15] = {15, 10, 25, 35, 5, 20, 40, 35, 10, 35, 45, 10, 10, 20, 40};


int main()
{
	int codes[N]; //все считанные штрихкоды
	int amount;//количество считанных штрихкодов
	amount = scan(codes);//считали штрихкоды
	int goods_amount[N];//количество штук для штрихкода
	int unic_codes[N];//массив уникальных штрихкодов
	int num_unic_codes = amount_calc(codes, unic_codes, goods_amount, amount);

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
	printf_s("Type 0 for exit\n");
	do
	{
		printf_s("Enter the code: ");
		scanf_s("%d", &value);
		for (int i = 0; i < 15; i++)
		{
			if (code[i] == value)
			{
				codes[j] = value;
				flag = 1;
				j++;
			}
		}
		if (flag == 0) {
			printf_s(" \nThe code isn't found\n");
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
		for (int j = 0; j < sizedb; j++)
		{
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

