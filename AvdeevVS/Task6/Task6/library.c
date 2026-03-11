#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

void Search(book* books, int nBooks, char* author,
    int** indecesAuthorBooks, int* nAuthorBooks) {
  int i, j, k = 0;
  int flag = 0;
  *nAuthorBooks = 0;
  for (i = 0; i < strlen(author); i++) {
    author[i] = tolower(author[i]);
  }
  for (i = 0; i < nBooks; i++) {
    char temp[MAX_WRITER_LEN];
    strcpy(temp, books[i].writer);
    for (j = 0; j < strlen(temp) + 1; j++) {
      temp[j] = tolower(temp[j]);
    }    
    if (strstr(temp, author) != NULL) {
        (*nAuthorBooks)++;
    }
  }
  if ((*nAuthorBooks) == 0)
  {
      *indecesAuthorBooks = NULL;
      return;
  }
  *indecesAuthorBooks = (int*)malloc((*nAuthorBooks) * sizeof(int));
  for (i = 0; i < nBooks; i++) {
      char temp[MAX_WRITER_LEN];
      strcpy(temp, books[i].writer);
      for (j = 0; j < strlen(temp) + 1; j++) {
          temp[j] = tolower(temp[j]);
      }
      if (strstr(temp, author) != NULL) {
          (*indecesAuthorBooks)[k++] = i;
      }
  }
}