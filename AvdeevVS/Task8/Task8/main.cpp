#include "working.hpp"
int main(int argc, char** argv) {
  try {
    if (argc < 2) {
      throw "Error --> Incorrect parameters of argv!";
    }
    jobless_base required;
    jobless_base jobless(argv[1]);
    jobless.Finding_right_options(required);
    cout << "Percentage of unemployed with higher education --> " << fixed << setprecision(0) << jobless.Required_percent(required) << "%" << endl << endl;
    cout << "unemployed with higher education:" << endl << endl;
    cout << required;
  }
  catch (const char* error_message) { cout << error_message << endl; }
  return 0;
}