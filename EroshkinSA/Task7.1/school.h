#ifndef __SCH_H_
#define __SCH_H_

typedef struct {
	int index, flat;
	char* country, * region, * district, * city, * street, * house;
} home_address;

typedef struct {
	int day, month, year;
} birth_date;

typedef struct {
	char* name, * klass, * gen;
	birth_date date;
	home_address home;
} school;

void swap(school* a, school* b);
school* read(const char* source, int* n);
void school_sort(school* list, int n);
void class_sort(school* list, int n);
void sorted_list(school* list, int n);
void print_school(school s);
void free_all(school* list, int n);

#endif