#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

int f = 0;

extern school* read(const char* source, int* n) {
	FILE* f = fopen(source, "r");
	if (f == NULL) return NULL;
	char buff[1000], *temp;
	int i, count = 0;
	while (fgets(buff, 1000, f)) count++;
	fclose(f);
	*n = count;
	if (n == 0) return NULL;
	school* list = (school*)malloc(count * sizeof(school));
	f = fopen(source, "r");
	for (i = 0; i < count; i++) {
		fgets(buff, 1000, f);
		list[i].name = _strdup(strtok(buff, ";"));
		list[i].klass = _strdup(strtok(NULL, ";"));
		list[i].gen = _strdup(strtok(NULL, ";"));
		temp = strtok(NULL, ";");
		list[i].home.index = atoi(strtok(NULL, ","));
		list[i].home.country = _strdup(strtok(NULL, ","));
		list[i].home.region = _strdup(strtok(NULL, ","));
		list[i].home.district = _strdup(strtok(NULL, ","));
		list[i].home.city = _strdup(strtok(NULL, ","));
		list[i].home.street = _strdup(strtok(NULL, ","));
		list[i].home.house = _strdup(strtok(NULL, ","));
		list[i].home.flat = atoi(strtok(NULL, ","));
		//_________________________________
		//_________________________________
		list[i].date.day = atoi(strtok(temp, "."));
		list[i].date.month = atoi(strtok(NULL, "."));
		list[i].date.year = atoi(strtok(NULL, "."));
	}
	fclose(f);
	return list;
}

void print_school(school s) {
	printf("#___#\n");
	printf("NAME: %s\n", s.name);
	printf("CLASS: %s   GENDER: %s\nHOME ADDRESS: %d - %s, %s, %s, %s, %s, %s, %d\n", s.klass, s.gen,
		s.home.index, s.home.country, s.home.region, s.home.district, s.home.city, s.home.street, s.home.house, s.home.flat);
	printf("BIRTH DATE: %d.%d.%d\n#___#\n", s.date.day, s.date.month, s.date.year);
}

static void school_sort(school* list, int n) {
	if (f) return;
	f = 1;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (strcmp(list[j].name, list[j + 1].name) > 0) swap(list + j, list + j + 1);
		}
	}
}

static void swap(school* a, school* b) {
	school t = *a;
	*a = *b;
	*b = t;
}

void list_class(char* klass, school* list, int n) {
	school_sort(list, n);
	int i, pos = 1;
	printf("###_______CLASS %s_______###\n", klass);
	for (i = 0; i < n; i++) if (strcmp(klass, list[i].klass) == 0) print(list[i], pos++);
	if (pos == 1) printf("This class is empty right now\n");
	printf("###_______________________###\n");
}

static print(school s, int n) {
	printf("%d) %s %s %d.%d.%d\n", n, s.name, s.gen, s.date.day, s.date.month, s.date.year);
}

void free_all(school* list, int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(list[i].home.country);
		free(list[i].home.region);
		free(list[i].home.district);
		free(list[i].home.city);
		free(list[i].home.street);
		free(list[i].home.house); 
		free(list[i].name);
		free(list[i].klass);
		free(list[i].gen);
	}
	free(list);
}