#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define N 1000
#define sizedb 15
const char* code[sizedb] = { "0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010", "0011", "0012", "0013", "0014", "0015"};
const char* name[15] = { "apples", "milk", "bananas", "bread", "juice", "ketchup", "mayonaise", "eggs", "cheese", "tomatoes", "sausages", "salad", "meat", "butter", "fish"};
const int price[15] = {100, 90, 75, 30, 300, 80, 75, 60, 140, 200, 300, 250, 400, 170, 270};
const int discount[15] = {15, 10, 25, 35, 5, 20, 40, 35, 10, 35, 45, 10, 10, 20, 40};


int main()
{
	char* codes[N]; //все считанные штрихкоды
	int amount;//количество считанных штрихкодов
	amount = scan(codes);//считали штрихкоды
	/*
	* for (int i = 0; i < 15; i++)
	{
		printf_s("%s", codes[i]);
	}
	*/
	int goods_amount[N];//количество штук для штрихкода
	char** unic_codes[N];//массив уникальных штрихкодов
	int num_unic_codes = amount_calc(codes, unic_codes, goods_amount, amount);

	create_receipt(unic_codes, goods_amount, num_unic_codes); //вызываем создание чека

	return 0; 
}

int scan(char** codes)
{
	int flag = 0;
	int j = 0;
	printf("Type 0 for exit\n");

	do
	{
		printf("Enter the code: ");
		char str[5];

		if (gets_s(str, sizeof(str)) == NULL) {
			break;
		}

		if (strcmp(str, "0") == 0) {
			break;
		}

		int found = 0;
		for (int i = 0; i < 15; i++)
		{
			if (strcmp(code[i], str) == 0)
			{
				codes[j] = (char*)malloc(strlen(str) + 1);
				if (codes[j] != NULL) {
					strcpy_s(codes[j], strlen(str) + 1, str);
				}
				flag = 1;
				j++;
				break;
			}
		}

		if (flag == 0) {
			printf("The code isn't found\n");
		}

	} while (1);

	return j;
}

int amount_calc(char **codes, char **unic_codes, int *goods_amount, int amount)
{
	int k = 0;
	for (int i = 0; i <= amount; i++) 
	{
		if (codes[i] == NULL)
		{
			continue; //берем следующий код
		}
		int flag = 0; 
		goods_amount[k] = 1; //считаем количество встретившегося штрихкода
		if ((i == amount - 1) && (codes[i] != NULL))
		{
			unic_codes[k] = malloc(strlen(codes[i]) + 1);
			strcpy_s(unic_codes[k], strlen(codes[i]) + 1, codes[i]);
			break;
		}
		for (int j = i+1; j < amount; j++)
		{
			if ((codes[i] != NULL) && (strcmp(codes[i], codes[j]) == 0))
			{
				goods_amount[k] += 1;//считаем количество встретившегося штрихкода
				unic_codes[k] = malloc(strlen(codes[i]) + 1);//записываем штрихкод в новый массив уникальных штрихкодов
				strcpy_s(unic_codes[k], strlen(codes[i]) + 1, codes[i]);
				codes[j] = NULL;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			unic_codes[k] = malloc(strlen(codes[i]) + 1);
			strcpy_s(unic_codes[k], strlen(codes[i]) + 1, codes[i]);

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

