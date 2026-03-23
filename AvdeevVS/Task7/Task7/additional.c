#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "find.h"
#include "additional.h"
int Number_of_jobless(char* filename) {
  int count = 0;
  char s[MAX_LEN];
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
  while ((fgets(s, MAX_LEN, f)) != NULL) {
    count++;
  }
  if (count == 0) {
    printf("The file is empty");
    exit(0);
  }
  fclose(f);
  return count;
}
void Filling_from_file(jobless_base jobless, char* filename) {
  int i = 0;
  char s[MAX_LEN];
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
  while ((fgets(s, MAX_LEN, f)) != NULL) {
    jobless.persons[i].full_name.surname = _strdup(strtok(s, " "));
    jobless.persons[i].full_name.first_name = _strdup(strtok(NULL, " "));
    jobless.persons[i].full_name.patronymic = _strdup(strtok(NULL, ";"));
    jobless.persons[i].birth_date.day = atoi(strtok(NULL, "."));
    jobless.persons[i].birth_date.month = atoi(strtok(NULL, "."));
    jobless.persons[i].birth_date.year = atoi(strtok(NULL, ";"));
    jobless.persons[i].profession = _strdup(strtok(NULL, ";"));
    jobless.persons[i].education = _strdup(strtok(NULL, ";"));
    jobless.persons[i].previous_job.position = _strdup(strtok(NULL, ";"));
    jobless.persons[i].previous_job.place = _strdup(strtok(NULL, ";"));
    jobless.persons[i].previous_job.reason_for_termination = _strdup(strtok(NULL, ";"));
    jobless.persons[i].marital_status = _strdup(strtok(NULL, ";"));
    jobless.persons[i].contact_information.phone_number = _strdup(strtok(NULL, ";"));
    jobless.persons[i].contact_information.address.town = _strdup(strtok(NULL, ","));
    jobless.persons[i].contact_information.address.street = _strdup(strtok(NULL, ","));
    jobless.persons[i].contact_information.address.home = atoi(strtok(NULL, ","));
    jobless.persons[i++].contact_information.address.flat = atoi(strtok(NULL, ","));
  }
  fclose(f);
}
void Print_of_result(jobless_base jobless, int* required_indexes, int nrequired_indexes) {
  int i;
  if (nrequired_indexes == 0) {
    printf("Unemployed people with higher education:\n");
    return;
  } 
  printf("\n Percentage of unemployed with higher education --> %.0f%%\n\n", ((nrequired_indexes * 100.f)/ jobless.njobless));
  printf(" Unemployed people with higher education:\n\n");
  for (i = 0; i < nrequired_indexes; i++) {
    printf("%d) --> ", i+1);
    printf("%s ", jobless.persons[required_indexes[i]].full_name.surname);
    printf("%s ", jobless.persons[required_indexes[i]].full_name.first_name);
    printf("%s;", jobless.persons[required_indexes[i]].full_name.patronymic);
    if (jobless.persons[required_indexes[i]].birth_date.day < 10) printf("0%d.", jobless.persons[required_indexes[i]].birth_date.day);
    else printf("%d.", jobless.persons[required_indexes[i]].birth_date.day);
    if (jobless.persons[required_indexes[i]].birth_date.month < 10) printf("0%d.", jobless.persons[required_indexes[i]].birth_date.month);
    else printf("%d.", jobless.persons[required_indexes[i]].birth_date.month);
    printf("%d;", jobless.persons[required_indexes[i]].birth_date.year);
    printf("%s;", jobless.persons[required_indexes[i]].profession);
    printf("%s;", jobless.persons[required_indexes[i]].education);
    printf("%s;", jobless.persons[required_indexes[i]].previous_job.position);
    printf("%s;", jobless.persons[required_indexes[i]].previous_job.place);
    printf("%s;", jobless.persons[required_indexes[i]].previous_job.reason_for_termination);
    printf("%s;", jobless.persons[required_indexes[i]].marital_status);
    printf("%s;", jobless.persons[required_indexes[i]].contact_information.phone_number);
    printf("%s,", jobless.persons[required_indexes[i]].contact_information.address.street);
    printf("%s,", jobless.persons[required_indexes[i]].contact_information.address.town);
    printf("%d,", jobless.persons[required_indexes[i]].contact_information.address.home);
    printf("%d\n\n", jobless.persons[required_indexes[i]].contact_information.address.flat);
  }
}
void Clearing_memory(jobless_base jobless, int* required_indexes) {
  int i;
  for (i = 0; i < jobless.njobless; i++) {
    free(jobless.persons[i].full_name.first_name);
    free(jobless.persons[i].full_name.surname);
    free(jobless.persons[i].full_name.patronymic);
    free(jobless.persons[i].profession);
    free(jobless.persons[i].education);
    free(jobless.persons[i].previous_job.position);
    free(jobless.persons[i].previous_job.place);
    free(jobless.persons[i].previous_job.reason_for_termination);
    free(jobless.persons[i].marital_status);
    free(jobless.persons[i].contact_information.phone_number);
    free(jobless.persons[i].contact_information.address.town);
    free(jobless.persons[i].contact_information.address.street);
  }
  free(jobless.persons);
  free(required_indexes);
}