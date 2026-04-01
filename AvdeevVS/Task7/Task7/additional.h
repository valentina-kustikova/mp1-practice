#ifndef _ADDITIONAL_H_
#define _ADDITIONAL_H_
#include "find.h"
int Number_of_jobless(char* filename);
void Filling_from_file(jobless_base jobless, char* filename);
void Print_of_result(jobless_base jobless, int* required_indexes, int nrequired_indexes);
void Clearing_memory(jobless_base jobless, int* required_indexes);
#endif
