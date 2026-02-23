#include <stdio.h>
#include <string.h>
#include "school.h"

int main() {
	school* list;
	int n;
	char klass[50], name[1000];
	do {
		printf("Insert File name: ");
		scanf("%s", name);
		list = read(strcat(name, ".txt"), &n);
		if (list == NULL) printf("Empty or Incorrect File! Please try again\n");
	} while (list == NULL);
	printf("Success!\n");
	do {
		printf("Insert class which list is needed to be shown (or \"exit\" to stop): ");
		scanf("%s", klass);
		if (strcmp(klass, "exit") == 0) break;
		list_class(klass, list, n);
	} while (1);
	return 0;
}