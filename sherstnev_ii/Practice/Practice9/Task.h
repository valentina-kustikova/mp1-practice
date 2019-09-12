#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

class Task {
public:
	string description;
	Date date;
	virtual void Print();
	string getDescription();
	Date getDate();
};