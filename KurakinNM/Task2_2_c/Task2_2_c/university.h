#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	unsigned int numOfSpecialties;
	char* name;
	char* adres;
	char** specialties;
	unsigned int* contestDay;
	unsigned int* contestNight;
	unsigned int* contestOnline;
	unsigned int* cost;
} UNIV;

int read(char* fileName, UNIV** universities);
void output(UNIV* univs, int numOfUnivers);

void allAboutUniver(UNIV* univers, char* name, int numOfUnivers);
void allAboutSpec(UNIV* univers, char* special, int numOfUnivers);
void minContestSpec(UNIV* univers, char* special, int numOfUnivers);
void findSpec(UNIV* univers, char* special, int numOfUnivers);

#endif