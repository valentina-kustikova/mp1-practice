#ifndef _ARG_H
#define _ARG_H
#define BUFFER_SIZE 1024

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
} ;

struct Address{
	string index;
	string country;
	string region_city;
	string street;

	friend ostream& operator << (ostream& out, const Address& a);
};

struct PersonInfo {
	FullName full_name;
	Gender gender;
	string nation;
	int height;
	int weight;
	Date date_of_birth;
	string number;
	Address address;

	friend ostream& operator << (ostream& out, const PersonInfo& a);
};

struct PersonsLibrary {
	PersonInfo* persons;
	int count;

	PersonsLibrary() : persons(nullptr), count(0) { };
	PersonsLibrary(const string& filename); 
	PersonsLibrary(const PersonsLibrary&);
	~PersonsLibrary();

	void SortPersons();

	friend ostream& operator << (ostream& out, const PersonsLibrary& a);
};

#endif