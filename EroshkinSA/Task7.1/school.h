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

static void swap(school* a, school* b);
extern school* read(const char* source, int* n);
static void school_sort(school* list, int n);
extern void list_class(char* klass, school* list, int n);
void print_school(school s);
static print(school s, int n);

#endif