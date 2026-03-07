#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libarg.h"
#include "tools.h"
#define BUFFER_SIZE 1024


void read_data(const char* filename, person_info** person, int* lines) {
	int i, h, w;
	char buffer[BUFFER_SIZE];
	char* s; char* n; char* p; char* g; char* nat; char* str_h; char* str_w; char* b; char* num; char* a;

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
		str_w = strtok(NULL, ";"); b = strtok(NULL, ";"); num = strtok(NULL, ";");
		a = strtok(NULL, ";");

		if (s && n && p && g && nat && str_h && str_w && b && num && a) {
			(*person)[i].surname = (char*)malloc((strlen(s) + 1) * sizeof(char));
			(*person)[i].name = (char*)malloc((strlen(n) + 1) * sizeof(char));
			(*person)[i].patronymic = (char*)malloc((strlen(p) + 1) * sizeof(char));
			(*person)[i].gender = (char*)malloc((strlen(g) + 1) * sizeof(char));
			(*person)[i].nation = (char*)malloc((strlen(nat) + 1) * sizeof(char));
			(*person)[i].birth = (char*)malloc((strlen(b) + 1) * sizeof(char));
			(*person)[i].number = (char*)malloc((strlen(num) + 1) * sizeof(char));
			(*person)[i].address = (char*)malloc((strlen(a) + 1) * sizeof(char));

			if ((*person)[i].surname && (*person)[i].name && (*person)[i].patronymic && (*person)[i].gender && (*person)[i].nation &&
				(*person)[i].birth && (*person)[i].number && (*person)[i].address) {
				strcpy((*person)[i].surname, s); strcpy((*person)[i].name, n); strcpy((*person)[i].patronymic, p);
				strcpy((*person)[i].gender, g); strcpy((*person)[i].nation, nat); strcpy((*person)[i].birth, b);
				strcpy((*person)[i].number, num); strcpy((*person)[i].address, a);

				if ((sscanf(str_w, "%d", &w) == 1) && (sscanf(str_h, "%d", &h) == 1)) {
					(*person)[i].height = h; (*person)[i].weight = w;
				}
				else {
					printf("Error of data field\n\n");
					(*person)[i].height = 0; (*person)[i].weight = 0;
				}
			}
		}
		else {
			printf("Error of line %d\n\n", i + 1);
			(*person)[i].surname = NULL; (*person)[i].name = NULL; (*person)[i].patronymic = NULL;
			(*person)[i].gender = NULL; (*person)[i].nation = NULL; (*person)[i].birth = NULL;
			(*person)[i].number = NULL; (*person)[i].address = NULL; (*person)[i].height = 0; (*person)[i].weight = 0;
		}
	}
	fclose(fp);
}

void print_sort_person(person_info* person, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s | %s | %s | %s | %s | %d | %d | %s | %s | %s\n\n", person[i].surname, person[i].name, person[i].patronymic, person[i].gender, person[i].nation,
			person[i].height, person[i].weight, person[i].birth, person[i].number, person[i].address);
	}
}