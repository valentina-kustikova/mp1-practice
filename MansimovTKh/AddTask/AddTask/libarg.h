#ifndef _LIBARG_H
#define _LIBARG_H

typedef struct {
	char* surname;
	char* name;
	char* patronymic;
	char* gender;
	char* nation;
	int height;
	int weight;
	int day; 
	int month;
	int year;
	char* number;
	char* index;
	char* country;
	char* region_city;
	char* street;
} person_info;

void sort_person(person_info* person, int n);

#endif

