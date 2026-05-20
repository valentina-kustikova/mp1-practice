#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "auxdep.h"

using namespace std;


int database_r(string filename, int* rows) {
	ifstream f(filename);
	if (!f.is_open()) {
		cout << "Error opening the file.\n" << endl;
		return 1;
	}
	cout << "The database found." << endl << endl;
	string s;
	while (getline(f, s)) {
		(*rows)++;
	}
	f.close();
	return 0;
}

void put_owners_into_array(string filename, OwnerLib* db) {
	int i;
	ifstream f(filename);
	string s;
	string sn, nm, pn, y, m, d, auto_n, pass_n, phone_n, dep;
	
	for (i = 0; i < db->count; i++) {
		getline(f, s);
		stringstream ss(s);

		getline(ss, sn, ' ');
		getline(ss, nm, ' ');
		getline(ss, pn, ';');

		db->owners[i].full_name.surname = sn;
		db->owners[i].full_name.name = nm;
		db->owners[i].full_name.patronymic = pn;

		getline(ss, y, '-');
		getline(ss, m, '-');
		getline(ss, d, ';');

		unsigned long ul_tmp = stoul(y);
		db->owners[i].birth_date.year = static_cast<unsigned int>(ul_tmp);
		ul_tmp = stoul(m);
		db->owners[i].birth_date.month = static_cast<unsigned int>(ul_tmp);
		ul_tmp = stoul(d);
		db->owners[i].birth_date.day = static_cast<unsigned int>(ul_tmp);

		getline(ss, auto_n, ';');
		getline(ss, pass_n, ';');
		getline(ss, phone_n, ';');
		getline(ss, dep, '\n');

		db->owners[i].auto_number = auto_n;
		db->owners[i].pass_number = pass_n;
		db->owners[i].phone_number = phone_n;
		db->owners[i].department = dep;
	}
	f.close();
}

void print_list(string requested_department, OwnerLib* found) {
	int i;
	if (found->count == 0) {
		cout << "There is no owners in " << requested_department << "." << endl << endl;
	}
	else {
		cout << "There is " << found->count << " owners in " << requested_department << "." << endl << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "FULL NAME, BIRTH DATE, AUTO NUMBER, PASS NUMBER, PHONE NUMBER, DEPARTMENT" << endl;
		cout << "-------------------------------------------------------------------------" << endl;

		for (i = 0; i < found->count; i++) {
			cout << found->owners[i] << endl;
		}
	}
}