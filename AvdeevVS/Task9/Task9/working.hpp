#ifndef _WORKING_HPP_
#define _WORKING_HPP_
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

class date_of_birth {
  int day;
  int month;
  int year;
  
public:
  date_of_birth() {};
  date_of_birth(int, int, int);
  friend ostream& operator<< (ostream&, const date_of_birth&);
};

class last_job {
  string position;
  string place;
  string reason_for_termination;

public:
  last_job() {};
  last_job(const string&, const string&, const string&);
  friend ostream& operator<< (ostream&, const last_job&);
};

class str_address {
  string town;
  string street;
  int home;
  int flat;

public:
  str_address() {};
  str_address(const string&, const string&, int, int);
  friend ostream& operator<< (ostream&, const str_address&);
};

class str_contact {
  string phone_number;
  str_address address;

public:
  str_contact() {};
  str_contact(const string&, const string&, const string&, int, int);
  friend ostream& operator<< (ostream&, const str_contact&);
};

class str_full_name {
  string first_name;
  string surname;
  string patronymic;

public:
  str_full_name() {};
  str_full_name(const string&, const string&, const string&);
  friend ostream& operator<< (ostream&, const str_full_name&);
};

class  jobless_people {
  str_full_name full_name;
  date_of_birth birth_date;
  string profession;
  string education;
  last_job previous_job;
  string marital_status;
  str_contact contact_information;

public:
  jobless_people();
  jobless_people(const str_full_name&, const date_of_birth&, const string&,
    const string&, const last_job&, const string&, const str_contact&);
  string GetEducation() const { return this->education; };
  friend ostream& operator<< (ostream&, const jobless_people&);
};

class jobless_base {
  jobless_people* persons;
  int njobless;

public:
  jobless_base();
  jobless_base(const string&);
  int GetNjobless() const { return this->njobless; };
  ~jobless_base() { delete[] this->persons; };
  void Finding_right_options(jobless_base& required);
  friend ostream& operator<< (ostream&, const jobless_base&);
  float Required_percent(const jobless_base& required) const;
};
#endif