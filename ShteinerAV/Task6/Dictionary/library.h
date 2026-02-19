#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct {
	char** authors;
	int cnt_authors;
	char* books_name;
	char* publishing;
	int year;
}Book;

int find_book(Book* arr, int size, char** id_books);

#endif