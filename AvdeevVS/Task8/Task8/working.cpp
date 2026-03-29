#include "working.hpp"
jobless_base::jobless_base() {
  this->njobless = 1;
  this->persons = new jobless_people[this->njobless];
  persons[0].full_name.surname = ' ';
  persons[0].full_name.first_name = ' ';
  persons[0].full_name.patronymic = ' ';
  persons[0].birth_date.day = 0;
  persons[0].birth_date.month = 0;
  persons[0].birth_date.year = 0;
  persons[0].profession = ' ';
  persons[0].education = ' ';
  persons[0].previous_job.position = ' ';
  persons[0].previous_job.place = ' ';
  persons[0].previous_job.reason_for_termination = ' ';
  persons[0].marital_status = ' ';
  persons[0].contact_information.phone_number = ' ';
  persons[0].contact_information.address.town = ' ';
  persons[0].contact_information.address.street = ' ';
  persons[0].contact_information.address.home = 0;
  persons[0].contact_information.address.flat = 0;
}
jobless_base::jobless_base(char* filename ) {
  ifstream f(filename);
  if (f.is_open() == false) {
     throw "Error --> The file does not exist or permissions are missing!";
  }
  string s;
  int count = 0;
  while (getline(f, s)) {
    count++;
  }
  if (count == 0) {
    throw "Error --> The database is empty!";
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
jobless_people::jobless_people() {
  this->full_name.surname = ' ';
  this->full_name.first_name = ' ';
  this->full_name.patronymic = ' ';
  this->birth_date.day = 0;
  this->birth_date.month = 0;
  this->birth_date.year = 0;
  this->profession = ' ';
  this->education = ' ';
  this->previous_job.position = ' ';
  this->previous_job.place = ' ';
  this->previous_job.reason_for_termination = ' ';
  this->marital_status = ' ';
  this->contact_information.phone_number = ' ';
  this->contact_information.address.town = ' ';
  this->contact_information.address.street = ' ';
  this->contact_information.address.home = 0;
  this->contact_information.address.flat = 0;
}
const jobless_people& jobless_people::operator= (const jobless_people& a) {
  if (this == &a) return *this;
  this->full_name.surname = a.full_name.surname;
  this->full_name.first_name = a.full_name.first_name;
  this->full_name.patronymic = a.full_name.patronymic;
  this->birth_date.day = a.birth_date.day;
  this->birth_date.month = a.birth_date.month;
  this->birth_date.year = a.birth_date.year;
  this->profession = a.profession;
  this->education = a.education;
  this->previous_job.position = previous_job.position;
  this->previous_job.place = previous_job.place;
  this->previous_job.reason_for_termination = a.previous_job.reason_for_termination;
  this->marital_status = a.marital_status;
  this->contact_information.phone_number = a.contact_information.phone_number;
  this->contact_information.address.town = a.contact_information.address.town;
  this->contact_information.address.street = contact_information.address.street;
  this->contact_information.address.home = a.contact_information.address.home;
  this->contact_information.address.flat = a.contact_information.address.flat;
  return *this;
}
void jobless_base::Finding_right_options(jobless_base required) {
  string s = "higher education";
  string temp;
  int count = 0;
  for (int i = 0; i < this->njobless; i++) {
    temp = this->persons[i].education;
    for (int j = 0; j < temp.size(); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (temp.find(s) != string::npos) {       //maybe contains() c++23
      count++;
    }
  }
  if(count == 0) {
    cout << "There are no unemployed people with higher education in the database!";
    exit(0);
  }
  required.njobless = count;
  delete[] required.persons;
  required.persons = new jobless_people[required.njobless];
  int k = 0;
  for (int i = 0; i < this->njobless; i++) {
    temp = this->persons[i].education;
    for (int j = 0; j < temp.size(); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (temp.find(s) != string::npos) {
      required.persons[k++] = this->persons[i];
    }
  }
}
float jobless_base::Required_percent(jobless_base required) {
  return (100.0f * required.njobless) / this->njobless;
}
ostream& operator<< (ostream& out, const jobless_base& a) {
  for (int i = 0; i < a.njobless; i++) {
    out << i + 1 << ") --> ";
    out << a.persons[i].full_name.surname<<" ";
    out << a.persons[i].full_name.first_name << " ";
    out << a.persons[i].full_name.patronymic << ";";
    if (a.persons[i].birth_date.day < 10) out << "0" << a.persons[i].birth_date.day << ".";
    else out << a.persons[i].birth_date.day << ".";
    if (a.persons[i].birth_date.month < 10) out << "0" << a.persons[i].birth_date.month << ".";
    else out << a.persons[i].birth_date.month << ".";
    out << a.persons[i].birth_date.year << ";";
    out << a.persons[i].profession << ";";
    out << a.persons[i].education << ";";
    out << a.persons[i].previous_job.position << ";";
    out << a.persons[i].previous_job.place << ";";
    out << a.persons[i].previous_job.reason_for_termination << ";";
    out << a.persons[i].marital_status << ";";
    out << a.persons[i].contact_information.phone_number << ";";
    out << a.persons[i].contact_information.address.street << ",";
    out << a.persons[i].contact_information.address.town << ",";
    out << a.persons[i].contact_information.address.home << ",";
    out << a.persons[i].contact_information.address.flat << endl << endl;
    return out;
  }
}