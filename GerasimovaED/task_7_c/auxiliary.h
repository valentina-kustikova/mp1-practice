#ifndef IS_AUXILIARY_INCLUDED
#define IS_AUXILIARY_INCLUDED

#include "repertoir.h"

int rep_counter(char pathway[], int* cnt);
void rep_reader(int cnt, char pathway[], FILM _rep[]);
void rep_printer(int dir_cnt, FILM dir_rep[]);

#endif