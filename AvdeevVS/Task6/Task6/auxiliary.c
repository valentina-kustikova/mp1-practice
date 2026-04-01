#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auxiliary.h"
#include "library.h"


int get_books_num(char* filename) {
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
  fclose(f);
  return count;
}

void read_books(book* books, char* filename){
  int i = 0;
  char s[MAX_LEN];
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
      printf("Error:The file does not exist or permissions are missing!");
      exit(0);
  }
  while (fgets(s, MAX_LEN, f) != NULL){
    strcpy(books[i].writer, _strdup(strtok(s, ";")));
    strcpy(books[i].name, _strdup(strtok(NULL, ";")));
    strcpy(books[i].publish, _strdup(strtok(NULL, ";")));
    books[i++].year = atoi(_strdup(strtok(NULL, ";")));
  }
  fclose(f);
}

void print_books(book* books, int nBooks, int* indecesAuthorBooks, int kAuthorBooks) {
  int i;
  if (kAuthorBooks == 0) {
    printf("\nBooks by this author:\n\n");
    printf("There are no books by this author\n\n");
    return;
  }
    printf("\nBooks by this author:\n\n");
    for (i = 0; i < kAuthorBooks; i++) {       
        printf("%s;", books[indecesAuthorBooks[i]].writer);
        printf("%s;", books[indecesAuthorBooks[i]].name);
        printf("%s;", books[indecesAuthorBooks[i]].publish);
        printf("%d\n", books[indecesAuthorBooks[i]].year);        
    }
    printf("\n");
}