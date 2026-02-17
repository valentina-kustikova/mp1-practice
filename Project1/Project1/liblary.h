#ifndef LIBLARY_H
#define LIBLARY_H
struct Book {
	char author[100];
	char name[100];
	char publisher[100];
	int year;
};
int searching(struct Book* array, int count, const char* author[], struct Book* search);
#endif 

