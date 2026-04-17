#define _CRT_SECURE_NO_WARNINGS

#include "auxiliary.h"
#include "repertoir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rep_counter(char pathway[], int* cnt) {
	char temp[MAX_SIZE];
	FILE* file_rep = fopen(pathway, "r");

	if (file_rep == NULL) {
		printf("FILE NOT FOUND\n");
		return 1;
	}
	while (fgets(temp, MAX_SIZE, file_rep) != NULL) (*cnt)++;
	fclose(file_rep);
	if (cnt == 0) {
		printf("NO FILMS IN REPERTOIR\n");
		return 1;
	}

	return 0;
}

void rep_reader(int cnt, char pathway[], FILM _rep[]) {
	int i, temp_year;
	unsigned int temp_budget, temp_fees;
	FILE* file_rep = fopen(pathway, "r");
	char temp[MAX_SIZE];
	char* temp_name, * temp_director, * temp_country;

	for (i = 0; i < cnt; i++) {
		fgets(temp, MAX_SIZE, file_rep);
		if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
		temp_name = strtok(temp, ";");
		temp_director = strtok(0, ";");
		temp_country = strtok(0, ";");
		sscanf(strtok(0, ";"), "%d", &temp_year);
		sscanf(strtok(0, ";"), "%d", &temp_budget);
		sscanf(strtok(0, ";"), "%d", &temp_fees);
		_rep[i].name = (char*)malloc((strlen(temp_name) + 1) * sizeof(char));
		_rep[i].director = (char*)malloc((strlen(temp_director) + 1) * sizeof(char));
		_rep[i].country = (char*)malloc((strlen(temp_country) + 1) * sizeof(char));
		strcpy(_rep[i].name, temp_name);
		strcpy(_rep[i].director, temp_director);
		strcpy(_rep[i].country, temp_country);
		_rep[i].year = temp_year;
		_rep[i].budget = temp_budget;
		_rep[i].fees = temp_fees;
	}
	fclose(file_rep);

	return;
}

void rep_printer(int dir_cnt, FILM dir_rep[]) {
	int i;
	printf("FILM LIST\n\n");
	for (i = 0; i < dir_cnt; i++) {
		printf("|----------------------------------------------------------------------------------------------------------------------|\n");
		printf("| ");
		printf("%-38s", dir_rep[i].name);
		printf(" | ");
		printf("%-15s", dir_rep[i].director);
		printf(" | ");
		printf("%-23s", dir_rep[i].country);
		printf(" | ");
		printf("%d", dir_rep[i].year);
		printf(" | ");
		printf("%-10u", dir_rep[i].budget);
		printf(" | ");
		printf("%-10u", dir_rep[i].fees);
		printf(" |\n");
	}
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
	return;
}