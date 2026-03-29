#include "working.hpp"
int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Fatal:Incorrect parameters!");
    return 1;
  }
  jobless_base required;
  jobless_base jobless(argv[1]);
  jobless.Finding_right_options(required);
  cout << "Percentage of unemployed with higher education --> " << jobless.Required_percent(required) << "%" << endl << endl;
  cout << "unemployed with higher education:" << endl << endl;
  cout << required;
  return 0;
}