#include <iostream>
#include <string>
#include "department.h"

using namespace std;


void find_owners(string requested_department, OwnerLib* db, OwnerLib* found) {
	found->count = 0;
	for (int i = 0; i < db->count; i++) {
		if (db->owners[i].department == requested_department) {
			found->count++;
		}
	}

	found->owners = new Owner[found->count];
	int j = 0;
	for (int i = 0; i < db->count; i++) {
		if (db->owners[i].department == requested_department) {
			found->owners[j].full_name.surname = db->owners[i].full_name.surname;
			found->owners[j].full_name.name = db->owners[i].full_name.name;
			found->owners[j].full_name.patronymic = db->owners[i].full_name.patronymic;

			found->owners[j].birth_date.day = db->owners[i].birth_date.day;
			found->owners[j].birth_date.month = db->owners[i].birth_date.month;
			found->owners[j].birth_date.year = db->owners[i].birth_date.year;

			found->owners[j].auto_number = db->owners[i].auto_number;
			found->owners[j].pass_number = db->owners[i].pass_number;
			found->owners[j].phone_number = db->owners[i].phone_number;
			found->owners[j].department = db->owners[i].department;
			j++;
		}
	}
}

ostream& operator << (ostream& out, const FullName& fn) {
	out << fn.surname << " " << fn.name << " " << fn.patronymic;
	return out;
}

ostream& operator << (ostream& out, const Date& dt) {
	out << dt.day << "." << dt.month << "." << dt.year;
	return out;
}

ostream& operator << (ostream& out, const Owner& own) {
	out << own.full_name << ", " << own.birth_date << ", " << own.auto_number << ", " << own.pass_number <<
		", " << own.phone_number << ", " << own.department;
	return out;
}