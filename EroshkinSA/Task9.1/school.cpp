#include <iostream>
#include <string>
#include "school.h"
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

birth_date::birth_date(const string& s) {
	istringstream ss(s);
	string buff = "";
	getline(ss, buff, '.');  this->day = stoi(buff);
	getline(ss, buff, '.');  this->month = stoi(buff);
	getline(ss, buff, '.');  this->year = stoi(buff);
}


home_address::home_address(const string& s) {
	for (int i = 0; i < 6; i++) this->index[i] = s[i];
	istringstream ss(s.substr(7));
	getline(ss, this->country, ',');
	getline(ss, this->region, ',');
	getline(ss, this->district, ',');
	getline(ss, this->city, ',');
	getline(ss, this->street, ',');
	getline(ss, this->house, ',');
	string buff = ""; getline(ss, buff, ',');
	this->flat = stoi(buff);
}


pupil::pupil(const string& FIO, const string& klass, const string& gen, const string& date,
	const string& address) : home(address), date(date) {
	istringstream ss(FIO);
	getline(ss, this->surname, ' ');
	getline(ss, this->name, ' ');
	getline(ss, this->fathername, ' ');
	this->klass = klass;
	if (gen == "Male") this->gen = gender::MAN;
	else this->gen = gender::WOMAN;
}

ostream& operator<<(ostream& out, const pupil& p) {
	out << setw(3) << p.klass << '\t' << p.surname << " "
		<< p.name << " " << p.fathername << '\t';
	if (p.gen == gender::MAN) out << "Male\t";
	else out << "Female\t";
	out<< p.date;
	return out;
}

ostream& operator<<(ostream& out, const home_address& home) {
	out << "HOME ADDRESS: ";
	for (int i = 0; i < 6; i++) out << home.index[i];
	out << " - " << home.country << ", " << home.region << ", "
		<< home.district << ", " << home.city << ", "
		<< home.street << ", "
		<< home.house << ", " << home.flat;
	return out;
}

ostream& operator<<(ostream& out, const birth_date& date) {
	out << "BIRTH DATE: ";
	if (date.day < 10) out << '0';
	out << date.day << ".";
	if (date.month < 10) out << '0';
	out << date.month << "." << date.year;
	return out;
}

ostream& operator<<(ostream& out, const school& sch) {
	out << "#_________________________#\n";
	for (int i = 0; i < sch.count; i++) {
		out << setw(2) << i + 1 << ") " << sch.list[i] << endl;
	}
	out << "#_________________________#\n";
	return out;
}

school::school(const string& fn) {
	ifstream file(fn);
	if (!file.is_open()) {
		cerr << "File doesn't exist or can't be read\n";
		throw "Error";
	}
	string FIO = "", klass = "", gen = "", date = "", address = "";
	int i = 0, cnt = 0, cur = 0;
	this->count = 0;
	while (getline(file, FIO)) this->count++;
	file.close(); file = ifstream(fn);
	this->list = new pupil[this->count];
	for (i = 0; i < this->count; i++) {
		getline(file, FIO, ';');
		getline(file, klass, ';');
		getline(file, gen, ';');
		getline(file, date, ';');
		getline(file, address, '\n');
		pupil p(FIO, klass, gen, date, address);
		this->list[i] = p;
	}
	file.close();
}

bool school::compare(const pupil& a, const pupil& b) {
	if (a.get_class() == b.get_class()) {
		if (a.get_surname() != b.get_surname()) return a.get_surname() < b.get_surname();
		else if (a.get_name() != b.get_name()) return a.get_name() < b.get_name();
		else return a.get_fathername() < b.get_fathername();
	}
	else {
		string sa = a.get_class(), sb = b.get_class();
		int codeA = stoi(sa.substr(0, sa.size() - 1)) * 100 + (sa.back() - 'A'),
			codeB = stoi(sb.substr(0, sb.size() - 1)) * 100 + (sb.back() - 'A');
		return codeA < codeB;
	}
}

void school::sort() {
	for (int i = 0; i < this->count - 1; i++) {
		for (int j = 0; j < this->count - i - 1; j++) {
			if (!compare(this->list[j], this->list[j + 1])) swap(this->list[j], this->list[j + 1]);
		}
	}
}

school::~school() {
	delete[]this->list;
}

void school::swap(pupil& a, pupil& b) {
	pupil temp = a;
	a = b;
	b = temp;
}