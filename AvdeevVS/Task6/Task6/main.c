#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
  //D.Protsko   E.Shklarsky
  static int n;
  static int k=1;
  book* num;
  int* req;
  n = Quantity();
  req = (int*)malloc(sizeof(int)*n);
  num = (book*)malloc(sizeof(book) * n);
  Read(num);
  while (k) {
    Search(req, num, n);
    Print(req, num, n, &k);
  }
  free(num);
  free(req);
  return 0;
}