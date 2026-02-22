#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Search(int* req, book* num,int n) {
  int i;
  int k = 0;
  char input[S];
  scanf("%s", input);
  if (strcmp(input, "Stop") == 0) {
    req[0] = 10;
    return;
  }
  for (int i = 0; i < n; i++) {
    req[i] = 0;
    if (strcmp(input, num[i].writer)==0) {
      req[i] = 1;
      k++;
    }
  }
  if (k == 0) {
    req[0] = 5;
  }
}