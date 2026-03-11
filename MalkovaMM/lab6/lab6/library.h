#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct {
	char* author;
	char* title;
	char* publisher;
	int year;
}Book;

Book* findByauthor(Book* bss, int n, const char* findauthor, int* nnew);

#endif