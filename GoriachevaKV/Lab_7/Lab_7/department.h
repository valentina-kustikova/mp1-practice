#ifndef __DEPARTMENT_H_
#define __DEPARTMENT_H_

typedef struct {
	char* surname;
	char* name;
	char* patronymic;
}FullName;

typedef struct {
	unsigned int day;
	unsigned int month;
	unsigned int year;
}Date;

typedef struct {
	FullName full_name;
	Date birth_date;
	char* auto_number;
	char* pass_number;
	char* phone_number;
	char* department;
}Owner;

typedef struct {
	Owner* owners;
	int count;
} OwnerLib;


void find_owners(char* requested_department, OwnerLib db, OwnerLib* found);
void free_data(OwnerLib data);
#endif