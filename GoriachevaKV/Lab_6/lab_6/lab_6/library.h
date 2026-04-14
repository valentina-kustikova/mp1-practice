#ifndef __LIBRARY_H_
#define __LIBRARY_H_

typedef struct {
	char* authors;
	char* name;
	char* publishing;
	int publishing_year;
}BOOK;

void find_authors_books(int* found_cnt, int lines, BOOK* library, BOOK** found_books, char* needed_author);
#endif