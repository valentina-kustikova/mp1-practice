#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

void read(const char* source, school* sch) {
	FILE* f = fopen(source, "r");
	char buff[1000], * temp;
	int i;
	if (f == NULL) return NULL;
	sch->count = 0;
	while (fgets(buff, 1000, f)) sch->count++;
	fclose(f);
	if (sch->count == 0) return NULL;
	sch->list = (pupil*)malloc(sch->count * sizeof(pupil));
	f = fopen(source, "r");
	for (i = 0; i < sch->count; i++) {
		fgets(buff, 1000, f);
		sch->list[i].surname = _strdup(strtok(buff, " "));
		sch->list[i].name = _strdup(strtok(NULL, " "));
		sch->list[i].fathername = _strdup(strtok(NULL, ";"));
		sch->list[i].klass = _strdup(strtok(NULL, ";"));
		sch->list[i].gen = !strcmp(strtok(NULL, ";"), "Male") ? MAN : WOMAN;
		sch->list[i].date.day = atoi(strtok(NULL, "."));
		sch->list[i].date.month = atoi(strtok(NULL, "."));
		sch->list[i].date.year = atoi(strtok(NULL, ";"));
		strncpy(sch->list[i].home.index, strtok(NULL, ","), 7);
		sch->list[i].home.country = _strdup(strtok(NULL, ","));
		sch->list[i].home.region = _strdup(strtok(NULL, ","));
		sch->list[i].home.district = _strdup(strtok(NULL, ","));
		sch->list[i].home.city = _strdup(strtok(NULL, ","));
		sch->list[i].home.street = _strdup(strtok(NULL, ","));
		sch->list[i].home.house = _strdup(strtok(NULL, ","));
		sch->list[i].home.flat = atoi(strtok(NULL, ","));
		//_________________________________
		//_________________________________
	}
	fclose(f);
}

void print_pupil(pupil s) {
	printf("#___#\n");
	printf("NAME: %s %s %s\n", s.surname, s.name, s.fathername);
	printf("CLASS: %s   GENDER: ", s.klass);
	if (s.gen == MAN) printf("Male");
	else printf("Female");
	printf("\nHOME ADDRESS: %s - %s, %s, %s, %s, %s, %s, %d\n",
		s.home.index, s.home.country, s.home.region, s.home.district, s.home.city, s.home.street, s.home.house, s.home.flat);
	printf("BIRTH DATE: %d.%d.%d\n#___#\n", s.date.day, s.date.month, s.date.year);
}

void school_sort(school* sch) {
	int i, j;
	for (i = 0; i < sch->count - 1; i++) {
		for (j = 0; j < sch->count - i - 1; j++) {
			if (strcmp(sch->list[j].klass, sch->list[j + 1].klass) == 0 &&
				!compare(sch->list + j, sch->list + j + 1)) swap(sch->list + j, sch->list + j + 1);
		}
	}
}

void class_sort(school* sch) {
	int i, j;
	for (i = 0; i < sch->count - 1; i++) {
		for (j = 0; j < sch->count - i - 1; j++) {
			if (strlen(sch->list[j].klass) == 3 && strlen(sch->list[j + 1].klass) == 3) {
				if (sch->list[j].klass[1] == sch->list[j + 1].klass[1]) {
					if (sch->list[j].klass[2] > sch->list[j + 1].klass[2]) swap(sch->list + j + 1, sch->list + j);
				}
				else if (strcmp(sch->list[j].klass, sch->list[j + 1].klass) > 0) swap(sch->list + j + 1, sch->list + j);
			}
			else if (strlen(sch->list[j].klass) == 2 && strlen(sch->list[j + 1].klass) == 2) {
				if (sch->list[j].klass[0] == sch->list[j + 1].klass[0]) {
					if (sch->list[j].klass[1] > sch->list[j + 1].klass[1]) swap(sch->list + j + 1, sch->list + j);
				}
				else if (strcmp(sch->list[j].klass, sch->list[j + 1].klass) > 0) swap(sch->list + j + 1, sch->list + j);
			}
			else if (strcmp(sch->list[j].klass, sch->list[j + 1].klass) < 0) swap(sch->list + j + 1, sch->list + j);
		}
	}
}

int compare(pupil* a, pupil* b) {
	if (strcmp(a->surname, b->surname) != 0) return (strcmp(a->surname, b->surname) < 0);
	else if (strcmp(a->name, b->name) != 0) return (strcmp(a->name, b->name) < 0);
	else return (strcmp(a->fathername, b->fathername) < 0);
}

void swap(pupil* a, pupil* b) {
	pupil t = *a;
	*a = *b;
	*b = t;
}

void sorted_list(school* sch) {
	int i;
	class_sort(sch);
	school_sort(sch);
	printf("###_______________________###\n");
	for (i = 0; i < sch->count; i++) {
		printf("%d) %s %s %s %s ", i + 1,
			sch->list[i].klass, sch->list[i].surname, sch->list[i].name, sch->list[i].fathername);
		if (sch->list[i].gen == MAN) printf("Male");
		else printf("Female");
		printf(" %d.%d.%d\n", sch->list[i].date.day, sch->list[i].date.month, sch->list[i].date.year);
		//print_pupil(sch->list[i]);
	}
	printf("###_______________________###\n");
}

void free_all(school* sch) {
	int i;
	for (i = 0; i < sch->count; i++) {
		free(sch->list[i].home.country);
		free(sch->list[i].home.region);
		free(sch->list[i].home.district);
		free(sch->list[i].home.city);
		free(sch->list[i].home.street);
		free(sch->list[i].home.house);
		free(sch->list[i].name);
		free(sch->list[i].surname);
		free(sch->list[i].fathername);
		free(sch->list[i].klass);
	}
	free(sch->list);
}