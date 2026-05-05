#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auxdep.h"

#define BUFFER_SIZE 1024


int database_r(char* filename, int* rows) {
	char buff[BUFFER_SIZE];
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("ERROR!\nProbably, the database is empty or the file does not exist.\n\n");
		return 1;
	}
	while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
		(*rows)++;
	}
	fclose(fp);
	printf("The database found.\n\n");
	return 0;
}

void put_owners_into_array(char* filename, OwnerLib db) {
	int i;
	unsigned int d = 0, m = 0, y = 0;
	char buff[BUFFER_SIZE];
	FILE* fp = fopen(filename, "r");
	char* sn, *nm, *pn, * auto_n, * pass_n, * phone_n, * dep;

	for (i = 0; i < db.count; i++) {
		fgets(buff, BUFFER_SIZE, fp);
		if (buff[strlen(buff) - 1] == '\n') {
			buff[strlen(buff) - 1] = '\0';
		}

		sn = strtok(buff, " ");
		nm = strtok(0, " ");
		pn = strtok(0, ";");

		sscanf(strtok(0, "-"), "%u", &y);
		sscanf(strtok(0, "-"), "%u", &m);
		sscanf(strtok(0, ";"), "%u", &d);

		auto_n = strtok(0, ";");
		pass_n = strtok(0, ";");
		phone_n = strtok(0, ";");
		dep = strtok(0, ";");

		db.owners[i].full_name.surname = (char*)malloc((strlen(sn) + 1) * sizeof(char));
		db.owners[i].full_name.name = (char*)malloc((strlen(nm) + 1) * sizeof(char));
		db.owners[i].full_name.patronymic = (char*)malloc((strlen(pn) + 1) * sizeof(char));

		db.owners[i].auto_number = (char*)malloc((strlen(auto_n) + 1) * sizeof(char));
		db.owners[i].pass_number = (char*)malloc((strlen(pass_n) + 1) * sizeof(char));
		db.owners[i].phone_number = (char*)malloc((strlen(phone_n) + 1) * sizeof(char));
		db.owners[i].department = (char*)malloc((strlen(dep) + 1) * sizeof(char));

		strcpy(db.owners[i].full_name.surname, sn);
		strcpy(db.owners[i].full_name.name, nm);
		strcpy(db.owners[i].full_name.patronymic, pn);

		db.owners[i].birth_date.day = d;
		db.owners[i].birth_date.month = m;
		db.owners[i].birth_date.year = y;

		strcpy(db.owners[i].auto_number, auto_n);
		strcpy(db.owners[i].pass_number, pass_n);
		strcpy(db.owners[i].phone_number, phone_n);
		strcpy(db.owners[i].department, dep);
	}
	fclose(fp);
}

void print_list(char* requested_department, OwnerLib found) {
	int i;
	if (found.count == 0) {
		printf("There is no owners in %s.\n\n", requested_department);
	}
	else {
		printf("There is %d owners in %s.\n\n", found.count, requested_department);
		printf("-------------------------------------------------------------------------\n");
		printf("FULL NAME, BIRTH DATE, AUTO NUMBER, PASS NUMBER, PHONE NUMBER, DEPARTMENT\n");
		printf("-------------------------------------------------------------------------\n");
		for (i = 0; i < found.count; i++) {
			printf("%s %s %s, %u.%u.%u, %s, %s, %s, %s\n", found.owners[i].full_name.surname,
				found.owners[i].full_name.name, found.owners[i].full_name.patronymic, found.owners[i].birth_date.day,
				found.owners[i].birth_date.month, found.owners[i].birth_date.year, found.owners[i].auto_number,
				found.owners[i].pass_number, found.owners[i].phone_number, found.owners[i].department);
		}
	}
}