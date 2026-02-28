#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void Search(int* req, book* num,int n,char* input) {
  int i,j;
  int flag = 0;
  char* res;
  for (i = 0; i < S; i++) {
    input[i] = tolower(input[i]);
  }
  for (i = 0; i < n; i++) {
    char temp[S];
    strcpy(temp, num[i].writer);
    req[i] = 0;
    for (j = 0; j < S; j++) {
      temp[j] = tolower(temp[j]);
    }
    res = strstr(temp, input);
    if (res != NULL) {
      req[i] = 1;
      flag = 1;
    }
  }
  if (flag == 0) {
    req[0] = 5;
  }
}