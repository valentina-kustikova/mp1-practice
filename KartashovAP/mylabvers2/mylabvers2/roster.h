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

    friend ostream& operator<<(ostream& out, const FullName& a);
};

struct Date {
    int day;
    int month;
    int year;

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

    friend ostream& operator<<(ostream& out, const Address& a);
};

struct Student {
    FullName full_name;
    string class_name;
    Gender gender;
    Date birth_date;
    Address address;

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

    void addStudent(const Student& student);
    void sortStudents();

    ClassGroup& operator=(const ClassGroup& other);
    friend ostream& operator<<(ostream& out, const ClassGroup& a);
};

struct School {
    ClassGroup* classes;
    int class_count;

    School();
    School(const string& filename);
    School(const School& other);
    ~School();

    void loadFromFile(const string& filename);
    void sortSchool();

    School& operator=(const School& other);
    friend ostream& operator<<(ostream& out, const School& a);
};

#endif