#ifndef LIBRARY_H
#define LIBRARY_H

#define LENGTH_STRING 255

#define MAIN_FRAME "\
|-----------------------------|\n\
|      Личная библиотека      |\n\
|-----------------------------|\n\n"

#define OPERATIONS "\
1. Показать список книг\n\
2. Найти книги по автору\n\
0. Выход\n\n"

typedef enum {
    SUCCESS,
    ERROR_MEMORY,
    ERROR_FILE,
    ERROR_NO_BOOKS
} STATUS;

typedef struct {
    char authors[LENGTH_STRING+1];
    char title[LENGTH_STRING+1];
    char publishingHouse[LENGTH_STRING+1];
    int yearPublishing;
} BOOK;

STATUS programCycle(BOOK* books, const int countBooks);
void printFrame();
int inputOperation();
STATUS searchBooksByAuthor(BOOK* books, const int countBooks);

#endif
