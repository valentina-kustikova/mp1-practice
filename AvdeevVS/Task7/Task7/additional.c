#include "find.h"
#include "additional.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Quantity() {
  int count = 0;
  char s[T];
  FILE* f = fopen("data_base.txt", "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
  while ((fgets(s, T, f)) != NULL) {
    count++;
  }
  fclose(f);
  return count;
}
void Read(jobless* arr) {
  int i = 0;
  char s[T];
  FILE* f = fopen("data_base.txt", "r");
  while ((fgets(s, T, f)) != NULL) {
    strcpy(arr[i].name, _strdup(strtok(s, ";")));
    strcpy(arr[i].birth.day, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].birth.month, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].birth.year, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].craft, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].education, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].last_job.post, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].last_job.place, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].last_job.reason, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].family, _strdup(strtok(NULL, ";")));
    strcpy(arr[i].contact.phone, _strdup(strtok(NULL, ";")));
    strcpy(arr[i++].contact.adress, _strdup(strtok(NULL, ";")));
  }
  fclose(f);
}