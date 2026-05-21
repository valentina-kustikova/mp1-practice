#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Gender {
    male,
    female,
    unknown
};

struct FullName {
    string surname;
    string name;
    string patronymic;

    friend istream& operator>>(istream& in, FullName& a);
    friend ostream& operator<<(ostream& out, const FullName& a);
};

struct Date {
    int day;
    int month;
    int year;

    Date(int d, int m, int y): day(d), month(m), year(y) {}

    friend istream& operator>>(istream& in, Date& a);
    friend ostream& operator<<(ostream& out, const Date& a);
};

struct Address {
    string postal_code;
    string country;
    string region;
    string district;
    string city;
    string street;
    string house;
    string apartment;

    friend istream& operator>>(istream& in, Address& a);
    friend ostream& operator<<(ostream& out, const Address& a);
};

struct Student {
    FullName full_name;
    string class_name;
    Gender gender;
    Date birth_date;
    Address address;

    Student() : gender(unknown), birth_date(1,1,2000) {}

    friend istream& operator>>(istream& in, Student& a);
    friend ostream& operator<<(ostream& out, const Student& a);
    bool operator<(const Student& other) const;
};

struct ClassGroup {
    string class_name;
    Student* students;
    int count;

    ClassGroup();
    ClassGroup(const string& name);
    ClassGroup(const ClassGroup& other);
    ~ClassGroup();

    const ClassGroup& operator=(const ClassGroup& other);
    friend istream& operator>>(istream& in, ClassGroup& a);
    friend ostream& operator<<(ostream& out, const ClassGroup& a);
};

struct School {
    ClassGroup* classes;
    int class_count;

    School();
    School(const School& other);
    ~School();

    void sortSchool();
    const School& operator=(const School& other);
    friend istream& operator>>(istream& in, School& a);
    friend ostream& operator<<(ostream& out, const School& a);
};

#endif