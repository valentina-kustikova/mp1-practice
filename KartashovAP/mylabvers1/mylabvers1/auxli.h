#ifndef AUXLI_H
#define AUXLI_H
#include "roster.h"

int countingstudents(const char* filename);
void readFile(int count_student, student* mas_student, const char* filename);
void printRes(student* search, int kol_res);

#endif
