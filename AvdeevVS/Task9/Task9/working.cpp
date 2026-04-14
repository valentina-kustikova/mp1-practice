#include "working.hpp"

date_of_birth::date_of_birth(int day, int month, int year) {
  this->day = day;
  this->month = month;
  this->year = year;
}
const date_of_birth& date_of_birth::operator= (const date_of_birth& a) {
  if (this == &a) return *this;
  this->day = a.day;
  this->month = a.month;
  this->year = a.year;
  return *this;
}
ostream& operator<< (ostream& out, const date_of_birth& a) {
  if (a.day < 10) out << "0" << a.day << ".";
  else out << a.day << ".";
  if (a.month < 10) out << "0" << a.month << ".";
  else out << a.month << ".";
  out << a.year << ";";
  return out;
}

last_job::last_job(const string& position, const string& place, const string& reason_for_termination) {
  this->position = position;
  this->place = place;
  this->reason_for_termination = reason_for_termination;
}
const last_job& last_job::operator= (const last_job& a) {
  if (this == &a) return *this;
  this->position = a.position;
  this->place = a.place;
  this->reason_for_termination = a.reason_for_termination;
  return *this;
}
ostream& operator<< (ostream& out, const last_job& a) {
  out << a.position << ";" << a.place << ";" << a.reason_for_termination << ";";
  return out;
}

str_address::str_address(const string& town, const string& street, int home, int flat) {
  this->town = town;
  this->street = street;
  this->home = home;
  this->flat = flat;
}
const str_address& str_address::operator= (const str_address& a) {
  if (this == &a) return *this;
  this->town = a.town;
  this->street = a.street;
  this->home = a.home;
  this->flat = a.flat;
  return *this;
}
ostream& operator<< (ostream& out, const str_address& a) {
  out << a.town << "," << a.street << "," << a.home << "," << a.flat;
  return out;
}

str_contact::str_contact(const string& phone_number, const string& town, const string& street, int home, int flat) {
  this->phone_number = phone_number;
  this->address = str_address(town, street, home, flat);
}
const str_contact& str_contact::operator= (const str_contact& a) {
  if (this == &a) return *this;
  this->phone_number = a.phone_number;
  this->address = a.address;
  return *this;
}
ostream& operator<< (ostream& out, const str_contact& a) {
  out << a.phone_number << ";" << a.address;
  return out;
}

str_full_name::str_full_name(const string& first_name, const string& surname, const string& patronymic) {
  this->first_name = first_name;
  this->surname = surname;
  this->patronymic = patronymic;
}
const str_full_name& str_full_name::operator= (const str_full_name& a) {
  if (this == &a) return *this;
  this->surname = a.surname;
  this->first_name = a.first_name;
  this->patronymic = a.patronymic;
  return *this;
}
ostream& operator<< (ostream& out, const str_full_name& a) {
  out << a.surname << " " << a.first_name << " " << a.patronymic << ";";
  return out;
}

jobless_people::jobless_people() {
  this->full_name = str_full_name(" ", " ", " ");
  this->birth_date = date_of_birth(0, 0, 0);
  this->profession = ' ';
  this->education = ' ';
  this->previous_job = last_job(" ", " ", " ");
  this->marital_status = ' ';
  this->contact_information = str_contact("", "", "", 0, 0);
}
jobless_people::jobless_people(const str_full_name& p1, const date_of_birth& p2, const string& p3,
  const string& p4, const last_job& p5, const string& p6, const str_contact& p7) {
  this->full_name = p1;
  this->birth_date = p2;
  this->profession = p3;
  this->education = p4;
  this->previous_job = p5;
  this->marital_status = p6;
  this->contact_information = p7;
}
const jobless_people& jobless_people::operator= (const jobless_people& a) {
  if (this == &a) return *this;
  this->full_name = a.full_name;
  this->birth_date = a.birth_date;
  this->profession = a.profession;
  this->education = a.education;
  this->previous_job = a.previous_job;
  this->marital_status = a.marital_status;
  this->contact_information = a.contact_information;
  return *this;
}
ostream& operator<< (ostream& out, const jobless_people& a) {
  out << a.full_name << a.birth_date << a.profession << ";"
    << a.education << ";" << a.previous_job << a.marital_status << ";" << a.contact_information;
  return out;
}

jobless_base::jobless_base() {
  this->njobless = 0;
  this->persons = nullptr;
}
jobless_base::jobless_base(const string& filename) {
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
  for (int i = 0; i < this->njobless; i++) {
    string surname, first_name, patronymic;
    getline(f, s, ' '); surname = s;
    getline(f, s, ' '); first_name = s;
    getline(f, s, ';'); patronymic = s;
    str_full_name fio;
    fio = str_full_name(first_name, surname, patronymic);

    int day, month, year;
    getline(f, s, '.'); day = stoi(s);
    getline(f, s, '.'); month = stoi(s);
    getline(f, s, ';'); year = stoi(s);
    date_of_birth date;
    date = date_of_birth(day, month, year);

    string prof, educ;
    getline(f, s, ';'); prof = s;
    getline(f, s, ';'); educ = s;

    string position, place, reason_for_termination;
    getline(f, s, ';'); position = s;
    getline(f, s, ';'); place = s;
    getline(f, s, ';'); reason_for_termination = s;
    last_job job;
    job = last_job(position, place, reason_for_termination);

    string marital;
    getline(f, s, ';'); marital = s;

    string phone_number, town, street; int home, flat;
    getline(f, s, ';'); phone_number = s;
    getline(f, s, ','); town = s;
    getline(f, s, ','); street = s;
    getline(f, s, ','); home = stoi(s);
    getline(f, s); flat = stoi(s);
    str_contact contact;
    contact = str_contact(phone_number, town, street, home, flat);
    jobless_people add = jobless_people(fio, date, prof, educ, job, marital, contact);
    this->persons[i] = add;
  }
  f.close();
}
void jobless_base::Finding_right_options(jobless_base& required) {
  string s = "higher education";
  string temp;
  int count = 0;
  for (int i = 0; i < this->njobless; i++) {
    temp = persons[i].GetEducation();
    for (int j = 0; j < temp.size(); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (temp.find(s) != string::npos) {
      count++;
    }
  }
  required.njobless = count;
  delete[] required.persons;
  required.persons = new jobless_people[required.njobless];
  int k = 0;
  for (int i = 0; i < this->njobless; i++) {
    temp = persons[i].GetEducation();
    for (int j = 0; j < temp.size(); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (temp.find(s) != string::npos) {
      required.persons[k++] = this->persons[i];
    }
  }
}
float jobless_base::Required_percent(const jobless_base& required) const {
  return (100.0f * required.njobless) / this->njobless;
}
ostream& operator<< (ostream& out, const jobless_base& a) {
  for (int i = 0; i < a.njobless; i++) {
    out << i + 1 << ") --> ";
    out << a.persons[i];
    out << endl << endl;
  }
  return out;
}