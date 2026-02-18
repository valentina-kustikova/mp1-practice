#ifndef LIBRARY_H
#define LIBRARY_H

#define LENGTH_STRING 255

typedef enum {
    SUCCESS,
    ERROR_MEMORY,
    ERROR_FILE,
    ERROR_NO_BOOKS,
	ERROR_NO_FILTRED_BOOKS
} STATUS;

typedef struct {
    char authors[LENGTH_STRING+1];
    char title[LENGTH_STRING+1];
    char publishingHouse[LENGTH_STRING+1];
    int yearPublishing;
} BOOK;


STATUS readLibrary(BOOK** books, int* countBooks);
int getCountBooks(FILE* fp);
void stringToStruct(FILE* fp, BOOK* books, const int count);
void changeField(BOOK* book, const int indexField, const char* str);

STATUS searchBooksByAuthor(BOOK* books, const int countBooks, const char* author, BOOK** authorBooks, int* countAuthorBooks);

#endif
