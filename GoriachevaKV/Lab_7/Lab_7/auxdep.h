#ifndef __AUXDEP_H_
#define __AUXDEP_H_
#include "department.h"


int database_r(int* rows, char* filename);
void put_owners_into_array(int rows, char* filename, Owner* database); // int rows, Owner* database -> OwnerLib*
void print_list(int found_cnt, Owner* found_owners, char* requested_department); // int found_cnt, Owner* found_owners -> OwnerLib*
#endif