#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char* name;
	char* adres; // struct
	unsigned int numOfSpecialties;
	char** specialties;
	unsigned int* contestDay;
	unsigned int* contestNight;
	unsigned int* contestOnline;
	unsigned int* cost; // float
} University;

typedef struct {
	University* universities;
	int count;
} DBUniversities;

int read(char* fileName, University** universities); // DBUniversities*
void output(University* univs, int numOfUnivers); // DBUniversities*

void allAboutUniver(University* univers, char* name, int numOfUnivers); // DBUniversities*
void allAboutSpec(University* univers, char* special, int numOfUnivers); // DBUniversities*
void minContestSpec(University* univers, char* special, int numOfUnivers); 
void findSpec(University* univers, char* special, int numOfUnivers);

#endif