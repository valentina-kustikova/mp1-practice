#ifndef IS_AUXILIARY_INCLUDED
#define IS_AUXILIARY_INCLUDED

#include "repertoir.h"

int rep_counter(char* pathway);
FilmLibrary rep_reader(char* pathway, int cnt);
void rep_printer(FilmLibrary dir_rep);

#endif