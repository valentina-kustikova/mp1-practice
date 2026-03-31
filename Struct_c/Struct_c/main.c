#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Athletes {
	char name[MAX_LEN];
	char gender[MAX_LEN];
	char date_of_birth[MAX_LEN];
	char country[MAX_LEN];
	char city[MAX_LEN];
	char sport[MAX_LEN];
	char club[MAX_LEN];
	char discipline[MAX_LEN];
	float record;
} Person;

int numberLines(const char* filename);
void readFile(int count, Person* array, const char* filename);
void findRecord(Person* array, int count, const char* input);

int main() {
	char input[1024];
	int count;
	//Person* array;
	count = numberLines("athletes.txt");

	if (count <= 0) {
		printf("Mistake with counting");
		return 1;
	}

	Person* array = (Person*)malloc(count * sizeof(Person));
	if (!array) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	readFile(count, array, "athletes.txt");

	printf("Enter name of sport\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;

	findRecord(array, count, input);

	free(array);
	return 0;
}





int numberLines(const char* filename) {
	char buff[1024];
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
	char buff[2048];
	FILE* file = fopen(filename, "r");

	for (int i = 0; i < count; i++) {
		fgets(buff, sizeof(buff), file);
		buff[strcspn(buff, "\n")] = 0;
		strcpy(array[i].name, strtok(buff, ";"));
		strcpy(array[i].gender, strtok(NULL, ";"));
		strcpy(array[i].date_of_birth, strtok(NULL, ";"));
		strcpy(array[i].country, strtok(NULL, ";"));
		strcpy(array[i].city, strtok(NULL, ";"));
		strcpy(array[i].sport, strtok(NULL, ";"));
		strcpy(array[i].club, strtok(NULL, ";"));
		strcpy(array[i].discipline, strtok(NULL, ";"));
		array[i].record = atof(strtok(NULL, ";"));
		//printf("%d %s\n",i+1, array[i].name);
	}
	fclose(file);
}









void findRecord(Person* array, int count, const char* input_sport) {

	typedef struct {
		char discipline[MAX_LEN];
		int best_index;
		float best_record;
	} BestEntry;
	int entry_count = 0;

	BestEntry* entries = malloc(count * sizeof(BestEntry));


	for (int i = 0; i < count; i++) {
		if (strstr(array[i].sport, input_sport) != NULL) {
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
			printf("Name: %s\n", p->name);
			printf("Record: %.2f\n", p->record);
			printf("Country: %s\n", p->country);
			printf("Club: %s\n", p->club);
		}
	}

	free(entries);
}