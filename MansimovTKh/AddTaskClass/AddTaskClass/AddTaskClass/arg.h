#ifndef _ARG_H
#define _ARG_H

#include <iostream>
#include <string>

using namespace std;

enum Gender {
	male,
	female,
	unknown	
};

struct FullName {
	string surname;
	string name;
	string patronymic;

	friend ostream& operator << (ostream& out, const FullName& a);
};

struct Date {
	int day;
	int month;
	int year;

	friend ostream& operator << (ostream& out, const Date& a);
};

struct Address {
	string index;
	string country;
	string region_city;
	string street;

	friend ostream& operator << (ostream& out, const Address& a);
};

struct Anthropometry {
	int height;
	int weight;

	friend ostream& operator << (ostream& out, const Anthropometry& a);
};

struct PersonInfo {
	FullName full_name;
	Gender gender;
	string nation;
	Anthropometry anthropometry;
	Date date_of_birth;
	string number;
	Address address;

	friend ostream& operator << (ostream& out, const PersonInfo& a);
};


#endif