#include <iostream>
#include <string>
#include "department.h"
#include "auxdep.h"

using namespace std;


int main(int argc, char** argv) {
	int rows = 0;
	OwnerLib db_lib;
	OwnerLib found_lib;

	if (argc < 2) {
		cout << "Input error." << endl;
		return 1;
	}

	string filename = argv[1];

	int error = database_r(filename, &rows);
	if (error == 1) return 1;

	db_lib.owners = new Owner[rows];
	db_lib.count = rows;

	put_owners_into_array(filename, &db_lib);

	string requested_department;
	cout << "Input the department >> ";
	getline(cin, requested_department);

	find_owners(requested_department, &db_lib, &found_lib);
	print_list(requested_department, &found_lib);

	delete[] found_lib.owners;
	delete[] db_lib.owners;
	return 0;
}