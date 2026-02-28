#include "auxiliary.h"
#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Quantity(int con,char* adress) {
  int count = 0;
  char s[P];
  //FILE* f = fopen("books.txt", "r");
  FILE* f = fopen(adress[1], "r");
  if (f == NULL) {
    printf("Error:The file does not exist or permissions are missing!");
    exit(0);
  }
  while ((fgets(s, P, f)) != NULL) {
    count++;
  }
  fclose(f);
  return count;
}
void Read(book* num, char* adress){
  int i = 0;
  char s[P];
  //FILE* f=open("books.txt,"r");
  FILE* f = fopen(adress[1], "r");
  while ((fgets(s, P, f)) != NULL){
    strcpy(num[i].writer, _strdup(strtok(s, ";")));
    strcpy(num[i].name, _strdup(strtok(NULL, ";")));
    strcpy(num[i].publish, _strdup(strtok(NULL, ";")));
    strcpy(num[i++].year, _strdup(strtok(NULL, ";")));
  }
  fclose(f);
}
void Print(int* req, book* num, int n) {
  int i;
  if (req[0] == 5) {
    printf("\nBooks by this author:\n\n");
    printf("There are no books by this author\n\n");
  }
  else {
    printf("\nBooks by this author:\n\n");
    for (i = 0; i < n; i++) {
      if (req[i] == 1) {
        printf("%s;", num[i].writer);
        printf("%s;", num[i].name);
        printf("%s;", num[i].publish);
        printf("%s", num[i].year);
      }
    }
    printf("\n");
  }
}