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

void freeDBU(DBUniversities* DB);

void read(char* fileName, DBUniversities* universities); // DBUniversities*
void output(DBUniversities univs); // DBUniversities*

void allAboutUniver(DBUniversities univs, char* name); // DBUniversities*
void allAboutSpec(DBUniversities univs, char* special); // DBUniversities*
void minContestSpec(University* univers, char* special, int numOfUnivers); // DBUniversities* //возвращать найденные
void findSpec(University* univers, char* special, int numOfUnivers); // DBUniversities* // поиск минимального конкурса по какой-либо специальности любого вуза

#endif