#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

int book_amount(const char* file_name) {
	char buf[2048];
	int count = 0;

	FILE* file = fopen(file_name, "r");
	if (!file) {
		printf("Didn't find file: %s\n", file_name);
		return 1;
	}

	while (fgets(buf, sizeof(buf), file) != NULL) 
		count++;


	fclose(file);
	return count;
}

void read_file(int count, Book* library, char* file_name) {
	char buf[2048];
	FILE* file = fopen(file_name, "r");
	if (!file) return 0;

	int i;
	for (i = 0; i < count; i++) {
		fgets(buf, sizeof(buf), file);
		buf[strcspn(buf, "\n")] = '\0';

		char* next_token = NULL;
		char* all_authors = strtok_s(buf, ";", &next_token);

		library[i].authors_count = 0;
		library[i].authors = NULL;

		char* author_token = NULL;
		char* one_author = strtok_s(all_authors, ",", &author_token);
		while (one_author != NULL) {
			library[i].authors = (char(*)[M])realloc(library[i].authors, (library[i].authors_count + 1) * sizeof(char[M]));

			strcpy(library[i].authors[library[i].authors_count++], one_author);
			one_author = strtok_s(NULL, ",", &author_token);
		}

		strcpy(library[i].name, strtok_s(NULL, ";", &next_token));
		strcpy(library[i].publisher, strtok_s(NULL, ";", &next_token));
		library[i].year = atoi(strtok_s(NULL, ";", &next_token));
	}
	fclose(file);
}

void print_books(Book* found_books, int k) {
	if (k == 1)
		printf("1 book was found\n");
	else
		printf("%d books were found\n", k);

	int i;
	for (i = 0; i < k; i++) {
		int j;
		for (j = 0; j < found_books[i].authors_count; j++) {
			printf("%s%s", found_books[i].authors[j], 
				(j == found_books[i].authors_count - 1) ? "" : ",");
		}

		printf("; %s; %s; %d\n",
			found_books[i].name,
			found_books[i].publisher,
			found_books[i].year);
	}
}