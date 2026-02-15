#ifndef _LIBRARY_
#define _LIBRARY_


typedef struct { 
	unsigned int numberOfAuthors;
	char** authors;
	char* title;
	char* ed;
	unsigned short year;
} BOOK;

int find(BOOK* lib, int numOfBooks, char* str, unsigned int** idBooks);


#endif