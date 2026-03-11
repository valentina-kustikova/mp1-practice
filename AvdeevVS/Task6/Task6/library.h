#ifndef _LIBRARY_H
#define _LIBRARY_H

#define MAX_WRITER_LEN 15
#define MAX_NAME_LEN 100
#define MAX_PUBLISHER_NAME 500
#define MAX_LEN 1000

typedef struct{
  char writer[MAX_WRITER_LEN];
  char name[MAX_NAME_LEN];
  char publish[MAX_PUBLISHER_NAME];
  int year;
} book;

void Search(book* books, int nBooks, char* author,
	int **indecesAuthorBooks, int *nAuthorBooks);

#endif