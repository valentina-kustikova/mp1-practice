#ifndef IS_LIBRARY_INCLUDED
#define IS_LIBRARY_INCLUDED

#define MAX_SIZE 1024

typedef struct {
	char* author;
	char* name;
	char* publishing;
	int year;
}BOOK;

void author_finder(char* author_name, int* au_cnt, BOOK** au_lib, int cnt, BOOK* _lib);

#endif