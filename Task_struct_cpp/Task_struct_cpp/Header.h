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

    PersonsLibrary();
    PersonsLibrary(string filename);
};

struct BestEntry {
    string discipline;
    int best_index;
    double best_record;
};



// Перегрузка функции convertSport
Sport convertSport(const std::string& input_sport);
Sport convertSport(const char* input_sport);  // для совместимости

// Основные функции
int numberLines(const std::string& filename);
void readFile(std::vector<Person>& athletes, const std::string& filename);
void findRecord(const std::vector<Person>& athletes, const std::string& input_sport,
    std::vector<BestEntry>& result);
void printResult(const std::vector<Person>& athletes, const std::vector<BestEntry>& result);

#endif
