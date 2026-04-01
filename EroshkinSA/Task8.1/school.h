#ifndef __SCH_H_
#define __SCH_H_
using namespace std;

struct home_address {
	char index[6] = "";
	int flat;
	string country, region, district, city, street, house;

	home_address(const string&);
	home_address();
};

struct birth_date {
	int day, month, year;

	birth_date(const string&);
	birth_date();
};

enum class gender{
	MAN = 1, WOMAN
};

struct pupil {
	string surname, name, fathername, klass;
	gender gen;
	birth_date date;
	home_address home;

	pupil (const string&, const string&, const string&, const string&, const string&);
	pupil();

	void print(); // ostream
};

struct school {
	int count;
	pupil* list;

	school(const string&);
	~school();

	void sort();
	void print(); // ostream
};



void swap(pupil& a, pupil& b);

#endif