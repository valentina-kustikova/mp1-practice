#include "working.hpp"
int main(int argc, char** argv) {
  try {
    system("color F5"); //5-violet 0-black

    string str_argv = argv[1];
    if (argc < 2) {
      throw "Error --> Incorrect parameters of argv!";
    }
    jobless_base required;
    jobless_base jobless(str_argv);
    //cout << jobless;
    jobless.Finding_right_options(required);
    if (required.GetNjobless() == 0) {
      cout << " There are no unemployed people with higher education in the database!";
      return 0;
    }
    cout << " Percentage of unemployed with higher education --> " << fixed << setprecision(0) << jobless.Required_percent(required) << "%" << endl << endl;
    cout << " Unemployed with higher education:" << endl << endl;
    cout << required;
  }
  catch (const char* error_message) { cout << error_message << endl; }
  return 0;
}