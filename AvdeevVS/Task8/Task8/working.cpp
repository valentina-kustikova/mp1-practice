#include "working.hpp"
jobless_base::jobless_base(char* filename) {
  ifstream f(filename);
  if (f.is_open() == false) {
    cout << "Error:The file does not exist or permissions are missing!";
  }
  string s;
  int count = 0;
  while (getline(f, s)) {
    count++;
  }
  this->njobless = count;
  this->persons = new jobless_people[this->njobless];
  f.close();
}