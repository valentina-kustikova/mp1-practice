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



void readFile(int count, Person* array, const char* filename) {
	char buff[MAX_BUFF], temp2[MAX_BUFF], temp3[MAX_BUFF];
	char* temp;
	FILE* file = fopen(filename, "r");
	
	if (file == NULL) {
		printf("Error opening file\n");
		return;
	}
	
	for (int i = 0; i < count; i++) {
		if (fgets(buff, sizeof(buff), file) == NULL) break;
		buff[strcspn(buff, "\n")] = 0;

		temp = strtok(buff, ";");
		strcpy(temp2, temp);

		temp = strtok(NULL, ";");
		if (temp) {
			if (strcmp(temp, "M") == 0) {
				array[i].gender = M;
			}
			else if (strcmp(temp, "F") == 0) {
				array[i].gender = F;
			}
		}

		temp = strtok(NULL, ";");
		strcpy(temp3, temp);

		temp = strtok(NULL, ";");
		strcpy(array[i].country, temp);

		temp = strtok(NULL, ";");
		strcpy(array[i].city, temp);

		temp = strtok(NULL, ";");
		if (temp) {
			if (strcmp(temp, "Athletics") == 0) array[i].sport = Athletics;
			else if (strcmp(temp, "Weightlifting") == 0) array[i].sport = Weightlifting;
			else if (strcmp(temp, "Boxing") == 0) array[i].sport = Boxing;
			else if (strcmp(temp, "Tennis") == 0) array[i].sport = Tennis;
			else if (strcmp(temp, "Football") == 0) array[i].sport = Football;
			else array[i].sport = Unknown;
		}

		temp = strtok(NULL, ";");
		strcpy(array[i].club, temp);

		temp = strtok(NULL, ";");
		strcpy(array[i].discipline, temp);

		temp = strtok(NULL, ";");
		array[i].record = atof(temp);


		if (temp2) {
			printf("1 %s\n", temp2);
			strcpy(array[i].name.last_name, strtok(temp2, " "));
			strcpy(array[i].name.first_name, strtok(NULL, " "));

		}


		if (temp3) {
			sscanf(temp3, "%d-%d-%d",
				&array[i].date_of_birth.year,
				&array[i].date_of_birth.month,
				&array[i].date_of_birth.day);
		}
	}

	fclose(file);
}









void findRecord(Person* array, int count, char* input_sport) {

	typedef struct {
		char discipline[MAX_LEN];
		int best_index;
		float best_record;
	} BestEntry;
	int entry_count = 0;

	BestEntry* entries = malloc(count * sizeof(BestEntry));
	Sport target_sport;
	if (strcmp(input_sport, "Athletics") == 0) target_sport = Athletics;
	else if (strcmp(input_sport, "Weightlifting") == 0) target_sport = Weightlifting;
	else if (strcmp(input_sport, "Boxing") == 0) target_sport = Boxing;
	else if (strcmp(input_sport, "Tennis") == 0) target_sport = Tennis;
	else if (strcmp(input_sport, "Football") == 0) target_sport = Football;
	else {
		printf("Uncorrect sport \n");
		return;
	}

	for (int i = 0; i < count; i++) {
		if (array[i].sport == target_sport) {
			int found_idx = -1;
			for (int j = 0; j < entry_count; j++) {
				if (strcmp(entries[j].discipline, array[i].discipline) == 0) {
					found_idx = j;
					break;
				}
			}

			if (found_idx == -1) {
				strcpy(entries[entry_count].discipline, array[i].discipline);
				entries[entry_count].best_index = i;
				entries[entry_count].best_record = array[i].record;
				entry_count++;
			}
			else {
				if (array[i].record > entries[found_idx].best_record) {
					entries[found_idx].best_record = array[i].record;
					entries[found_idx].best_index = i;
				}
			}
		}
	}


	if (entry_count == 0) {
		printf("Uncorrect sport \n");
	}
	else {
		printf("\nBest records in sport: %s\n", input_sport);
		for (int i = 0; i < entry_count; i++) {
			Person* p = &array[entries[i].best_index];
			printf("\nDiscipline: %s\n", p->discipline);
			printf("Name: %s %s\n", p->name.first_name, p->name.last_name);
			printf("Record: %.2f\n", p->record);
			printf("Country: %s\n", p->country);
			printf("Club: %s\n", p->club);
		}
	}

	free(entries);
}