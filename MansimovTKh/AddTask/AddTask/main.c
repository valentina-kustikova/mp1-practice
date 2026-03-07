#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libarg.h"
#include "tools.h"
#define BUFFER_SIZE 1024

int main() {
	int lines = 0, i;
	person_info* person = NULL;

	read_data("Data.txt", &person, &lines);
	/*for (i=0; i<lines; i++)
	{
		printf(" %s %s %s %s %s %d %d %s %s %s", person[i].surname, person[i].name, person[i].patronymic,
			person[i].gender, person[i].nation, person[i].height, person[i].weight, person[i].birth, person[i].number, person[i].address);
	}*/
	/*for (i = 0; i < lines; i++) {
		printf(" %s\n", person[i].surname);
	}*/
	/*printf("\n\n");*/
	sort_person(person, lines);
	/*for (i = 0; i < lines; i++) {
		printf(" %s\n", person[i].surname);
	}*/
	print_sort_person(person, lines);

	for (i = 0; i < lines; i++) {
		free(person[i].surname); free(person[i].name); free(person[i].patronymic);
		free(person[i].gender); free(person[i].nation); free(person[i].birth);
		free(person[i].number); free(person[i].address);
	}

	free(person);
	return 0;
}