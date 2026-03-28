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

void read_file(int count, struct Book* library, char* file_name) {
	char buf[2048];
	FILE* file = fopen(file_name, "r");

	int i;
	for (i = 0; i < count; i++) {
		fgets(buf, sizeof(buf), file);
		buf[strcspn(buf, "\n")] = '\0';
		strcpy(library[i].author, strtok(buf, ";"));
		strcpy(library[i].name, strtok(NULL, ";"));
		strcpy(library[i].publisher, strtok(NULL, ";"));
		library[i].year = atoi(strtok(NULL, ";"));
	}

	fclose(file);
}

void print_books(struct Book* found_books, int k) {
	if (k == 1) 
		printf("1 book was found\n");
	else
		printf("%d books were found\n", k);

	int i;
	for (i = 0; i < k; i++)
		printf("%s; %s; %s; %d\n", found_books[i].author, found_books[i].name, found_books[i].publisher, found_books[i].year);
}