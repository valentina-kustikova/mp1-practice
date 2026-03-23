#include <string>
#include <iostream>
#include "school.h"
using namespace std;

birth_date::birth_date() {
	this->day = stoi("20");
	this->month = stoi("09");
	this->year = stoi("2007");
}

home_address::home_address() {
	this->city = "NN";
	this->country = "Russia";
	this->district = "Avtaz";
	this->flat = 24;
	this->house = "14";
	for (int i = 0; i < 6; i++) this->index[i] = '6';
	this->region = "NO";
	this->street = "Krasnyh Partizan";
}

pupil::pupil() {
	this->name = "Sergey";
	this->date = birth_date();
	this->home = home_address();
	this->fathername = "Aleksandrovich";
	this->gen = gender::MAN;
	this->klass = "11A";
	this->surname = "Eroshkin";
}

ostream& pupil::operator<<(ostream& cout) {
	cout << "#___#" << endl;
	cout << "NAME: " << this->surname << " " << this->name << " " << this->fathername << endl;
	cout << "CLASS: " << this->klass << "   GENDER: " << endl;
	if (this->gen == gender::MAN) cout << "Male";
	else cout << "Female";
	cout << endl << "HOME ADDRESS: " << this->home.index << " - " << this->home.country << " "
		<< this->home.region << " " << this->home.district << " " << this->home.city << " "
		<< this->home.street << " " << this->home.house << " " << this->home.flat << endl;
	cout << "BIRTH DATE: " << this->date.day << "." << this->date.month << "." << this->date.year << endl << "#___#" << endl;
	return cout;
}