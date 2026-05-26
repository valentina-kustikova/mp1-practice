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

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

string Address::getPostalCode() const { return postal_code; }
string Address::getCountry() const { return country; }
string Address::getRegion() const { return region; }
string Address::getDistrict() const { return district; }
string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }
string Address::getHouse() const { return house; }
string Address::getApartment() const { return apartment; }

void Address::setPostalCode(const string& pc) { postal_code = pc; }
void Address::setCountry(const string& c) { country = c; }
void Address::setRegion(const string& r) { region = r; }
void Address::setDistrict(const string& d) { district = d; }
void Address::setCity(const string& c) { city = c; }
void Address::setStreet(const string& s) { street = s; }
void Address::setHouse(const string& h) { house = h; }
void Address::setApartment(const string& a) { apartment = a; }

Person::Person() : gender(unknown) {}
Person::Person(const FullName& fn, Gender g, const Date& bd)
    : full_name(fn), gender(g), birth_date(bd) {
}

void Person::setFullName(const FullName& fn) { full_name = fn; }
void Person::setGender(Gender g) { gender = g; }
void Person::setBirthDate(const Date& bd) { birth_date = bd; }

void Person::print(ostream& out) const {
    out << full_name << "\n  Gender: ";
    switch (gender) {
    case male: out << "Male"; break;
    case female: out << "Female"; break;
    default: out << "Unknown";
    }
    out << "\n  Birth date: " << birth_date;
}

bool Person::operator<(const Person& other) const {
    return full_name < other.full_name;
}

Student::Student() : Person(), class_name("") {}
Student::Student(const FullName& fn, Gender g, const Date& bd,
    const string& cls, const Address& addr)
    : Person(fn, g, bd), class_name(cls), address(addr) {
}

string Student::getClassName() const { return class_name; }
void Student::setClassName(const string& cls) { class_name = cls; }
void Student::setAddress(const Address& addr) { address = addr; }

bool Student::operator<(const Student& other) const {
    return full_name < other.full_name;
}

void Student::print(ostream& out) const {
    Person::print(out);
    out << "\n  Class: " << class_name << "\n  Address: " << address;
}

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