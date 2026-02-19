#include "library.h"

#ifndef _FUNCS_
#define _FUNCS_

#define sektors 4
#define max_simbols_in_line 512

void u_answer(char* user);
void enter_the_author(char* users_choice);
int scan_file(char* link);
void fill_arr(Book* arr, char* link);
void print_books(Book* arr, int* id_books, int size);


#endif