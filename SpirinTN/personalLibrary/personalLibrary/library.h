#ifndef LIBRARY_H
#define LIBRARY_H

#define LENGTH_STRING 255

typedef enum {
    SUCCESS,
	INSUFFICIENT_ARGUMENTS_ERROR,
    ERROR_MEMORY,
    INVALID_FILE,
    FILE_OPENING_ERROR,
    FILE_CLOSE_ERROR,
    ERROR_NO_BOOKS,
	ERROR_NO_FILTRED_BOOKS
} STATUS;

typedef struct {
    char authors[LENGTH_STRING+1];
    char title[LENGTH_STRING+1];
    char publishingHouse[LENGTH_STRING+1];
    int yearPublishing;
} BOOK;


STATUS readLibrary(BOOK** books, int* countBooks, char* fileName);
int getCountBooks(FILE* fp);
STATUS stringToStruct(FILE* fp, BOOK* books, int count);
void changeField(BOOK* book, int indexField, char* str);

STATUS searchBooksByAuthor(BOOK* books, int countBooks, char* author, BOOK** authorBooks, int* countAuthorBooks);
void toLowerCase(char* str);

#endif
