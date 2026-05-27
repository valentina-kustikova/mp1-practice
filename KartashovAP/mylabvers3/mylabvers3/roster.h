#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum Gender {
    male,
    female,
    unknown
};

class FullName {
private:
    string surname;
    string name;
    string patronymic;
public:
    FullName() = default;
    FullName(const string& s, const string& n, const string& p);

    friend istream& operator>>(istream& in, FullName& a);
    friend ostream& operator<<(ostream& out, const FullName& a);
    bool operator<(const FullName& other) const;
};

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int d, int m, int y);
    friend istream& operator>>(istream& in, Date& a);
    friend ostream& operator<<(ostream& out, const Date& a);
};

class Address {
private:
	string postal_code;
	string country;
	string region;
	string district;
	string city;
	string street;
	string house;
	string apartment;
public:
	Address() = default;
	Address(const string& pc, const string& c, const string& r, 
		const string& d, const string& ct, const string& s,const string& h, const string& ap);
	friend istream& operator>>(istream& in, Address& a);
	friend ostream& operator<<(ostream& out, const Address& a);
};

class Person {
protected:
	FullName full_name;
	Gender gender;
	Date birth_date;
public:
	Person();
	Person(const FullName& fn, Gender g, const Date& bd);
	virtual ~Person() = default;

	bool operator<(const Person& other) const;
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);
};

class Student : public Person {
private:
	string class_name;
	Address address;
public:
	Student();
	Student(const FullName& fn, Gender g, const Date& bd, const string& cls, const Address& addr);

	string getClassName() const;
	void setClassName(const string& cls);
	void setAddress(const Address& addr);

	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);
};

class ClassGroup {
private:
    string class_name;
    Student* students;
    int count;

    void copyFrom(const ClassGroup& other);
    void free();
public:
    ClassGroup();
    ClassGroup(const string& name);
    ClassGroup(const ClassGroup& other);
    ~ClassGroup();

    const ClassGroup& operator=(const ClassGroup& other);

    void addStudent(const Student& s);
    void sortStudents();

    string getClassName() const;
    int getCount() const;
    Student* getStudents() const;

    friend istream& operator>>(istream& in, ClassGroup& a);
    friend ostream& operator<<(ostream& out, const ClassGroup& a);
};

class School {
private:
    ClassGroup* classes;
    int class_count;

    void copyFrom(const School& other);
    void free();
public:
    School();
    School(const School& other);
    ~School();

    const School& operator=(const School& other);
    void sortSchool();

    friend istream& operator>>(istream& in, School& a);
    friend ostream& operator<<(ostream& out, const School& a);
};

#endif