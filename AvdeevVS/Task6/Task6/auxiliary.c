#include "auxiliary.h"
#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define O 1
int Quantity() {
  int count = 0;
  char a[O];
  FILE* f = fopen("books.txt", "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
  while (a[0] = fgetc(f) != EOF) {
    if (a[0] == '\n') {
      count++;
    }
  }
    fclose(f);
    count++;
    return count;
}
void Read(book* num){
  int i = 0;
  char s[P];
  FILE* f = fopen("books.txt", "r"); 
  while ((fgets(s, P, f)) != NULL){
    num[i].writer = strdup(strtok(s, ";"));
    num[i].name = strdup(strtok(NULL, ";"));
    num[i].publish = strdup(strtok(NULL, ";"));
    num[i++].year = strdup(strtok(NULL, ";"));
  }
  fclose(f);
  return 0;
}
void Print(int* req, book* num, int n) {
  int i;
  if (req[0] == 5) {
    printf("There are no books by this author");
  }
  else if (req[0] == 10) {
    printf("The end!");
  }
  else {
    for (i = 0; i < n; i++) {
      if (req[i] == 1) {
        printf("%s ", num[i].writer);
        printf("%s ", num[i].name);
        printf("%s ", num[i].publish);
        printf("%s", num[i].year);
        printf("\n");
      }
    }
  }
}