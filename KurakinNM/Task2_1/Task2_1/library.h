#ifndef _LIBRARY_
#define _LIBRARY_

#include <stdlib.h>

typedef struct { 
	unsigned int numberOfAuthors;
	char** authors;
	char* title;
	char* ed;
	unsigned short year;
} BOOK;

int find(BOOK* lib, BOOK** findedBooks, int numOfBooks, char* str);


#endif