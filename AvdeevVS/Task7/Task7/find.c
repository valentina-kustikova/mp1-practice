#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "find.h"
#include "additional.h"
#define MAX_EDUCATION_LEN 20
void Finding_right_options(jobless_base jobless, int* nrequired_indexes, int** required_indexes){
  int i,j,k=0;
  char higher_education[MAX_EDUCATION_LEN] = "higher education";
  for (i = 0; i < jobless.njobless; i++) {
    char temp[MAX_LEN];
    strcpy(temp, jobless.persons[i].education);
    for (j = 0; j < strlen(temp); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (strstr(temp, higher_education) != NULL) {
      (*nrequired_indexes)++;
    }
  }
  if ((*nrequired_indexes) == 0){
    *required_indexes = NULL;
    return;
  }
  else {
    *required_indexes = (int*)malloc((*nrequired_indexes) * sizeof(int));
  }
  for (i = 0; i < jobless.njobless; i++) {
    char temp[MAX_LEN];
    strcpy(temp, jobless.persons[i].education);
    for (j = 0; j < strlen(temp); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (strstr(temp, higher_education) != NULL) {
      (*required_indexes)[k++] = i;
    }
  }
}