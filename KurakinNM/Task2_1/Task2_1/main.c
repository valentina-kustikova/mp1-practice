#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	BOOK* lib; int n, n2, i, j; char str[100]; size_t* idBooks;
	system("chcp 1251");
	system("cls");
	n = read("lib.txt",&lib);

	while (1) {
		printf("¬ведите автора (0 - выход): ");
		fgets(str, 100, stdin);
		if (strncmp(str, "0\n", 2) == 0) break;
		n2 = find(lib, n, str, &idBooks);
		if (n2 == 0) { printf(" ниг этого автора не найдено\n\n"); }
		else output(lib, idBooks, n2);
		free(idBooks);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < lib[i].numberOfAuthors; j++)
		{
			free(lib[i].authors[j]);
		}
		free(lib[i].authors);
		free(lib[i].title);
		free(lib[i].ed);
	}
	free(lib);
	return 0;
}