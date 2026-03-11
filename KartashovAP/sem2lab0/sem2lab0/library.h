#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_LEN 1024
//наша структура

typedef struct Book {
	char author[MAX_LEN];
	char name[MAX_LEN];
	char publish[MAX_LEN];
	int year;
} Book;

//функция поиска 
void searching(Book* masbook, int count_book, const char* author, Book** search, int* countAuthorBooks);

#endif 

