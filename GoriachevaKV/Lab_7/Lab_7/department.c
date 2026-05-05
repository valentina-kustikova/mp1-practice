#include <string.h>
#include <stdlib.h>
#include "department.h"


void find_owners(char* requested_department, OwnerLib db, OwnerLib* found) {
	int i, j = 0;
	for (i = 0; i < db.count; i++) {
		if (strcmp(db.owners[i].department, requested_department) == NULL) {
			(*found).count++;
		}
	}

	(*found).owners = (Owner*)malloc((*found).count * sizeof(Owner));
	for (i = 0; i < db.count; i++) {
		if ((strcmp(db.owners[i].department, requested_department) == NULL)) {
			(*found).owners[j].full_name.surname = (char*)malloc((strlen(db.owners[i].full_name.surname) + 1) * sizeof(char));
			(*found).owners[j].full_name.name = (char*)malloc((strlen(db.owners[i].full_name.name) + 1) * sizeof(char));
			(*found).owners[j].full_name.patronymic = (char*)malloc((strlen(db.owners[i].full_name.patronymic) + 1) * sizeof(char));

			(*found).owners[j].auto_number = (char*)malloc((strlen(db.owners[i].auto_number) + 1) * sizeof(char));
			(*found).owners[j].pass_number = (char*)malloc((strlen(db.owners[i].pass_number) + 1) * sizeof(char));
			(*found).owners[j].phone_number = (char*)malloc((strlen(db.owners[i].phone_number) + 1) * sizeof(char));
			(*found).owners[j].department = (char*)malloc((strlen(db.owners[i].department) + 1) * sizeof(char));

			strcpy((*found).owners[j].full_name.surname, db.owners[i].full_name.surname);
			strcpy((*found).owners[j].full_name.name, db.owners[i].full_name.name);
			strcpy((*found).owners[j].full_name.patronymic, db.owners[i].full_name.patronymic);

			(*found).owners[j].birth_date.day = db.owners[i].birth_date.day;
			(*found).owners[j].birth_date.month = db.owners[i].birth_date.month;
			(*found).owners[j].birth_date.year = db.owners[i].birth_date.year;

			strcpy((*found).owners[j].auto_number, db.owners[i].auto_number);
			strcpy((*found).owners[j].pass_number, db.owners[i].pass_number);
			strcpy((*found).owners[j].phone_number, db.owners[i].phone_number);
			strcpy((*found).owners[j].department, db.owners[i].department);
			j++;
		}
	}
}

void free_data(OwnerLib data) {
	int i;
	for (i = 0; i < data.count; i++) {
		free(data.owners[i].full_name.surname);
		free(data.owners[i].full_name.name);
		free(data.owners[i].full_name.patronymic);

		free(data.owners[i].auto_number);
		free(data.owners[i].pass_number);
		free(data.owners[i].phone_number);
		free(data.owners[i].department);
	}
	free(data.owners);
}