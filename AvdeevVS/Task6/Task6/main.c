#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
  //D.Protsko   E.Shklarsky
  static int n;
  int i,j;
  static int k=1;
  book* num;
  int* req;
  n = Quantity();
  req = (int*)malloc(sizeof(int)*n);
  num = (book*)malloc(sizeof(book) * n);
  void Read(num);
  for (i = 0; i < n; i++) {
    printf("%s ", num[i].writer);
    printf("%s ", num[i].name);
    printf("%s ", num[i].publish);
    printf("%s", num[i].year);
    printf("\n");
  }
  while (k) {
    Search(req, num, n);
    Print(req, num, n, &k);
  }
  free(num);
  free(req);
  return 0;
}