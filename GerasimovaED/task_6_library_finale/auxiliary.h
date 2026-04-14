#ifndef IS_AUXILIARY_INCLUDED
#define IS_AUXILIARY_INCLUDED

#include "library.h"

int cab_counter(int* cnt, char* pathway);
void cab_reader(int* cnt, char* pathway, BOOK** _lib);
void cab_printer(int au_cnt, BOOK* au_lib);

#endif