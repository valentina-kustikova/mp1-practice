#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "department.h"


void find_owners(char* requested_department, int rows, OWNER* database, int* found_cnt, OWNER** found_owners) {
	int i, j = 0;
	for (i = 0; i < rows; i++) {
		if (strcmp(database[i].department, requested_department) == NULL) {
			(*found_cnt)++;
		}
	}

	(*found_owners) = (OWNER*)malloc((*found_cnt) * sizeof(OWNER));
	for (i = 0; i < rows; i++) {
		if ((strcmp(database[i].department, requested_department) == NULL)) {
			(*found_owners)[j].full_name = (char*)malloc((strlen(database[i].full_name) + 1) * sizeof(char));
			(*found_owners)[j].birth_date = (char*)malloc((strlen(database[i].birth_date) + 1) * sizeof(char));
			(*found_owners)[j].auto_number = (char*)malloc((strlen(database[i].auto_number) + 1) * sizeof(char));
			(*found_owners)[j].pass_number = (char*)malloc((strlen(database[i].pass_number) + 1) * sizeof(char));
			(*found_owners)[j].phone_number = (char*)malloc((strlen(database[i].phone_number) + 1) * sizeof(char));
			(*found_owners)[j].department = (char*)malloc((strlen(database[i].department) + 1) * sizeof(char));

			strcpy((*found_owners)[j].full_name, database[i].full_name);
			strcpy((*found_owners)[j].birth_date, database[i].birth_date);
			strcpy((*found_owners)[j].auto_number, database[i].auto_number);
			strcpy((*found_owners)[j].pass_number, database[i].pass_number);
			strcpy((*found_owners)[j].phone_number, database[i].phone_number);
			strcpy((*found_owners)[j].department, database[i].department);
			j++;
		}
	}
}

void free_data(OWNER* data, int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		free(data[i].full_name);
		free(data[i].birth_date);
		free(data[i].auto_number);
		free(data[i].pass_number);
		free(data[i].phone_number);
		free(data[i].department);
	}
	free(data);
}