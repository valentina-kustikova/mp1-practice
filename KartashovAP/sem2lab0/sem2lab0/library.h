#ifndef LIBRARY_H
#define LIBRARY_H

//наша структура

typedef struct Book {
	char author[100];
	char name[100];
	char publish[100];
	int year;
} Book;

//функция поиска 
void searching(Book* masbook, int count_book, const char* author, Book** search, int* countAuthorBooks);

#endif 

