#ifndef __LIB_H
#define __LIB_H

typedef struct {
	char** authors;
	char* name, *publisher;
	int year, cnt_aut;
} book;

book** search(char* author, book* lib, int n, int* cnt);

#endif
