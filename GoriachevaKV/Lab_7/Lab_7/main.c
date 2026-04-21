#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "department.h"
#include "auxdep.h"

#define FILENAME_MAX_LEN 101
#define MAX_DEP_LEN 101


int main() {
	int i, rows = 0, found_cnt = 0, error = 0;
	char filename[FILENAME_MAX_LEN];
	char requested_department[MAX_DEP_LEN];
	OWNER* database = NULL;
	OWNER* found_owners = NULL;

	printf("Input the filename >> ");
	scanf_s("%100s", &filename, sizeof(filename));

	error = database_r(&rows, filename);
	if (error == 1) return 1;

	database = (OWNER*)malloc(rows * sizeof(OWNER));

	printf("Input the department >> ");
	scanf_s("%100s", &requested_department, sizeof(requested_department));

	put_owners_into_array(rows, filename, database);
	find_owners(requested_department, rows, database, &found_cnt, &found_owners);
	print_list(found_cnt, found_owners, requested_department);

	free_data(found_owners, found_cnt);
	free_data(database, rows);
	return 0;
}