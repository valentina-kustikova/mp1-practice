#include <iostream>
#include <string>
#include "arg.h"

using namespace std;

int main(int argc, char **argv) {
	if (argc < 2) {
		cout << "Incorrect number of arguments" << endl;
		return 1;
	}
	cout << argc << endl << argv[0] << endl << argv[1] << endl << endl;

	string filename = string(argv[1]);
	PersonsLibrary lib(filename);
	lib.SortPersons();
	cout << lib;
	return 0;
}

