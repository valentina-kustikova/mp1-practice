#ifndef LIBRARY_H
#define LIBRARY_H

#define AUTHORS 5
#define M 256

typedef struct {
	char (*authors)[M];
	int authors_count;
	char name[M];
	char publisher[M];
	int year;
} Book;

int searching(Book* library, int count, const char* author, Book* found_books);
void free_library(Book* library, int count);
#endif
