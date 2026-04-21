#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auxdep.h"

#define BUFFER_SIZE 1024


int database_r(int* rows, char* filename) {
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

void put_owners_into_array(int rows, char* filename, OWNER* database) {
	int i;
	char buff[BUFFER_SIZE];
	FILE* fp = fopen(filename, "r");
	char* fn, * bd, * auto_n, * pass_n, * phone_n, * dep;
	char delimiter[1] = ";";

	for (i = 0; i < rows; i++) {
		fgets(buff, BUFFER_SIZE, fp);
		if (buff[strlen(buff) - 1] == '\n') {
			buff[strlen(buff) - 1] = '\0';
		}

		fn = strtok(buff, delimiter);
		bd = strtok(0, delimiter);
		auto_n = strtok(0, delimiter);
		pass_n = strtok(0, delimiter);
		phone_n = strtok(0, delimiter);
		dep = strtok(0, delimiter);

		database[i].full_name = (char*)malloc((strlen(fn) + 1) * sizeof(char));
		database[i].birth_date = (char*)malloc((strlen(bd) + 1) * sizeof(char));
		database[i].auto_number = (char*)malloc((strlen(auto_n) + 1) * sizeof(char));
		database[i].pass_number = (char*)malloc((strlen(pass_n) + 1) * sizeof(char));
		database[i].phone_number = (char*)malloc((strlen(phone_n) + 1) * sizeof(char));
		database[i].department = (char*)malloc((strlen(dep) + 1) * sizeof(char));

		strcpy(database[i].full_name, fn);
		strcpy(database[i].birth_date, bd);
		strcpy(database[i].auto_number, auto_n);
		strcpy(database[i].pass_number, pass_n);
		strcpy(database[i].phone_number, phone_n);
		strcpy(database[i].department, dep);
	}
	fclose(fp);
}

void print_list(int found_cnt, OWNER* found_owners, char* requested_department) {
	int i;
	if (found_cnt == 0) {
		printf("There is no owners in %s.\n\n", requested_department);
	}
	else {
		printf("There is %d owners in %s.\n\n", found_cnt, requested_department);
		printf("-------------------------------------------------------------------------\n");
		printf("FULL NAME, BIRTH DATE, AUTO NUMBER, PASS NUMBER, PHONE NUMBER, DEPARTMENT\n");
		printf("-------------------------------------------------------------------------\n");
		for (i = 0; i < found_cnt; i++) {
			printf("%s, %s, %s, %s, %s, %s\n", found_owners[i].full_name, found_owners[i].birth_date, found_owners[i].auto_number,
				found_owners[i].pass_number, found_owners[i].phone_number, found_owners[i].department);
		}
	}
}