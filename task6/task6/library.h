#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

typedef struct {
	char authors[100];
	char name[100];
	char publisher[100];
	int year;
} book;

int* find(book* books, char* aut, int n);
void printer(book* books, int* ans);

#endif
