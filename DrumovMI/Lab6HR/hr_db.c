#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
#include "csv.h"
#include "hr_db.h"

Employee* csv_to_employees(csv tbl, int* employee_count) {
	int i;
	Employee* employees;
	*employee_count = tbl.lines_cnt;
	employees = (Employee*)malloc(tbl.lines_cnt * sizeof(Employee));
	for (i = 0; i < tbl.lines_cnt; i++) {
		Passport passport = (Passport) { atoi(tbl.cells[i][0]), atoi(tbl.cells[i][1]), tbl.cells[i][2],
			to_date(tbl.cells[i][3]), to_date(tbl.cells[i][4]), tbl.cells[i][5] };
		employees[i] = (Employee) { passport, tbl.cells[i][6], tbl.cells[i][7], tbl.cells[i][8],
			tbl.cells[i][9], atoi(tbl.cells[i][10]), to_date(tbl.cells[i][11]), to_date(tbl.cells[i][12])};
	}
	return employees;
}

int* search_pension(Employee* employees, int employee_cnt, int* found_cnt, Date date) {
	int i, j, *found_employee_ids = (int*)malloc(employee_cnt * sizeof(int));
	*found_cnt = 0;
	if (found_employee_ids == NULL) {
		printf("malloc error while searching\n");
		return;
	}

	for (i = 0; i < employee_cnt; i++)
		if (employee_age(employees[i], date) > 60)
			found_employee_ids[(*found_cnt)++] = i;

	found_employee_ids = (int*)realloc(found_employee_ids, *found_cnt * sizeof(int));
	return found_employee_ids;
}

int employee_age(Employee employee, Date date) {
	return year_diff(employee.passport.birthday, date);
}

void print_employee(Employee employee) {
	Passport passport = employee.passport;
	printf("Passport: %d %d, issued by %s on ", passport.series, passport.number, passport.issued_by);
	print_date(passport.issue_date);
	printf(". Born on ");
	print_date(passport.birthday);
	printf(". Official residence: %s.\n", passport.place_of_residence);
	printf("Education: %s. Specialty: %s.\nDepartment: %s. Position: %s. Salary: %d.\n",
		employee.education, employee.specialty, employee.department, employee.position, employee.salary);
	printf("Entry date: ");
	print_date(employee.entry_date);
	printf(". Last designation: ");
	print_date(employee.last_designation);
}