#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int con,char** adress) {
  //D.Protsko   E.Shklarsky
  int n;
  int k=1;
  char stop[5] = "stop";
  book* num;
  int* req;
  n = Quantity(adress[1]);
  req = (int*)malloc(sizeof(int)*n);
  num = (book*)malloc(sizeof(book) * n);
  Read(num, adress[1]);
  while (k) {
    char input[S];
    scanf("%s", input);
    if (strcmp(input, stop) == 0) {
      printf("The end!");
      break;
    }
    Search(req, num, n, input);
    Print(req, num, n);
  }
  free(num);
  free(req);
  return 0;
}