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
		list = read(argv[1], &n);
		if (list == NULL) printf("Empty or Incorrect File! Please try again\n");
	} while (list == NULL);
	sorted_list(list, n);
	free_all(list, n);
	return 0;
}