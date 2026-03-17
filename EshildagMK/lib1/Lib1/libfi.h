#ifndef LIB_H
#define LIB_H

typedef struct {
    char* author;
    char* book_name;
    char* publisher;
    int book_year;
} book_info;

void searcher(book_info* books, int lines, const char* auth_name,
    book_info** found_books, int* found_count);

#endif      