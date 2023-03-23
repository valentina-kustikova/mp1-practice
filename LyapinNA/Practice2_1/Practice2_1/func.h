#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct {
	char* employee, name_company, salary, work_cond, request;
}vacancy;

FILE* open_stream(const char* path);
int count_vacancy(FILE* read);
void allocate_memory(vacancy* Vacancy, int countVacancy);
vacancy* fill_structures(FILE* file, int vacancyCount);
int* search_employee(vacancy* Vacancy, int countVacancy);
void output_info(vacancy* Vacancy, int* ind, int countVacancy);
void free_memory(vacancy* Vacancy);

