#include <stdio.h>
#include <string.h>
#include "school.h"

int main(int argc, char** argv) {
	school* list;
	int n;
	char klass[50], name[1000];
	if (argc < 2) {
		printf("Incorrect parameters!");
		return 1;
	}
	do {
		printf("Insert File name: ");
		scanf("%s", name);
		list = read(argv[1], &n);
		if (list == NULL) printf("Empty or Incorrect File! Please try again\n");
	} while (list == NULL);
	printf("Success!\n");
	do {
		printf("Insert class which list is needed to be shown (or \"exit\" to stop): ");
		scanf("%s", klass);
		if (strcmp(klass, "exit") == 0) break;
		list_class(klass, list, n);
	} while (1);
	free_all(list, n);
	return 0;
}