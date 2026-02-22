#include "library.h"
#include "auxiliary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
  static int n;
  int proof;
  static int k=1;
  book* num;
  int* req;
  n = Quantity();
  req = (int*)malloc(sizeof(int)*n);
  num = (book*)malloc(sizeof(book) * n);
  void Read(num);
  while (k) {
    void Search(req, num, n);
    void Print(req, num, n);
  }
  free(num);
  free(req);
  return 0;
}