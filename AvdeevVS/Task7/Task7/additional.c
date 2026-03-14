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
  }
  if (count == 0) {
    printf("The file is empty");
    exit(0);
  }
  fclose(f);
  return count;
}
void Filling_from_file(jobless_people* jobless) {
  int i = 0;
  char s[MAX_LEN];
  FILE* f = fopen("data_base1.txt", "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
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
void Print_of_result(jobless_people* jobless, int* required_indexes, int nrequired_indexes, int njobless) {
  int i;
  if (nrequired_indexes == 0) {
    printf("Unemployed people with higher education:\n");
    return;
  } 
  printf("\nPercentage of unemployed with higher education --> %.0f%%\n\n", ((nrequired_indexes * 100.f)/ njobless));
  printf("Unemployed people with higher education:\n\n");
  for (i = 0; i < nrequired_indexes; i++) {
    printf("%s;", jobless[required_indexes[i]].full_name);
    if (jobless[required_indexes[i]].birth_date.day < 10) printf("0%d.", jobless[required_indexes[i]].birth_date.day);
    else printf("%d.", jobless[required_indexes[i]].birth_date.day);
    if (jobless[required_indexes[i]].birth_date.month < 10) printf("0%d.", jobless[required_indexes[i]].birth_date.month);
    else printf("%d.", jobless[required_indexes[i]].birth_date.month);
    printf("%d;", jobless[required_indexes[i]].birth_date.year);
    printf("%s;", jobless[required_indexes[i]].profession);
    printf("%s;", jobless[required_indexes[i]].education);
    printf("%s;", jobless[required_indexes[i]].previous_job.position);
    printf("%s;", jobless[required_indexes[i]].previous_job.place);
    printf("%s;", jobless[required_indexes[i]].previous_job.reason_for_termination);
    printf("%s;", jobless[required_indexes[i]].marital_status);
    printf("%s;", jobless[required_indexes[i]].contact_information.phone_number);
    printf("%s,", jobless[required_indexes[i]].contact_information.address.street);
    printf("%s,", jobless[required_indexes[i]].contact_information.address.town);
    printf("%d,", jobless[required_indexes[i]].contact_information.address.home);
    printf("%d\n\n", jobless[required_indexes[i]].contact_information.address.flat);
  }
}
void Clearing_memory(jobless_people* jobless, int njobless, int* required_indexes) {
  int i;
  for (i = 0; i < njobless; i++) {
    free(jobless[i].full_name);
    free(jobless[i].profession);
    free(jobless[i].education);
    free(jobless[i].previous_job.position);
    free(jobless[i].previous_job.place);
    free(jobless[i].previous_job.reason_for_termination);
    free(jobless[i].marital_status);
    free(jobless[i].contact_information.phone_number);
    free(jobless[i].contact_information.address.town);
    free(jobless[i].contact_information.address.street);
  }
  free(jobless);
  free(required_indexes);
}