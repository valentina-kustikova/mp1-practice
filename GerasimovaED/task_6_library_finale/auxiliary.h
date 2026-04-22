#ifndef IS_AUXILIARY_INCLUDED
#define IS_AUXILIARY_INCLUDED

#include "library.h"

void cab_counter(char* pathway, int* cnt);
void cab_reader(int cnt, char* pathway, BOOK* _lib);
void cab_printer(int au_cnt, BOOK* au_lib);

#endif