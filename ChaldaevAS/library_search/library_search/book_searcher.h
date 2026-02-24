#ifndef BOOK_SEARCHER_H
#define BOOK_SEARCHER_H

#include "book_reader.h"

int search_books_by_author(Book books[], int book_count, const char* author, int results[]);

void print_book(const Book* book);

void print_search_results(Book books[], int book_count, int results[], int result_count);

int is_author_in_list(const char* authors_str, const char* search_author);

#endif