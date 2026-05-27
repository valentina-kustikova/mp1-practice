#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

Person::Person() {
    Person_data name();
    gender = M;
    Birsday date_of_birth();
    country = "";
    city = "";
    sport = Unknown;
    club = "";
    discipline = "";
    record = 0.0;
}

Person_data::Person_data(const string& first, const string& last) {
  first_name = first;
  last_name = last;
}

Birsday::Birsday(int day, int month, int year) {
  setDay(day);
  setMonth(month);
  setYear(year);
}

PersonsLibrary::PersonsLibrary(const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        throw "error with opening file";
    }
    int count = 0;
    string line;
    while (getline(file, line)) { count++; }
    this->count = count;
    this->array = new Person[this->count];
    file.clear();
    file.seekg(0);


    for (int i = 0; i < this->count; i++) {
        getline(file, line);
        if (line.empty()) continue;

        array[i] = Person(line);
    }
    file.close();

}


PersonsLibrary::~PersonsLibrary() {
    delete[]array;
}


Person::Person(const string& line) {
    stringstream ss(line);
    string token;
    string temp;
    int year = 2000, month = 1, day = 1;
    getline(ss, token, ';');
    stringstream fio_ss(token);
    getline(fio_ss, temp, ' ');
    string last = temp;
    getline(fio_ss, temp, ' ');
    string first = temp;
    Person_data name(first, last);
    getline(ss, token, ';');
    this->gender = (token == "M") ? M : F;

    getline(ss, token, ';');
    stringstream date_ss(token);
    getline(date_ss, temp, '-');
    date_of_birth.setYear(year);
    getline(date_ss, temp, '-');
    date_of_birth.setMonth(month);
    getline(date_ss, temp, '-');
    date_of_birth.setDay(day);
    getline(ss, this->country, ';');

    getline(ss, this->city, ';');

    getline(ss, token, ';');
    this->sport = convertSport(token);

    getline(ss, this->club, ';');

    getline(ss, this->discipline, ';');

    getline(ss, token, ';');
    this->record = stod(token);
}

Sport convertSport(const string& input_sport) {
    if ((input_sport == "Athletics") || (input_sport == "athletics")) return Athletics;
    if ((input_sport == "Weightlifting") || (input_sport == "weightlifting")) return Weightlifting;
    if ((input_sport == "Boxing") || (input_sport == "boxing")) return Boxing;
    if ((input_sport == "Tennis") || (input_sport == "tennis")) return Tennis;
    if ((input_sport == "Football") || (input_sport == "football")) return Football;
    return Unknown;
}


BestEntries PersonsLibrary::findRecord(const string& input) {
    Sport target_sport = convertSport(input);
    int entryCount = 0;
    if (target_sport == Unknown) {
        cout << "incorrect sport";
    }

    
    BestEntry* unique_disciplines = new BestEntry[this->count];

    for (int i = 0; i < this->count; i++) {
        if (this->array[i].getSport() == target_sport) {
            bool found = false;
            for (int j = 0; j < entryCount; j++) {
                if (unique_disciplines[j].discipline == array[i].getDiscipline()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unique_disciplines[entryCount].discipline = array[i].getDiscipline();
                entryCount++;
            }
        }
    }

    BestEntries result(entryCount);



    for (int i = 0; i < result.getEntryCount(); i++) {
        result.getUniqueDisciplines()[i].best_record = 0;
        for (int j = 0; j < this->count; j++) {
            if (unique_disciplines[i].discipline == this->array[j].getDiscipline()) {
                result.getUniqueDisciplines()[i].discipline = this->array[j].getDiscipline();
                if (this->array[j].getRecord() > result.getUniqueDisciplines()[i].best_record) {

                    result.getUniqueDisciplines()[i].person = this->array[j];
                }
            }
        }
    }
    delete[]unique_disciplines;
    return result;
}