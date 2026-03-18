#ifndef __SCH_H_
#define __SCH_H_

typedef struct {
	char index[6];
	int flat;
	char* country, * region, * district, * city, * street, * house;
} home_address;

typedef struct {
	int day, month, year;
} birth_date;

typedef enum {
	MEN = 1, WOMAN
} genders;

typedef struct {
	char* surname, * name, * fathername, * klass;
	char* gen; // gen - enum 
	birth_date date;
	home_address home;
} pupil;

void swap(pupil* a, pupil* b);
pupil* read(const char* source, int* n);
void school_sort(pupil* list, int n);
void class_sort(pupil* list, int n);
void sorted_list(pupil* list, int n);         // struct iz pupil + n
void print_pupil(pupil s);
void free_all(pupil* list, int n);

#endif