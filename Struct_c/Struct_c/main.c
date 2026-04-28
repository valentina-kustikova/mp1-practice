#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


int main(int argc, char** argv) {
	char input[MAX_BUFF];
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
	PersonsLibrary info;
	info.array = array;
	info.count = count;

	readFile(info, filename);

	printf("Enter name of sport\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;

	BestEntry* result;
	int countResult;

	findRecord(info, input, &result, &countResult);
	printResult(info, result, countResult);
	free(array);
	free(result);
	return 0;
}