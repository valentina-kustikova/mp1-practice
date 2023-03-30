#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct {

	char* employee;
	char* name_company;
	char* salary;
	char* work_cond;
	char* request;
	//char employee[20], name_company[20], salary[20], work_cond[100], request[100]

}vacancy;

char* enter_path();
FILE* open_stream(const char* path);
int count_vacancy(FILE* read);
void allocate_memory(vacancy* Vacancy, int countVacancy);
vacancy* fill_structures(FILE* file, int vacancyCount);
int* search_employee(vacancy* Vacancy, int countVacancy);
void output_info(vacancy* Vacancy, int* ind, int countVacancy);
void free_memory(vacancy* Vacancy);

