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

  date_of_birth() {};
  date_of_birth(int, int, int);
  const date_of_birth& operator= (const date_of_birth&);
  friend ostream& operator<< (ostream&, const date_of_birth&);
};

struct last_job {
  string position;
  string place;
  string reason_for_termination;

  last_job() {};
  last_job(const string&, const string&, const string&);
  friend ostream& operator<< (ostream&, const last_job&);
  const last_job& operator= (const last_job&);
};

struct str_address{
  string town;
  string street;
  int home;
  int flat;

  str_address() {};
  str_address(const string&, const string&, int, int);
  friend ostream& operator<< (ostream&, const str_address&);
  const str_address& operator= (const str_address&);
};

struct str_contact{
  string phone_number;
  str_address address;

  str_contact() {};
  str_contact(const string&, const string&, const string&, int, int);
  friend ostream& operator<< (ostream&, const str_contact&);
  const str_contact& operator= (const str_contact&);
};

struct str_full_name{
  string first_name;
  string surname;
  string patronymic;

  str_full_name() {};
  str_full_name(const string&, const string&, const string&);
  friend ostream& operator<< (ostream&, const str_full_name&);
  const str_full_name& operator= (const str_full_name&);
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
  friend ostream& operator<< (ostream&, const jobless_people&);
};

struct jobless_base{
  jobless_people* persons;
  int njobless;

  jobless_base();
  jobless_base(const string&);
  ~jobless_base() {delete[] this->persons;}
  void Finding_right_options(jobless_base& required);
  friend ostream& operator<< (ostream&, const jobless_base&);
  float Required_percent(const jobless_base& required) const;
};
//ostream& operator<< (ostream&, const jobless_base&); --> рабочий вариант
#endif