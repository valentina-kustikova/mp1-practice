#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxx.h"

int main(int argc, char** argv) {
	char* filename;
	char author[100];
	int cnt, foundBooks;
	BookData* array;
	BookData* result;
	if (argc < 2) {
		printf("Incorrect number of arguments");
		return 1;
	}
	filename = argv[1];

	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: cant open file");
		return 1;
	}

	cnt = cntBooks(file);
	rewind(file);

	array = (BookData*)malloc(cnt * sizeof(BookData));
	readFile(array, cnt, file);
	fclose(file);

	printf("Enter the author - ");
	scanf(" %[^\n]", author);

	search(array, cnt, author, &result, &foundBooks);

	printf("There are %d books in the library\n", cnt);
	printResult(result, foundBooks);

	free(array);
	if (result != NULL) {
		free(result);
	}
	
	return 0;
}