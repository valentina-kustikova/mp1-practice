#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libarg.h"
#include "tools.h"

int main(int argc, char **argv) {
	PersonsLibrary* lib = NULL;

	if (argc < 2) {
		printf("Incorrect number of arguments\n"); return 1;
	}
	printf("%d\n %s\n %s\n\n", argc, argv[0], argv[1]);

	lib = (PersonsLibrary*)malloc(sizeof(PersonsLibrary));
	lib->count = 0; lib->persons = NULL;
	read_data(argv[1], lib);

	sort_person(lib);
	print_sort_person(lib);

	free_persons_lib(lib);
	free(lib);

	return 0;
}