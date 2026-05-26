#include <iostream>
#include <clocale> 
#include <cmath>
#include <fstream> 
#include <string>

using namespace std;
#include "funcs.h"

int main() {
  setlocale(LC_ALL, "Russian");

  const char* filename = "triangle.txt";
  TriangleLib lib;
  lib.file_open(filename);
  lib.show_dots();
  return 0;
}