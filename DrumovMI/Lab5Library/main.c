#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library.h"
#include "auxiliary.h"

int main() {
	csv tbl;
	FILE *file;
	fopen_s(&file, "library.txt", "r");
	read_csv(file, &tbl);
	for (int i = 0; i < tbl.lines_cnt; i++)
		for (int j = 0; j < tbl.cells_cnt[i]; j++)
			printf("Cell R%dC%d: %s\n", i + 1, j + 1, tbl.cells[i][j]);
	return 0;
}

/*
int main() {
	csv cards_tbl;
	book *books;
	int book_cnt;
	FILE *cardfile;
	while (true) {
		char filename[512];
		printf("filename: ");
		fgets(filename, 512, stdin);
		cardfile = fopen(filename, "r");
		if (cardfile == NULL) {
			printf("error opening file %s\n", filename);
		} else {
			printf("file %s opened successfully\n", filename);
			break;
		}
	}

	if (read_csv(cardfile, &cards_tbl)) {
		printf("error reading csv\n");
		return 1;
	}
	fclose(cardfile);
	csv_to_books(cards_tbl, books, &book_cnt);

	while (true) {
		char author[512];
		int *book_ids;
		int found_cnt;
		int i;

		printf("author: ");
		fgets(author, 512, stdin);
		book_ids = search_by_author(books, book_cnt, &found_cnt, author);
		printf("found %d books by %s", found_cnt, author);
		for (i = 0; i < found_cnt; i++)
			print_book(books + book_ids[i]);
		free(book_ids);
	}
	
}
*/