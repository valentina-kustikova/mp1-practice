#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"
#include "library.h"

void search_by_author(book* books, int book_cnt, int *found_book_ids, int *found_cnt, char *author) {
	int i, j;
	found_book_ids = (int *) malloc(book_cnt * sizeof(int));
	*found_cnt = 0;
	if (found_book_ids == NULL) {
		printf("malloc error while searching\n");
		return;
	}

	for (i = 0; i < book_cnt; i++) {
		if (!strcmp(author, books[i].authors)) {
			found_book_ids[*found_cnt++] = i;
			break;
		}
	}
	found_book_ids = (int *) realloc(found_book_ids, *found_cnt * sizeof(int));
}

void csv_to_books(csv tbl, book *books, int *book_cnt) {
	return;
}

void print_book(book *book) {
	printf("\"%s\" authored by %s. ", book->title, book->authors);
	printf("Published by %s in the year %d.\n", book->publisher, book->year_published);
}