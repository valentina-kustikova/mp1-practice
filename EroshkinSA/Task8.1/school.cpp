#include <string>
#include <iostream>
#include <sstream>
#include "school.h"
using namespace std;

birth_date::birth_date(string s) {
	istringstream ss(s);
	string buff = "";
	getline(ss, buff, '.');  this->day = stoi(buff);
	getline(ss, buff, '.');  this->month = stoi(buff);
	getline(ss, buff, '.');  this->year = stoi(buff);
}

home_address::home_address(string s) {
	for (int i = 0; i < 6; i++) this->index[i] = s[i];
	s = s.substr(7);
	istringstream ss(s);
	getline(ss, this->country, ',');
	getline(ss, this->region, ',');
	getline(ss, this->district, ',');
	getline(ss, this->city, ',');
	getline(ss, this->street, ',');
	getline(ss, this->house, ',');
	string buff = ""; getline(ss, buff, ',');
	this->flat = stoi(buff);
}

pupil::pupil(string FIO, string klass, string gen, string date,
	string address) : home(address), date(date) {
	istringstream ss(FIO);
	getline(ss, this->surname, ' ');
	getline(ss, this->name, ' ');
	getline(ss, this->fathername, ' ');
	this->klass = klass;
	if (gen == "Male") this->gen = gender::MAN;
	else this->gen = gender::WOMAN;
}

pupil::pupil() : home("111111,a,b,c,d,e,f,1"), date("1.1.1") {
	this->surname = "";
	this->name = "";
	this->fathername = "";
	this->gen = gender::MAN;
	this->klass = "";
}

void pupil::print() {
	cout << "#___#" << endl;
	cout << "NAME: " << this->surname << " " << this->name << " "
		 << this->fathername << endl;
	cout << "CLASS: " << this->klass << "   GENDER: ";
	if (this->gen == gender::MAN) cout << "Male";
	else cout << "Female";
	cout << endl << "HOME ADDRESS: ";
	for (int i = 0; i < 6; i++) cout << this->home.index[i];
	cout << " - " << this->home.country << ", " << this->home.region << ", "
		<< this->home.district << ", " << this->home.city << ", "
		<< this->home.street << ", "
		<< this->home.house << ", " << this->home.flat << endl;
	cout << "BIRTH DATE: ";
	if (this->date.day < 10) cout << '0';
	cout << this->date.day << ".";
	if (this->date.month < 10) cout << '0';
	cout << this->date.month << "." << this->date.year << endl
		 << "#___#" << endl;
}

void school::print() {
	cout << "#_________________________#\n";
	for (int i = 0; i < this->count; i++) {
		cout << i + 1 << ") " << this->list[i].klass << "\t"
			<< this->list[i].surname << " " << this->list[i].name << " "
			<< this->list[i].fathername << "\t";
		if (this->list[i].gen == gender::MAN) cout << "Male\t";
		else cout << "Female\t";
		if (this->list[i].date.day < 10) cout << '0';
		cout << this->list[i].date.day << ".";
		if (this->list[i].date.month < 10) cout << '0';
		cout << this->list[i].date.month << "." << this->list[i].date.year << endl;
	}
	cout << "#_________________________#\n";
}


school::school(const char* fn) {
	freopen(fn, "r", stdin);
	string FIO = "", klass = "", gen = "", date = "", address = "";
	int i = 0, cnt = 0, cur = 0;
	this->count = 0;
	while (getline(cin, FIO)) this->count++;
	this->list = new pupil[this->count];
	freopen(fn, "r", stdin);
	cin.clear();
	for(i = 0; i < this->count; i++) {
		getline(cin, FIO, ';');
		getline(cin, klass, ';');
		getline(cin, gen, ';');
		getline(cin, date, ';');
		getline(cin, address, '\n');
		pupil p(FIO, klass, gen, date, address);
		this->list[i] = p;
	}
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