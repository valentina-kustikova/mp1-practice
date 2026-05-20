#ifndef __DEPARTMENT_H_
#define __DEPARTMENT_H_

using namespace std;


struct FullName{
	string surname;
	string name;
	string patronymic;

	friend ostream& operator << (ostream& out, const FullName& fn);
};

struct Date{
	unsigned int day;
	unsigned int month;
	unsigned int year;

	friend ostream& operator << (ostream& out, const Date& fn);
};

struct Owner{
	FullName full_name;
	Date birth_date;
	string auto_number;
	string pass_number;
	string phone_number;
	string department;

	friend ostream& operator << (ostream& out, const Owner& fn);
};

struct OwnerLib{
	Owner* owners;
	int count;
};


void find_owners(string requested_department, OwnerLib* db, OwnerLib* found);
#endif