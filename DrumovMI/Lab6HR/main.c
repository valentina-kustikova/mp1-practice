#include <stdio.h>
#include "hr_db.h"
#include "csv.h"

int main(int argc, char **argv) {
	FILE *file;
	csv tbl;
	Date date;
	Employee *employees;
	int employee_cnt;
	int found_cnt;
	int *employee_ids;
	int i;

	if (argc != 3) {
		printf("Usage: %s <filename> <date>\n", argv[0]);
		return 1;
	}

	fopen_s(&file, argv[1], "r");
	if (file == NULL) {
		printf("Error reading file %s.\n", argv[1]);
		return 1;
	}

	date = to_date(argv[2]);
	read_csv(file, &tbl);
	employees = csv_to_employees(tbl, &employee_cnt);
	employee_ids = search_pension(employees, employee_cnt, &found_cnt, date);
	for (i = 0; i < found_cnt; i++) {
		print_employee(employees[employee_ids[i]]);
		printf("\n");
	}
	return 0;
}