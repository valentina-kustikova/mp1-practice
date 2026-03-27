#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "functions.h"
#include "global_names.h"



int main()
{
	int exit_prog = 1;
	do { 
		char code[8]; //переменная, в которую считываем код
		char ans[8];//переменная, в которую считываем проверку на запись в чек и выход из цикла
		int err = scan(code);

		if (strcmp(code, "exit") == 0)
		{
			exit_prog = 0;
			break;
		}
		if (err != 0)
		{
			printf_s("Item not found. Try again\n");
			continue;
		}//продолжаем, если код найден
		//при сканировании спрашивать, добавить ли товар в чек
		printf_s("Add? ");
		gets_s(ans, sizeof(ans));


		if (strcmp(ans, "y") == 0) add(code);
		else (printf_s("the item is not added\n"));
	} while (exit_prog);
	print_receipt();
	return 0; 
}