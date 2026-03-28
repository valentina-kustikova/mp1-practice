#include "working.hpp"
jobless_base::jobless_base(char* filename) {
  ifstream f(filename);
  if (f.is_open() == false) {
    cout << "Error:The file does not exist or permissions are missing!";
  }
  string s;
  int count = 0;
  while (getline(f, s)) {
    count++;
  }
  this->njobless = count;
  this->persons = new jobless_people[this->njobless];
  f.clear();
  f.seekg(0, ios::beg);
  int i=0;
  while (getline(f, s)) {
    getline(f, s, ' '); persons[i].full_name.surname = s;
    getline(f, s, ' '); persons[i].full_name.first_name = s;
    getline(f, s, ';'); persons[i].full_name.patronymic = s;
    getline(f, s, '.'); persons[i].birth_date.day = stoi(s);
    getline(f, s, '.'); persons[i].birth_date.month = stoi(s);
    getline(f, s, ';'); persons[i].birth_date.year = stoi(s);
    getline(f, s, ';'); persons[i].profession = s;
    getline(f, s, ';'); persons[i].education = s;
    getline(f, s, ';'); persons[i].previous_job.position = s;
    getline(f, s, ';'); persons[i].previous_job.place = s;
    getline(f, s, ';'); persons[i].previous_job.reason_for_termination = s;
    getline(f, s, ';'); persons[i].marital_status = s;
    getline(f, s, ';'); persons[i].contact_information.phone_number = s;
    getline(f, s, ','); persons[i].contact_information.address.town = s;
    getline(f, s, ','); persons[i].contact_information.address.street = s;
    getline(f, s, ','); persons[i].contact_information.address.home = stoi(s);
    getline(f, s, ','); persons[i++].contact_information.address.flat = stoi(s);
  }
  f.close();
}