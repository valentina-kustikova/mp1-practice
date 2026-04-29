#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


int main(int argc, char** argv) {
	char input[MAX_BUFF];
	char* filename;
  PersonsLibrary info;

  BestEntry* result;
  int countResult;

	if (argc < 2) {
		printf("incorrect number of argc");
		return 1;
	}
	filename = argv[1];

  info.count = numberLines(filename);
	if (info.count <= 0) {
		printf("Mistake with counting");
		return 1;
	}

  info.array = (Person*)malloc(info.count * sizeof(Person));
	if (!info.array) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	readFile(info, filename);

	printf("Enter name of sport\n");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;


	findRecord(info, input, &result, &countResult);
	printResult(info, result, countResult);
	free(info.array);
	free(result);
	return 0;
}