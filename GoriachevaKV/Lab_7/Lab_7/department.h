#ifndef __DEPARTMENT_H_
#define __DEPARTMENT_H_

typedef struct {
	char* full_name;
	char* birth_date;
	char* auto_number;
	char* pass_number;
	char* phone_number;
	char* department;
}OWNER;

void find_owners(int* found_cnt, int rows, OWNER* database, OWNER** found_owners, char* requested_department);
#endif