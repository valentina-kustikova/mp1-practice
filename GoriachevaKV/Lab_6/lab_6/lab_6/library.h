#ifndef __LIBRARY_H_
#define __LIBRARY_H_

#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100

typedef struct {
	char* author;
	char* name;
	char* publishing;
	char* publishing_year;
}BOOK;

/*typedef struct {
	char* author[MAX_STRING_SIZE];
	char* name[MAX_STRING_SIZE];
	char* publishing[MAX_STRING_SIZE];
	char* publishing_year[MAX_STRING_SIZE];
}BOOK;*/

#endif