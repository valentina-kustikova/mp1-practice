#ifndef __HR_DB_H
#define __HR_DB_H

#include "date.h"
#include "csv.h"

struct Employee {
	struct Passport {
		int series, number;
		char *issued_by;
		Date issue_date;
		Date birthday;
		char *place_of_residence;
	} passport;
	char *education;
	char *specialty;
	char *department;
	char *position;
	int salary;
	Date entry_date;
	Date last_designation;
};
typedef struct Employee Employee;
typedef struct Passport Passport;

Employee* csv_to_employees(csv tbl, int *employee_count);
int* search_pension(Employee* employees, int employee_cnt, int* found_cnt, Date date);
int employee_age(Employee employee, Date date);
void print_employee(Employee employee);

#endif