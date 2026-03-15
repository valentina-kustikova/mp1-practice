#ifndef _FIND_H_
#define _FIND_H_
#define MAX_LEN 1000
typedef struct {
  int day;
  int month;
  int year;
} date_of_birth;
typedef struct {
  char* position;
  char* place;
  char* reason_for_termination;
} last_job;
typedef struct {
  char* town;
  char* street;
  int home;
  int flat;
} str_address;
typedef struct {
  char* phone_number;
  str_address address;
} str_contact;
typedef struct {
  char* full_name;
  date_of_birth birth_date;
  char* profession;
  char* education;
  last_job previous_job;
  char* marital_status;
  str_contact contact_information;
} jobless_people;
void Finding_right_options(jobless_people* jobless, int njobless, int* nrequired_indexes, int** required_indexes);
//float percentage_of_higher_education(int nrequired_indexes, int njobless);
#endif