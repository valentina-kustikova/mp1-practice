#ifndef _AUXILIARY_H
#define _AUXILIARY_H

#include <stdlib.h>
#include "library.h"

int get_books_num(char* filename);
void read_books(book* books, char* filename);
void print_books(book* books, int nBooks, int *indecesAuthorBooks, int kAuthorBooks);

#endif