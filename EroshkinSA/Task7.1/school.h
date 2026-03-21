#ifndef __SCH_H_
#define __SCH_H_

typedef struct {
	char index[7];
	int flat;
	char* country, * region, * district, * city, * street, * house;
} home_address;

typedef struct {
	int day, month, year;
} birth_date;

typedef enum {
	MAN = 1, WOMAN
} gender;

typedef struct {
	char* surname, * name, * fathername, * klass;
	gender gen;
	birth_date date;
	home_address home;
} pupil;

typedef struct {
	int count;
	pupil* list;
} school;

void swap(pupil* a, pupil* b);
void read(const char* source, school* sch);
void school_sort(school* sch);
void class_sort(school* sch);
int compare(pupil* a, pupil* b);
void sorted_list(school* sch);
void print_pupil(pupil s);
void free_all(school* sch);

#endif