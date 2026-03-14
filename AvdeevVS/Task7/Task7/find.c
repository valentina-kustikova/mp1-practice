#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "find.h"
#include "additional.h"
#define MAX_EDUCATION_LEN 20
void finding_right_options(jobless_people* jobless, int njobless,int* nrequired_indexes, int** required_indexes){
  int i,j,k=0;
  char higher_education[MAX_EDUCATION_LEN] = "higher education";
  for (i = 0; i < njobless; i++) {
    char temp[MAX_LEN];
    strcpy(temp, jobless[i].education);
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
  for (i = 0; i < njobless; i++) {
    char temp[MAX_LEN];
    strcpy(temp, jobless[i].education);
    for (j = 0; j < strlen(temp); j++) {
      temp[j] = tolower(temp[j]);
    }
    if (strstr(temp, higher_education) != NULL) {
      (*required_indexes)[k++] = i;
    }
  }
}
/*float percentage_of_higher_education(int nrequired_indexes, int njobless) {
  float percent = (nrequired_indexes / njobless) * 100.f;
  return percent;
}*/