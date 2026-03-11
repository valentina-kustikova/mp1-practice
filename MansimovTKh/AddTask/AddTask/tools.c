#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libarg.h"
#include "tools.h"


void print_sort_person(person_info* person, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s | %s | %s | %s | %s | %d | %d | %d | %d | %d | %s | %s | %s | %s | %s|\n\n", person[i].surname,
			person[i].name, person[i].patronymic, person[i].gender, person[i].nation,
			person[i].height, person[i].weight, person[i].day, person[i].month, 
			person[i].year, person[i].number, person[i].index, person[i].country,
			person[i].region_city, person[i].street);
	}
}

void read_data(const char* filename, person_info** person, int* lines) {
	int i, h, w, d, m, y;
	char buffer[BUFFER_SIZE];
	char* s, * n, * p, * g, * nat,
		* str_h, * str_w, * str_d, * str_m, 
		* str_y, * num, * ind, * cou, *cr, *st;
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("error of file\n\n");
		(*person) = NULL; (*lines) = 0;
		return;
	}
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL) (*lines)++;
	(*person) = (person_info*)malloc((*lines) * sizeof(person_info));

	rewind(fp);
	if ((*person) == NULL) {
		printf("ERROR of malloc");
		fclose(fp);
		return;
	}
	for (i = 0; i < (*lines); i++) {
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
			(*person)[i].surname = (char*)malloc((strlen(s) + 1) * sizeof(char));
			(*person)[i].name = (char*)malloc((strlen(n) + 1) * sizeof(char));
			(*person)[i].patronymic = (char*)malloc((strlen(p) + 1) * sizeof(char));
			(*person)[i].gender = (char*)malloc((strlen(g) + 1) * sizeof(char));
			(*person)[i].nation = (char*)malloc((strlen(nat) + 1) * sizeof(char));
			(*person)[i].number = (char*)malloc((strlen(num) + 1) * sizeof(char));
			(*person)[i].index = (char*)malloc((strlen(ind) + 1) * sizeof(char));
			(*person)[i].country = (char*)malloc((strlen(cou) + 1) * sizeof(char));
			(*person)[i].region_city = (char*)malloc((strlen(cr) + 1) * sizeof(char));
			(*person)[i].street = (char*)malloc((strlen(st) + 1) * sizeof(char));

			if ((*person)[i].surname && (*person)[i].name && (*person)[i].patronymic &&
					(*person)[i].gender && (*person)[i].nation && (*person)[i].number && 
					(*person)[i].index && (*person)[i].country && 
					(*person)[i].region_city && (*person)[i].street) {

				strcpy((*person)[i].surname, s); strcpy((*person)[i].name, n); strcpy((*person)[i].patronymic, p);
				strcpy((*person)[i].gender, g); strcpy((*person)[i].nation, nat); strcpy((*person)[i].number, num);
				strcpy((*person)[i].index, ind); strcpy((*person)[i].country, cou); strcpy((*person)[i].region_city, cr);
				strcpy((*person)[i].street, st);

				if ((sscanf(str_w, "%d", &w) == 1) && (sscanf(str_h, "%d", &h) == 1) && (sscanf(str_d, "%d", &d) == 1) &&
					(sscanf(str_m, "%d", &m) == 1) && (sscanf(str_y, "%d", &y) == 1)) {
					(*person)[i].height = h; (*person)[i].weight = w; (*person)[i].day = d; 
					(*person)[i].month = m; (*person)[i].year = y;
				}
				else {
					printf("Error of data field\n\n");
					(*person)[i].height = 0; (*person)[i].weight = 0;
					(*person)[i].day = 0; (*person)[i].month = 0; (*person)[i].year = 0;
				}
			}
		}
		else {
			printf("Error of line %d\n\n", i + 1);
			(*person)[i].surname = NULL; (*person)[i].name = NULL; (*person)[i].patronymic = NULL;
			(*person)[i].gender = NULL; (*person)[i].nation = NULL; (*person)[i].number = NULL; 
			(*person)[i].index = NULL; (*person)[i].country = NULL; (*person)[i].region_city = NULL;
			(*person)[i].street = NULL; (*person)[i].height = 0; (*person)[i].weight = 0;
			(*person)[i].day = 0; (*person)[i].month = 0; (*person)[i].year = 0;
		}
	}
	fclose(fp);
}
