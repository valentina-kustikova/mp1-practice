#ifndef _LIBARG_H
#define _LIBARG_H

typedef struct {
	char* authors;
	char* title;
	char* publisher;
	int year;
} book_info;

void find_books(const char* author_surname, book_info** found_books, book_info* books, int lines, int* found);

#endif