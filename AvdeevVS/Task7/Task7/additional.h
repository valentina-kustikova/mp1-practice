#ifndef _ADDITIONAL_H_
#define _ADDITIONAL_H_
#include "find.h"
int Number_of_jobless(char* filename);
void Filling_from_file(jobless_people* jobless, char* filename);
void Print_of_result(jobless_people* jobless, int* required_indexes, int nrequired_indexes, int njobless);
void Clearing_memory(jobless_people* jobless, int njobless, int* required_indexes);
#endif
