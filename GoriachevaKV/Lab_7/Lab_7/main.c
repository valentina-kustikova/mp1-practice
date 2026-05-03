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
	char c;
	Owner* database = NULL;
	Owner* found_owners = NULL;

	printf("Input the filename >> "); // int argc, char** argv
	scanf_s("%100s", &filename, sizeof(filename));
	while ((c = getchar()) != '\n' && c != EOF) {}

	error = database_r(&rows, filename);
	if (error == 1) return 1;

	database = (Owner*)malloc(rows * sizeof(Owner));

	printf("Input the department >> ");
	fgets(requested_department, sizeof(requested_department), stdin);
	if (requested_department[strlen(requested_department) - 1] == '\n') {
		requested_department[strlen(requested_department) - 1] = '\0';
	}

	put_owners_into_array(rows, filename, database);
	find_owners(requested_department, rows, database, &found_cnt, &found_owners);
	print_list(found_cnt, found_owners, requested_department);

	free_data(found_owners, found_cnt);
	free_data(database, rows);
	return 0;
}