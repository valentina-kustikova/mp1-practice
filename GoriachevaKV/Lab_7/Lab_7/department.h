#ifndef __DEPARTMENT_H_
#define __DEPARTMENT_H_

typedef struct {
	char* surname;
	char* name;
	char* patronymic;
}FullName;

typedef struct {
	char* day;
	char* month;
	char* year;
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

// int rows, Owner* database -> OwnerLib*
// int* found_cnt, Owner** found_owners -> OwnerLib* 
void find_owners(char* requested_department, int rows, Owner* database, int* found_cnt, Owner** found_owners);
void free_data(Owner* data, int cnt); // Owner* data, int cnt -> OwnerLib*
#endif