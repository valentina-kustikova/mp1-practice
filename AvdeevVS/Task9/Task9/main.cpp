#include "working.hpp"
int main(int argc, char** argv) {
  try {
    system("color F0"); //5-violet 0-black
    ios::sync_with_stdio(false);

    string str_argv = argv[1];
    if (argc < 2) {
      throw "Error --> Incorrect parameters of argv!";
    }
    jobless_base required;
    jobless_base jobless(str_argv);
    //cout << jobless;
    jobless.Finding_right_options(required);
    cout << " Percentage of unemployed with higher education --> " <<
        fixed << setprecision(0) << jobless.Required_percent(required) <<
        "%" << endl << endl;
    cout << " Unemployed with higher education:" << endl << endl;
    cout << required;
  }
  catch (const char* error_message) {
      cout << error_message << endl;
  }
  return 0;
}