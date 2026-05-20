#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

Person::Person() {
    name.first_name = "";
    name.last_name = "";
    gender = M;
    date_of_birth.day = 1;
    date_of_birth.month = 1;
    date_of_birth.year = 2000;
    country = "";
    city = "";
    sport = Unknown;
    club = "";
    discipline = ""; 
    record = 0.0;
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

      this->array[i] = Person(line);
      
    }
    file.close();
    
}

PersonsLibrary::~PersonsLibrary() {
  delete[]array;
}

Person::Person(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, token, ';');
    stringstream fio_ss(token);
    getline(fio_ss, this->name.last_name, ' ');
    getline(fio_ss, this->name.first_name, ' ');
    getline(ss, token, ';');
    this->gender = (token == "M") ? M : F;

    getline(ss, token, ';');
    sscanf(token.c_str(), "%d-%d-%d",
        &this->date_of_birth.year,
        &this->date_of_birth.month,
        &this->date_of_birth.day);

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
    if ((input_sport == "Athletics")||(input_sport == "athletics")) return Athletics;
    if ((input_sport == "Weightlifting")||(input_sport == "weightlifting")) return Weightlifting;
    if ((input_sport == "Boxing")||(input_sport == "boxing")) return Boxing;
    if ((input_sport == "Tennis")||(input_sport == "tennis")) return Tennis;
    if ((input_sport == "Football")||(input_sport == "football")) return Football;
    return Unknown;
}

BestEntries PersonsLibrary::findRecord(const string& input) {
  Sport target_sport = convertSport(input);

 /* if (target_sport == Unknown) {
    cout << "incorrect sport";
    return ;
  }*/

  BestEntries result;
  result.entryCount = 0;
  BestEntry* unique_disciplines = new BestEntry[this->count];

  for (int i = 0; i < this->count; i++) {
    if (this->array[i].sport == target_sport) {
      bool found = false;
      for (int j = 0; j < result.entryCount; j++) {
        if (unique_disciplines[j].discipline == this->array[i].discipline) {
          found = true;
          break;
        }
      }
      if (!found) unique_disciplines[result.entryCount++].discipline = this->array[i].discipline;
    }
  }

  result.unique_disciplines = new BestEntry[result.entryCount];


  for (int i = 0; i < result.entryCount; i++) {
      result.unique_disciplines[i].best_record = 0;
      for (int j = 0; j < this->count; j++) {
          if (unique_disciplines[i].discipline == this->array[j].discipline) {
              result.unique_disciplines[i].discipline = this->array[j].discipline;
              if (this->array[j].record > result.unique_disciplines[i].best_record) {

                  result.unique_disciplines[i].person = this->array[j];
              }
          }
      }
  }
  delete[]unique_disciplines;
  return result;
}

