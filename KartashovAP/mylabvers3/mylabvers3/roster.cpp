#include "roster.h"

FullName::FullName(const string& s, const string& n, const string& p)
	: surname(s), name(n), patronymic(p) {
}

bool FullName::operator<(const FullName& other) const {
	if (surname != other.surname) return surname < other.surname;
	if (name != other.name) return name < other.name;
	return patronymic < other.patronymic;
}

Date::Date() : day(1), month(1), year(2000) {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Address::Address(const string& pc, const string& c, const string& r, const string& d, const string& ct, const string& s, const string& h, const string& ap): 
	postal_code(pc), country(c), region(r), district(d), city(ct), street(s), house(h), apartment(ap) {
}

Person::Person() : gender(unknown) {}
Person::Person(const FullName& fn, Gender g, const Date& bd)
	: full_name(fn), gender(g), birth_date(bd) {
}

bool Person::operator<(const Person& other) const {
	return full_name < other.full_name;
}

Student::Student() : Person(), class_name("") {}
Student::Student(const FullName& fn, Gender g, const Date& bd, const string& cls, const Address& addr):
	Person(fn, g, bd), class_name(cls), address(addr) {
}

string Student::getClassName() const { return class_name; }
void Student::setClassName(const string& cls) { class_name = cls; }
void Student::setAddress(const Address& addr) { address = addr; }

void ClassGroup::copyFrom(const ClassGroup& other) {
	class_name = other.class_name;
	count = other.count;
	if (count > 0) {
		students = new Student[count];
		for (int i = 0; i < count; i++)
			students[i] = other.students[i];
	}
	else {
		students = nullptr;
	}
}

void ClassGroup::free() {
	delete[] students;
}

ClassGroup::ClassGroup() : students(nullptr), count(0) {}
ClassGroup::ClassGroup(const string& name) : class_name(name), students(nullptr), count(0) {}
ClassGroup::ClassGroup(const ClassGroup& other) { copyFrom(other); }
ClassGroup::~ClassGroup() { free(); }

const ClassGroup& ClassGroup::operator=(const ClassGroup& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void ClassGroup::addStudent(const Student& s) {
	Student* new_arr = new Student[count + 1];
	for (int i = 0; i < count; i++)
		new_arr[i] = students[i];
	new_arr[count] = s;
	delete[] students;
	students = new_arr;
	count++;
}

void ClassGroup::sortStudents() {
	for (int i = 0; i < count - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < count; j++) {
			if (students[j] < students[min_idx])
				min_idx = j;
		}
		if (min_idx != i) {
			Student temp = students[i];
			students[i] = students[min_idx];
			students[min_idx] = temp;
		}
	}
}

string ClassGroup::getClassName() const { return class_name; }
int ClassGroup::getCount() const { return count; }
Student* ClassGroup::getStudents() const { return students; }

void School::copyFrom(const School& other) {
	class_count = other.class_count;
	if (class_count > 0) {
		classes = new ClassGroup[class_count];
		for (int i = 0; i < class_count; i++)
			classes[i] = other.classes[i];
	}
	else {
		classes = nullptr;
	}
}

void School::free() {
	delete[] classes;
}

School::School() : classes(nullptr), class_count(0) {}
School::School(const School& other) { copyFrom(other); }
School::~School() { free(); }

const School& School::operator=(const School& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void School::sortSchool() {
	for (int i = 0; i < class_count; i++)
		classes[i].sortStudents();
}
