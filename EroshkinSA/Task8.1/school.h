#ifndef __SCH_H_
#define __SCH_H_
using namespace std;

struct home_address {
	char index[6] = "";
	int flat;
	string country, region, district, city, street, house;

	home_address(string);
	//~home_address();
};

struct birth_date {
	int day, month, year;

	birth_date(string);
	//~birth_date();
};

enum class gender{
	MAN = 1, WOMAN
};

struct pupil {
	string surname, name, fathername, klass;
	gender gen;
	birth_date date;
	home_address home;

	pupil (string, string, string, string, string);
	pupil();
	//~pupil();

	void print();
};

struct school {
	int count;
	pupil* list;

	school(const char*);
	//~school();

	void sort();
	void print();
};



void swap(pupil& a, pupil& b);

//____________________________________________
//____________________________________________

void swap(pupil* a, pupil* b); // +
void read(const char* source, school* sch); // constructor
void school_sort(school* sch); // +
void class_sort(school* sch); // inside of school_sort
int compare(pupil* a, pupil* b); 
void sorted_list(school* sch); // -
void print_pupil(pupil s); // +
void free_all(school* sch); // ?

#endif