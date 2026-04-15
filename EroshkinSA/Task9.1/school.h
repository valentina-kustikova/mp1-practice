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
	friend ostream& operator<<(ostream&, const home_address&);
};


class birth_date {
	int day, month, year;
public:
	birth_date(const string&);
	birth_date() {};
	friend ostream& operator<<(ostream&, const birth_date&);
};


enum class gender {
	MAN = 1, WOMAN
};

class pupil {
	string surname, name, fathername, klass;
	gender gen;
	birth_date date;
	home_address home;
public:
	pupil(const string&, const string&, const string&, const string&, const string&);
	pupil() {};
	friend ostream& operator<<(ostream&, const pupil&);
	string get_class() const { return this->klass; }
	string get_name() const { return this->name; }
	string get_surname() const { return this->surname; }
	string get_fathername() const { return this->fathername; }
};

class school {
	int count;
	pupil* list;

	void swap(pupil& a, pupil& b);
	bool compare(const pupil& a, const pupil& b);
public:
	school(const string&);
	~school();
	friend ostream& operator<<(ostream&, const school&);
	void sort();
};

#endif