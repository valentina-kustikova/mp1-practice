#include <string.h>
#include <stdlib.h>
#include "department.h"


void find_owners(char* requested_department, int rows, Owner* database, int* found_cnt, Owner** found_owners) {
	int i, j = 0;
	for (i = 0; i < rows; i++) {
		if (strcmp(database[i].department, requested_department) == NULL) {
			(*found_cnt)++;
		}
	}

	(*found_owners) = (Owner*)malloc((*found_cnt) * sizeof(Owner));
	for (i = 0; i < rows; i++) {
		if ((strcmp(database[i].department, requested_department) == NULL)) {
			(*found_owners)[j].full_name.surname = (char*)malloc((strlen(database[i].full_name.surname) + 1) * sizeof(char));
			(*found_owners)[j].full_name.name = (char*)malloc((strlen(database[i].full_name.name) + 1) * sizeof(char));
			(*found_owners)[j].full_name.patronymic = (char*)malloc((strlen(database[i].full_name.patronymic) + 1) * sizeof(char));

			(*found_owners)[j].auto_number = (char*)malloc((strlen(database[i].auto_number) + 1) * sizeof(char));
			(*found_owners)[j].pass_number = (char*)malloc((strlen(database[i].pass_number) + 1) * sizeof(char));
			(*found_owners)[j].phone_number = (char*)malloc((strlen(database[i].phone_number) + 1) * sizeof(char));
			(*found_owners)[j].department = (char*)malloc((strlen(database[i].department) + 1) * sizeof(char));

			strcpy((*found_owners)[j].full_name.surname, database[i].full_name.surname);
			strcpy((*found_owners)[j].full_name.name, database[i].full_name.name);
			strcpy((*found_owners)[j].full_name.patronymic, database[i].full_name.patronymic);

			(*found_owners)[j].birth_date.day = database[i].birth_date.day;
			(*found_owners)[j].birth_date.month = database[i].birth_date.month;
			(*found_owners)[j].birth_date.year = database[i].birth_date.year;

			strcpy((*found_owners)[j].auto_number, database[i].auto_number);
			strcpy((*found_owners)[j].pass_number, database[i].pass_number);
			strcpy((*found_owners)[j].phone_number, database[i].phone_number);
			strcpy((*found_owners)[j].department, database[i].department);
			j++;
		}
	}
}

void free_data(Owner* data, int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		free(data[i].full_name.surname);
		free(data[i].full_name.name);
		free(data[i].full_name.patronymic);

		free(data[i].auto_number);
		free(data[i].pass_number);
		free(data[i].phone_number);
		free(data[i].department);
	}
	free(data);
}