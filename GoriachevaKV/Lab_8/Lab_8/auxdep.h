#ifndef __AUXDEP_H_
#define __AUXDEP_H_
#include "department.h"

using namespace std;


int database_r(string filename, int* rows);
void put_owners_into_array(string filename, OwnerLib* db);
void print_list(string requested_department, OwnerLib* found);
#endif