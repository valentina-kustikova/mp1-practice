#ifndef LIBRARY_H
#define LIBRARY_H
struct Book {
	char author[100];
	char name[100];
	char publisher[100];
	int year;
};
void searching(struct Book* array, int count, const char* author, struct Book** search, int* countAuthorBooks);
#endif 
