#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libarg.h"
#include "tools.h"
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
	int lines = 0, i;
	person_info* person = NULL;

	if (argc < 2) {
		printf("Incorrect number of arguments\n"); return 1;
	}
	printf("%d\n %s\n %s\n\n", argc, argv[0], argv[1]);

	read_data("Data.txt", &person, &lines);
	sort_person(person, lines);
	print_sort_person(person, lines);

	for (i = 0; i < lines; i++) {
		free(person[i].surname); free(person[i].name); free(person[i].patronymic);
		free(person[i].gender); free(person[i].nation); free(person[i].birth);
		free(person[i].number); free(person[i].address);
	}

	free(person);
	return 0;
}