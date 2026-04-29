#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int numberLines(const char* filename) {
	char buff[MAX_BUFF];
	int count = 0;
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("mistake");
		return 1;
	}
	while (1) {

		if (fgets(buff, sizeof(buff), file)) {
			count++;
		}
		else break;
	}
	fclose(file);
	return count;
}



void readFile(PersonsLibrary info, const char* filename) {
	char buff[MAX_BUFF], temp2[MAX_BUFF], temp3[MAX_BUFF];
	char* temp;
	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		printf("Error opening file\n");
		return;
	}

	for (int i = 0; i < info.count; i++) {
		if (fgets(buff, sizeof(buff), file) == NULL) break;
		buff[strcspn(buff, "\n")] = 0;

		temp = strtok(buff, ";");
		strcpy(temp2, temp);

		temp = strtok(NULL, ";");
		if (temp) {
			if (strcmp(temp, "M") == 0) {
				info.array[i].gender = M;
			}
			else if (strcmp(temp, "F") == 0) {
				info.array[i].gender = F;
			}
		}

		temp = strtok(NULL, ";");
		strcpy(temp3, temp);

		temp = strtok(NULL, ";");
		strcpy(info.array[i].country, temp);

		temp = strtok(NULL, ";");
		strcpy(info.array[i].city, temp);

		temp = strtok(NULL, ";");
		if (temp) {
			if (strcmp(temp, "Athletics") == 0) info.array[i].sport = Athletics;
			else if (strcmp(temp, "Weightlifting") == 0) info.array[i].sport = Weightlifting;
			else if (strcmp(temp, "Boxing") == 0) info.array[i].sport = Boxing;
			else if (strcmp(temp, "Tennis") == 0) info.array[i].sport = Tennis;
			else if (strcmp(temp, "Football") == 0) info.array[i].sport = Football;
			else info.array[i].sport = Unknown;
		}

		temp = strtok(NULL, ";");
		strcpy(info.array[i].club, temp);

		temp = strtok(NULL, ";");
		strcpy(info.array[i].discipline, temp);

		temp = strtok(NULL, ";");
		info.array[i].record = atof(temp);


		if (temp2) {
			printf("1 %s\n", temp2);
			strcpy(info.array[i].name.last_name, strtok(temp2, " "));
			strcpy(info.array[i].name.first_name, strtok(NULL, " "));

		}


		if (temp3) {
			sscanf(temp3, "%d-%d-%d",
				&info.array[i].date_of_birth.year,
				&info.array[i].date_of_birth.month,
				&info.array[i].date_of_birth.day);
		}
	}

	fclose(file);
}





Sport convertSport(char* input_sport) {
	Sport target_sport;
	if (strcmp(input_sport, "Athletics") == 0) target_sport = Athletics;
	else if (strcmp(input_sport, "Weightlifting") == 0) target_sport = Weightlifting;
	else if (strcmp(input_sport, "Boxing") == 0) target_sport = Boxing;
	else if (strcmp(input_sport, "Tennis") == 0) target_sport = Tennis;
	else if (strcmp(input_sport, "Football") == 0) target_sport = Football;
	else return target_sport = Unknown;
	return target_sport;
}



void findRecord(PersonsLibrary info, char* input_sport, BestEntry** result, int* countResult) {

	int entry_count = 0;
	Sport target_sport = convertSport(input_sport);
	BestEntry* entries = malloc(info.count * sizeof(BestEntry));


	for (int i = 0; i < info.count; i++) {
		if (info.array[i].sport == target_sport) {
			int found_idx = -1;
			for (int j = 0; j < entry_count; j++) {
				if (strcmp(entries[j].discipline, info.array[i].discipline) == 0) {
					found_idx = j;
					break;
				}
			}
			if (found_idx == -1) strcpy(entries[entry_count++].discipline, info.array[i].discipline);
		}
	}
	printf("total disciplines - %d\n", entry_count);


	*countResult = entry_count;
	*result = (BestEntry*)malloc(*countResult * sizeof(BestEntry));;

	for (int i = 0; i < entry_count; i++) {
		(*result)[i].best_record = 0;
		for (int j = 0; j < info.count; j++) {
			if (strcmp(entries[i].discipline, info.array[j].discipline) == 0) {
				strcpy((*result)[i].discipline, info.array[j].discipline);
				if (info.array[j].record > (*result)[i].best_record) {
					(*result)[i].best_record = info.array[j].record;
					(*result)[i].best_index = j;
				}
			}
		}
	}
	free(entries);
}


void printResult(PersonsLibrary info, BestEntry* result, int countResult) {
	if (countResult == 0) {
		printf("Uncorrect sport \n");
	}
	else {
		for (int i = 0; i < countResult; i++) {
			Person* p = &info.array[result[i].best_index];
			printf("\nDiscipline: %s\n", p->discipline);
			printf("Name: %s %s\n", p->name.first_name, p->name.last_name);
			printf("Record: %.2f\n", p->record);
			printf("Country: %s\n", p->country);
			printf("Club: %s\n", p->club);
		}
	}
}