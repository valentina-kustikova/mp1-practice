#ifndef __LIBRARY_H_
#define __LIBRARY_H_


typedef struct {
	char* authors;
	char* name;
	char* publishing;
	int publishing_year;
}BOOK;

void find_authors_books(char* needed_author, int lines, BOOK* library, int* found_cnt, BOOK** found_books);
void free_lib(BOOK* lib, int cnt);

#endif