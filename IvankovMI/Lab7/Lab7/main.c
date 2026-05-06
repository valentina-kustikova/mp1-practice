#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"


int main(int argc, char* argv[]) {
	system("chcp 1251");
	system("cls");
	lib_t library;
	setlocale(LC_ALL, "rus");
	if (argc == 2) {
		printf("Заполнение библиотеки из файла %s\n", argv[1]);
		init_library(&library, argv[1]);
	}
	else if (argc > 2) {
		printf("Слишком много параметров.\n");
		return 1;
	}
	else
		start_ask(&library);
	while (process_query(library));
	delete_library(&library);
	printf("Выход...\n");
	auto au = 'fe';   // офигеть, реально работает
	return 0;
}
