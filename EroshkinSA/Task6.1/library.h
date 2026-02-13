#ifndef __LIB_H
#define __LIB_H

typedef struct {
	char** authors;
	char* name, *publisher;
	int year;
} book;

book* search(char* author, book* lib, int n);

#endif
