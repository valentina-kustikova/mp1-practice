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

	printf("Input the department >> ");
	scanf_s("%100s", &requested_department, sizeof(requested_department));

	put_owners_into_array(&rows, filename, &database);
	find_owners(&found_cnt, rows, database, &found_owners, requested_department);
	print_list(found_cnt, found_owners, requested_department);

	for (i = 0; i < found_cnt; i++) {
		free(found_owners[i].full_name);
		free(found_owners[i].birth_date);
		free(found_owners[i].auto_number);
		free(found_owners[i].pass_number);
		free(found_owners[i].phone_number);
		free(found_owners[i].department);
	}

	for (i = 0; i < rows; i++) {
		free(database[i].full_name);
		free(database[i].birth_date);
		free(database[i].auto_number);
		free(database[i].pass_number);
		free(database[i].phone_number);
		free(database[i].department);
	}

	free(found_owners);
	free(database);
	return 0;
}