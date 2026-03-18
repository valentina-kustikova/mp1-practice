#ifndef _UNIVERSITY_
#define _UNIVERSITY_

#include <stdlib.h>
#include <string.h>

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

#endif