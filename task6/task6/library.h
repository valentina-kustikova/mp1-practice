#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

typedef struct {
	char authors[100];
	char name[100];
	char publisher[100];
	int year;
} book;

typedef struct {
	int len;
	book* books;
} Fbooks;

Fbooks find(Fbooks books, char* aut); // book*, int
void printer(Fbooks ans);

#endif
