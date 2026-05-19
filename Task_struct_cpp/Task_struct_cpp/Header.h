#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_BUFF 2048

using namespace std;

struct Person_data {
    string first_name;
    string last_name; 

  //  Person_data();
  //  Person_data(const string& ln, const string& fn); 
}; 

struct Birsday {
    int day = 0;
    int month = 0;
    int year = 0;

  //  Birsday();
  //  Birsday(int d, int m, int y);
};

enum Gender { M, F };
enum Sport { Athletics, Weightlifting, Boxing, Tennis, Football, Unknown };

struct Person {
    Person_data name;
    Gender gender;
    Birsday date_of_birth;
    string country;
    string city;
    Sport sport;
    string club;
    string discipline;
    double record;

    Person();
    Person(string line);
};

struct PersonsLibrary {
    int count;
    Person* array;

    PersonsLibrary(string filename);

    void findRecord(const string input);
};

struct BestEntry {
    string discipline;
    int best_index;
    double best_record;
    Person person;
};

struct BestEntries {
    int entryCount;
    BestEntry* unique_disciplines;

    friend ostream& operator << (ostream& out, const BestEntries& entries) {
      for (int i = 0; i < entries.entryCount; i++) {
        out << "\nDiscipline: " << entries.unique_disciplines[i].person.discipline << endl;
        out << "Record: " << entries.unique_disciplines[i].person.record << endl;
        out << "Name: " << entries.unique_disciplines[i].person.name.first_name <<" "<< entries.unique_disciplines[i].person.name.last_name <<endl;
      }
      return out;
    }
};



Sport convertSport(const std::string& input_sport);




#endif
