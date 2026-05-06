#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "PersonsLibrary.h"

using namespace std;

PersonsLibrary::PersonsLibrary(const string& filename) {
	this->count = 0;
	ifstream fp(filename);
	if (!fp.is_open()) {
		this->persons = nullptr;
		throw "error of file opening\n";
	}

	string line;
	while (getline(fp, line)) {
		this -> count++;
	}

	this->persons = new PersonInfo[this->count];
	if (this->persons == nullptr) {
		this->count = 0;
		throw "error of memory allocation\n";
	}

	fp.clear();
	fp.seekg(0, ios::beg);
	for (int i = 0; i < this->count; i++) {
		getline(fp, line);

		size_t pos;
		pos = line.find(';'); this->persons[i].full_name.surname = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].full_name.name = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].full_name.patronymic = line.substr(0, pos); line.erase(0, pos + 1);

		pos = line.find(';'); string g = line.substr(0, pos);
		if (g == "Male") this->persons[i].gender = male;
		else if (g == "Female") this->persons[i].gender = female;
		else this->persons[i].gender = unknown;
		line.erase(0, pos + 1);

		pos = line.find(';'); this->persons[i].nation = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].anthropometry.height = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].anthropometry.weight = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].date_of_birth.day = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].date_of_birth.month = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].date_of_birth.year = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].number = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].address.index = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].address.country = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].address.region_city = line.substr(0, pos); line.erase(0, pos + 1);
		this->persons[i].address.street = line;
	}
	fp.close();
}

PersonsLibrary::PersonsLibrary(const PersonsLibrary& a) {
	this->count = a.count;
	this->persons = new PersonInfo[this->count];
	for (int i = 0; i < this->count; i++) {
		this->persons[i].full_name = a.persons[i].full_name;
		this->persons[i].gender = a.persons[i].gender;
		this->persons[i].nation = a.persons[i].nation;
		this->persons[i].anthropometry = a.persons[i].anthropometry;
		this->persons[i].date_of_birth = a.persons[i].date_of_birth;
		this->persons[i].number = a.persons[i].number;
		this->persons[i].address = a.persons[i].address;
	}
}

PersonsLibrary::~PersonsLibrary() {
	delete[] this->persons;
}

void PersonsLibrary::SortPersons() {
	if (this->persons == nullptr) return;

	int min_idx = 0;
	for (int i = 0; i < this->count - 1; i++) {
		min_idx = i;
		for (int j = i + 1; j < this->count; j++) {
			if (this->persons[j].full_name.surname < this->persons[min_idx].full_name.surname) {
				min_idx = j;
			}
			else if (this->persons[j].full_name.surname == this->persons[min_idx].full_name.surname) {
				if (this->persons[j].full_name.name < this->persons[min_idx].full_name.name) {
					min_idx = j;
				}
				else if (this->persons[j].full_name.name == this->persons[min_idx].full_name.name) {
					if (this->persons[j].full_name.patronymic < this->persons[min_idx].full_name.patronymic) {
						min_idx = j;
					}
				}
			}
		}
		if (min_idx != i) {
			PersonInfo temp = this->persons[i];
			this->persons[i] = this->persons[min_idx];
			this->persons[min_idx] = temp;
		}
	}
}

ostream& operator << (ostream& out, const PersonsLibrary& a) {
	for (int i = 0; i < a.count; i++) {
		out << a.persons[i]<<endl<<endl;
	}
	return out;
}
