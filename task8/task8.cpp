#include <iostream>
#include <clocale> 
#include <cmath>
#include <fstream> 
#include <string>

using namespace std;
#include "funcs.h"

int main(int argc, char** argv) {

  if (argc < 2) {
    printf("incorrect parameters");
    return 1;
  }

  char* filename = argv[1];
  setlocale(LC_ALL, "Russian");
  TriangleLib* lib = file_open(filename);

  show_dots(lib->triangles, lib->count);

  for (int i = 0; i < lib->count; i++) {

    print_file(&lib->triangles[i]);
  }

  free(lib->triangles);
  free(lib);
  return 0;
}