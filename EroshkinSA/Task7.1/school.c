#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

school* read(const char* source, int* n) {
	FILE* f = fopen(source, "r");
	char buff[1000], * temp;
	int i, count = 0;
	school* list;
	if (f == NULL) return NULL;
	while (fgets(buff, 1000, f)) count++;
	fclose(f);
	*n = count;
	if (n == 0) return NULL;
	list = (school*)malloc(count * sizeof(school));
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

void school_sort(school* list, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (strcmp(list[j].klass, list[j + 1].klass) == 0 && strcmp(list[j].name, list[j + 1].name) > 0) swap(list + j, list + j + 1);
		}
	}
}

void class_sort(school* list, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		j = i + 1;
		while (j != n && strcmp(list[j].klass, list[i].klass) != 0) j++;
		if (j == n) continue;
		swap(list + i + 1, list + j);
	}
}

void swap(school* a, school* b) {
	school t = *a;
	*a = *b;
	*b = t;
}

void sorted_list(school* list, int n) {
	int i;
	class_sort(list, n);
	school_sort(list, n);
	printf("###_______________________###\n");
	for (i = 0; i < n; i++) printf("%d) %s %s %s %d.%d.%d\n", i + 1,
		list[i].klass, list[i].name, list[i].gen, list[i].date.day, list[i].date.month, list[i].date.year);
	printf("###_______________________###\n");
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