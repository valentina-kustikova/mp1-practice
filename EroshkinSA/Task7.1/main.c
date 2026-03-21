#include <stdio.h>
#include <string.h>
#include "school.h"

int main(int argc, char** argv) {
	school sch;
	if (argc < 2) {
		printf("Incorrect parameters!");
		return 1;
	}
	do {
		read(argv[1], &sch);
		if (sch.list == NULL) printf("Empty or Incorrect File! Please try again\n");
	} while (sch.list == NULL);
	sorted_list(&sch);
	free_all(&sch);
	return 0;
}