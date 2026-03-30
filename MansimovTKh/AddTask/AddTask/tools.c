#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libarg.h"
#include "tools.h"


void print_sort_person(PersonsLibrary* lib_persons) {
	if (lib_persons == NULL || lib_persons->persons == NULL) return;
	int i;
	for (i = 0; i < lib_persons->count; i++) {
		printf("%s | %s | %s | ", lib_persons->persons[i].full_name.surname, 
			lib_persons->persons[i].full_name.name, lib_persons->persons[i].full_name.patronymic);

		if (lib_persons->persons[i].gender == male) printf("Male | ");
		else if (lib_persons->persons[i].gender == female) printf("Female | ");

		printf("%s | %d | %d | %d | %d | %d | %s | %s | %s | %s | %s|\n\n", 
			lib_persons->persons[i].nation, lib_persons->persons[i].height, 
			lib_persons->persons[i].weight, lib_persons->persons[i].date_of_birth.day, 
			lib_persons->persons[i].date_of_birth.month, lib_persons->persons[i].date_of_birth.year, 
			lib_persons->persons[i].number, lib_persons->persons[i].address.index,
			lib_persons->persons[i].address.country, lib_persons->persons[i].address.region_city, 
			lib_persons->persons[i].address.street);
	}
}

void read_data(const char* filename, PersonsLibrary* lib_persons) {
	int i, h, w, d, m, y;
	char buffer[BUFFER_SIZE];
	char* s, * n, * p, * g, * nat,
		* str_h, * str_w, * str_d, * str_m, 
		* str_y, * num, * ind, * cou, *cr, *st;
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("error of file\n\n");
		lib_persons->persons = NULL; lib_persons->count = 0;
		return;
	}
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL) (lib_persons->count)++;
	(lib_persons -> persons) = (PersonInfo*)malloc((lib_persons->count) * sizeof(PersonInfo));

	rewind(fp);
	if ((lib_persons->persons) == NULL) {
		printf("ERROR of malloc");
		fclose(fp);
		return;
	}
	for (i = 0; i < (lib_persons->count); i++) {
		fgets(buffer, BUFFER_SIZE, fp);
		if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n') {
			buffer[strlen(buffer) - 1] = '\0';
		}
		s = strtok(buffer, ";"); n = strtok(NULL, ";"); p = strtok(NULL, ";");
		g = strtok(NULL, ";"); nat = strtok(NULL, ";"); str_h = strtok(NULL, ";");
		str_w = strtok(NULL, ";"); str_d = strtok(NULL, ";"); str_m = strtok(NULL, ";");
		str_y = strtok(NULL, ";"); num = strtok(NULL, ";"); ind = strtok(NULL, ";");
		cou = strtok(NULL, ";"); cr = strtok(NULL, ";"); st = strtok(NULL, ";");

		if (s && n && p && g && nat && str_h &&
			str_w && str_m && str_d && str_y &&
			num && ind && cou && cr && st) {
			(lib_persons->persons)[i].full_name.surname = (char*)malloc((strlen(s) + 1) * sizeof(char));
			(lib_persons->persons)[i].full_name.name = (char*)malloc((strlen(n) + 1) * sizeof(char));
			(lib_persons->persons)[i].full_name.patronymic = (char*)malloc((strlen(p) + 1) * sizeof(char));
			(lib_persons->persons)[i].nation = (char*)malloc((strlen(nat) + 1) * sizeof(char));
			(lib_persons->persons)[i].number = (char*)malloc((strlen(num) + 1) * sizeof(char));
			(lib_persons->persons)[i].address.index = (char*)malloc((strlen(ind) + 1) * sizeof(char));
			(lib_persons->persons)[i].address.country = (char*)malloc((strlen(cou) + 1) * sizeof(char));
			(lib_persons->persons)[i].address.region_city = (char*)malloc((strlen(cr) + 1) * sizeof(char));
			(lib_persons->persons)[i].address.street = (char*)malloc((strlen(st) + 1) * sizeof(char));

			if ((lib_persons->persons)[i].full_name.surname && (lib_persons->persons)[i].full_name.name && 
					(lib_persons->persons)[i].full_name.patronymic &&
					(lib_persons->persons)[i].nation && (lib_persons->persons)[i].number &&
					(lib_persons->persons)[i].address.index && (lib_persons->persons)[i].address.country &&
					(lib_persons->persons)[i].address.region_city && (lib_persons->persons)[i].address.street) {

				strcpy((lib_persons->persons)[i].full_name.surname, s); strcpy((lib_persons->persons)[i].full_name.name, n);
				strcpy((lib_persons->persons)[i].full_name.patronymic, p); strcpy((lib_persons->persons)[i].nation, nat);
				strcpy((lib_persons->persons)[i].number, num); strcpy((lib_persons->persons)[i].address.index, ind);
				strcpy((lib_persons->persons)[i].address.country, cou); strcpy((lib_persons->persons)[i].address.region_city, cr);
				strcpy((lib_persons->persons)[i].address.street, st);

				if (strcmp("Male", g) == 0) (lib_persons->persons)[i].gender = male;
				else if (strcmp("Female", g) == 0) (lib_persons->persons)[i].gender = female;
				else (lib_persons->persons)[i].gender = unknown;

				if ((sscanf(str_w, "%d", &w) == 1) && (sscanf(str_h, "%d", &h) == 1) && (sscanf(str_d, "%d", &d) == 1) &&
					(sscanf(str_m, "%d", &m) == 1) && (sscanf(str_y, "%d", &y) == 1)) {
					(lib_persons->persons)[i].height = h; (lib_persons->persons)[i].weight = w; (lib_persons->persons)[i].date_of_birth.day = d;
					(lib_persons->persons)[i].date_of_birth.month = m; (lib_persons->persons)[i].date_of_birth.year = y;
				}
				else {
					printf("Error of data field\n\n");
					(lib_persons->persons)[i].height = 0; (lib_persons->persons)[i].weight = 0;
					(lib_persons->persons)[i].date_of_birth.day = 0; (lib_persons->persons)[i].date_of_birth.month = 0;
					(lib_persons->persons)[i].date_of_birth.year = 0;
				}
			}
		}
		else {
			printf("Error of line %d\n\n", i + 1);
			(lib_persons->persons)[i].full_name.surname = NULL; (lib_persons->persons)[i].full_name.name = NULL;
			(lib_persons->persons)[i].full_name.patronymic = NULL; (lib_persons->persons)[i].gender = unknown;
			(lib_persons->persons)[i].nation = NULL; (lib_persons->persons)[i].number = NULL;
			(lib_persons->persons)[i].address.index = NULL; (lib_persons->persons)[i].address.country = NULL;
			(lib_persons->persons)[i].address.region_city = NULL; (lib_persons->persons)[i].address.street = NULL;
			(lib_persons->persons)[i].height = 0; (lib_persons->persons)[i].weight = 0; 
			(lib_persons->persons)[i].date_of_birth.day = 0; (lib_persons->persons)[i].date_of_birth.month = 0; 
			(lib_persons->persons)[i].date_of_birth.year = 0;
		}
	}
	fclose(fp);
}

void free_persons_lib(PersonsLibrary* lib_persons) {
	int i;
	if (lib_persons == NULL || lib_persons->persons == NULL) return;
	for (i = 0; i < lib_persons->count; i++) {
		free(lib_persons->persons[i].full_name.surname); free(lib_persons->persons[i].full_name.name); free(lib_persons->persons[i].full_name.patronymic);
		free(lib_persons->persons[i].nation); free(lib_persons->persons[i].number); free(lib_persons->persons[i].address.index);
		free(lib_persons->persons[i].address.country); free(lib_persons->persons[i].address.region_city); free(lib_persons->persons[i].address.street);
	}
	free(lib_persons->persons);

}
