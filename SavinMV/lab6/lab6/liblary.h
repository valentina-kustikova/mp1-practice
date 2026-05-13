#ifndef LIBLARY_H
#define LIBLARY_H
#define MAX 256
typedef struct Book {
    char avtor[MAX];
    char name[MAX];
    char izdanie[MAX];
    int year;
} Book;
void poisk(Book* arr, int count, const char* avtor, Book** itogpoiska, int* kolvonaydenknig);
#endif 
