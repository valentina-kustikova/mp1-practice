#ifndef LIBRARY_H
#define LIBRARY_H
struct Book {
	char author[256];
	char name[256];
	char publisher[256];
	int year;
};
int searching(struct Book* library, int count, const char* author[], struct Book* found_books);
#endif
