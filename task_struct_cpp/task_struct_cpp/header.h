#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>


#define MAX_BUFF 2048

using namespace std;

class Person_data {
private:
    string first_name;
    string last_name;
public:
    string getFirstName() { return first_name; }
    string getLastName() { return last_name; }
    void setFirstName(const string& temp) { first_name = temp; }
    void setLastName(const string& temp) { last_name = temp; }
};

class Birsday {
private:
    int day = 0;
    int month = 0;
    int year = 0;
public:
    int getDay() const { return day; }
    void setDay(int temp) { day = temp; }
    void setMonth(int temp) { month = temp; }
    void setYear(int temp) { year = temp; }
};

enum Gender { M, F };
enum Sport { Athletics, Weightlifting, Boxing, Tennis, Football, Unknown };

class Person {
private:
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
    Person(const string& line);
    Person_data getName() const { return name; }
    friend ostream& operator << (ostream& out, const Person& person) {
        out << "\nDiscipline: " << person.discipline << endl;
        out << "Record: " << person.record << endl;
        out << "Name: " << person.getName().getFirstName() << " " << person.getName().getLastName() << endl;
        return out;
    }
    string getDiscipline() const { return discipline; }
    void setDiscipline(string temp) { discipline = temp; }
    Sport getSport() const { return sport; }
    double getRecord() const { return record; }
};

class BestEntries;

class PersonsLibrary {
private:
    int count;
    Person* array;
public:
    PersonsLibrary(const string& filename);
    ~PersonsLibrary();
    BestEntries findRecord(const string& input);
};

class BestEntry {
private:
    string discipline;
    int best_index;
    double best_record;
    Person person;
public:
    Person getPerson() const { return person; }
    void setPerson(Person temp) { person = temp; }
    string getDiscipline() const { return discipline; }
    int getBestRecord() const { return best_record; }
    void setBestRecord(double temp) { best_record = temp; }
    void setDiscipline(string temp) { discipline = temp; }
    void setBestIndex(int temp) { best_index = temp; }
};

class BestEntries {
private:
    int entryCount;
    BestEntry* unique_disciplines;
public:
    int  getEntryCount() const { return entryCount; }
    void setEntryCount(int temp) { entryCount = temp; }
    BestEntry* getUniqueDisciplines() const { return unique_disciplines; }
    void setUniqueDisciplines(BestEntry* temp) { unique_disciplines = temp; }
    friend ostream& operator << (ostream& out, const BestEntries& entries) {

        for (int i = 0; i < entries.entryCount; i++) {
            out << entries.unique_disciplines[i].getPerson();
        }
        return out;
    }
};

Sport convertSport(const std::string& input_sport);

#endif