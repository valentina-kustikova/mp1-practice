#ifndef __SCH_H_
#define __SCH_H_
using namespace std;

class home_address {
	char index[6] = "";
	int flat;
	string country, region, district, city, street, house;
public:
	home_address(const string&);
	home_address() {};
	friend ostream& operator<<(ostream&, home_address&);
};


class birth_date {
	int day, month, year;
public:
	birth_date(const string&);
	birth_date() {};
	friend ostream& operator<<(ostream&, birth_date&);
};


enum class gender {
	MAN = 1, WOMAN
};

class pupil {
	string surname, name, fathername, klass;
	gender gen;
	birth_date date;
	home_address home;
	friend void swap(pupil& a, pupil& b);
	friend bool compare(pupil& a, pupil& b);
public:
	pupil(const string&, const string&, const string&, const string&, const string&);
	pupil() {};
	friend ostream& operator<<(ostream&, pupil&);
};

class school {
	int count;
	pupil* list;
public:
	school(const string&);
	~school();
	friend ostream& operator<<(ostream&, school&);
	void sort();
};

#endif