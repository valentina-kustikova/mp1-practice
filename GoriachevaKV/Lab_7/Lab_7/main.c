#include <stdio.h>
#include <stdlib.h>
#include "department.h"
#include "auxdep.h"

#define FILENAME_MAX_LEN 101
#define MAX_DEP_LEN 101


int main(int argc, char** argv) {
	int i, rows = 0, error = 0;
	char* filename = NULL;
	char requested_department[MAX_DEP_LEN];
	OwnerLib db_lib;
	OwnerLib found_lib;

	if (argc < 2) {
		printf("Input error.\n\n");
		return 1;
	}
	
	filename = argv[1];

	printf("/%s/\n", filename);
	
	error = database_r(filename, &rows);
	if (error == 1) return 1;

	db_lib.owners = (Owner*)malloc(rows * sizeof(Owner));
	db_lib.count = rows;
	found_lib.owners = NULL;
	found_lib.count = 0;

	printf("Input the department >> ");
	fgets(requested_department, sizeof(requested_department), stdin);
	if (requested_department[strlen(requested_department) - 1] == '\n') {
		requested_department[strlen(requested_department) - 1] = '\0';
	}

	put_owners_into_array(filename, db_lib);
	find_owners(requested_department, db_lib, &found_lib);
	print_list(requested_department, found_lib);

	free_data(found_lib);
	free_data(db_lib);
	return 0;
}