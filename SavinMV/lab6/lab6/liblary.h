#ifndef LIBLARY_H
#define LIBLARY_H
typedef struct Book {
    char avtor[100];
    char name[100];
    char izdanie[100];
    int year;
} Book;
void poisk(Book* arr, int count, const char* avtor, Book** itogpoiska, int* kolvonaydenknig);
#endif 
