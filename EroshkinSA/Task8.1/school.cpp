#include <string>
#include <iostream>
#include <sstream>
#include "school.h"
#include <fstream>
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

ostream& operator<<(ostream& out, pupil& p) {
	out << "#___#" << endl;
	out << "NAME: " << p.surname << " " << p.name << " "
		<< p.fathername << endl;
	out << "CLASS: " << p.klass << "   GENDER: ";
	if (p.gen == gender::MAN) out << "Male";
	else out << "Female";
	out << endl << p.home << endl;
	out << p.date << endl << "#___#" << endl;
	return out;
}

ostream& operator<<(ostream& out, home_address& home) {
	out << "HOME ADDRESS: ";
	for (int i = 0; i < 6; i++) out << home.index[i];
	out << " - " << home.country << ", " << home.region << ", "
		<< home.district << ", " << home.city << ", "
		<< home.street << ", "
		<< home.house << ", " << home.flat;
	return out;
}

ostream& operator<<(ostream& out, birth_date& date) {
	out << "BIRTH DATE: ";
	if (date.day < 10) out << '0';
	out << date.day << ".";
	if (date.month < 10) out << '0';
	out << date.month << "." << date.year;
	return out;
}

ostream& operator<<(ostream& out, school& sch) {
	out << "#_________________________#\n";
	for (int i = 0; i < sch.count; i++) {
		out << i + 1 << ") " << sch.list[i].klass << "\t"
			<< sch.list[i].surname << " " << sch.list[i].name << " "
			<< sch.list[i].fathername << "\t";
		if (sch.list[i].gen == gender::MAN) out << "Male\t";       
		else out << "Female\t";
		out << sch.list[i].date << endl;
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
	for(i = 0; i < this->count; i++) {
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

void school::sort() {
	// class sort
	for (int i = 0; i < this->count - 1; i++) {
		for (int j = 0; j < this->count - i - 1; j++) {
			string a = this->list[j].klass, b = this->list[j + 1].klass;
			int codeA = stoi(a.substr(0, a.size() - 1)) * 100 + (a.back() - 'A'),
				codeB = stoi(b.substr(0, b.size() - 1)) * 100 + (b.back() - 'A');
			if (codeB < codeA) swap(this->list[j], this->list[j + 1]);
		}
	}
	// name sort
	for (int i = 0; i < this->count - 1; i++) {
		for (int j = 0; j < this->count - i - 1; j++) {
			if (this->list[j].klass == this->list[j + 1].klass) {
				if (this->list[j].surname != this->list[j + 1].surname) {
					if (this->list[j].surname > this->list[j + 1].surname)
						swap(this->list[j], this->list[j + 1]);
				}
				else {
					if (this->list[j].name != this->list[j + 1].name) {
						if (this->list[j].name > this->list[j + 1].name)
							swap(this->list[j], this->list[j + 1]);
					}
					else {
						if (this->list[j].fathername > this->list[j + 1].fathername)
							swap(this->list[j], this->list[j + 1]);
					}
				}
			}
		}
	}
}

school::~school() {
	delete[]this->list;
}

void swap(pupil& a, pupil& b) {
	pupil temp = a;
	a = b;
	b = temp;
}