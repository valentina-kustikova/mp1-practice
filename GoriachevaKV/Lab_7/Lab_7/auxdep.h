#ifndef __AUXDEP_H_
#define __AUXDEP_H_
#include "department.h"


int database_r(char* filename, int* rows);
void put_owners_into_array(char* filename, OwnerLib* db);
void print_list(char* requested_department, OwnerLib* found);
#endif