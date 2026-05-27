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
    Person_data(const string&, const string&);
    Person_data() {
      first_name = "";
      last_name = "";
    }
    string getFirstName() { return first_name; }
    string getLastName() { return last_name; }
};

class Birsday {
private:
    int day = 0;
    int month = 0;
    int year = 0;
public:
    Birsday() {
      day = 1;
      month = 1;
      year = 2000;
    }
    Birsday(int, int, int);
    int getDay() const { return day; }
    void setDay(int temp) { if ((temp < 32) && (temp > 0)) day = temp; else throw "error"; }
    void setMonth(int temp) { if ((temp < 13) && (temp > 0)) month = temp; else throw "error"; }
    void setYear(int temp) { if (temp < 2027) year = temp; else throw "error"; }
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
    void setDiscipline(const string& temp) { discipline = temp; }
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

struct BestEntry { 
    string discipline;
    int best_index;
    double best_record;
    Person person;

};

class BestEntries {
private:
    int entryCount{ 0 };
    BestEntry* unique_disciplines{ NULL };
public:
    BestEntries(int count) { entryCount = count; unique_disciplines = new BestEntry[entryCount]; };
    int  getEntryCount() const { return entryCount; }
    BestEntry* getUniqueDisciplines() const { return unique_disciplines; }
    friend ostream& operator << (ostream& out, const BestEntries& entries) {

        for (int i = 0; i < entries.entryCount; i++) {
            out << entries.unique_disciplines[i].person;
        }
        return out;
    }
};

Sport convertSport(const std::string& input_sport);

#endif