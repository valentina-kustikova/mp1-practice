#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "reader.h"

int* search_by_author(struct Book* books, int book_count, char* author, int* found_count);
int* search_by_title(struct Book* books, int book_count, char* title, int* found_count);
void print_filtered_books(struct Book* books, int* indexes, int count);
void free_indexes(int* indexes);

#endif