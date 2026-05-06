#include <iostream>
#include <string>
#include "arg.h"

using namespace std;


ostream& operator << (ostream& out, const FullName& a) {
	out << a.surname << " | " << a.name << " | " << a.patronymic;
	return out;
}

ostream& operator << (ostream& out, const Date& a) {
	out << a.day << " | " << a.month << " | " << a.year;
	return out;
}

ostream& operator << (ostream& out, const Address& a) {
	out << a.index << " | " << a.country << " | " << a.region_city << " | " << a.street;
	return out;
}

ostream& operator << (ostream& out, const Anthropometry& a) {
	out << a.height << " | " << a.weight;
	return out;
}

ostream& operator << (ostream& out, const PersonInfo& a) {
	out << a.full_name << " | ";

	if (a.gender == male) out << "Male";
	else if (a.gender == female) out << "Female";
	else out << "Unknown";

	out << " | " << a.nation << " | " << a.date_of_birth
		<< " | " << a.number << " | " << a.address;
	return out;
}
