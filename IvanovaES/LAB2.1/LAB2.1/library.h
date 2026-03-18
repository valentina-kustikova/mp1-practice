#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_LEN 2048

typedef struct BookData {
	char author[MAX_LEN];
	char name[MAX_LEN];
	char publishing[MAX_LEN];
	int year;
} BookData;

void search(BookData* array, int cnt, char* author, BookData** result, int* foundBooks);

#endif