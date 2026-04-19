#define _CRT_SECURE_NO_WARNINGS

#include "auxiliary.h"
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cab_counter(char pathway[], int* cnt) {
	char temp[MAX_SIZE];
	FILE* file_cab = fopen(pathway, "r");
	if (file_cab == NULL) {
		printf("FILE NOT FOUND\n");
		return;
	}
	while (fgets(temp, MAX_SIZE, file_cab) != NULL) (*cnt)++;
	fclose(file_cab);
	if (cnt == 0) {
		printf("NO BOOKS IN CABINET\n");
	}
	return;
}

void cab_reader(int cnt, char pathway[], BOOK _lib[]) {
	int temp_year, i;
	FILE* file_cab = fopen(pathway, "r");
	char temp[MAX_SIZE];
	char* temp_author, * temp_name, * temp_publishing;

	for (i = 0; i < cnt; i++) {
		fgets(temp, MAX_SIZE, file_cab);
		if (temp[strlen(temp) - 1] == '\n') temp[strlen(temp) - 1] = '\0';
		temp_author = strtok(temp, ";");
		temp_name = strtok(0, ";");
		temp_publishing = strtok(0, ";");
		sscanf(strtok(0, ";"), "%d", &temp_year);
		_lib[i].author = (char*)malloc((strlen(temp_author) + 1) * sizeof(char));
		_lib[i].name = (char*)malloc((strlen(temp_name) + 1) * sizeof(char));
		_lib[i].publishing = (char*)malloc((strlen(temp_publishing) + 1) * sizeof(char));
		strcpy(_lib[i].author, temp_author);
		strcpy(_lib[i].name, temp_name);
		strcpy(_lib[i].publishing, temp_publishing);
		_lib[i].year = temp_year;
	}
	fclose(file_cab);

	return;
}

void cab_printer(int au_cnt, BOOK au_lib[]) {
	int i;
	printf("BOOK LIST\n\n");
	for (i = 0; i < au_cnt; i++) {
		printf("|-------------------------------------------------------------------------------------------|\n");
		printf("| ");
		printf("%-15s", au_lib[i].author);
		printf(" | ");
		printf("%-38s", au_lib[i].name);
		printf(" | ");
		printf("%-23s", au_lib[i].publishing);
		printf(" | ");
		printf("%d", au_lib[i].year);
		printf(" |\n");
	}
	printf("|-------------------------------------------------------------------------------------------|\n");
	return;
}