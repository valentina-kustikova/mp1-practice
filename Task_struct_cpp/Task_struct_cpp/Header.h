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

    Person_data();
    Person_data(const string& ln, const string& fn);
}; 

struct Birsday {
    int day = 0;
    int month = 0;
    int year = 0;

    Birsday();
    Birsday(int d, int m, int y);
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
};

struct PersonsLibrary {
    int count;
    Person* array;

    PersonsLibrary(string filename);
    ~PersonsLibrary();

    void findRecord(const string input);
    //friend ostream& operator <<(ostream& out, const BestEntries& result) {
    //  for (int i = 0; i < result.entryCount; i++) {
    //    const Person p = this->array[result.unique_disciplines[i].best_index];
    //    out << "\nDiscipline: " << p.discipline << endl;
    //    out << "Name: " << p.name.first_name << " " << p.name.last_name << endl;
    //    out << "Record: " << p.record << endl;
    //    out << "Country: " << p.country << endl;
    //    out << "Club: " << p.club << endl;
    //  }
    //  return out;
    //}
};

struct BestEntry {
    string discipline;
    int best_index;
    double best_record;
};

struct BestEntries {
    int entryCount;
    BestEntry* unique_disciplines;

    friend ostream& operator << (ostream& out, const BestEntries& entries) {
      for (int i = 0; i < entries.entryCount; i++) {
        out << "\nDiscipline: " << entries.unique_disciplines[i].discipline << endl;
        out << "Record: " << entries.unique_disciplines[i].best_record << endl;
      }
      return out;
    }
};



Sport convertSport(const std::string& input_sport);
Sport convertSport(const char* input_sport); 



#endif
