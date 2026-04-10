#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "arg.h"

using namespace std;

PersonsLibrary::PersonsLibrary(const string& filename) {
	this->count = 0;
	string line;
	size_t pos;
	ifstream fp(filename);

	if (!fp.is_open()) {
		this->persons = NULL; this->count = 0;
		throw "error of file\n";
	}
	while (getline(fp, line)) {
		this->count++;
	}
	(this->persons) = new PersonInfo[this->count];
	if ((this->persons) == nullptr) {
		throw "error of memory allocation\n";
	}

	fp.clear();
	fp.seekg(0, ios::beg);
	for (int i = 0; i < this->count; i++) {
		getline(fp, line);

		pos = line.find(';'); this->persons[i].full_name.surname = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].full_name.name = line.substr(0, pos); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].full_name.patronymic = line.substr(0, pos); line.erase(0, pos + 1);

		pos = line.find(';'); string g = line.substr(0, pos);
		if (g == "Male") this->persons[i].gender = male;
		else if (g == "Female") this->persons[i].gender = female;
		else this->persons[i].gender = unknown;
		line.erase(0, pos + 1);

		pos = line.find(';'); this->persons[i].nation = line.substr(0, pos); line.erase(0, pos + 1);

		pos = line.find(';'); this->persons[i].height = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		pos = line.find(';'); this->persons[i].weight = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
		
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
		this->persons[i].full_name.surname = a.persons[i].full_name.surname;
		this->persons[i].full_name.name = a.persons[i].full_name.name;
		this->persons[i].full_name.patronymic = a.persons[i].full_name.patronymic;
		this->persons[i].gender = a.persons[i].gender;
		this->persons[i].nation = a.persons[i].nation;
		this->persons[i].height = a.persons[i].height;
		this->persons[i].weight = a.persons[i].weight;
		this->persons[i].date_of_birth.day = a.persons[i].date_of_birth.day;
		this->persons[i].date_of_birth.month = a.persons[i].date_of_birth.month;
		this->persons[i].date_of_birth.year = a.persons[i].date_of_birth.year;
		this->persons[i].number = a.persons[i].number;
		this->persons[i].address.index = a.persons[i].address.index;
		this->persons[i].address.country = a.persons[i].address.country;
		this->persons[i].address.region_city = a.persons[i].address.region_city;
		this->persons[i].address.street = a.persons[i].address.street;
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

