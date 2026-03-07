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
	char* birth;
	char* number;
	char* address;
} person_info;

void sort_person(person_info* person, int n);

#endif

