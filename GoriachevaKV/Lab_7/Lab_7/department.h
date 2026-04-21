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

void find_owners(char* requested_department, int rows, OWNER* database, int* found_cnt, OWNER** found_owners);
void free_data(OWNER* data, int cnt);
#endif