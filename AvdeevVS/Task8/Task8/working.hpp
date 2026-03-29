#ifndef _WORKING_HPP_
#define _WORKING_HPP_
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

struct date_of_birth{
  int day;
  int month;
  int year;
};

struct last_job {
  string position;
  string place;
  string reason_for_termination;
};

struct str_address{
  string town;
  string street;
  int home;
  int flat;
};

struct str_contact{
  string phone_number;
  str_address address;
};

struct str_full_name{
  string first_name;
  string surname;
  string patronymic;
};

struct  jobless_people{
  str_full_name full_name;
  date_of_birth birth_date;
  string profession;
  string education;
  last_job previous_job;
  string marital_status;
  str_contact contact_information;
  jobless_people();
  const jobless_people& operator= (const jobless_people&);
};

struct jobless_base{
  jobless_people* persons;
  int njobless;
  jobless_base();
  jobless_base(char* filename);
  ~jobless_base() {delete[] this->persons;}
  void Finding_right_options(jobless_base& required);
  friend ostream& operator<< (ostream&, const jobless_base&);
  float Required_percent(jobless_base& required);
};
//ostream& operator<< (ostream&, const jobless_base&);
#endif