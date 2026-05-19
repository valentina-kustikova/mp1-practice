#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_BUFF 2048

using namespace std;

class Person_data {
    public:
        string first_name;
        string last_name;

};

class Birsday {
    public:
        int day = 0;
        int month = 0;
        int year = 0;

};

enum Gender { M, F };
enum Sport { Athletics, Weightlifting, Boxing, Tennis, Football, Unknown };

class Person {
public:
    Person_data name;
    Gender gender;
    Birsday date_of_birth;
    string country;
    string city;
    Sport sport;
    string club;
    string discipline;
    double record;
public:
    Person();
    Person(string line);
};

class PersonsLibrary: Person {
protected:
    int count;
    Person* array;
public:
    PersonsLibrary(string filename);
    void findRecord(const string input);
};

struct BestEntry: Person{
public:
    string discipline;
    int best_index;
    double best_record;
    Person person;
};

struct BestEntries: BestEntry{
public:
    int entryCount;
    BestEntry* unique_disciplines;

    friend ostream& operator << (ostream& out, const BestEntries& entries) {
        for (int i = 0; i < entries.entryCount; i++) {
            out << "\nDiscipline: " << entries.unique_disciplines[i].person.discipline << endl;
            out << "Record: " << entries.unique_disciplines[i].person.record << endl;
            out << "Name: " << entries.unique_disciplines[i].person.name.first_name << " " << entries.unique_disciplines[i].person.name.last_name << endl;
        }
        return out;
    }
};



Sport convertSport(const std::string& input_sport);




#endif#pragma once
