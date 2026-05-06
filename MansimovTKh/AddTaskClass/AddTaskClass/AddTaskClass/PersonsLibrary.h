#ifndef _LIB_H
#define _LIB_H

#include <iostream>
#include <string>
#include "arg.h"

using namespace std;

class PersonsLibrary {
private:
	PersonInfo* persons;
	int count;
public:
	PersonsLibrary() : persons(nullptr), count(0) {};
	PersonsLibrary(const string& filename);
	PersonsLibrary(const PersonsLibrary& a);
	~PersonsLibrary();

	void SortPersons();

	friend ostream& operator << (ostream& out, const PersonsLibrary& a);

};


#endif