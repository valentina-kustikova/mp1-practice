#include <iostream>
#include <clocale> 
#include <cmath>
#include <fstream> 
#include <string>

using namespace std;
#include "funcs.h"

int main(int argc, char** argv) {
  setlocale(LC_ALL, "Russian");
  if (argc < 2) {
    printf("incorrect parameters");
    return 1;
  }
  const char* filename = argv[1];
  TriangleLib lib;
  lib.file_open(filename);
  return 0;
}