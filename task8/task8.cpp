#include <iostream>
#include <clocale> 
#include <cmath>
#include <fstream> 
#include <string>
#include "funcs.h"

using namespace std;


int main(int argc, char **argv) {
  setlocale(LC_ALL, "Russian");
  if (argc < 2)
  {
    cout << "incorrect arguments";
    return 1;
  }
  const char* filename = argv[1];
  TriangleLib lib;
  lib.file_open(filename);
  cout << lib;
  return 0;
}