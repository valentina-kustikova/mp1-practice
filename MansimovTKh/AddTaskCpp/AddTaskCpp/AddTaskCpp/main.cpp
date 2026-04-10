#include <iostream>
#include "arg.h"

using namespace std;

int main(int argc, char **argv) {
	PersonsLibrary* lib = nullptr;

	if (argc < 2) {
		printf("Incorrect number of arguments\n"); return 1;
	}
	printf("%d\n %s\n %s\n\n", argc, argv[0], argv[1]);

	lib = new PersonsLibrary(string(argv[1]));
	lib->SortPersons();
	cout << *lib;

	delete lib;

	return 0;
}

