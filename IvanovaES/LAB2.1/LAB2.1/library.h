#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct BookData {
	char author[100];
	char name[100];
	char publishing[100];
	int year;
} BookData;

void search(BookData* array, int cnt, char* author, BookData** result, int* foundBooks);

#endif