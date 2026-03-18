#ifndef LIBLARY_H
#define LIBLARY_H
typedef struct Book {
	char author[100];
	char name[100];
	char publisher[100];
	int year;
} Book;
void searching(Book* array, int count, const char* author,Book** search, int* countAuthorBooks);
#endif 

 