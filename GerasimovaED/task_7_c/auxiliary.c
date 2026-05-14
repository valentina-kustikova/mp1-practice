#include "auxiliary.h"
#include "repertoir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void rep_counter(char* pathway, FilmLibrary* _rep) {
	char temp[MAX_SIZE];
	FILE* file_rep = fopen(pathway, "r");
	if (file_rep == NULL) {
		printf("FILE NOT FOUND\n");
		return;
	}
	while (fgets(temp, MAX_SIZE, file_rep) != NULL) (_rep->cnt)++;
	fclose(file_rep);
	if (_rep->cnt == 0) {
		printf("NO FILMS IN REPERTOIR\n");
	}
	return;
}

void rep_reader(char* pathway, FilmLibrary* _rep) {
	int i, temp_year;
	unsigned int temp_budget, temp_fees;
	FILE* file_rep = fopen(pathway, "r");
	char temp[MAX_SIZE];
	char* temp_name, * temp_director, * temp_country;

	for (i = 0; i < _rep->cnt; i++) {
		fgets(temp, MAX_SIZE, file_rep);
		if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
		temp_name = strtok(temp, ";");
		temp_director = strtok(0, ";");
		temp_country = strtok(0, ";");
		sscanf(strtok(0, ";"), "%d", &temp_year);
		sscanf(strtok(0, ";"), "%d", &temp_budget);
		sscanf(strtok(0, ";"), "%d", &temp_fees);
		_rep->info[i].name = (char*)malloc((strlen(temp_name) + 1) * sizeof(char));
		_rep->info[i].director = (char*)malloc((strlen(temp_director) + 1) * sizeof(char));
		_rep->info[i].country = (char*)malloc((strlen(temp_country) + 1) * sizeof(char));
		strcpy(_rep->info[i].name, temp_name);
		strcpy(_rep->info[i].director, temp_director);
		strcpy(_rep->info[i].country, temp_country);
		_rep->info[i].year = temp_year;
		_rep->info[i].budget = temp_budget;
		_rep->info[i].fees = temp_fees;
	}
	fclose(file_rep);

	return;
}

void rep_printer(FilmLibrary* dir_rep) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	int i;
	printf("FILM LIST\n\n");
	for (i = 0; i < dir_rep->cnt; i++) {
		printf("|---------------------------------------------------------------------------------------------------------------------|\n");
		printf("| ");
		printf("%-38s", dir_rep->info[i].name);
		printf(" | ");
		SetConsoleTextAttribute(console, 0 * 16 + 2);
		printf("%-15s", dir_rep->info[i].director);
		SetConsoleTextAttribute(console, 0 * 16 + 15);
		printf(" | ");
		SetConsoleTextAttribute(console, 0 * 16 + 4);
		printf("%-23s", dir_rep->info[i].country);
		SetConsoleTextAttribute(console, 0 * 16 + 15);
		printf(" | ");
		SetConsoleTextAttribute(console, 0 * 16 + 3);
		printf("%d", dir_rep->info[i].year);
		SetConsoleTextAttribute(console, 0 * 16 + 15);
		printf(" | ");
		printf("%-10u", dir_rep->info[i].budget);
		printf(" | ");
		printf("%-10u", dir_rep->info[i].fees);
		printf(" |\n");
	}
	printf("|---------------------------------------------------------------------------------------------------------------------|\n");
	return;
}