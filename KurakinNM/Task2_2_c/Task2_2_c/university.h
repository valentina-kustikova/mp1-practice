#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char* city;
	char* street;
	char* home;
} Adres;

typedef struct {
	char* name;
	Adres adres;
	unsigned int numOfSpecialties;
	char** specialties;
	unsigned int* contestDay;
	unsigned int* contestNight;
	unsigned int* contestOnline;
	float* cost; // float
} University;

typedef struct {
	University* universities;
	int count;
} DBUniversities;

int read(char* fileName, University** universities); // DBUniversities*
void output(University* univs, int numOfUnivers); // DBUniversities*

void allAboutUniver(University* univers, char* name, int numOfUnivers); // DBUniversities*
void allAboutSpec(University* univers, char* special, int numOfUnivers); // DBUniversities*
void minContestSpec(University* univers, char* special, int numOfUnivers); // DBUniversities* //возвращать найденные
void findSpec(University* univers, char* special, int numOfUnivers); // DBUniversities* // поиск минимального конкурса по какой-либо специальности любого вуза

#endif