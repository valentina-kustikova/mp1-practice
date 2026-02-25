#ifndef LIBRARY_H
#define LIBRARY_H
typedef struct {
	char* author;
	char* title;
	char* publisher;
	int year;
}Book;

int findByauthor(const Book* book, const char *findauthor);
#endif