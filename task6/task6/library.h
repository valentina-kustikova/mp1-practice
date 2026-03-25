#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

typedef struct {
	char* authors;
	char* name;
	char* publisher;
	int year;
} book;

int* find(book* books, char* aut, int n);
void printer(book* books, int* ans);

#endif
