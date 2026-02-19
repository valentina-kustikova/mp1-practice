#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	BOOK* lib; BOOK* findedBooks;
	int n, n2, i, j;
	char str[100];
	system("chcp 1251");
	system("cls");
	n = read("lib.txt",&lib);

	while (1) {
		printf("¬ведите автора (0 - выход): ");
		fgets(str, 100, stdin);
		if (strncmp(str, "0\n", 2) == 0) break;
		printf("===========================================\n");
		n2 = find(lib, &findedBooks, n, str);
		if (n2 == 0) { printf(" ниг этого автора не найдено\n\n"); }
		else output(findedBooks, n2);

		for (i = 0; i < n2; i++) {
			for (j = 0; j < findedBooks[i].numberOfAuthors; j++)
			{
				free(findedBooks[i].authors[j]);
			}
			free(findedBooks[i].authors);
			free(findedBooks[i].title);
			free(findedBooks[i].ed);
		}

		free(findedBooks);
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