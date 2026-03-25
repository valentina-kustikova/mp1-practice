#include <string>
#include <iostream>
#include "school.h"
using namespace std;

birth_date::birth_date(string s) {
	char* buff = new char[s.size() + 1];
	s.copy(buff, s.size());
	buff[s.size()] = '\0';
	this->day = stoi(strtok(buff, "."));
	this->month = stoi(strtok(NULL, "."));
	this->year = stoi(strtok(NULL, "."));
	delete[]buff;
}

home_address::home_address(string s) {
	char* buff = new char[s.size() + 1];
	s.copy(buff, s.size());
	buff[s.size()] = '\0';
	for (int i = 0; i < 6; i++) this->index[i] = buff[i];
	strtok(buff, ",");
	this->country = strtok(NULL, ",");
	this->region = strtok(NULL, ",");
	this->district = strtok(NULL, ",");
	this->city = strtok(NULL, ",");
	this->street = strtok(NULL, ",");
	this->house = strtok(NULL, ",");
	this->flat = stoi(strtok(NULL, ","));
	delete[]buff;
}

pupil::pupil(string FIO, string klass, string gen, string date, string address) : home(address), date(date) {
	char* buff = new char[FIO.size() + 1];
	FIO.copy(buff, FIO.size());
	buff[FIO.size()] = '\0';
	this->surname = strtok(buff, " ");
	this->name = strtok(NULL, " ");
	this->fathername = strtok(NULL, ";");
	this->klass = klass;
	if (gen == "Male") this->gen = gender::MAN;
	else this->gen = gender::WOMAN;
	delete[]buff;
}

pupil::pupil() : home("111111, a, b, c, d, e, f, 1"), date("1.1.1") {
	this->surname = "";
	this->name = "";
	this->fathername = "";
	this->gen = gender::MAN;
	this->klass = "";
}

void pupil::print() {
	cout << "#___#" << endl;
	cout << "NAME: " << this->surname << " " << this->name << " " << this->fathername << endl;
	cout << "CLASS: " << this->klass << "   GENDER: ";
	if (this->gen == gender::MAN) cout << "Male";
	else cout << "Female";
	cout << endl << "HOME ADDRESS: ";
	for (int i = 0; i < 6; i++) cout << this->home.index[i];
	cout << " - " << this->home.country << ", " << this->home.region << ", "
		<< this->home.district << ", " << this->home.city << ", " << this->home.street << ", "
		<< this->home.house << ", " << this->home.flat << endl;
	cout << "BIRTH DATE: ";
	if (this->date.day < 10) cout << '0';
	cout << this->date.day << ".";
	if (this->date.month < 10) cout << '0';
	cout << this->date.month << "." << this->date.year << endl << "#___#" << endl;
}


school::school(const char* fn) {
	freopen(fn, "r", stdin);
	string s;
	string FIO = "", klass = "", gen = "", date = "", address = "";
	int i, cnt = 0, cur = 0;
	this->count = 0;
	while (getline(cin, s)) this->count++;
	this->list = new pupil[this->count];
	freopen(fn, "r", stdin);
	cin.clear();
	while (getline(cin, s)) {
		FIO = ""; klass = ""; gen = ""; date = ""; address = "";
		FIO = s.substr(cur, s.find(";") - cur);
		cur = s.find(";");
		s[cur] = ' ';
		cur++;
		klass = s.substr(cur, s.find(";") - cur);
		cur = s.find(";");
		s[cur] = ' ';
		cur++;
		gen = s.substr(cur, s.find(";") - cur);
		cur = s.find(";");
		s[cur] = ' ';
		cur++;
		date = s.substr(cur, s.find(";") - cur);
		cur = s.find(";");
		s[cur] = ' ';
		cur++;
		address = s.substr(cur, s.size() - cur);
		cur = 0;
		/*for (i = 0;; i++) {
			if (s[i] == ';') {
				i++;
				break;
			}
			FIO += s[i];
		}
		for (;; i++) {
			if (s[i] == ';') {
				i++;
				break;
			}
			klass += s[i];
		}
		for (;; i++) {
			if (s[i] == ';') {
				i++;
				break;
			}
			gen += s[i];
		}
		for (;; i++) {
			if (s[i] == ';') {
				i++;
				break;
			}
			date += s[i];*/
	}
	pupil p(FIO, klass, gen, date, address);
	this->list[cnt++] = p;
}