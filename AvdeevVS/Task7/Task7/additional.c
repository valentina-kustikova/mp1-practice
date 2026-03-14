#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "find.h"
#include "additional.h"
int Number_of_jobless() {
  int count = 0;
  char s[MAX_LEN];
  FILE* f = fopen("data_base1.txt", "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
  while ((fgets(s, MAX_LEN, f)) != NULL) {
    count++;
    //printf("%d\n", count);
  }
  fclose(f);
  return count;
}
void Filling_from_file(jobless_people* jobless) {
  int i = 0;
  char s[MAX_LEN];
  FILE* f = fopen("data_base1.txt", "r");
  while ((fgets(s, MAX_LEN, f)) != NULL) {
    jobless[i].full_name = _strdup(strtok(s, ";"));
    jobless[i].birth_date.day = atoi(strtok(NULL, "."));
    jobless[i].birth_date.month = atoi(strtok(NULL, "."));
    jobless[i].birth_date.year = atoi(strtok(NULL, ";"));
    jobless[i].profession = _strdup(strtok(NULL, ";"));
    jobless[i].education = _strdup(strtok(NULL, ";"));
    jobless[i].previous_job.position = _strdup(strtok(NULL, ";"));
    jobless[i].previous_job.place = _strdup(strtok(NULL, ";"));
    jobless[i].previous_job.reason_for_termination = _strdup(strtok(NULL, ";"));
    jobless[i].marital_status = _strdup(strtok(NULL, ";"));
    jobless[i].contact_information.phone_number = _strdup(strtok(NULL, ";"));
    jobless[i].contact_information.address.town = _strdup(strtok(NULL, ","));
    jobless[i].contact_information.address.street = _strdup(strtok(NULL, ","));
    jobless[i].contact_information.address.home = atoi(strtok(NULL, ","));
    jobless[i++].contact_information.address.flat = atoi(strtok(NULL, ","));
  }
  fclose(f);
}
void Print_of_result(jobless_people* jobless) {
  int i;
  for (i = 0; i < 1000; i++) {
    printf("%s;", jobless[i].full_name);
    printf("%d.", jobless[i].birth_date.day);
    printf("%d.", jobless[i].birth_date.month);
    printf("%d;", jobless[i].birth_date.year);
    printf("%s;", jobless[i].profession);
    printf("%s;", jobless[i].education);
    printf("%s;", jobless[i].previous_job.position);
    printf("%s;", jobless[i].previous_job.place);
    printf("%s;", jobless[i].previous_job.reason_for_termination);
    printf("%s;", jobless[i].marital_status);
    printf("%s;", jobless[i].contact_information.phone_number);
    printf("%s,", jobless[i].contact_information.address.street);
    printf("%s,", jobless[i].contact_information.address.town);
    printf("%d,", jobless[i].contact_information.address.home);
    printf("%d\n\n", jobless[i].contact_information.address.flat);
  }
}