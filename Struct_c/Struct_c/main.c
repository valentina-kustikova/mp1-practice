#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"




int main(int argc, char **argv) {
	char input[1024];
	char* filename;
	int count;
	if (argc < 2) {
		printf("incorrect number of argc");
		return 1;
	}
	filename = argv[1];

	count = numberLines(filename);

	if (count <= 0) {
		printf("Mistake with counting");
		return 1;
	}

	Person* array = (Person*)malloc(count * sizeof(Person));
	if (!array) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	readFile(count, array, filename);

	printf("Enter name of sport\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;

	findRecord(array, count, input);

	free(array);
	return 0;
}
