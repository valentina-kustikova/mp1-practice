#ifndef __LIBRARY_H
#define __LIBRARY_H

typedef struct _book {
    char   *str;
    char   *authors;
    char   *title;
    char   *publisher;
    int     year_published;
} book;

void search_by_author(book* books, int book_cnt, int* found_book_ids, int* found_cnt, char* author);
void csv_to_books(csv tbl, book *books, int *book_cnt);
void print_book(book *book);

#endif