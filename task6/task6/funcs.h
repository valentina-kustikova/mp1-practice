#ifndef FUNCS_H
#define FUNCS_H

typedef struct {
    char* authors;
    char* title;
    char* publisher;
    int year;
}Book;


Book* file_open(const char* filename, int* n);
Book divide_line(char* line);
void show_books(Book* books, int n);
char* to_lower(char* arr);
void find_by_author(Book* books, int n, char* author);
void free_books(Book* books, int n);

#endif