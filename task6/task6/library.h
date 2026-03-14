#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

typedef struct {
	char autors[40];
	char name[20];
	char publisher[20];
	int year;
} book;

int* find(book* books, char* aut, int n);
void printer(book* books, int* ans);

#endif
